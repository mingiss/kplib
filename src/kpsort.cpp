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
   const unsigned char * const *p_plpszKeytable,
   const int p_iTabSize,
   bool p_bCaseSens,
   bool p_bWholeWords
)
{
int ix;
unsigned char kwd_str[KP_KWD_LEN + 1];
int ii;
int retv = TV_TG_NoKey;

    KP_ASSERT((p_lpszKeywrd != null) && (p_plpszKeytable != NULL), E_INVALIDARG, null); 
    KP_ASSERT(strlen(p_lpszKeywrd) < KP_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);

    ix = 0;
    while
    (
        ((p_iTabSize < 0) || (ix < p_iTabSize)) &&
        ((p_iTabSize >= 0) || (p_plpszKeytable[ix] != null)) &&
        (retv == TV_TG_NoKey)
    )
    {
        strcpy(kwd_str, p_lpszKeywrd);
        if(p_plpszKeytable[ix] != null)
        {
            if(!p_bWholeWords)
            { 
                ii = strlen(p_plpszKeytable[ix]);
                KP_ASSERT(ii < KP_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
                kwd_str[ii] = Nul;
            }

            if(UcStrCmp(kwd_str, p_plpszKeytable[ix], False, KP_LNG_ENG, p_bCaseSens, False) == 0)
                retv = ix;
        }
         
        ix++;
    }

return(retv);
}
