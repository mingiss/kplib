/* ----------------
 * rtif.cpp
 *      {keyword, value} (runtime info) tag processing
 *      implementation
 *
 *  Changelog:
 *      2013-06-07  mp  split off from drti.c
 *      2013-06-12  mp  tinyxml implemented
 *
 */

#include "envir.h"

#include <stdio.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

#include "tinyxml.h"

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"
#include "txml.h"
#include "rtid.h"
#include "fmtf.h"
#include "rtif.h"


// ---------------------------
RtiClass *pRtiObjPtr = NULL;


// ---------------------------
RtInfo InfoRtiArr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};
RtInfo SettingsRtiArr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};
RtInfo RunToolRtiArr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};
RtInfo SomeToolRtiArr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};
RtInfo ImsRefRtiArr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};
RtInfo StructPybRtiArr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};
RtInfo PageInfoRtiArr[RTI_NUM_OF_KWDS + 1] = {{"", ""}};


// ------------------------------------  
RtiClass::RtiClass(void)
{
    m_pFmtFileObj = NULL;
    m_iOutputListSize = 0;
    m_iGrpListSize = 0;
}


RtiClass::~RtiClass()
{
    CloseOutFile();
}


// ------------------------------------  
void RtiClass::OpenOutFile(const UCHAR *p_lpszOutFileName, FmtFileForgeFptr p_FmtFileForge)
{
    KP_ASSERT(m_pFmtFileObj == NULL, KP_E_DOUBLE_CALL, null);
    m_pFmtFileObj = (*p_FmtFileForge)(p_lpszOutFileName, (const UCHAR *)"w");
    KP_ASSERT(m_pFmtFileObj != NULL, KP_E_DIR_ERROR, p_lpszOutFileName);
}


// ------------------------------------  
void RtiClass::CloseOutFile(void)
{
    if(m_pFmtFileObj != NULL)
    {
        m_pFmtFileObj->CloseOutFile();
        KP_DELETE(m_pFmtFileObj);
    }
}


// ---------------------------------
void RtiClass::PrintOutput(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFmtFileObj != NULL, E_POINTER, null);
    m_pFmtFileObj->PrintOutput(p_pRti, p_pbOutputEmpty, p_lpszGrpTagName);
}



void RtiClass::PrintOutputHead(void)
{
    KP_ASSERT(m_pFmtFileObj != NULL, E_POINTER, null);
    m_pFmtFileObj->PrintOutputHead();
}


void RtiClass::PrintOutputTail(void)
{
    KP_ASSERT(m_pFmtFileObj != NULL, E_POINTER, null);
    m_pFmtFileObj->PrintOutputTail();
}


void RtiClass::OpenGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFmtFileObj != NULL, E_POINTER, null);
    m_pFmtFileObj->OpenGrTag(p_lpszGrpTagName);
}


void RtiClass::CloseGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFmtFileObj != NULL, E_POINTER, null);
    m_pFmtFileObj->CloseGrTag(p_lpszGrpTagName);
}


// ------------------------------------  
void RtiClass::ScanOutputList(const UCHAR *p_lpszKwdStr)
{
    scan_kwd_list(m_szaOutputList, &m_iOutputListSize, p_lpszKwdStr); 
} 


void RtiClass::ScanGrpList(const UCHAR *p_lpszKwdStr)
{
    scan_kwd_list(m_szaGrpList, &m_iGrpListSize, p_lpszKwdStr);
}


