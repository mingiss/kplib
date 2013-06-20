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

#if FALSE
// TODO:
    DVI_set_rule,   // 132     set_rule     a[4], b[4]     typeset a rule and move right
    DVI_put,        // 133     put1     c[1]     typeset a character
        DVI_put_last = 136,
    DVI_put_rule,   // 137     put_rule     a[4], b[4]     typeset a rule
    DVI_nop,        // 138     nop         no operation
    DVI_bop,        // 139     bop     c_0[4]..c_9[4], p[4]     beginning of page
    DVI_eop,        // 140     eop         ending of page
    DVI_push,       // 141     push         save the current positions
    DVI_pop,        // 142     pop         restore previous positions
    DVI_right,      // 143     right1     b[1]     move right
        DVI_right_last = 146,   
    DVI_w,          // 147     w0         move right by w
        DVI_w_last = 151,
    DVI_x,          // 152     x0         move right by x
        DVI_x_last = 156,                 
    DVI_down,       // 157     down1     a[1]     move down
        DVI_down_last = 160,                    
    DVI_y,          // 161     y0         move down by y
        DVI_y_last = 165,                    
    DVI_z,          // 166     z0         move down by z
        DVI_z_last = 170,
    DVI_fnt_num,    // 171...234     fnt_num_i         set current font to i
        DVI_fnt_num_last = 234, 
    DVI_fnt,        // 235     fnt1     k[1]     set current font
        DVI_fnt_last = 238,                    
    DVI_post,       // 248     post     p[4], num[4], den[4], mag[4], l[4], u[4], s[2], t[2] < font definitions >     postamble beginning
    DVI_post_post,  // 249     post_post     q[4], i[1]; 223's    postamble ending
    DVI_undefined,  // 250...255     undefined     
#endif


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
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kperrno.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kptt.h"
#include "kpstring.h"

#include "dvi.h"
#include "rtid.h"
#include "dvread.h"


// -------------------------
/* Table for opcodes 128 to 170 inclusive. */

op_info  op_info_128_170 [] =
{
  {DVI_set,     "s1",   1,  "1",  /* DVREAD_TransExtChar_Ix, */  (DvTransFunPtr)&DviRead::TransExtChar, DVI_set},
  {DVI_set + 1, "s2",   1,  "2",  /* DVREAD_TransExtChar_Ix, */  (DvTransFunPtr)&DviRead::TransExtChar, DVI_set},
  {DVI_set + 2, "s3",   1,  "3",  /* DVREAD_TransExtChar_Ix, */  (DvTransFunPtr)&DviRead::TransExtChar, DVI_set},
  {DVI_set + 3, "s4",   1,  "-4", /* DVREAD_TransExtChar_Ix, */ (DvTransFunPtr)&DviRead::TransExtChar, DVI_set},
  {132,         "sr",   2,  "-4 -4", /* DVREAD_TransExtChar_NoIx, */ NULL, 132},
  {133,         "p1",   1,  "1",    NULL,   133},
  {134,         "p2",   1,  "2",    NULL,   134},
  {135,         "p3",   1,  "3",    NULL,   135},
  {136,         "p4",   1,  "-4",   NULL,   136},
  {137,         "pr",   2,  "-4 -4", NULL,  137},
  {138,         "nop",  0,  "",     NULL,   138},
  {139,         "bop",  11, "-4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4", NULL, 139},
  {140,         "eop",  0,  "",     NULL,   140},
  {141,         "[",    0,  "",     NULL,   141},
  {142,         "]",    0,  "",     NULL,   142},
  {143,         "r1",   1,  "1",    NULL,   143},
  {144,         "r2",   1,  "2",    NULL,   144},
  {145,         "r3",   1,  "3",    NULL,   145},
  {146,         "r4",   1,  "4",    NULL,   146},
  {147,         "w0",   0,  "",     NULL,   147},
  {148,         "w1",   1,  "1",    NULL,   148},
  {149,         "w2",   1,  "2",    NULL,   149},
  {150,         "w3",   1,  "3",    NULL,   150},
  {151,         "w4",   1,  "4",    NULL,   151},
  {152,         "x0",   0,  "",     NULL,   152},
  {153,         "x1",   1,  "1",    NULL,   153},
  {154,         "x2",   1,  "2",    NULL,   154},
  {155,         "x3",   1,  "3",    NULL,   155},
  {156,         "x4",   1,  "4",    NULL,   156},
  {157,         "d1",   1,  "1",    NULL,   157},
  {158,         "d2",   1,  "2",    NULL,   158},
  {159,         "d3",   1,  "3",    NULL,   159},
  {160,         "d4",   1,  "4",    NULL,   160},
  {161,         "y0",   0,  "",     NULL,   161},
  {162,         "y1",   1,  "1",    NULL,   162},
  {163,         "y2",   1,  "2",    NULL,   163},
  {164,         "y3",   1,  "3",    NULL,   164},
  {165,         "y4",   1,  "4",    NULL,   165},
  {166,         "z0",   0,  "",     NULL,   166},
  {167,         "z1",   1,  "1",    NULL,   167},
  {168,         "z2",   1,  "2",    NULL,   168},
  {169,         "z3",   1,  "3",    NULL,   169},
  {170,         "z4",   1,  "4",    NULL,   170}
};  /* op_info  op_info_128_170 [] */
                            
                       
op_table  op_128_170  =  {"op_128_170", 128, 170, op_info_128_170};
                       
                       
/* Table for font with 1 to 4 bytes (opcodes 235 to 238) inclusive. */
                       
