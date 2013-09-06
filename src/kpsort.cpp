/* -----------------------------
 * kpsort.cpp
 *      searching and sorting capabilities
 *      
 *  Changelog:
 *      2013-06-11  mp  initial creation
 *       
 */  


#include "envir.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "kpstdlib.h"
#include "kperrno.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpsort.h"
#include "kpmsg.h"
#include "kperr.h"


// ================================================== sort order definition
int iCharWeigths[C_CharArrSize44] =
{
#include "KpCharWgt.cpp"
};


// --------------------------------------------------
int GetKwrdIndex
(
   const unsigned char *p_lpszKeywrd,
   const uchar * const *p_plpszKeytable,
   const int p_iTabSize,
   bool p_bCaseSens,
   bool p_bWholeWords
)
{
int ix;
uchar kwd_str[KP_KWD_LEN + 1];
int ii;
int retv = TV_TG_NoKey;

    KP_ASSERT(p_lpszKeywrd && p_plpszKeytable, E_INVALIDARG, null); 
    KP_ASSERT(strlen(p_lpszKeywrd) < KP_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);

    ix = 0;
    while
    (
        ((p_iTabSize < 0) || (ix < p_iTabSize)) &&
        ((p_iTabSize >= 0) || p_plpszKeytable[ix]) &&
        (retv == TV_TG_NoKey)
    )
    {
        strcpy(kwd_str, p_lpszKeywrd);
        if (p_plpszKeytable[ix])
        {
            if (!p_bWholeWords)
            { 
                ii = strlen(p_plpszKeytable[ix]);
                KP_ASSERT(ii < KP_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
                kwd_str[ii] = Nul;
            }

            if (UcStrCmp(kwd_str, p_plpszKeytable[ix], False, KP_LNG_ENG, p_bCaseSens, False) == 0)
                retv = ix;
        }
         
        ix++;
    }

return(retv);
}

int GetKwrdIndexArr
(
   const unsigned char *p_lpszKeywrd,
   const uchar *p_plpszKeytable,
   const int p_iTabSize,
   bool p_bCaseSens,
   bool p_bWholeWords,
   int p_iKeySize
)
{
int ix;
uchar kwd_str[KP_KWD_LEN + 1];
int ii;
int retv = TV_TG_NoKey;
const uchar *cur_kwd = p_plpszKeytable;

    KP_ASSERT(p_lpszKeywrd && p_plpszKeytable, E_INVALIDARG, null); 
    KP_ASSERT(strlen(p_lpszKeywrd) < KP_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
    KP_ASSERT(p_iKeySize > 1, E_INVALIDARG, null);

    ix = 0;
    while
    (
        ((p_iTabSize < 0) || (ix < p_iTabSize)) &&
        ((p_iTabSize >= 0) || *cur_kwd) &&
        (retv == TV_TG_NoKey)
    )
    {
        strcpy(kwd_str, p_lpszKeywrd);
        if (*cur_kwd)
        {
            if (!p_bWholeWords)
            { 
                ii = strlen(cur_kwd);
                KP_ASSERT(ii < KP_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
                kwd_str[ii] = Nul;
            }

            if (UcStrCmp(kwd_str, cur_kwd, False, KP_LNG_ENG, p_bCaseSens, False) == 0)
                retv = ix;
        }
         
        cur_kwd += p_iKeySize;
        ix++;
    }

return(retv);
}
