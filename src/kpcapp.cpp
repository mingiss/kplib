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
KpLang KpCommonApp::m_iMsgLangOff = KpLangEn;


// ----------------------------------
KpCommonApp::KpCommonApp(const uchar *p_lpszProdName, int p_iProdVer)
{
    m_iMsgLangOff = KpLangEn;
#ifdef __WIN32__
    m_hInstance = NULL;
    m_hWndHandle = NULL;
    m_hWndParent = NULL; 
#endif

    m_lpszAppName[0] = Nul;
   
    SetProd(p_lpszProdName, p_iProdVer);
    
    m_lpszCmdLine[0] = Nul;
    KP_ASSERT(p_lpszProdName, E_INVALIDARG, null);
    KP_ASSERT(strlen(KP_CUR_DIR_STR) + strlen(KP_DIR_SEP_STR) + strlen(p_lpszProdName) + strlen(KP_EXT_SEP_STR) + strlen(KP_EXE_EXT) 
        <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, p_lpszProdName);
    strcpy(m_lpszCmdLine, KP_CUR_DIR_STR); 
    strcat(m_lpszCmdLine, KP_DIR_SEP_STR); 
    strcat(m_lpszCmdLine, p_lpszProdName);
    strcat(m_lpszCmdLine, KP_EXT_SEP_STR); 
    strcat(m_lpszCmdLine, KP_EXE_EXT);
   
    strncpy(m_lpszProdDate, CUR_DATE, KP_MAX_FNAME_LEN);
    m_lpszProdDate[KP_MAX_FNAME_LEN] = Nul;
    
    m_pStackTop = NULL;
}


// ----------------------------------
KpCommonApp::~KpCommonApp(void){}


// ----------------------------------
void KpCommonApp::Init(HINSTANCE p_hInstance, const uchar *p_lpszCmdLine, const void *p_pStackTop)
{
#ifdef __WIN32__
    KpInitWindows(p_hInstance);
#endif

    KP_ASSERT(p_lpszCmdLine, E_POINTER, null);
    strncpy(m_lpszCmdLine, p_lpszCmdLine, KP_MAX_FNAME_LEN);
    m_lpszCmdLine[KP_MAX_FNAME_LEN] = Nul;

    m_pStackTop = p_pStackTop;

static uchar log_fname[KP_MAX_FNAME_LEN + 1];
    KpError.GetLogFileName(log_fname);
    remove((const char *)log_fname);
}


// ----------------------------------
void KpCommonApp::SetProd(const uchar *p_lpszProdName, int p_iProdVer)
{
    KP_ASSERT(p_lpszProdName, E_INVALIDARG, null);
    KpError.SetProdName(p_lpszProdName);
    m_iProdVer = p_iProdVer;
}


// ----------------------------------
void KpCommonApp::GetAppName(uchar *p_lpszNameBuf)
{
    KP_ASSERT(p_lpszNameBuf, E_INVALIDARG, null);
    
    if (m_lpszAppName[0])
        strcpy(p_lpszNameBuf, m_lpszAppName); // tik pirmą kartą būna teisingas kelias, paskui nustatau SetCurrentDirectory() ir santykinis kelias išsiderina
    else
    {
uchar *pnts = m_lpszCmdLine;

static uchar name_buf_tmp[KP_MAX_FNAME_LEN + 1];
        if (*pnts != '\"')
        {
            strncpy(name_buf_tmp, pnts, KP_MAX_FNAME_LEN);
            name_buf_tmp[KP_MAX_FNAME_LEN] = Nul;
            
            pnts = const_cast<uchar *>(strchr(name_buf_tmp, Spc));
        }
        else
        {
            strncpy(name_buf_tmp, pnts + 1, KP_MAX_FNAME_LEN);
            name_buf_tmp[KP_MAX_FNAME_LEN] = Nul;
            pnts = strchr(name_buf_tmp, '\"');
        }
        if (pnts) *pnts = Nul;

#ifdef __WIN32__
#ifdef UNICODE
// TODO: get full unicode path
        strcpy(p_lpszNameBuf, name_buf_tmp);
#else
DWORD ll = 0L;
        ll = GetFullPathName((const char *)name_buf_tmp, KP_MAX_FNAME_LEN, (char *)p_lpszNameBuf, NULL);
//      KP_ASSERT(ll > 0L, KP_E_SYSTEM_ERROR, GetLastError());
        KP_ASSERTW0(ll < KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        p_lpszNameBuf[KP_MAX_FNAME_LEN] = Nul;
#endif
#else
// TODO Linux: get full path
        strcpy(p_lpszNameBuf, name_buf_tmp);
#endif        
        strcpy(m_lpszAppName, p_lpszNameBuf);
    }
}
