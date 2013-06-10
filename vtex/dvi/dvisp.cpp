/* ----------------
 * dvisp.cpp
 *      reading special tags of DVI file
 *      implementation (of the class DviSp) 
 *
 *  Changelog:
 *      2013-06-07  mp  split from drti.c
 *
 *  TODO: perdaryt į XML medį XmlNode su išvedimo draiveriais KpFile
 *  TODO: "vtex:settings.sometool" opcijas kaupt dinamiškai kuriant grupinius tagus bet kokioms "sometool"
 *                 
 */

#include "envir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"

#include "dvi.h"
#include "rti.h"
#include "dvread.h"
#include "dvisp.h"


// -----------------------------
const UCHAR *lpszaIgnoreSpecList[] =
{
    (const UCHAR *)"\" ",
    (const UCHAR *)"!", 
    (const UCHAR *)"ps:", 
    (const UCHAR *)"PSfile=",

    (const UCHAR *)"color ",
    (const UCHAR *)"background ",
    
    (const UCHAR *)"em: graph ",
    (const UCHAR *)"mt:destination",

    (const UCHAR *)"vtex:bmc.artifact.",
    (const UCHAR *)"vtex:emc.artifact.",

    (const UCHAR *)"fp",
    (const UCHAR *)"bk",
    (const UCHAR *)"sp",
    (const UCHAR *)"pn ", // "pn 5"
    (const UCHAR *)"pa ", // "pa 639 -2122"
    (const UCHAR *)"ar ", // "ar 0 0 26 26 0 6.2832"
    
    null
};

const UCHAR *lpszaIgnoreFullSpecList[] =
{
    (const UCHAR *)"MC:Contents",
    
    (const UCHAR *)"BMC:Book/SpringerURL",
    (const UCHAR *)"BMC:BookCopyright/CopyrightHolderName",
    (const UCHAR *)"BMC:BookCopyright/CopyrightYear",
    (const UCHAR *)"BMC:BookCopyright/CopyrightYearFormerEditions",
    (const UCHAR *)"BMC:Contents",
    (const UCHAR *)"BMC:MyCopy/Intro",
    (const UCHAR *)"BMC:MyCopy/SpringerURL",
    (const UCHAR *)"BMC:text",
    (const UCHAR *)"BMC:VTEX/LCCN",
    (const UCHAR *)"EMC:Book/SpringerURL",
    (const UCHAR *)"EMC:BookCopyright/CopyrightHolderName",
    (const UCHAR *)"EMC:BookCopyright/CopyrightYear",
    (const UCHAR *)"EMC:BookCopyright/CopyrightYearFormerEditions",
    (const UCHAR *)"EMC:Contents",
    (const UCHAR *)"EMC:MyCopy/Intro",
    (const UCHAR *)"EMC:MyCopy/SpringerURL",
    (const UCHAR *)"EMC:text",
    (const UCHAR *)"EMC:VTEX/LCCN",

    (const UCHAR *)"BMC:BookInfo/BookDOI",
    (const UCHAR *)"BMC:BookInfo/BookElectronicISBN",
    (const UCHAR *)"BMC:BookInfo/BookPrintISBN",
    (const UCHAR *)"EMC:BookInfo/BookDOI",
    (const UCHAR *)"EMC:BookInfo/BookElectronicISBN",
    (const UCHAR *)"EMC:BookInfo/BookPrintISBN",
    (const UCHAR *)"BMC:SeriesInfo/SeriesElectronicISSN",
    (const UCHAR *)"BMC:SeriesInfo/SeriesPrintISSN",
    (const UCHAR *)"EMC:SeriesInfo/SeriesElectronicISSN",
    (const UCHAR *)"EMC:SeriesInfo/SeriesPrintISSN",
    
    null
};


// -------------------------
DviSpClass::DviSpClass(void)
{
    m_lpszInFileName[0] = Nul;
    m_pInFile = stdin;
}


