/* ----------------
 * rti.cpp
 *      {keyword, value} (runtime info) tag processing
 *      implementation
 *
 *  Changelog:
 *      2013-06-07  mp  split off from drti.c
 *
 */

#include "envir.h"

#include <stdio.h>
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

#include "rti.h"


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
    m_lpszFileName[0] = Nul;
    m_pOutFile = stdout;
    m_iOutputListSize = 0;
    m_iGrpListSize = 0;
}


// ------------------------------------  
void RtiClass::OpenOutFile(const UCHAR *lpszOutFileName)
{
    if(lpszOutFileName != null) if (lpszOutFileName[0] != Nul)
    {
        KP_ASSERT(strlen(lpszOutFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszFileName, lpszOutFileName);

        m_pOutFile = fopen((const CHAR *)m_lpszFileName, "w");
        KP_ASSERT(m_pOutFile != NULL, KP_E_DIR_ERROR, lpszOutFileName);
    }
}


// ------------------------------------  
void RtiClass::CloseOutFile(void)
{
    if(m_pOutFile == stdout)
        KP_ASSERT(fflush(m_pOutFile) != EOF, KP_E_FERROR, null)
    else
        KP_ASSERT(fclose(m_pOutFile) != EOF, KP_E_FERROR, m_lpszFileName);
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


void add_to_rti(const UCHAR *p_lpszKwdStr, pRtInfo p_pRti)
{
HRESULT retc = S_OK;
pRtInfo rti_ptr = p_pRti;
UCHAR kwd_str_buf[RTI_KWD_LEN + 1];
/* const */ UCHAR *cur_kwd = null;
UCHAR tag_name[RTI_KWD_LEN + 1];
UCHAR tag_val[RTI_KWD_LEN + 1];

    KP_ASSERT((p_lpszKwdStr != null) && (p_pRti != NULL), E_INVALIDARG, null);

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
