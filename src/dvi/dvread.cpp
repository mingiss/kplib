/* ----------------
 * dvread.cpp
 *      reading DVI file
 *      implementation 
 *
 *  Changelog:
 *      2013-06-07  mp  split from drti.c
 *      2013-06-20  mp  DviRead class implemented 
 *
 */


// -------------------------
#include "envir.h"

#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

#include "kpstdlib.h"
#include "kperrno.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kptree.h"
#include "kptt.h"
#include "kpstring.h"

#include "dvi.h"
#include "rtid.h"
#include "dvread.h"


// -------------------------
/* Table for opcodes 128 to 170 inclusive. */

op_info  op_info_128_170 [] =
{
  {DVI_set,     "s1",   1,  "1",  /* DVREAD_TransExtChar_Ix, */ (DvTransFunPtr)&DviRead::TransExtChar, DVI_set},    // 128
  {DVI_set + 1, "s2",   1,  "2",  /* DVREAD_TransExtChar_Ix, */ (DvTransFunPtr)&DviRead::TransExtChar, DVI_set},    // 129
  {DVI_set + 2, "s3",   1,  "3",  /* DVREAD_TransExtChar_Ix, */ (DvTransFunPtr)&DviRead::TransExtChar, DVI_set},    // 130
  {DVI_set + 3, "s4",   1,  "-4", /* DVREAD_TransExtChar_Ix, */ (DvTransFunPtr)&DviRead::TransExtChar, DVI_set},    // 131
  {DVI_set_rule, "sr",  2,  "-4 -4", /* DVREAD_Trans_NoIx, */   (DvTransFunPtr)&DviRead::TransRule, DVI_set_rule},  // 132
  {DVI_put,     "p1",   1,  "1",    (DvTransFunPtr)&DviRead::TransExtChar,   DVI_put},  // 133
  {DVI_put + 1, "p2",   1,  "2",    (DvTransFunPtr)&DviRead::TransExtChar,   DVI_put},  // 134
  {DVI_put + 2, "p3",   1,  "3",    (DvTransFunPtr)&DviRead::TransExtChar,   DVI_put},  // 135
  {DVI_put + 3, "p4",   1,  "-4",   (DvTransFunPtr)&DviRead::TransExtChar,   DVI_put},  // 136
  {DVI_put_rule,"pr",   2,  "-4 -4", (DvTransFunPtr)&DviRead::TransRule, DVI_put_rule}, // 137
  {DVI_nop,     "nop",  0,  "",     NULL,   DVI_nop}, // 138
  {DVI_bop,     "bop",  11, "-4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4", (DvTransFunPtr)&DviRead::TransPage, DVI_bop}, // 139
  {DVI_eop,     "eop",  0,  "",     NULL,   DVI_eop}, // 140
  {DVI_push,    "[",    0,  "",     (DvTransFunPtr)&DviRead::TransPush, DVI_push},      // 141
  {DVI_pop,     "]",    0,  "",     (DvTransFunPtr)&DviRead::TransPop,  DVI_pop},       // 142
  {DVI_right,   "r1",   1,  "1",    (DvTransFunPtr)&DviRead::TransMove,   DVI_right},   // 143
  {DVI_right + 1, "r2", 1,  "2",    (DvTransFunPtr)&DviRead::TransMove,   DVI_right},   // 144
  {DVI_right + 2, "r3", 1,  "3",    (DvTransFunPtr)&DviRead::TransMove,   DVI_right},   // 145
  {DVI_right + 3, "r4", 1,  "-4",   (DvTransFunPtr)&DviRead::TransMove,   DVI_right},   // 146
  {DVI_w,       "w0",   0,  "",     (DvTransFunPtr)&DviRead::TransMove,   DVI_w + 1},   // 147
  {DVI_w + 1,   "w1",   1,  "1",    (DvTransFunPtr)&DviRead::TransMove,   DVI_w + 1},   // 148
  {DVI_w + 2,   "w2",   1,  "2",    (DvTransFunPtr)&DviRead::TransMove,   DVI_w + 1},   // 149
  {DVI_w + 3,   "w3",   1,  "3",    (DvTransFunPtr)&DviRead::TransMove,   DVI_w + 1},   // 150
  {DVI_w + 4,   "w4",   1,  "-4",   (DvTransFunPtr)&DviRead::TransMove,   DVI_w + 1},   // 151
  {DVI_x,       "x0",   0,  "",     (DvTransFunPtr)&DviRead::TransMove,   DVI_x + 1},   // 152
  {DVI_x + 1,   "x1",   1,  "1",    (DvTransFunPtr)&DviRead::TransMove,   DVI_x + 1},   // 153
  {DVI_x + 2,   "x2",   1,  "2",    (DvTransFunPtr)&DviRead::TransMove,   DVI_x + 1},   // 154
  {DVI_x + 3,   "x3",   1,  "3",    (DvTransFunPtr)&DviRead::TransMove,   DVI_x + 1},   // 155
  {DVI_x + 4,   "x4",   1,  "-4",   (DvTransFunPtr)&DviRead::TransMove,   DVI_x + 1},   // 156
  {DVI_down,    "d1",   1,  "1",    (DvTransFunPtr)&DviRead::TransMove,   DVI_down},    // 157
  {DVI_down + 1, "d2",  1,  "2",    (DvTransFunPtr)&DviRead::TransMove,   DVI_down},    // 158
  {DVI_down + 2, "d3",  1,  "3",    (DvTransFunPtr)&DviRead::TransMove,   DVI_down},    // 159
  {DVI_down + 3, "d4",  1,  "-4",   (DvTransFunPtr)&DviRead::TransMove,   DVI_down},    // 160
  {DVI_y,        "y0",  0,  "",     (DvTransFunPtr)&DviRead::TransMove,   DVI_y + 1},   // 161
  {DVI_y + 1,    "y1",  1,  "1",    (DvTransFunPtr)&DviRead::TransMove,   DVI_y + 1},   // 162
  {DVI_y + 2,    "y2",  1,  "2",    (DvTransFunPtr)&DviRead::TransMove,   DVI_y + 1},   // 163
  {DVI_y + 3,    "y3",  1,  "3",    (DvTransFunPtr)&DviRead::TransMove,   DVI_y + 1},   // 164
  {DVI_y + 4,    "y4",  1,  "-4",   (DvTransFunPtr)&DviRead::TransMove,   DVI_y + 1},   // 165
  {DVI_z,        "z0",  0,  "",     (DvTransFunPtr)&DviRead::TransMove,   DVI_z + 1},   // 166
  {DVI_z + 1,    "z1",  1,  "1",    (DvTransFunPtr)&DviRead::TransMove,   DVI_z + 1},   // 167
  {DVI_z + 2,    "z2",  1,  "2",    (DvTransFunPtr)&DviRead::TransMove,   DVI_z + 1},   // 168
  {DVI_z + 3,    "z3",  1,  "3",    (DvTransFunPtr)&DviRead::TransMove,   DVI_z + 1},   // 169
  {DVI_z + 4,    "z4",  1,  "-4",   (DvTransFunPtr)&DviRead::TransMove,   DVI_z + 1}    // 170
};  /* op_info  op_info_128_170 [] */
                            
                       
op_table  op_128_170  =  {"op_128_170", 128, 170, op_info_128_170};
                       
                       
/* Table for font with 1 to 4 bytes (opcodes 235 to 238) inclusive. */
                       
