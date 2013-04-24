/* -----------------------------------------------
 *
 * kpwindow.cpp
 *
 *    common Win32 things
 *
 * 2013-04-11  mp  initial creation
 *
 */


#ifdef __WIN32__

#include "envir.h"

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


// ------------------------------------------
void KpCommonApp::KpInitWindows(void)
{
// -----------------
    m_hInstance = GetModuleHandle(NULL);

// -----------------
#ifdef MsgLang
#   if (MsgLang == KpLangNo_p)
        m_iMsgLangOff = KpLangEn;

#   elif (MsgLang == KpLangSel_p)
        KP_THROW(E_NOTIMPL, null);

#   elif ((MsgLang == KpLangEn_p) || (MsgLang == KpLangLt_p) || (MsgLang == KpLangPl_1250_p) || (MsgLang == KpLangPl_1257_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))
        m_iMsgLangOff = (KpLang)MsgLang;

#   elif ((MsgLang == KpLangPl_p) || (MsgLang == KpLangRu_p))
HRESULT retc = S_OK;
HKEY key = NULL;
LONG retw = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\Nls\\CodePage", 0, KEY_QUERY_VALUE, &key);
        KP_ASSERTW(retw == ERROR_SUCCESS, KP_E_KWD_NOT_FOUND, retw);
        KP_ASSERTW(key != NULL, KP_E_SYSTEM_ERROR, null);
DWORD buf_len = KP_KWD_LEN;
unsigned char key_buf[KP_KWD_LEN + 1];
        if(SUCCEEDED(retc))
        {
DWORD val_type;
            retw = RegQueryValueEx(key, "ACP", NULL, &val_type, key_buf, &buf_len);
            KP_ASSERTW(retw == ERROR_SUCCESS, KP_E_KWD_NOT_FOUND, retw);
            KP_ASSERTW(val_type == REG_SZ, KP_E_KWD_NOT_FOUND, retw);
        }
        if(SUCCEEDED(retc))
        {
            key_buf[buf_len] = Nul;
            CutInitTrailSpcs(key_buf);
#       if (MsgLang == KpLangPl_p)
                if(strcmp(key_buf, "1257") == 0) iMsgLangOff = KpLangPl_1257;
                else /* if(strcmp(key_buf, "1250") == 0) */  iMsgLangOff = KpLangPl_1250;

#       elif (MsgLang == KpLangRu_p)
                if(strcmp(key_buf, "1251") == 0) iMsgLangOff = KpLangRu_1251;
                else iMsgLangOff = KpLangRu_0;

#       else
                KP_THROW(E_INVALIDARG, null);
#       endif
        }
        if(key != NULL) RegCloseKey(key);
        key = NULL;

#   else
        KP_THROW(E_INVALIDARG, null); 
        break;

#   endif // #  elif ((MsgLang == KpLangPl_p) || (MsgLang == KpLangRu_p))

#endif // #ifdef MsgLang

    KP_ASSERT((m_iMsgLangOff >= 0) && (m_iMsgLangOff < KpNumOfLangs), KP_E_SYSTEM_ERROR, null);
}

#endif // #ifdef __WIN32__
