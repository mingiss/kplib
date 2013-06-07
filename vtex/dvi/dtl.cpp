/* ----------------
 * dtl.cpp
 *      DTL file I/O
 *
 *      2013-06-07  mp  split off from drti.cpp 
 *
 */

#include "dtl.h"
#include "rti.h"


// ---------------------------
/* Is each DTL command parenthesised by a BCOM and an ECOM? */
int group = 0;  /* by default, no grouping */

// output file
FILE * dtl = stdout;

// --------------------------- converter callbacks
void RtiCmdOpen(void)
{
    PRINT_BCOM;
}

void RtiCmdClose(void)
{
    PRINT_ECOM;
}

// ----------------------------
void RtiTransPreamble(int p_iNumOfBytes, FILE *p_pDviFile)
{
RtiSkipinBytes(p_iNumOfBytes, p_pDviFile);
}

Void
RtiTransFontDef // xferstring
#ifdef STDC
  (int k, FILE * dvi /* , FILE * dtl */)
#else
  (k, dvi /* , dtl */)
  int k;
  FILE * dvi;
// FILE * dtl;
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
RtiTransSpec // xxxferstring
#ifdef STDC
  (int k, FILE * dvi /* , FILE * dtl */)
#else
  (k, dvi /* , dtl */)
  int k;
  FILE * dvi;
// FILE * dtl;
#endif
/* copy string of k characters from dvi file to dtl file */
{
  HRESULT retc = S_OK;
  
  int ii, j;
  bool hd_found = False;
  int ch; 
// int s[RTI_KWD_LEN];
  char src_buf[RTI_KWD_LEN + 1];
  char dst_buf[RTI_KWD_LEN + 1];
// int *pts = s;
  char *src_ptr = src_buf;
  static rti rti_arr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};
  prti rti_ptr = NULL;
  const char *head = DVISP_SPEC_RTI_HEAD;

    KP_ASSERT(k < RTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);

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
        head = DVISP_SPEC_RTI_HEAD;
        hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
        if (hd_found) rti_ptr = rti_arr;

// "papersize="
        if (!hd_found)
        {
            head = DVISP_SPEC_PAPERSIZE_HEAD;
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
            head = DVISP_SPEC_HEADER_HEAD;
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
            head = DVISP_SPEC_STAGE_HPROOF_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
        
            if (!hd_found)
            {
// "mt:proof"            
                head = DVISP_SPEC_STAGE_PROOF_HEAD;
                hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            }

            if (!hd_found)
            {
// "mt:pproof"            
                head = DVISP_SPEC_STAGE_PPROOF_HEAD;
                hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            }

            if (!hd_found)
            {
// "mt:crc"            
                head = DVISP_SPEC_STAGE_CRC_HEAD;
                hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            }

            if (!hd_found)
            {
// "mt:s" // "mt:s250"            
                head = DVISP_SPEC_STAGE_PRECRC_HEAD;
                hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            }

            if (hd_found)
            {
                head = DVISP_SPEC_STAGE_HEAD;
                KP_ASSERTW(strlen(src_buf) + strlen(DRTI_STAGE_TAG) + 3 < RTI_KWD_LEN,
                    KP_E_BUFFER_OVERFLOW, null);
                if(SUCCEEDED(retc))
                {
                    strcpy(dst_buf, head);
                    strcat(dst_buf, DRTI_STAGE_TAG);
                    strcat(dst_buf, "={"); // RTI_EQ_SIGN, RTI_OPENING_BRACE
                    strcat(dst_buf, src_buf + strlen(head));
                    strcat(dst_buf, "}"); // RTI_CLOSING_BRACE
                    strcpy(src_buf, dst_buf);
    
                    rti_ptr = rti_arr;
                }
            }
        }

// "mt:" // "mt:badrefs"
        if (!hd_found)
        {
            head = DVISP_SPEC_MT_HEAD;
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
            head = DVISP_SPEC_INFO_HEAD;
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
            head = DVISP_SPEC_IMSREF_HEAD;
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
            head = DVISP_SPEC_RUNTOOL_HEAD;
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
            head = DVISP_SPEC_SOMETOOL_HEAD;
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
            head = DVISP_SPEC_STRUCTPYB_HEAD;
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
            head = DVISP_SPEC_SETTINGS_HEAD;
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
            head = DVISP_SPEC_PAGEINFO_HEAD;
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
            if (strchr(pnt_rest, RTI_EQ_SIGN) == NULL)
            {
// pridedam <option> prie visų "vtex:settings." tagų be "="
                if ((strncmp(src_buf, DVISP_SPEC_SETTINGS_HEAD, strlen(DVISP_SPEC_SETTINGS_HEAD)) == 0))
                {
                    KP_ASSERTW(strlen(src_buf) + strlen(DRTI_OPTION_TAG) + 2 < RTI_KWD_LEN,
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
                    KP_ASSERTW(strlen(src_buf) + 1 < RTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
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
                        printoutput(rti_ptr, output_format /* , dtl */, &output_empty, null); 
    
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