op_info op_info_235_248[] =
// op_info  fnt_n [] =    
{                      
    { DVI_fnt,      "f1", 1, "1",   (DvTransFunPtr)&DviRead::TransSetFont, DVI_fnt}, // 235
    { DVI_fnt + 1,  "f2", 1, "2",   (DvTransFunPtr)&DviRead::TransSetFont, DVI_fnt}, // 236
    { DVI_fnt + 2,  "f3", 1, "3",   (DvTransFunPtr)&DviRead::TransSetFont, DVI_fnt}, // 237
    { DVI_fnt + 3,  "f4", 1, "-4",  (DvTransFunPtr)&DviRead::TransSetFont, DVI_fnt}, // 238
// };  /* op_info  fnt_n [] */
// op_table  fnt  =  {"f", 235, 238, fnt_n};
    { DVI_xxx,      "xxx1", 1,  "1",   (DvTransFunPtr)&DviRead::TransSpec, DVI_xxx }, // 239
    { DVI_xxx + 1,  "xxx1", 1,  "2",   (DvTransFunPtr)&DviRead::TransSpec, DVI_xxx }, // 240
    { DVI_xxx + 2,  "xxx1", 1,  "3",   (DvTransFunPtr)&DviRead::TransSpec, DVI_xxx }, // 241
    { DVI_xxx + 3,  "xxx1", 1,  "-4",  (DvTransFunPtr)&DviRead::TransSpec, DVI_xxx }, // 242
    { DVI_fnt_def,      "fnt_def1", 6,  "1 -4 -4 -4 1 1",   (DvTransFunPtr)&DviRead::TransFontDef, DVI_fnt_def }, // 243
    { DVI_fnt_def + 1,  "fnt_def2", 6,  "2 -4 -4 -4 1 1",   (DvTransFunPtr)&DviRead::TransFontDef, DVI_fnt_def }, // 244
    { DVI_fnt_def + 2,  "fnt_def3", 6,  "3 -4 -4 -4 1 1",   (DvTransFunPtr)&DviRead::TransFontDef, DVI_fnt_def }, // 245
    { DVI_fnt_def + 3,  "fnt_def4", 6,  "-4 -4 -4 -4 1 1",  (DvTransFunPtr)&DviRead::TransFontDef, DVI_fnt_def }, // 246
    { DVI_pre,          "pre",      5,  "1 -4 -4 -4 1", (DvTransFunPtr)&DviRead::TransPreamble, DVI_pre },  // 247
    { DVI_post,         "post",     8,  "4 4 4 4 4 4 2 2", (DvTransFunPtr)&DviRead::TransPost, DVI_post }   // 248
};
                       