// ------------------------------------  
void scan_kwd_list(UCHAR p_szaKwdList[][RTI_KWD_LEN + 1], int *p_piKwdListSize, const UCHAR *p_lpszKwdStr)
{ 
HRESULT retc = S_OK;
const UCHAR *temp;
    
    KP_ASSERTW((p_szaKwdList != NULL) && (p_piKwdListSize != NULL) && (p_lpszKwdStr != null),
        E_INVALIDARG, null);
    if (SUCCEEDED(retc))
    {
        *p_piKwdListSize = 0;
        if (p_lpszKwdStr[0] != Nul)
        {
            KP_ASSERTW(strlen(p_lpszKwdStr) <= RTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
            if (SUCCEEDED(retc))
            { 
                strcpy(p_szaKwdList[0], p_lpszKwdStr);
                temp = (const UCHAR *)strtok((CHAR *)p_szaKwdList[0], ",");
            }
                
            KP_ASSERT(*p_piKwdListSize < RTI_NUM_OF_KWDS, KP_E_BUFFER_OVERFLOW, null);
            if (SUCCEEDED(retc)) (*p_piKwdListSize)++;

            while ((temp != null) && SUCCEEDED(retc))
            {
                temp = (const UCHAR *)strtok(NULL, ",");
                if(temp != null)
                {
                    KP_ASSERT(*p_piKwdListSize < RTI_NUM_OF_KWDS, KP_E_BUFFER_OVERFLOW, null);
                    if (SUCCEEDED(retc)) 
                    {
                        strcpy(p_szaKwdList[*p_piKwdListSize], temp);
                        (*p_piKwdListSize)++;
                    }
                }
            }
  
        } // if (p_lpszKwdStr[0] != Nul)
    
    } // if (SUCCEEDED(retc))
}



bool kwd_in_list(/* const */ UCHAR p_szaKwdList[][RTI_KWD_LEN + 1], int p_iKwdListSize, const UCHAR *p_lpszKwd) 
{
HRESULT retc = S_OK;
bool retv = False;
int ii;

    KP_ASSERTW((p_szaKwdList != NULL) && (p_lpszKwd != null), E_INVALIDARG, null);
    if(SUCCEEDED(retc))
    {
        for (ii = 0; ii < p_iKwdListSize; ii++)
        {
	        // if (stricmp(p_lpszKwd, p_szaKwdList[ii]) == 0)
	        if (strcmp(p_lpszKwd, p_szaKwdList[ii]) == 0)
            {
                retv = True;
                break;
            }
        }
    }
          
return(retv);
}


// -----------------------------
void str_del(UCHAR *t, UCHAR *s, const UCHAR *p_lpszHead)
{
  int iC, iB; 
  iC = strlen(p_lpszHead);
  iB = strlen(s) - iC;
  //  printf("%d-%d\n", iC, iB);
  memcpy(&t[0], &s[iC], iB);
  t[iB] = '\0';
  //  printf("%s\n", t);
}


void add_to_rti(const UCHAR *p_lpszKwdStr, pRtInfo p_pRti, const UCHAR *p_lpszGrpTagName, const UCHAR *p_lpszGrpGrpTagName)
{
HRESULT retc = S_OK;
pRtInfo rti_ptr = p_pRti;
UCHAR kwd_str_buf[RTI_KWD_LEN + 1];
/* const */ UCHAR *cur_kwd = null;
UCHAR tag_name[RTI_KWD_LEN + 1];
UCHAR tag_val[RTI_KWD_LEN + 1];
const UCHAR *grp_tag_name = p_lpszGrpTagName;
    
    KP_ASSERT((p_lpszKwdStr != null) && (p_pRti != NULL), E_INVALIDARG, null);

    KP_ASSERT(pRtiObjPtr != NULL, E_POINTER, null);
    KP_ASSERT(pRtiObjPtr->m_pFmtFileObj != NULL, E_POINTER, null);

    pRtiObjPtr->m_pFmtFileObj->CreateGrpNode(DRTI_XML_GRP_TAG, null);
    if(p_lpszGrpGrpTagName != null)
        pRtiObjPtr->m_pFmtFileObj->CreateGrpNode(p_lpszGrpGrpTagName, DRTI_XML_GRP_TAG);
    if(p_lpszGrpTagName != null)
        pRtiObjPtr->m_pFmtFileObj->CreateGrpNode(p_lpszGrpTagName, 
            (p_lpszGrpGrpTagName != null)?p_lpszGrpGrpTagName:DRTI_XML_GRP_TAG);

    if(grp_tag_name == null) grp_tag_name = DRTI_XML_GRP_TAG;

// ieškom p_pRti galo
    rti_ptr = p_pRti;
    while (rti_ptr->name[0] != Nul) rti_ptr++;
    
// pradedam tagų skanavimą    
    KP_ASSERTW(strlen(p_lpszKwdStr) <= RTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
    if (SUCCEEDED(retc))
    { 
        strcpy(kwd_str_buf, p_lpszKwdStr);
        cur_kwd = (/* const */ UCHAR *)strtok((CHAR *)kwd_str_buf, "}"); // RTI_CLOSING_BRACE
    }
        
// pildom p_pRti
    while ((cur_kwd != null) && SUCCEEDED(retc))
    {
        // valom tarpus pradžioj
        while(*cur_kwd == Spc) cur_kwd++;
        // ar ne tuščia eilutė?
        if(*cur_kwd != Nul)
        {
            KP_ASSERTW(rti_ptr - p_pRti < RTI_NUM_OF_KWDS, KP_E_BUFFER_OVERFLOW, null);
            if(SUCCEEDED(retc))
            {
                split_strings(tag_name, tag_val, cur_kwd);
                // printf("RTI:%s:\n", tag_name);
 
                strcpy(rti_ptr->name, tag_name); 
                strcpy(rti_ptr->value, tag_val);
                //  printf("RTI:%s:%s\n", tag_val, tag_val);

                rti_ptr++;
        
                // add empty delimiter record
                rti_ptr->name[0] = Nul;
                rti_ptr->value[0] = Nul;

            // ------------------ pildom XML struktūrą
            TiXmlNode *grp_node = NULL;
                if (grp_tag_name != null)
                    grp_node = FindNodeByName(grp_tag_name, &pRtiObjPtr->m_pFmtFileObj->m_XmlDoc);
                if (grp_node == NULL)            
                    grp_node = &pRtiObjPtr->m_pFmtFileObj->m_XmlDoc;
            
            TiXmlElement *element = new TiXmlElement((const CHAR *)tag_name);
            TiXmlText *text = new TiXmlText((const CHAR *)tag_val);
                element->LinkEndChild(text);
                grp_node->LinkEndChild(element);
            }
        }
        
        // continue scanning
        cur_kwd = (/* const */ UCHAR *)strtok(NULL, "}"); // RTI_CLOSING_BRACE
    }
}

int split_strings(UCHAR *t, UCHAR *tt, /* const */ UCHAR *s)
{
/* const */ UCHAR *ps; 
  ps = strchr(s, RTI_EQ_SIGN); // '='
  int l, m;
  if (ps == NULL)
  {
   printf("Wrong format (no '=' sign) in special \'%s\'\n", s);
   return -1;
  }
  l = ps - s;
// m = strlen(s) - l;

  //  printf("-%i-\n", l);

  strncpy(&t[0], &s[0], l);
  *(&t[l]) = '\0';

// strncpy(&tt[0], &s[l+2], m - 3);
// *(&tt[m-3]) = '\0';
    ps++;
    if(*ps == RTI_OPENING_BRACE) ps++; // '{'
    strcpy(tt, ps);
    m = strlen(tt);
    if(m > 0) if(tt[m - 1] == RTI_CLOSING_BRACE) tt[m - 1] = Nul; // '}' 
  
  return 0;
}


// ----------------------------
void RtiSkipInBytes(int p_iNumOfBytes, FILE *p_pDviFile)
{
int ii;
    for (ii=0; ii < p_iNumOfBytes; ii++) fgetc(p_pDviFile);
}
