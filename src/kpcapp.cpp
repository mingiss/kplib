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

#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "kperrno.h"
#include "kpstdlib.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kpcapp.h"
#include "kpcurdat.h"


// ----------------------------------
#ifdef WIN32
HINSTANCE KpCommonApp::m_hInstance = NULL;
#endif

KpLang KpCommonApp::m_iMsgLangOff = KpLangEn;


// ----------------------------------
KpCommonApp::KpCommonApp(const UCHAR *lpszProdName, int iProdVer)
{
    m_iMsgLangOff = KpLangEn;
#ifdef WIN32
    m_hInstance = 0L;
    KpInitWindows();
#endif

    m_lpszAppName[0] = Nul;
   
    KP_ASSERT(lpszProdName != null, E_INVALIDARG, null);
    strncpy(m_lpszProdName, lpszProdName, KP_MAX_FNAME_LEN);
    m_lpszProdName[KP_MAX_FNAME_LEN] = Nul;
   
    m_iProdVer = iProdVer;
   
    strncpy(m_lpszProdDate, CUR_DATE, KP_MAX_FNAME_LEN);
    m_lpszProdDate[KP_MAX_FNAME_LEN] = Nul;
}


// ----------------------------------
void KpCommonApp::Init(HINSTANCE hInstance, const UCHAR *lpszCmdLine)
{
#ifdef WIN32
    if(hInstance != 0L) m_hInstance = hInstance;
#endif
}


// ----------------------------------
void KpCommonApp::GetAppName(UCHAR *lpszNameBuf)
{
    KP_ASSERT(lpszNameBuf != null, E_INVALIDARG, null);
    
    if(m_lpszAppName[0] != Nul)
        strcpy(lpszNameBuf, m_lpszAppName); // tik pirmą kartą būna teisingas kelias, paskui nustatau SetCurrentDirectory() ir santykinis kelias išsiderina
    else
    {
UCHAR *pnts = null;
        pnts = (UCHAR *)GetCommandLine();
        KP_ASSERT(pnts != null, E_INVALIDARG, null);

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

DWORD ll = 0L;
        ll = GetFullPathName((const CHAR *)name_buf_tmp, KP_MAX_FNAME_LEN, (char *)lpszNameBuf, NULL);
        KP_ASSERT(ll != 0L, KP_E_SYSTEM_ERROR, GetLastError());
        KP_ASSERTW0(ll < KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        lpszNameBuf[KP_MAX_FNAME_LEN] = Nul;
        
        strcpy(m_lpszAppName, lpszNameBuf);
    }
}
