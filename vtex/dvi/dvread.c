/* ----------------
 * dvread.c
 *      reading of .dvi file
 *      implementation 
 *
 *
 *  Changelog:
 *      2013-06-07  mp  split from drti.c
 *
 */


// -------------------------
#include "envir.h"

#include <stdio.h>
#include <stdbool.h>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "kpstdlib.h"
#include "kperrno.h"
#include "kperr.h"
#include "kptt.h"
#include "kpstring.h"

#include "dvi.h"
#include "dvread.h"

// TODO: po pilno atskyrimo išmest 
#include "dtl.h"
#include "drtim.h"
#include "dvisp.h"

// -------------------------
/* Table for opcodes 128 to 170 inclusive. */

op_info  op_info_128_170 [] =
{
  {128, "s1", 1, "1"},
  {129, "s2", 1, "2"},
  {130, "s3", 1, "3"},
  {131, "s4", 1, "-4"},
  {132, "sr", 2, "-4 -4"},
  {133, "p1", 1, "1"},
  {134, "p2", 1, "2"},
  {135, "p3", 1, "3"},
  {136, "p4", 1, "-4"},
  {137, "pr", 2, "-4 -4"},
  {138, "nop", 0, ""},
  {139, "bop", 11, "-4 -4 -4 -4 -4 -4 -4 -4 -4 -4 -4"},
  {140, "eop", 0, ""},
  {141, "[", 0, ""},
  {142, "]", 0, ""},
  {143, "r1", 1, "-1"},
  {144, "r2", 1, "-2"},
  {145, "r3", 1, "-3"},
  {146, "r4", 1, "-4"},
  {147, "w0", 0, ""},
  {148, "w1", 1, "-1"},
  {149, "w2", 1, "-2"},
  {150, "w3", 1, "-3"},
  {151, "w4", 1, "-4"},
  {152, "x0", 0, ""},
  {153, "x1", 1, "-1"},
  {154, "x2", 1, "-2"},
  {155, "x3", 1, "-3"},
  {156, "x4", 1, "-4"},
  {157, "d1", 1, "-1"},
  {158, "d2", 1, "-2"},
  {159, "d3", 1, "-3"},
  {160, "d4", 1, "-4"},
  {161, "y0", 0, ""},
  {162, "y1", 1, "-1"},
  {163, "y2", 1, "-2"},
  {164, "y3", 1, "-3"},
  {165, "y4", 1, "-4"},
  {166, "z0", 0, ""},
  {167, "z1", 1, "-1"},
  {168, "z2", 1, "-2"},
  {169, "z3", 1, "-3"},
  {170, "z4", 1, "-4"}
};  /* op_info  op_info_128_170 [] */


op_table  op_128_170  =  {"op_128_170", 128, 170, op_info_128_170};


/* Table for font with 1 to 4 bytes (opcodes 235 to 238) inclusive. */

op_info  fnt_n [] =
{
  {235, "f1", 1, "1"},
  {236, "f2", 1, "2"},
  {237, "f3", 1, "3"},
  {238, "f4", 1, "-4"}
};  /* op_info  fnt_n [] */

op_table  fnt  =  {"f", 235, 238, fnt_n};


// ------------------------------------  
int
open_dvi
#ifdef STDC
  (const UCHAR * dvi_file, FILE ** pdvi)
#else
  (dvi_file, pdvi)
  const UCHAR * dvi_file;
  FILE ** pdvi;
#endif
/* I:  dvi_file;  I:  pdvi;  O:  *pdvi. */
{
  if (pdvi == NULL)
  {
    fprintf (stderr, "%s:  address of dvi variable is NULL.\n", program);
    exit (1);
  }

  *pdvi = fopen (dvi_file, "rb");

  if (*pdvi == NULL)
  {
    fprintf (stderr, "%s:  Cannot open \"%s\" for binary reading.\n",
      program, dvi_file);
    exit (1);
  }

  return 1;  /* OK */
}
/* open_dvi */


// ----------------------------------
int
dvread
#ifdef STDC
  (FILE * dvi, FILE * dtl)
#else
  (dvi, dtl)
  FILE * dvi;
  FILE * dtl;
