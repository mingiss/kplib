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

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpsort.h"
#include "kpmsg.h"
#include "kperr.h"


// -----------------------------
size_t strlen(const UCHAR *src){ return(strlen((const CHAR *)src)); }

UCHAR *strcpy(UCHAR *dest, const UCHAR *src)
   { return ((UCHAR *)strcpy((CHAR *)dest, (const CHAR *)src)); }
UCHAR *strcpy(UCHAR *dest, const CHAR *src)
   { return ((UCHAR *)strcpy((CHAR *)dest, src)); }

UCHAR *strncpy(UCHAR *dest, const UCHAR *src, size_t nbytes)
   { return ((UCHAR *)strncpy((CHAR *)dest, (const CHAR *)src, nbytes)); }

UCHAR *strcat(UCHAR *dest, const UCHAR *src)
   { return ((UCHAR *)strcat((CHAR *)dest, (const CHAR *)src)); }
UCHAR *strcat(UCHAR *dest, const CHAR *src)
   { return ((UCHAR *)strcat((CHAR *)dest, src)); }

int strcmp(const UCHAR *str1, const UCHAR *str2)
   { return (strcmp((const CHAR *)str1, (const CHAR *)str2)); }

int strcmp(const UCHAR *str1, const CHAR *str2)
   { return (strcmp((const CHAR *)str1, str2)); }

int strncmp(const UCHAR *str1, const UCHAR *str2, size_t nbytes)
   { return (strncmp((const CHAR *)str1, (const CHAR *)str2, nbytes)); }

// --------------------------------------------------
UCHAR *strchr(UCHAR *p_lpszString, KpChar p_iCh)
    { return((UCHAR *)strchr((CHAR *)p_lpszString, p_iCh)); }

const UCHAR *strchr(const UCHAR *p_lpszString, KpChar p_iCh)
{
const UCHAR *str_ptr = p_lpszString;

    while((*str_ptr != Nul) && (*str_ptr != p_iCh)) str_ptr++;
    if(*str_ptr == Nul) str_ptr = null;

return(str_ptr);
}

// --------------------------------------------------
UCHAR *strstr(UCHAR *p_lpszString, const CHAR *p_lpszPattern)
    { return ((UCHAR *)strstr((CHAR *)p_lpszString, p_lpszPattern)); }
    
const UCHAR *strstr(const UCHAR *p_lpszString, const CHAR *p_lpszPattern)
    {
        KP_ASSERT(p_lpszString != null, E_INVALIDARG, null);
    UCHAR *str = null;
        KP_NEWA(str, UCHAR, strlen(p_lpszString) + 1);
        strcpy(str, p_lpszString);

    const UCHAR *retv = null;
        retv = strstr(str, p_lpszPattern);
        if(retv != null) retv = p_lpszString + (retv - str);
        
        KP_DELETEA(str);
     return (retv); 
     }

UCHAR *strstr(UCHAR *p_lpszString, const UCHAR *p_lpszPattern)
    { return(strstr(p_lpszString, (const CHAR *)p_lpszPattern)); }
    
const UCHAR *strstr(const UCHAR *p_lpszString, const UCHAR *p_lpszPattern)
    { return(strstr(p_lpszString, (const CHAR *)p_lpszPattern)); }

// --------------------------------------------------
UCHAR *strlwr(UCHAR *str)
    { return((UCHAR *)strlwr((CHAR *)str)); }


// --------------------------------------------------
void KpStripTrailing(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs)
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


void KpStripLeading(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs)
{
UCHAR *pnts = null;
UCHAR *pntd = null;

    KP_ASSERT(lpszString != null, E_INVALIDARG, null);

    pntd = pnts = lpszString;
    while(strchr(lpszSpcs, *pnts) != null) pnts++;
    while(*pnts != Nul) *pntd++ = *pnts++;
    *pntd = Nul;
}


