/* -----------------------------------------------
 *
 * kpstring.cpp
 *
 *    string tools
 *
 * 2013-04-05  mp  initial creation
 *
 */

#include "envir.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"


// -----------------------------
size_t strlen(const UCHAR *src){ return(strlen((const CHAR *)src)); }

UCHAR *strcpy(UCHAR *dest, const UCHAR *src)
   { return((UCHAR *)strcpy((CHAR *)dest, (const CHAR *)src)); }
UCHAR *strcpy(UCHAR *dest, const CHAR *src)
   { return((UCHAR *)strcpy((CHAR *)dest, src)); }

UCHAR *strncpy(UCHAR *dest, const UCHAR *src, size_t nbytes)
   { return((UCHAR *)strncpy((CHAR *)dest, (const CHAR *)src, nbytes)); }

UCHAR *strcat(UCHAR *dest, const UCHAR *src)
   { return((UCHAR *)strcat((CHAR *)dest, (const CHAR *)src)); }
UCHAR *strcat(UCHAR *dest, const CHAR *src)
   { return((UCHAR *)strcat((CHAR *)dest, src)); }
   
/* const */ UCHAR *strchr(/* const */ UCHAR *src, UCHAR ch)
   { return((/* const */ UCHAR *)strchr((/* const */ CHAR *)src, ch)); }

int strcmp(const UCHAR *str1, const UCHAR *str2)
   { return(strcmp((const CHAR *)str1, (const CHAR *)str2)); }


// --------------------------------------------------
void CutTrailSpcs(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs)
{
UCHAR *pnts = null;

    KP_ASSERT(lpszString != null, E_INVALIDARG, null);

    pnts = lpszString + strlen(lpszString);
    while(pnts > lpszString)
    {
        --pnts;
        if(strchr(lpszSpcs, *pnts) == null) // TODO: TvStrChr()
        {
            pnts++;
            break;
        }
    }

    *pnts = Nul;
}


// -----------------------------
KpChStrStatic::KpChStrStatic(void)
{
    m_iazStr = NULL;
}


KpChStrStatic::KpChStrStatic(KpChar *iazKpChArr)
{
    m_iazStr = iazKpChArr;
}


// -----------------------------
KpChStr::~KpChStr(void)
{
    KP_DELETEA(m_iazStr);
}


// --------------------------------------------------
int KpChStrStatic::Len(void) const
{
int chr_cnt = 0;

    if(m_iazStr != NULL)
    {
const KpChar *pnts = m_iazStr;
        while(*pnts++ != C_Nul) chr_cnt++;
    }

return(chr_cnt);
}