#endif
{
  int opcode;
  COUNT count;  /* intended to count bytes to DVI file; as yet unused. */

  PRINT_BCOM;

//DG  fprintf (dtl, "variety ");
/*  fprintf (dtl, BMES); */
//DG  fprintf (dtl, VARIETY);
/*  fprintf (dtl, EMES); */
  PRINT_ECOM;
//DG  fprintf (dtl, "\n");

  /* start counting DVI bytes */
  count = 0;
  while ((opcode = fgetc (dvi)) != EOF)
  {
    PRINT_BCOM;  /* start of command and parameters */
    if (opcode < 0 || opcode > 255)
    {
      count += 1;
      fprintf (stderr, "%s:  Non-byte from \"fgetc()\"!\n", program);
      exit (1);
    }
    else if (opcode <= 127)
    {
      /* setchar commands */
      /* count += 1; */
      /* fprintf (dtl, "%s%d", SETCHAR, opcode); */
      count +=
      setseq (opcode, dvi, dtl);
    }
    else if (opcode >= 128 && opcode <= 170)
    {
      count +=
      wtable (op_128_170, opcode, dvi, dtl);
    }
    else if (opcode >= 171 && opcode <= 234)
    {
      count += 1;
//DG      fprintf (dtl, "%s%d", FONTNUM, opcode - 171);
    }
    else if (opcode >= 235 && opcode <= 238)
    {
      count +=
      wtable (fnt, opcode, dvi, dtl);
    }
    else if (opcode >= 239 && opcode <= 242)
    {
      count +=
      special (dvi, dtl, opcode - 238);
    }
    else if (opcode >= 243 && opcode <= 246)
    {
      count +=
      fontdef (dvi, dtl, opcode - 242);
    }
    else if (opcode == 247)
    {
      count +=
      preamble (dvi, dtl);
    }
    else if (opcode == 248)
    {
      count +=
      postamble (dvi, dtl);
    }
    else if (opcode == 249)
    {
      count +=
      postpost (dvi, dtl);
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
    PRINT_ECOM;  /* end of command and parameters */
//DG    fprintf (dtl, "\n");
    if (fflush (dtl) == EOF)
    {
      fprintf (stderr, "%s:  fflush on dtl file gave write error!\n", program);
      exit (1);
    }
  } /* end while */
  
  
// -----------------  
// calculate and put out checksums of manuscript related files
    if (kwd_in_list(grp_list_e, grp_list_n, DRTI_ALL_GRP_TAG) || 
        kwd_in_list(grp_list_e, grp_list_n, DRTI_CHKSUM_GRP_TAG))
    {
HRESULT retc = S_OK;
prti p_chksums = calc_chksums();
        KP_ASSERTW(p_chksums != NULL, E_POINTER, null);
        if (SUCCEEDED(retc))
            print_rti_array(p_chksums, DRTI_CHKSUM_GRP_TAG, output_format, dtl);
    }
  
// -----------------  
// put out other groups
// "vtex:info"
    print_rti_array(InfoRtiArr, DRTI_INFO_GRP_TAG, output_format, dtl);
    
// "vtex:settings" grupę išvedam, tik jei yra netuščių jos tagų sąrašų 
    if ((SettingsRtiArr[0].name[0] != Nul) || (RunToolRtiArr[0].name[0] != Nul) || (SomeToolRtiArr[0].name[0] != Nul) ||  
        (ImsRefRtiArr[0].name[0] != Nul) || (StructPybRtiArr[0].name[0] != Nul))
    {
        open_grtag(DRTI_SETTINGS_GRP_TAG, output_format, dtl);
    
        print_rti_array(SettingsRtiArr, null, output_format, dtl);
        print_rti_array(RunToolRtiArr, DRTI_RUNTOOL_GRP_TAG, output_format, dtl);
        print_rti_array(SomeToolRtiArr, DRTI_SOMETOOL_GRP_TAG, output_format, dtl);
        print_rti_array(ImsRefRtiArr, DRTI_IMSREF_GRP_TAG, output_format, dtl);
        print_rti_array(StructPybRtiArr, DRTI_STRUCTPYB_GRP_TAG, output_format, dtl);

        close_grtag(DRTI_SETTINGS_GRP_TAG, output_format, dtl);
    }
// "MC:PageInfo"
    print_rti_array(PageInfoRtiArr, DRTI_PAGEINFO_GRP_TAG, output_format, dtl);

    
// -----------------  
  if (output_empty) fprintf(stderr, "Nothing found to print...\n");
  else printoutput_tail(output_format, dtl);

  return 1;  /* OK */
}
/* dvread */


COUNT
wunsigned
#ifdef STDC
  (int n, FILE * dvi, FILE * dtl)
#else
  (n, dvi, dtl)
  int n;
  FILE * dvi;
  FILE * dtl;
#endif
{
  U4 unum;

//DG  fprintf (dtl, " ");
  unum = runsigned (n, dvi);
//DG  fprintf (dtl, UF4, unum);
  return n;
}
/* end wunsigned */

COUNT
wsigned
#ifdef STDC
  (int n, FILE * dvi, FILE * dtl)
#else
  (n, dvi, dtl)
  int n;
  FILE * dvi;
  FILE * dtl;
#endif
{
  S4 snum;

//DG  fprintf (dtl, " ");
  snum = rsigned (n, dvi);
//DG  fprintf (dtl, SF4, snum);
  return n;
}
/* end wsigned */

U4
runsigned
#ifdef STDC
  (int n,  FILE * dvi)
#else
  (n, dvi)
  int n;
  FILE * dvi;
#endif
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
    ibyte = fgetc (dvi);
    integer += ibyte;
  }

  return integer;
}
/* end runsigned */