// -------------------------
void DviSpClass::OpenInFile(const UCHAR *lpszInFileName)
{
    if(lpszInFileName != null) if(lpszInFileName[0] != Nul)
    {
        KP_ASSERT(strlen(lpszInFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszInFileName, lpszInFileName);
         
        open_dvi(m_lpszInFileName, &m_pInFile);
    }
}


// -------------------------
bool kwd_in_plist(const UCHAR *p_lpszaKwdList[], const UCHAR *p_lpszKwd) 
{
HRESULT retc = S_OK;
bool retv = False;
const UCHAR **list_ptr = p_lpszaKwdList;

    KP_ASSERTW((p_lpszaKwdList != NULL) && (p_lpszKwd != null), E_INVALIDARG, null);
    if(SUCCEEDED(retc))
    {
        while (*list_ptr != null)
        {
            if (p_lpszaKwdList == lpszaIgnoreSpecList)
                retv = (strncmp(p_lpszKwd, *list_ptr, strlen(*list_ptr)) == 0);
            else
	           retv = (strcmp(p_lpszKwd, *list_ptr) == 0);
            
            if (retv) break;
            
            list_ptr++;
        }
    }
          
return(retv);
}


// --------------------------- converter callbacks
void RtiCmdOpen(void){}
void RtiCmdClose(void){}


// ----------------------------
void RtiTransPreamble(int p_iNumOfBytes, FILE *p_pDviFile)
{
RtiSkipInBytes(p_iNumOfBytes, p_pDviFile);
}

void RtiTransFontDef(int p_iNumOfBytes, FILE *p_pDviFile)
{
RtiSkipInBytes(p_iNumOfBytes, p_pDviFile);
}


// ----------------------------
void RtiTransSpec(int p_iNumOfBytes, FILE *p_pDviFile)
{
HRESULT retc = S_OK;
  
int ii;
bool hd_found = False;
int ch; 
UCHAR src_buf[RTI_KWD_LEN + 1];
UCHAR dst_buf[RTI_KWD_LEN + 1];
UCHAR *src_ptr = src_buf;
static rti rti_arr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};
prti rti_ptr = NULL;
const UCHAR *head = DVISP_SPEC_RTI_HEAD;

    KP_ASSERT(pRtiObjPtr != NULL, KP_E_SYSTEM_ERROR, null);
    KP_ASSERT(p_iNumOfBytes < RTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);

    rti_arr[0].name[0] = Nul;

    for (ii = 0; ii < p_iNumOfBytes; ii++)
        *src_ptr++ = fgetc(p_pDviFile);
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
                head = (const UCHAR *)"";
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
                head = (const UCHAR *)"";
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
                head = (const UCHAR *)"";
            }
        }
        
// "vtex:info."
        if(!hd_found)
        {
            head = DVISP_SPEC_INFO_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_INFO_GRP_TAG))
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
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_IMSREF_GRP_TAG) ||
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_SETTINGS_GRP_TAG))
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
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_RUNTOOL_GRP_TAG) ||
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_SETTINGS_GRP_TAG))
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
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_SOMETOOL_GRP_TAG) ||
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_SETTINGS_GRP_TAG))
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
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_STRUCTPYB_GRP_TAG) ||
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_SETTINGS_GRP_TAG))
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
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_SETTINGS_GRP_TAG))
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
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_PAGEINFO_GRP_TAG))
                        rti_ptr = PageInfoRtiArr;
//              else hd_found = False;
            }
        }

// tagai be reikšmių (nėra "=")
        if (hd_found)
        {
/* const */ UCHAR *pnt_rest = src_buf + strlen(head);
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

                if(rti_ptr == rti_arr) // main tags -- immediate output
                    OutputRtiArr(rti_ptr);
            }
        }            
#ifdef DRTIM_DEBUG
        else printf("[%s]\n", src_buf);
#endif

    } // if(!kwd_in_plist(lpszaIgnoreSpecList, src_buf)) if(!kwd_in_plist(lpszaIgnoreFullSpecList, src_buf))
}