op_table op_235_248 = { "op_235_248", 235, 248, op_info_235_248 };


// ------------------------------------  
DviSteps::DviSteps(void)
{
    m_iHorStepW = 0;
    m_iHorStepX = 0;
    m_iVertStepY = 0;
    m_iVertStepZ = 0;
}


// ------------------------------------  
void DviRead::SetHorStepW(int p_iHorStepW)
{                       
    KP_ASSERT(m_pCurSteps != NULL, E_POINTER, null);
    KP_ASSERT(m_pCurSteps->m_lpRecord != NULL, E_POINTER, null);
    m_pCurSteps->m_lpRecord->m_iHorStepW = p_iHorStepW;
}


int DviRead::GetHorStepW(void)
{                       
    KP_ASSERT(m_pCurSteps != NULL, E_POINTER, null);
    KP_ASSERT(m_pCurSteps->m_lpRecord != NULL, E_POINTER, null);
return(m_pCurSteps->m_lpRecord->m_iHorStepW);
}


void DviRead::SetHorStepX(int p_iHorStepX)
{                       
    KP_ASSERT(m_pCurSteps != NULL, E_POINTER, null);
    KP_ASSERT(m_pCurSteps->m_lpRecord != NULL, E_POINTER, null);
    m_pCurSteps->m_lpRecord->m_iHorStepX = p_iHorStepX;
}


int DviRead::GetHorStepX(void)
{                       
    KP_ASSERT(m_pCurSteps != NULL, E_POINTER, null);
    KP_ASSERT(m_pCurSteps->m_lpRecord != NULL, E_POINTER, null);
return(m_pCurSteps->m_lpRecord->m_iHorStepX);
}


void DviRead::SetVertStepY(int p_iVertStepY)
{                       
    KP_ASSERT(m_pCurSteps != NULL, E_POINTER, null);
    KP_ASSERT(m_pCurSteps->m_lpRecord != NULL, E_POINTER, null);
    m_pCurSteps->m_lpRecord->m_iVertStepY = p_iVertStepY;
}