S4
rsigned
#ifdef STDC
  (int n,  FILE * dvi)
#else
  (n, dvi)
  int n;
  FILE * dvi;
#endif
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
    ibyte = fgetc (dvi);
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

COUNT
wtable
#ifdef STDC
  (op_table table, int opcode, FILE * dvi, FILE * dtl)
#else
  (table, opcode, dvi, dtl)
  op_table table;
  int opcode;
  FILE * dvi;
  FILE * dtl;
#endif
/* write command with given opcode in given table */
/* return number of DVI bytes in this command */
{
  op_info op;  /* pointer into table of operations and arguments */
  COUNT bcount = 0;  /* number of bytes in arguments of this opcode */
  String args;  /* arguments string */
  int i;  /* count of arguments read from args */
  int pos;  /* position in args */

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

    bcount += ( argtype < 0 ?
               wsigned  (-argtype, dvi, dtl) :
               wunsigned (argtype, dvi, dtl)  ) ;
  } /* end for */

  return bcount;

}
/* wtable */

COUNT
setseq
#ifdef STDC
  (int opcode, FILE * dvi, FILE * dtl)
#else
  (opcode, dvi, dtl)
  int opcode;
  FILE * dvi;
  FILE * dtl;
#endif
/* write a sequence of setchar commands */
/* return count of DVI bytes interpreted into DTL */
{
  int charcode = opcode;  /* fortuitous */
  int ccount = 0;

  if (!isprint (charcode))
  {
    ccount = 1;
//DG    fprintf (dtl, "%s%02X", SETCHAR, opcode);
  }
  else
  {
    /* start of sequence of font characters */
//DG    fprintf (dtl, BSEQ);

    /* first character */
    ccount = 1;
    setpchar (charcode, dtl);

    /* subsequent characters */
    while ((opcode = fgetc (dvi)) != EOF)
    {
      if (opcode < 0 || opcode > 127)
      {
        break;  /* not a setchar command, so sequence has ended */
      }
      charcode = opcode;  /* fortuitous */
      if (!isprint (charcode))  /* not printable ascii */
      {
        break;  /* end of font character sequence, as for other commands */
      }
      else  /* printable ASCII */
      {
        ccount += 1;
        setpchar (charcode, dtl);
      }
    }  /* end for loop */

    /* prepare to reread opcode of next DVI command */
    if (ungetc (opcode, dvi) == EOF)
    {
      fprintf (stderr, "setseq:  cannot push back a byte\n");
      exit (1);
    }

    /* end of sequence of font characters */
//DG    fprintf (dtl, ESEQ);
  }
  return ccount;
}
/* setseq */

