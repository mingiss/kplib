/* -----------------------------------------------
 *
 * kpcapp.cpp
 *
 *    common application
 *
 * 2013-04-04  mp  initial creation
 *
 */
 
#include "envir.h"

#include <stdio.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kpcapp.h"
#include "kpcurdat.h"

using namespace std;


// ----------------------------------
#ifdef __WIN32__
HINSTANCE KpCommonApp::m_hInstance = NULL;
#endif

KpLang KpCommonApp::m_iMsgLangOff = KpLangEn;


// ----------------------------------
KpCommonApp::KpCommonApp(const UCHAR *lpszProdName, int iProdVer)
{
    m_iMsgLangOff = KpLangEn;
#ifdef __WIN32__
    m_hInstance = 0L;
    KpInitWindows();
#endif

    m_lpszAppName[0] = Nul;
    m_lpszProdName[0] = Nul;
   
    SetProd(lpszProdName, iProdVer);
   
    strncpy(m_lpszProdDate, CUR_DATE, KP_MAX_FNAME_LEN);
    m_lpszProdDate[KP_MAX_FNAME_LEN] = Nul;
    
    m_pStackTop = NULL;
}


// ----------------------------------
KpCommonApp::~KpCommonApp(void){}


// ----------------------------------
void KpCommonApp::Init(HINSTANCE hInstance, const UCHAR *lpszCmdLine, const void *pStackTop)
{
#ifdef __WIN32__
    if(hInstance != 0L) m_hInstance = hInstance;
#endif

    KP_ASSERT(lpszCmdLine != NULL, E_POINTER, null);
    strncpy(m_lpszCmdLine, lpszCmdLine, KP_MAX_FNAME_LEN);
    m_lpszCmdLine[KP_MAX_FNAME_LEN] = Nul;

    m_pStackTop = pStackTop;

static UCHAR log_fname[KP_MAX_FNAME_LEN + 1];
    KpError.GetLogFileName(log_fname);
    remove((const char *)log_fname);
}


// ----------------------------------
void KpCommonApp::SetProd(const UCHAR *lpszProdName, int iProdVer)
{
    KP_ASSERT(lpszProdName != null, E_INVALIDARG, null);
    strncpy(m_lpszProdName, lpszProdName, KP_MAX_FNAME_LEN);
    m_lpszProdName[KP_MAX_FNAME_LEN] = Nul;
   
    m_iProdVer = iProdVer;
}


// ----------------------------------
void KpCommonApp::GetAppName(UCHAR *lpszNameBuf)
{
    KP_ASSERT(lpszNameBuf != null, E_INVALIDARG, null);
    
    if(m_lpszAppName[0] != Nul)
        strcpy(lpszNameBuf, m_lpszAppName); // tik pirmą kartą būna teisingas kelias, paskui nustatau SetCurrentDirectory() ir santykinis kelias išsiderina
    else
    {
UCHAR *pnts = m_lpszCmdLine;

static UCHAR name_buf_tmp[KP_MAX_FNAME_LEN + 1];
        if(*pnts != '\"')
        {
            strncpy(name_buf_tmp, pnts, KP_MAX_FNAME_LEN);
            name_buf_tmp[KP_MAX_FNAME_LEN] = Nul;
            
            pnts = strchr(name_buf_tmp, Spc);
        }
        else
        {
            strncpy(name_buf_tmp, pnts + 1, KP_MAX_FNAME_LEN);
            name_buf_tmp[KP_MAX_FNAME_LEN] = Nul;
            pnts = strchr(name_buf_tmp, '\"');
        }
        if(pnts != null) *pnts = Nul;

#ifdef __WIN32__
DWORD ll = 0L;
        ll = GetFullPathName((const CHAR *)name_buf_tmp, KP_MAX_FNAME_LEN, (char *)lpszNameBuf, NULL);
        KP_ASSERT(ll != 0L, KP_E_SYSTEM_ERROR, GetLastError());
        KP_ASSERTW0(ll < KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        lpszNameBuf[KP_MAX_FNAME_LEN] = Nul;
#else
// TODO Linux: get full path
        strcpy(lpszNameBuf, name_buf_tmp);
#endif        
        strcpy(m_lpszAppName, lpszNameBuf);
    }
}