int DviRead::GetVertStepY(void)
{                       
    KP_ASSERT(m_pCurSteps != NULL, E_POINTER, null);
    KP_ASSERT(m_pCurSteps->m_lpRecord != NULL, E_POINTER, null);
return(m_pCurSteps->m_lpRecord->m_iVertStepY);
}


void DviRead::SetVertStepZ(int p_iVertStepZ)
{                       
    KP_ASSERT(m_pCurSteps != NULL, E_POINTER, null);
    KP_ASSERT(m_pCurSteps->m_lpRecord != NULL, E_POINTER, null);
    m_pCurSteps->m_lpRecord->m_iVertStepZ = p_iVertStepZ;
}


int DviRead::GetVertStepZ(void)
{                       
    KP_ASSERT(m_pCurSteps != NULL, E_POINTER, null);
    KP_ASSERT(m_pCurSteps->m_lpRecord != NULL, E_POINTER, null);
return(m_pCurSteps->m_lpRecord->m_iVertStepZ);
}


// ------------------------------------  
DviRead::DviRead(void) 
{                      
    m_lpszInFileName[0] = Nul;
    m_pDviFile = stdin;

    m_pCurSteps = NULL;
DviSteps *dvi_steps = NULL;
    KP_NEW(dvi_steps, DviSteps); 
    KP_NEW(m_pCurSteps, KpTreeEntry<DviSteps>(dvi_steps, NULL));
}                      
                       
                       
DviRead::~DviRead()
{
    Close();
    KP_ASSERT(m_pCurSteps->GetFather() == NULL, E_POINTER, "Stack m_pCurSteps leakage");
    KP_DELETE(m_pCurSteps);
}