Void
setpchar
#ifdef STDC
  (int charcode, FILE * dtl)
#else
  (charcode, dtl)
  int charcode;
  FILE * dtl;
#endif
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

Void
xferstring
#ifdef STDC
  (int k, FILE * dvi, FILE * dtl)
#else
  (k, dvi, dtl)
  int k;
  FILE * dvi;
  FILE * dtl;
#endif
/* copy string of k characters from dvi file to dtl file */
{
  int i;
  int ch;
  //  fprintf (dtl, "\n");
  //  fprintf (dtl, " ");
  //  fprintf (dtl, "'");
  for (i=0; i < k; i++)
  {
    ch = fgetc (dvi);
    if (ch == ESC_CHAR || ch == EMES_CHAR)
    {
      //      fprintf (dtl, "%c", ESC_CHAR);
    }
    //    fprintf (dtl, "%c", ch);
  }
  //  fprintf (dtl, "'");
}
/* xferstring */


Void
xxxferstring
#ifdef STDC
  (int k, FILE * dvi, FILE * dtl)
#else
  (k, dvi, dtl)
  int k;
  FILE * dvi;
  FILE * dtl;
#endif
/* copy string of k characters from dvi file to dtl file */
{
  HRESULT retc = S_OK;
  
  int ii, j;
  bool hd_found = False;
  int ch; 
// int s[KP_MAX_FILE_LIN_LEN];
  char src_buf[KP_MAX_FILE_LIN_LEN + 1];
  char dst_buf[KP_MAX_FILE_LIN_LEN + 1];
// int *pts = s;
  char *src_ptr = src_buf;
  static rti rti_arr[DRTI_MAX_NUM_OF_RTIS + 1] = {{"", ""}};
  prti rti_ptr = NULL;
  const char *head = DRTI_SPEC_RTI_HEAD;

    KP_ASSERT(k < KP_MAX_FILE_LIN_LEN, KP_E_BUFFER_OVERFLOW, null);

    rti_arr[0].name[0] = Nul;

  //  fprintf (dtl, "\n");
  //  fprintf (dtl, " ");
  //  fprintf (dtl, "'");
    for (ii = 0; ii < k; ii++)
    {
//      ch = fgetc (dvi);
    /*  if (ch == ESC_CHAR || ch == EMES_CHAR)
        {
            fprintf (dtl, "%c", ESC_CHAR);
        }
        fprintf (dtl, "%c", ch);
    */
//      s[i] = ch;

//      *src_ptr++ = *pts++;

        *src_ptr++ = fgetc(dvi);
    }

    *src_ptr++ = '\0';

    if(!kwd_in_plist(lpszaIgnoreSpecList, src_buf)) 
        if(!kwd_in_plist(lpszaIgnoreFullSpecList, src_buf)) 
    {
        rti_ptr = NULL;
        
// "vtex:info.runtime."
        head = DRTI_SPEC_RTI_HEAD;
        hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
        if (hd_found) rti_ptr = rti_arr;

// "papersize="
        if (!hd_found)
        {
            head = DRTI_SPEC_PAPERSIZE_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found) 
            {
                rti_ptr = rti_arr;
                head = "";
            }
        }

// "header="
        if (!hd_found)
        {
            head = DRTI_SPEC_HEADER_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found) 
            {
                rti_ptr = rti_arr;
                head = "";
            }
        }

        if (!hd_found)
        {
// "mt:hproof"
            head = DRTI_SPEC_STAGE_HPROOF_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
        
            if (!hd_found)
            {
// "mt:proof"            
                head = DRTI_SPEC_STAGE_PROOF_HEAD;
                hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            }

            if (!hd_found)
            {
// "mt:pproof"            
                head = DRTI_SPEC_STAGE_PPROOF_HEAD;
                hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            }

            if (!hd_found)
            {
// "mt:crc"            
                head = DRTI_SPEC_STAGE_CRC_HEAD;
                hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            }

            if (!hd_found)
            {
// "mt:s" // "mt:s250"            
                head = DRTI_SPEC_STAGE_PRECRC_HEAD;
                hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            }

            if (hd_found)
            {
                head = DRTI_SPEC_STAGE_HEAD;
                KP_ASSERTW(strlen(src_buf) + strlen(DRTI_STAGE_TAG) + 3 < KP_MAX_FILE_LIN_LEN,
                    KP_E_BUFFER_OVERFLOW, null);
                if(SUCCEEDED(retc))
                {
                    strcpy(dst_buf, head);
                    strcat(dst_buf, DRTI_STAGE_TAG);
                    strcat(dst_buf, "={"); // DVISP_EQ_SIGN, DVISP_OPENING_BRACE
                    strcat(dst_buf, src_buf + strlen(head));
                    strcat(dst_buf, "}"); // DVISP_CLOSING_BRACE
                    strcpy(src_buf, dst_buf);
    
                    rti_ptr = rti_arr;
                }
            }
        }