void KpStrip(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs)
{
    KpStripLeading(lpszString, lpszSpcs);
    KpStripTrailing(lpszString, lpszSpcs);
}


void KpStripAll(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs)
{
UCHAR *pnts = null;
UCHAR *pntd = null;

    KP_ASSERT(lpszString != null, E_INVALIDARG, null);

    pntd = pnts = lpszString;
    while(*pnts != Nul)
    {
        while(strchr(lpszSpcs, *pnts) != null) pnts++;
        *pntd++ = *pnts++;
    }
    *pntd = Nul;
}


// --------------------------------------------------
int UcStrCmp(const UCHAR *p_lpszStr1, const UCHAR *p_lpszStr2, bool p_bSkipSpc,
    int p_iSortLng, bool p_bCaseSens, bool p_bRoundFlg)
{
int retv = 0;
// TODO: const KpChar *pnts1, *pnts2;
const UCHAR *pnts1, *pnts2;
int wgt1, wgt2;

    KP_ASSERT((p_lpszStr1 != null) && (p_lpszStr2 != null), E_INVALIDARG, null);

// TODO: convert p_lpszStr1 and p_lpszStr2 to KpChar*
    pnts1 = p_lpszStr1;
    pnts2 = p_lpszStr2;

    while(((*pnts1 != C_Nul) || (*pnts2 != C_Nul)) && (retv == 0))
    {
// TODO: išmest, kai perkonvertuosiu
KP_ASSERT((*pnts1 < KPT_FirstKptChar) && (*pnts2 < KPT_FirstKptChar), E_NOTIMPL, "UTF-8 character");

        if(p_bSkipSpc)
        {
            if(*pnts1 != C_Nul)
                while(((strchr(lpszSpCharsSpcEol, *pnts1) != null) || (*pnts1 == '\'')) &&
                       (*pnts1 != C_Nul)) pnts1++;
            if(*pnts2 != C_Nul)
                while(((strchr(lpszSpCharsSpcEol, *pnts2) != null) || (*pnts2 == '\'')) &&
                    (*pnts2 != C_Nul)) pnts2++;
        }

        if((*pnts1 != C_Nul) && (*pnts2 != C_Nul))
        {
            wgt1 = iCharWeigths[*pnts1];
            wgt2 = iCharWeigths[*pnts2];

            if((p_iSortLng == KP_LNG_LIT) || (p_iSortLng == KP_LNG_LIX) || (p_iSortLng == KP_LNG_LIS))
            {
                if(wgt1 / 10000 == C_Y) wgt1 = C_I * 10000 + wgt1 % 10000;
                if(wgt1 / 10000 == C_y) wgt1 = C_i * 10000 + wgt1 % 10000;
                if(wgt2 / 10000 == C_Y) wgt2 = C_I * 10000 + wgt2 % 10000;
                if(wgt2 / 10000 == C_y) wgt2 = C_i * 10000 + wgt2 % 10000;
            }

            if(!p_bCaseSens)
            {
                wgt1 = ToLowWgt(wgt1);
                wgt2 = ToLowWgt(wgt2);
            }

            if(p_bRoundFlg)
            {
                if(p_iSortLng != KP_LNG_LIS)
                {
                    wgt1 = RoundChWgt(wgt1);
                    wgt2 = RoundChWgt(wgt2);

                    if(p_iSortLng == KP_LNG_LIX)
                    {
                        wgt1 -= wgt1 % 10000;
                        wgt2 -= wgt2 % 10000;
                    }
                }
            }

            if(wgt1 > wgt2) retv = 1;
            if(wgt1 < wgt2) retv = (-1);

            pnts1++;
            pnts2++;
        }
        else break;
    }

    if(retv == 0)
    {
        if((*pnts1 != C_Nul) && (*pnts2 == C_Nul)) retv = 1;
        if((*pnts1 == C_Nul) && (*pnts2 != C_Nul)) retv = (-1);
    }

return(retv);
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