// ------------------------------------  
void DviRead::Open(const UCHAR *p_lpszDviFileName)
{
    if(p_lpszDviFileName != null) if(p_lpszDviFileName[0] != Nul)
    {
        KP_ASSERT(strlen(p_lpszDviFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszInFileName, p_lpszDviFileName);
         
        KP_ASSERT(m_pDviFile == stdin, KP_E_DOUBLE_CALL, p_lpszDviFileName);
     
        m_pDviFile = fopen((const CHAR *)p_lpszDviFileName, "rb");
        KP_ASSERT(m_pDviFile != NULL, KP_E_FILE_NOT_FOUND, p_lpszDviFileName);
    } 
}


void DviRead::Close(void)
{
    if(m_pDviFile != stdin) fclose(m_pDviFile);
    m_pDviFile = stdin;
}


// ----------------------------------
int DviRead::dvread(void)
{
  int opcode;
  COUNT count;  /* intended to count bytes to DVI file; as yet unused. */

  CmdOpen(); // PRINT_BCOM;

//DG  fprintf (dtl, "variety ");
/*  fprintf (dtl, BMES); */
//DG  fprintf (dtl, VARIETY);
/*  fprintf (dtl, EMES); */

  CmdClose(); // PRINT_ECOM;
  
  /* start counting DVI bytes */
  count = 0;
  while ((opcode = fgetc (m_pDviFile)) != EOF)
  {
    CmdOpen(); // PRINT_BCOM;  /* start of command and parameters */
    
    if (opcode < 0 || opcode > 255)
    {
      count += 1;
      fprintf (stderr, "%s:  Non-byte from \"fgetc()\"!\n", program);
      exit (1);
    }
    else if (opcode <= DVI_set_char_last) // (opcode <= 127)
    {
      /* setchar commands */
      /* count += 1; */
      /* fprintf (dtl, "%s%d", SETCHAR, opcode); */
      count +=
      setseq (opcode);
    }
    else if (opcode >= DVI_set && opcode <= 170) // (opcode >= 128 && opcode <= 170)
    {
      count +=
      wtable (op_128_170, opcode);
    }
    else if (opcode >= DVI_fnt_num && opcode <= DVI_fnt_num_last) // (opcode >= 171 && opcode <= 234)
    {
      count += 1;
//DG      fprintf (dtl, "%s%d", FONTNUM, opcode - DVI_fnt_num);
      count += TransSetFont(opcode, opcode - DVI_fnt_num + 1, opcode - DVI_fnt_num);
    }
#if FALSE
    else if (opcode >= 235 && opcode <= 238)
    {
      count +=
      wtable (fnt, opcode);
    }
    else if (opcode >= DVI_xxx && opcode <= DVI_xxx_last) // (opcode >= 239 && opcode <= 242)
    {
      count +=
      special (opcode - DVI_xxx + 1);
    }
    else if (opcode >= DVI_fnt_def && opcode <= DVI_fnt_def_last) // (opcode >= 243 && opcode <= 246)
    {
      count +=
      fontdef (opcode - DVI_fnt_def + 1);
    }
    else if (opcode == DVI_pre) // 247
    {
      count +=
        preamble ();
    }
    else if (opcode == DVI_post) // 248
    {
      count +=
      postamble ();
    }
#endif
    else if (opcode >= 235 && opcode <= 248)
      count += wtable(op_235_248, opcode);
    else if (opcode == DVI_post_post) // 249
    {
      count +=
      postpost ();
    }
    else if (opcode >= DVI_undefined && opcode <= DVI_undefined_last) // (opcode >= 250 && opcode <= 255)
    {
      count += 1;
//DG      fprintf (dtl, "opcode%d", opcode);
    }
    else
    {
      count += 1;
//DG      fprintf (stderr, "%s:  unknown byte.\n", program);
      exit (1);
    }
      CmdClose();  // PRINT_ECOM; /* end of command and parameters */

  } /* end while */

  return 1;  /* OK */
}
/* dvread */


COUNT DviRead::wunsigned(int n)
{
  U4 unum;

  unum = runsigned (n);
  return n;
}
/* end wunsigned */


COUNT DviRead::wsigned(int n)
{
  S4 snum;

  snum = rsigned (n);
  return n;
}
/* end wsigned */


U4 DviRead::runsigned(int n)
/* read 1 <= n <= 4 bytes for an unsigned integer from dvi file */
/* DVI format uses Big-endian storage of numbers. */
{
  U4 integer;
  int ibyte = 0;
  int i;

  if (n < 1 || n > 4)
  {
    fprintf (stderr,
      "%s:  runsigned() asked for %d bytes.  Must be 1 to 4.\n", program, n);
    exit (1);
  }

  /* Following calculation works iff storage is big-endian. */
  integer = 0;
  for (i = 0; i < n; i++)
  {
    integer *= 256;
    ibyte = fgetc (m_pDviFile);
    integer += ibyte;
  }

  return integer;
}
/* end runsigned */


S4 DviRead::rsigned(int n)
/* read 1 <= n <= 4 bytes for a signed integer from dvi file */
/* DVI format uses Big-endian storage of numbers. */
{
  S4 integer;
  int ibyte = 0;
  int i;

  if (n < 1 || n > 4)
  {
    fprintf (stderr,
      "%s:  rsigned() asked for %d bytes.  Must be 1 to 4.\n", program, n);
    exit (1);
  }

  /* Following calculation works iff storage is big-endian. */
  integer = 0;
  for (i = 0; i < n; i++)
  {
    integer *= 256;
    ibyte = fgetc (m_pDviFile);
    /* Big-endian implies sign byte is first byte. */
    if (i == 0 && ibyte >= 128)
    {
      ibyte -= 256;
    }
    integer += ibyte;
  }

  return integer;
}
/* end rsigned */


COUNT DviRead::wtable(op_table table, int opcode)
/* write command with given opcode in given table */
/* return number of DVI bytes in this command */
{
  op_info op;  /* pointer into table of operations and arguments */
  COUNT bcount = 0;  /* number of bytes in arguments of this opcode */
  String args;  /* arguments string */
  int i;  /* count of arguments read from args */
  int pos;  /* position in args */
  
  // parametrai callback funkcijoms
  // struct -- kad masyvą perduotų by value 
  struct { int val[DVREAD_MAX_NUM_OF_ARGS]; } argt; 
  
  for(int ii = 0; ii < DVREAD_MAX_NUM_OF_ARGS; ii++) argt.val[ii] = 0;

  /* Defensive programming. */
  if (opcode < table.first || opcode > table.last)
  {
    fprintf (stderr,
      "%s: opcode %d is outside table %s [ %d to %d ] !\n",
      program, opcode, table.name, table.first, table.last);
    exit (1);
  }

  op = table.list [opcode - table.first];

  /* Further defensive programming. */
  if (op.code != opcode)
  {
    fprintf (stderr, "%s: internal table %s wrong!\n", program, table.name);
    exit (1);
  }
  KP_ASSERT(op.nargs <= DVREAD_MAX_NUM_OF_ARGS, KP_E_SYSTEM_ERROR, "internal table wrong!"); 

  bcount = 1;
//DG  fprintf (dtl, "%s", op.name);

  /* NB:  sscanf does an ungetc, */
  /*      so args must be writable. */

  strncpy (args, op.args, MAXSTRLEN);

  pos = 0;
  for (i = 0; i < op.nargs; i++)
  {
    int argtype;  /* sign and number of bytes in current argument */
    int nconv;  /* number of successful conversions from args */
    int nread;  /* number of bytes read from args */

    nconv = sscanf (args + pos, "%d%n", &argtype, &nread);

    /* internal consistency checks */
    if (nconv != 1 || nread <= 0)
    {
      fprintf (stderr,
        "%s: internal read of table %s failed!\n", program, table.name);
      exit (1);
    }

    pos += nread;

//  bcount += ( argtype < 0 ?
//             wsigned  (-argtype) :
//             wunsigned (argtype)  ) ;
    argt.val[i] = (argtype < 0) ? rsigned(-argtype) : runsigned(argtype);
    bcount += abs(argtype);

  } /* end for */

// --------------------------------
#if FALSE
    if ((opcode >= DVI_set) && (opcode <= DVI_set_last)) // ((opcode >= 128) && (opcode <= 131))
    {
        KP_ASSERT(op.nargs == 1, KP_E_SYSTEM_ERROR, null);
        TransExtChar(argt.val[0]); 
    }
    
    switch(opcode)
    {
    case : 
    }
#endif

// calling virtual callback method through the pointer in op.m_pTransFun
    if (op.m_pTransFun != NULL) bcount +=  
        (this->*op.m_pTransFun)(opcode, 
            op.code - op.m_iFirstGrpOpcode + 1, // offset in the group of opcode's
            argt);  // passing all argt.val[DVREAD_MAX_NUM_OF_ARGS] values as parameters
                    // callback function will evaluate some first of them
    
#if FALSE
// calling virtual callback method through the pointer in vtable
// totally non portable 
    if (op.m_iCallbackIx != DVREAD_Trans_NoIx)
    { 
        // assume pointer to the vtable is in the very first hidden word in the body of the object
        KP_ASSERT(m_lpszInFileName - (const UCHAR *)this == sizeof(TransFunPtr), 
            E_NOTIMPL, "Wrong offset of the vtable");
TransFunPtr *vtable = *(TransFunPtr **)this;  
        bcount += vtable[
            op.m_iCallbackIx]( // vtable index of the callback corresponding to the opcode
            this,   // this -- first parameter to the class methods
            opcode, op.code - op.m_iFirstGrpOpcode + 1, argt);   
    }
#endif

  return bcount;

}
/* wtable */


COUNT DviRead::setseq(int opcode)
/* write a sequence of setchar commands */
/* return count of DVI bytes interpreted into DTL */
{
  int charcode = opcode;  /* fortuitous */
  int ccount = 0;
  
  string out_str;

// if (!isprint (charcode))
// {
//  ccount = 1;
//DG    fprintf (dtl, "%s%02X", SETCHAR, opcode);
// }
// else
  {
    /* start of sequence of font characters */
//DG    fprintf (dtl, BSEQ);

    /* first character */
    ccount = 1;
    setpchar (charcode);
    
    out_str += charcode;

    /* subsequent characters */
    while ((opcode = fgetc (m_pDviFile)) != EOF)
    {
      if (opcode < DVI_set_char || opcode > DVI_set_char_last) // (opcode < 0 || opcode > 127)
      {
        break;  /* not a setchar command, so sequence has ended */
      }
      charcode = opcode;  /* fortuitous */
//    if (!isprint (charcode))  /* not printable ascii */
//    {
//      break;  /* end of font character sequence, as for other commands */
//    }
//    else  /* printable ASCII */
      {
        ccount += 1;
        setpchar (charcode);

        out_str += charcode;
      }
    }  /* end for loop */

    /* prepare to reread opcode of next DVI command */
    if (ungetc (opcode, m_pDviFile) == EOF)
    {
      fprintf (stderr, "setseq:  cannot push back a byte\n");
      exit (1);
    }

    /* end of sequence of font characters */
//DG    fprintf (dtl, ESEQ);
  }
  
  TransText((const UCHAR *)(out_str.c_str()));
  
  return ccount;
}
/* setseq */


Void DviRead::setpchar(int charcode)
/* set printable character */
{
  switch (charcode)
  {
    case ESC_CHAR:
//DG      fprintf (dtl, "%c", ESC_CHAR);
//DG      fprintf (dtl, "%c", ESC_CHAR);
      break;
    case QUOTE_CHAR:
//DG      fprintf (dtl, "%c", ESC_CHAR);
//DG      fprintf (dtl, "%c", QUOTE_CHAR);
      break;
    case BSEQ_CHAR:
//DG      fprintf (dtl, "%c", ESC_CHAR);
//DG      fprintf (dtl, "%c", BSEQ_CHAR);
      break;
    case ESEQ_CHAR:
//DG      fprintf (dtl, "%c", ESC_CHAR);
//DG	  fprintf (dtl, "%c", ESEQ_CHAR);
      break;
    default:
//DG      fprintf (dtl, "%c", charcode);
      break;
  }
}
/* setpchar */


#if FALSE
COUNT DviRead::special(int n)
/* read special 1 .. 4 from dvi and write in dtl */
/* return number of DVI bytes interpreted into DTL */
{
  U4  k;

  if (n < 1 || n > 4)
  {
    fprintf (stderr, "%s:  special %d, range is 1 to 4.\n", program, n);
    exit (1);
  }

  /* k[n] = length of special string */
  k = runsigned (n);

  /* x[k] = special string */
  TransSpec /* xxxferstring */ (DVI_xxx, n, k);

  return (1 + n + k);
}
/* end special */
#endif


#if FALSE
COUNT DviRead::fontdef(int n)
/* read fontdef 1 .. 4 from dvi and write in dtl */
/* return number of DVI bytes interpreted into DTL */
{
  U4 ku, c, s, d, a, l;
  S4 ks;

  if (n < 1 || n > 4)
  {
    fprintf (stderr, "%s:  font def %d, range is 1 to 4.\n", program, n);
    exit (1);
  }

//DG  fprintf (dtl, "%s%d", FONTDEF, n);

  /* k[n] = font number */
//DG  fprintf (dtl, " ");
  if (n == 4)
  {
    ks = rsigned (n);
  }
  else
  {
    ku = runsigned (n);
  }

  /* c[4] = checksum */
  c = runsigned (4);

  /* s[4] = scale factor */
  s = runsigned (4);

  /* d[4] = design size */
  d = runsigned (4);

  /* a[1] = length of area (directory) name */
  a = runsigned (1);

  /* l[1] = length of font name */
  l = runsigned (1);

  /* n[a+l] = font pathname string => area (directory) + font */
  TransFontDef(DVI_fnt_def, n, (n == 4)?ks:ku, c, s, d, a, l);

  return (1 + n + 4 + 4 + 4 + 1 + 1 + a + l);
}
/* end fontdef */
#endif


#if FALSE
COUNT DviRead::preamble(void)
/* read preamble from dvi and write in dtl */
/* return number of DVI bytes interpreted into DTL */
{
  U4 id, num, den, mag, k;

//DG  fprintf (dtl, "pre");

  /* i[1] = DVI format identification */
  id = runsigned (1);

  /* num[4] = numerator of DVI unit */
  num = runsigned (4);

  /* den[4] = denominator of DVI unit */
  den = runsigned (4);

  /* mag[4] = 1000 x magnification */
  mag = runsigned (4);

  /* k[1] = length of comment */
  k = runsigned (1);

  /* x[k] = comment string */
  TransPreamble(DVI_pre, 1, id, num, den, mag, k);

  return (1 + 1 + 4 + 4 + 4 + 1 + k);
}
/* end preamble */
#endif


#if FALSE
COUNT DviRead::postamble(void)
/* read postamble from dvi and write in dtl */
/* return number of bytes */
{
  U4 p, num, den, mag, l, u, s, t;

//DG  fprintf (dtl, "post");

  /* p[4] = pointer to final bop */
  p = runsigned (4);

  /* num[4] = numerator of DVI unit */
  num = runsigned (4);

  /* den[4] = denominator of DVI unit */
  den = runsigned (4);

  /* mag[4] = 1000 x magnification */
  mag = runsigned (4);

  /* l[4] = height + depth of tallest page */
  l = runsigned (4);

  /* u[4] = width of widest page */
  u = runsigned (4);

  /* s[2] = maximum stack depth */
  s = runsigned (2);

  /* t[2] = total number of pages (bop commands) */
  t = runsigned (2);

  TransPost(DVI_post, 1, p, num, den, mag, l, u, s, t);

/*  return (29);  */
  return (1 + 4 + 4 + 4 + 4 + 4 + 4 + 2 + 2);
}
/* end postamble */
#endif


COUNT DviRead::postpost(void)
/* read post_post from dvi and write in dtl */
/* return number of bytes */
{
  U4 q, id;
  int b223;  /* hope this is 8-bit clean */
  int n223;  /* number of "223" bytes in final padding */

//DG  fprintf (dtl, "post_post");

  /* q[4] = pointer to post command */
  q = runsigned (4);

  /* i[1] = DVI identification byte */
  id = runsigned (1);

  /* final padding by "223" bytes */
  /* hope this way of obtaining b223 is 8-bit clean */
  for (n223 = 0; (b223 = fgetc (m_pDviFile)) == DVI_POST_SIGNATURE; n223++) // 223
  {
  }
  if (n223 < 4)
  {
    fprintf (stderr,
      "%s:  bad post_post:  fewer than four \"223\" bytes.\n", program);
    exit (1);
  }
  if (b223 != EOF)
  {
    fprintf (stderr,
      "%s:  bad post_post:  doesn't end with a \"223\".\n", program);
    exit (1);
  }

  return (1 + 4 + 1 + n223);
}
/* end postpost */


    
// ----------------------------
COUNT DviRead::TransMove(int p_iOpCode, int p_iFirstArgLen, int p_iOff)
{
int offset = p_iOff;

    switch(p_iOpCode)
    {
    case DVI_w:
        offset = GetHorStepW();
        break; 
    case DVI_w + 1:
    case DVI_w + 2:
    case DVI_w + 3:
    case DVI_w + 4:
        SetHorStepW(p_iOff);
        break;
        
    case DVI_x:
        offset = GetHorStepX();
        break; 
    case DVI_x + 1:
    case DVI_x + 2:
    case DVI_x + 3:
    case DVI_x + 4:
        SetHorStepX(p_iOff);
        break;
        
    case DVI_y:
        offset = GetVertStepY();
        break; 
    case DVI_y + 1:
    case DVI_y + 2:
    case DVI_y + 3:
    case DVI_y + 4:
        SetVertStepY(p_iOff);
        break;
        
    case DVI_z:
        offset = GetVertStepZ();
        break; 
    case DVI_z + 1:
    case DVI_z + 2:
    case DVI_z + 3:
    case DVI_z + 4:
        SetVertStepZ(p_iOff);
        break;
    }
    
return (TransMoveLocal(p_iOpCode, p_iFirstArgLen, offset, p_iOff)); 
}


// ----------------------------
void DviRead::SkipInBytes(int p_iNumOfBytes)
{
    for (int ii = 0; ii < p_iNumOfBytes; ii++) fgetc(m_pDviFile);
}