// "mt:" // "mt:badrefs"
        if (!hd_found)
        {
            head = DRTI_SPEC_MT_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            { 
                rti_ptr = rti_arr;
                head = "";
            }
        }
        
// "vtex:info."
        if(!hd_found)
        {
            head = DRTI_SPEC_INFO_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(grp_list_e, grp_list_n, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_INFO_GRP_TAG))
                        rti_ptr = InfoRtiArr;
//              else hd_found = False;
            }
        }

// "vtex:settings.imsref={"
        if(!hd_found)
        {
            head = DRTI_SPEC_IMSREF_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(grp_list_e, grp_list_n, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_IMSREF_GRP_TAG) ||
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_SETTINGS_GRP_TAG))
                        rti_ptr = ImsRefRtiArr;
//              else hd_found = False;
            }
        }

// "vtex:settings.runtool={"
        if(!hd_found)
        {
            head = DRTI_SPEC_RUNTOOL_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(grp_list_e, grp_list_n, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_RUNTOOL_GRP_TAG) ||
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_SETTINGS_GRP_TAG))
                        rti_ptr = RunToolRtiArr;
//              else hd_found = False;
            }
        }

// "vtex:settings.sometool={"
        if(!hd_found)
        {
            head = DRTI_SPEC_SOMETOOL_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(grp_list_e, grp_list_n, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_SOMETOOL_GRP_TAG) ||
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_SETTINGS_GRP_TAG))
                        rti_ptr = SomeToolRtiArr;
//              else hd_found = False;
            }
        }

// "vtex:settings.structpyb={"
        if(!hd_found)
        {
            head = DRTI_SPEC_STRUCTPYB_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(grp_list_e, grp_list_n, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_STRUCTPYB_GRP_TAG) ||
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_SETTINGS_GRP_TAG))
                        rti_ptr = StructPybRtiArr;
//              else hd_found = False;
            }
        }

// "vtex:settings."
        if(!hd_found)
        {
            head = DRTI_SPEC_SETTINGS_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(grp_list_e, grp_list_n, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_SETTINGS_GRP_TAG))
                        rti_ptr = SettingsRtiArr;
//              else hd_found = False;
            }
        }

// MC:PageInfo voffset={-72.26999pt} hoffset={-72.26999pt} topmargin={29.98857pt} headheight={12.0pt} headsep={14.0pt} textheight={540.60236pt} textwidth={332.89723pt} oddsidemargin={54.0pt} evensidemargin={54.0pt} footskip={20.0pt} baselineskip={12.0pt plus 0.3pt minus 0.3pt} headmargin={29.98857pt} backmargin={54.0pt} columnwidth={332.89723pt} trimbox={0 0 439.3701 666.1417}
        if(!hd_found)
        {
            head = DRTI_SPEC_PAGEINFO_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(grp_list_e, grp_list_n, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(grp_list_e, grp_list_n, DRTI_PAGEINFO_GRP_TAG))
                        rti_ptr = PageInfoRtiArr;
//              else hd_found = False;
            }
        }