op_info  fnt_n [] =    
{                      
  {235,         "f1", 1, "1",   NULL, 235},
  {236,         "f2", 1, "2",   NULL, 236},
  {237,         "f3", 1, "3",   NULL, 237},
  {238,         "f4", 1, "-4",  NULL, 238}
};  /* op_info  fnt_n [] */
                       
op_table  fnt  =  {"f", 235, 238, fnt_n};
                       
                       
// ------------------------------------  
DviRead::DviRead(void) 
{                      
    m_lpszInFileName[0] = Nul;
    m_pDviFile = stdin;
}                      
                       
                       
DviRead::~DviRead()
{
    Close();
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
    else if (opcode >= 171 && opcode <= 234)
    {
      count += 1;
//DG      fprintf (dtl, "%s%d", FONTNUM, opcode - 171);
    }
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
    else if (opcode == 248)
    {
      count +=
      postamble ();
    }
    else if (opcode == 249)
    {
      count +=
      postpost ();
    }
    else if (opcode >= 250 && opcode <= 255)
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
    if (op.m_pTransFun != NULL) 
        (this->*op.m_pTransFun)(op.code - op.m_iFirstGrpOpcode + 1, argt);
    
#if FALSE
// calling virtual callback method through the pointer in vtable
// totally non portable 
    if (op.m_iCallbackIx != DVREAD_TransExtChar_NoIx)
    { 
        // assume pointer to the vtable is in the very first word of the object
        KP_ASSERT(m_lpszInFileName - (const UCHAR *)this == sizeof(TransFunPtr), 
            E_NOTIMPL, "Wrong offset of the vtable");
TransFunPtr *vtable = *(TransFunPtr **)this;  
        vtable[
            op.m_iCallbackIx]( // vtable index of the callback corresponding to the opcode
            this,   // this -- first parameter to the class methods 
            op.code - op.m_iFirstGrpOpcode + 1,
            argt);  // passing all argt.val[DVREAD_MAX_NUM_OF_ARGS] values as parameters
                    // callback function will evaluate some first of them  
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
  TransSpec /* xxxferstring */ (k);

  return (1 + n + k);
}
/* end special */


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
  TransFontDef(n, (n == 4)?ks:ku, c, s, d, a, l);

  return (1 + n + 4 + 4 + 4 + 1 + 1 + a + l);
}
/* end fontdef */


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
  TransPreamble(id, num, den, mag, k);

  return (1 + 1 + 4 + 4 + 4 + 1 + k);
}
/* end preamble */


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

/*  return (29);  */
  return (1 + 4 + 4 + 4 + 4 + 4 + 4 + 2 + 2);
}
/* end postamble */


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
  for (n223 = 0; (b223 = fgetc (m_pDviFile)) == 223; n223++)
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
void DviRead::SkipInBytes(int p_iNumOfBytes)
{
    for (int ii = 0; ii < p_iNumOfBytes; ii++) fgetc(m_pDviFile);
}
