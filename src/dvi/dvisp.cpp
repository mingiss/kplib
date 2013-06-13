/* ----------------
 * dvisp.cpp
 *      reading special tags of DVI and .special file
 *      implementation (of the class DviSp) 
 *
 *  Changelog:
 *      2013-06-07  mp  split from drti.c
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *      2013-06-13  mp  pridėtas .special failo parsinimas
 *
 *  TODO: "vtex:settings.sometool" opcijas kaupt dinamiškai kuriant grupinius tagus bet kokioms "sometool"
 *  TODO: pRtiObjPtr perdaryt per parametrą, ne globalų pointerį
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
#include "kpsort.h"
#include "kpmsg.h"
#include "kperr.h"

#include "tinyxml.h"

#include "dvi.h"
#include "rtid.h"
#include "fmtf.h"
#include "dvread.h"
#include "dvisp.h"
#include "rtif.h"


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
//  m_pInFile = stdin;
}


// -------------------------
void DviSpClass::OpenInFile(const UCHAR *lpszInFileName)
{
    if(lpszInFileName != null) if(lpszInFileName[0] != Nul)
    {
        KP_ASSERT(strlen(lpszInFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszInFileName, lpszInFileName);
         
// ReadFile() pats atsidaro ir vėėl užsidaro reikiamus failus
//      open_dvi(m_lpszInFileName, &m_pInFile);
    }
}


// -------------------------
void DviSpClass::ReadFile(void)
{
UCHAR in_fname[KP_MAX_FNAME_LEN + 100];
FILE *in_file = NULL;

// ------------ .dvi
    strcpy(in_fname, m_lpszInFileName);
    strcat(in_fname, ".dvi");
    
    in_file = fopen((const CHAR *)in_fname, "rb");
    if(in_file != NULL)
    {
        fclose(in_file);
        in_file = NULL;    
    
        if (strcmp(m_lpszInFileName, (const UCHAR *)"") != 0)
            open_dvi(in_fname, &in_file);

        if(in_file != NULL)
        {
            dvread(in_file);
            fclose(in_file);
        }
    }
    
// --------------  .specials    
    strcpy(in_fname, m_lpszInFileName);
    strcat(in_fname, ".specials");
    
    in_file = fopen((const CHAR *)in_fname, "r");
    if(in_file != NULL)
    {
        SpecRead(in_file);
        fclose(in_file);
    }

    ProcessSpecial((const UCHAR *)""); // kad išsiflushintų sukauptas XML-as last_xml_str
}


// ---------------------------
void DviSpClass::SpecRead(FILE *p_pInFile)
{
    KP_ASSERT(p_pInFile != NULL, E_INVALIDARG, null);
    
    while(!feof(p_pInFile))
    {
UCHAR in_line[KP_MAX_FILE_LIN_LEN + 1];    
        if(fgets((CHAR *)in_line, KP_MAX_FILE_LIN_LEN, p_pInFile) != NULL)
        {
int ll = strlen(in_line);
int ii;
            for(ii = 0; ((ii < 2) && (ll > 0)); ii++)
                if ((in_line[ll - 1] == Cr) || (in_line[ll - 1] == Lf)) ll--; 
            in_line[ll] = Nul;        
            ProcessSpecial(in_line);
        }
        else break;
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
UCHAR src_buf[RTI_KWD_LEN + 1];
UCHAR *src_ptr = src_buf;

    KP_ASSERT(p_iNumOfBytes < RTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);

    for (int ii = 0; ii < p_iNumOfBytes; ii++)
        *src_ptr++ = fgetc(p_pDviFile);
    *src_ptr++ = '\0';

    ProcessSpecial(src_buf);
}


const UCHAR *prev_grp_tag = DRTI_INFO_GRP_TAG;
string last_xml_str = ""; // xml-as būna per kelias eilutes, į add_xml_to_rti() perduodam per kelis iškvietimus sukauptą stringą  
void ProcessSpecial(const UCHAR *p_lpszSrcBuf)
{
HRESULT retc = S_OK;
const UCHAR *head = DVISP_SPEC_RTI_HEAD;
bool hd_found = False;
UCHAR src_buf[RTI_KWD_LEN + 1];
UCHAR dst_buf[RTI_KWD_LEN + 1];
const UCHAR *grp_tag_name = null;
const UCHAR *grp_grp_tag_name = null;
// xml tęsinių eilutėms
bool xml_fl = False;

    KP_ASSERT(p_lpszSrcBuf != NULL, E_INVALIDARG, null);
    KP_ASSERT(strlen(p_lpszSrcBuf) <= RTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);

    KP_ASSERT(pRtiObjPtr != NULL, KP_E_SYSTEM_ERROR, null);

    strcpy(src_buf, p_lpszSrcBuf);
    
    if (!kwd_in_plist(lpszaIgnoreSpecList, src_buf)) 
        if (!kwd_in_plist(lpszaIgnoreFullSpecList, src_buf))
//  if (GetKwrdIndex(src_buf, lpszaIgnoreSpecList, -1, True, False) == TV_TG_NoKey)
//      if (GetKwrdIndex(src_buf, lpszaIgnoreFullSpecList, -1, True, True) == TV_TG_NoKey)
    {
        grp_tag_name = null;
        grp_grp_tag_name = null;
        prev_grp_tag = DRTI_INFO_GRP_TAG;
        xml_fl = False;
        
// "vtex:info.runtime."
        head = DVISP_SPEC_RTI_HEAD;
        hd_found = (strncmp(src_buf, head, strlen(head)) == 0);

// "papersize="
        if (!hd_found)
        {
            head = DVISP_SPEC_PAPERSIZE_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found) 
                head = (const UCHAR *)"";
        }

// "header="
        if (!hd_found)
        {
            head = DVISP_SPEC_HEADER_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found) 
                head = (const UCHAR *)"";
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
                }
            }
        }

// "mt:" // "mt:badrefs"
        if (!hd_found)
        {
            head = DVISP_SPEC_MT_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
                head = (const UCHAR *)"";
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
                        grp_tag_name = DRTI_INFO_GRP_TAG;
                else hd_found = False;
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
                {
                    grp_tag_name = DRTI_IMSREF_GRP_TAG;
                    grp_grp_tag_name = DRTI_SETTINGS_GRP_TAG;
                }
                else hd_found = False;
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
                {
                    grp_tag_name = DRTI_RUNTOOL_GRP_TAG;
                    grp_grp_tag_name = DRTI_SETTINGS_GRP_TAG;
                }
                else hd_found = False;
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
                {
                    grp_tag_name = DRTI_SOMETOOL_GRP_TAG;
                    grp_grp_tag_name = DRTI_SETTINGS_GRP_TAG;
                }
                else hd_found = False;
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
                {
                    grp_tag_name = DRTI_STRUCTPYB_GRP_TAG;
                    grp_grp_tag_name = DRTI_SETTINGS_GRP_TAG;
                }
                else hd_found = False;
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
                        grp_tag_name = DRTI_SETTINGS_GRP_TAG;
                else hd_found = False;
            }
        }

// MC:PageInfo voffset={-72.26999pt} hoffset={-72.26999pt} topmargin={29.98857pt} headheight={12.0pt} headsep={14.0pt} textheight={540.60236pt} textwidth={332.89723pt} oddsidemargin={54.0pt} evensidemargin={54.0pt} footskip={20.0pt} baselineskip={12.0pt plus 0.3pt minus 0.3pt} headmargin={29.98857pt} backmargin={54.0pt} columnwidth={332.89723pt} trimbox={0 0 439.3701 666.1417}
// "MC:PageInfo "
        if(!hd_found)
        {
            head = DVISP_SPEC_PAGEINFO_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_PAGEINFO_GRP_TAG))
                        grp_tag_name = DRTI_PAGEINFO_GRP_TAG;
                else hd_found = False;
            }
        }

// vtex:xml <sec name="TeX info"><key name="voffset">-72.26999pt</key><key name="hoffset">-72.26999pt</key><key name="topmargin">36.0pt</key><key name="headheight">11.0pt</key><key name="headsep">12.0pt</key><key name="textheight">560.51929pt</key><key name="textwidth">364.19527pt</key><key name="oddsidemargin">39.83386pt</key><key name="evensidemargin">36.98859pt</key><key name="footskip">12.0pt</key><key name="columnwidth">364.19527pt</key><key name="baselineskip">13.0pt plus 0.1pt minus 0.1pt</key>
// "vtex:xml <sec name="TeX info">"
        if(!hd_found)
        {
            head = DVISP_SPEC_INFO_XML_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_INFO_GRP_TAG))
                {
                    prev_grp_tag = grp_tag_name = DRTI_INFO_GRP_TAG;
                    xml_fl = True;
                    head = DVISP_SPEC_XML_HEAD;
                }
                else hd_found = False;
            }
        }

// ankstesnio vtex:xml tęsinys
// <key name="trimwidth">6in</key><key name="trimheight">9in</key><key name="headmargin">36.0pt</key><key name="backmargin">39.83386pt</key></sec>
// "<key name=\""
        if(!hd_found)
        {
            head = DVISP_SPEC_XML_KEY_HEAD;
            hd_found = (strncmp(src_buf, head, strlen(head)) == 0);
            if (hd_found)
            {
                if (kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, DRTI_ALL_GRP_TAG) || 
                    kwd_in_list(pRtiObjPtr->m_szaGrpList, pRtiObjPtr->m_iGrpListSize, prev_grp_tag))
                {
                    grp_tag_name = prev_grp_tag;
                    xml_fl = True;
                    head = (const UCHAR *)"";
                }
                else hd_found = False;
            }
        }

// tagai be reikšmių (nėra "=")
        if (hd_found)
        {
/* const */ UCHAR *pnt_rest = src_buf + strlen(head);

            if (strchr(pnt_rest, RTI_EQ_SIGN) == null)
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
        if ((!hd_found) || (!xml_fl))
            if (last_xml_str.length() > 0)
            {
                add_xml_to_rti(&last_xml_str, prev_grp_tag, null);
                last_xml_str = "";
            }

        if (hd_found)
        {
            str_del(dst_buf, src_buf, head);

            if (xml_fl)
                last_xml_str += (const CHAR *)dst_buf;
            else 
                add_to_rti(dst_buf, grp_tag_name, grp_grp_tag_name);
        }            
#ifdef DRTIM_DEBUG
        // loginam neatpažintus tagus
        else printf("[%s]\n", src_buf);
#endif

    } // if(!kwd_in_plist(lpszaIgnoreSpecList, src_buf)) if(!kwd_in_plist(lpszaIgnoreFullSpecList, src_buf))
}