// tagai be reikšmių (nėra "=")
        if (hd_found)
        {
const CHAR *pnt_rest = src_buf + strlen(head);
            if (strchr(pnt_rest, DVISP_EQ_SIGN) == NULL)
            {
// pridedam <option> prie visų "vtex:settings." tagų be "="
                if ((strncmp(src_buf, DRTI_SPEC_SETTINGS_HEAD, strlen(DRTI_SPEC_SETTINGS_HEAD)) == 0))
                {
                    KP_ASSERTW(strlen(src_buf) + strlen(DRTI_OPTION_TAG) + 2 < KP_MAX_FILE_LIN_LEN,
                        KP_E_BUFFER_OVERFLOW, null);
                    if(SUCCEEDED(retc))
                    {
                        strcpy(dst_buf, head);
                        strcat(dst_buf, DRTI_OPTION_TAG);
                        strcat(dst_buf, "={");
                        strcat(dst_buf, pnt_rest);
                        strcpy(src_buf, dst_buf);
                    }
                }
                else
                {
// kitiems pridedam gale "="
                    KP_ASSERTW(strlen(src_buf) + 1 < KP_MAX_FILE_LIN_LEN, KP_E_BUFFER_OVERFLOW, null);
                    if(SUCCEEDED(retc)) strcat(src_buf, "=");
                }
            }
        }
        
// -------------        
        if (hd_found)
        {
            if (rti_ptr != NULL)
            {
                str_del(dst_buf, src_buf, head);
                add_to_rti(dst_buf, rti_ptr);

                if(rti_ptr == rti_arr) // main tags
                {
                    if (kwd_in_list(output_list_e, output_list_n, rti_ptr->name) || (output_list_n == 0))
                    {
                        printoutput(rti_ptr, output_format, dtl, &output_empty, null); 
    
                    }// end of j;
                    //          printf("%s\n\n", rti_ptr->name);
                    //          printf("%s\n\n", rti_ptr->value);
                }

            } // end og i;
        }            
#ifdef DRTIM_DEBUG
        else printf("[%s]\n", src_buf);
#endif

    //  fprintf (dtl, "%s\n", dst_buf);
   
    // kaka
    //  fprintf (stderr, "kaka\n");
    
    } // if(!kwd_in_plist(lpszaIgnoreSpecList, src_buf)) if(!kwd_in_plist(lpszaIgnoreFullSpecList, src_buf))
}
/* xferstring */


COUNT
special
#ifdef STDC
  (FILE * dvi,  FILE * dtl,  int n)
#else
  (dvi, dtl, n)
  FILE * dvi;
  FILE * dtl;
  int n;
#endif
/* read special 1 .. 4 from dvi and write in dtl */
/* return number of DVI bytes interpreted into DTL */
{
  U4  k;

  if (n < 1 || n > 4)
  {
    fprintf (stderr, "%s:  special %d, range is 1 to 4.\n", program, n);
    exit (1);
  }

//DG  fprintf (dtl, "%s%d", SPECIAL, n);

  /* k[n] = length of special string */
//DG  fprintf (dtl, " ");
  k = runsigned (n, dvi);
//DG  fprintf (dtl, UF4, k);

  /* x[k] = special string */
  xxxferstring (k, dvi, dtl);

  return (1 + n + k);
}
/* end special */

COUNT
fontdef
#ifdef STDC
  (FILE * dvi,  FILE * dtl,  int n)
#else
  (dvi,  dtl,  n)
  FILE * dvi;
  FILE * dtl;
  int n;
#endif
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
    ks = rsigned (n, dvi);
//DG    fprintf (dtl, SF4, ks);
  }
  else
  {
    ku = runsigned (n, dvi);
//DG    fprintf (dtl, UF4, ku);
  }

  /* c[4] = checksum */
//DG  fprintf (dtl, " ");
  c = runsigned (4, dvi);
#ifdef HEX_CHECKSUM
//DG  fprintf (dtl, XF4, c);
#else /* NOT HEX_CHECKSUM */
  /* write in octal, to allow quick comparison with tftopl's output */
//DG  fprintf (dtl, OF4, c);
#endif

  /* s[4] = scale factor */
//DG  fprintf (dtl, " ");
  s = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, s);

  /* d[4] = design size */
//DG  fprintf (dtl, " ");
  d = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, d);

  /* a[1] = length of area (directory) name */
  a = runsigned (1, dvi);
//DG  fprintf (dtl, " ");
//DG  fprintf (dtl, UF4, a);

  /* l[1] = length of font name */
  l = runsigned (1, dvi);
//DG  fprintf (dtl, " ");
//DG  fprintf (dtl, UF4, l);

  /* n[a+l] = font pathname string => area (directory) + font */
  xferstring (a, dvi, dtl);
  xferstring (l, dvi, dtl);

  return (1 + n + 4 + 4 + 4 + 1 + 1 + a + l);
}
/* end fontdef */

COUNT
preamble
#ifdef STDC
  (FILE * dvi,  FILE * dtl)
#else
  (dvi,  dtl)
  FILE * dvi;
  FILE * dtl;
#endif
/* read preamble from dvi and write in dtl */
/* return number of DVI bytes interpreted into DTL */
{
  U4 id, num, den, mag, k;

//DG  fprintf (dtl, "pre");

  /* i[1] = DVI format identification */
//DG  fprintf (dtl, " ");
  id = runsigned (1, dvi);
//DG  fprintf (dtl, UF4, id);

  /* num[4] = numerator of DVI unit */
//DG  fprintf (dtl, " ");
  num = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, num);

  /* den[4] = denominator of DVI unit */
//DG  fprintf (dtl, " ");
  den = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, den);

  /* mag[4] = 1000 x magnification */
//DG  fprintf (dtl, " ");
  mag = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, mag);

  /* k[1] = length of comment */
//DG  fprintf (dtl, " ");
  k = runsigned (1, dvi);
//DG  fprintf (dtl, UF4, k);

  /* x[k] = comment string */
  xferstring (k, dvi, dtl);

  return (1 + 1 + 4 + 4 + 4 + 1 + k);
}
/* end preamble */

COUNT
postamble
#ifdef STDC
  (FILE * dvi,  FILE * dtl)
#else
  (dvi,  dtl)
  FILE * dvi;
  FILE * dtl;
#endif
/* read postamble from dvi and write in dtl */
/* return number of bytes */
{
  U4 p, num, den, mag, l, u, s, t;

//DG  fprintf (dtl, "post");

  /* p[4] = pointer to final bop */
//DG  fprintf (dtl, " ");
  p = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, p);

  /* num[4] = numerator of DVI unit */
//DG  fprintf (dtl, " ");
  num = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, num);

  /* den[4] = denominator of DVI unit */
//DG  fprintf (dtl, " ");
  den = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, den);

  /* mag[4] = 1000 x magnification */
//DG  fprintf (dtl, " ");
  mag = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, mag);

  /* l[4] = height + depth of tallest page */
//DG  fprintf (dtl, " ");
  l = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, l);

  /* u[4] = width of widest page */
//DG  fprintf (dtl, " ");
  u = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, u);

  /* s[2] = maximum stack depth */
//DG  fprintf (dtl, " ");
  s = runsigned (2, dvi);
//DG  fprintf (dtl, UF4, s);

  /* t[2] = total number of pages (bop commands) */
//DG  fprintf (dtl, " ");
  t = runsigned (2, dvi);
//DG  fprintf (dtl, UF4, t);

/*  return (29);  */
  return (1 + 4 + 4 + 4 + 4 + 4 + 4 + 2 + 2);
}
/* end postamble */

COUNT
postpost
#ifdef STDC
  (FILE * dvi,  FILE * dtl)
#else
  (dvi,  dtl)
  FILE * dvi;
  FILE * dtl;
#endif
/* read post_post from dvi and write in dtl */
/* return number of bytes */
{
  U4 q, id;
  int b223;  /* hope this is 8-bit clean */
  int n223;  /* number of "223" bytes in final padding */

//DG  fprintf (dtl, "post_post");

  /* q[4] = pointer to post command */
//DG  fprintf (dtl, " ");
  q = runsigned (4, dvi);
//DG  fprintf (dtl, UF4, q);

  /* i[1] = DVI identification byte */
//DG  fprintf (dtl, " ");
  id = runsigned (1, dvi);
//DG  fprintf (dtl, UF4, id);

  /* final padding by "223" bytes */
  /* hope this way of obtaining b223 is 8-bit clean */
  for (n223 = 0; (b223 = fgetc (dvi)) == 223; n223++)
  {
//DG    fprintf (dtl, " ");
//DG    fprintf (dtl, "%d", 223);
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
