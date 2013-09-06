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
size_t strlen(const uchar *src){ return(strlen((const char *)src)); }

uchar *strcpy(uchar *dest, const uchar *src)
   { return ((uchar *)strcpy((char *)dest, (const char *)src)); }
uchar *strcpy(uchar *dest, const char *src)
   { return ((uchar *)strcpy((char *)dest, src)); }

uchar *strncpy(uchar *dest, const uchar *src, size_t nbytes)
   { return ((uchar *)strncpy((char *)dest, (const char *)src, nbytes)); }

uchar *strcat(uchar *dest, const uchar *src)
   { return ((uchar *)strcat((char *)dest, (const char *)src)); }
uchar *strcat(uchar *dest, const char *src)
   { return ((uchar *)strcat((char *)dest, src)); }

int strcmp(const uchar *str1, const uchar *str2)
   { return (strcmp((const char *)str1, (const char *)str2)); }

int strcmp(const uchar *str1, const char *str2)
   { return (strcmp((const char *)str1, str2)); }

int strncmp(const uchar *str1, const uchar *str2, size_t nbytes)
   { return (strncmp((const char *)str1, (const char *)str2, nbytes)); }

// --------------------------------------------------
uchar *strchr(uchar *p_lpszString, KpChar p_iCh)
    { return((uchar *)strchr((char *)p_lpszString, p_iCh)); }

const uchar *strchr(const uchar *p_lpszString, KpChar p_iCh)
{
const uchar *str_ptr = p_lpszString;

    while (*str_ptr && (*str_ptr != p_iCh)) str_ptr++;
    if (*str_ptr == Nul) str_ptr = null;

return(str_ptr);
}

// --------------------------------------------------
uchar *strstr(uchar *p_lpszString, const char *p_lpszPattern)
    { return ((uchar *)strstr((char *)p_lpszString, p_lpszPattern)); }
    
const uchar *strstr(const uchar *p_lpszString, const char *p_lpszPattern)
    {
        KP_ASSERT(p_lpszString, E_INVALIDARG, null);
    uchar *str = null;
        KP_NEWA(str, uchar, strlen(p_lpszString) + 1);
        strcpy(str, p_lpszString);

    const uchar *retv = null;
        retv = strstr(str, p_lpszPattern);
        if (retv) retv = p_lpszString + (retv - str);
        
        KP_DELETEA(str);
     return (retv); 
     }

uchar *strstr(uchar *p_lpszString, const uchar *p_lpszPattern)
    { return(strstr(p_lpszString, (const char *)p_lpszPattern)); }
    
const uchar *strstr(const uchar *p_lpszString, const uchar *p_lpszPattern)
    { return(strstr(p_lpszString, (const char *)p_lpszPattern)); }

// --------------------------------------------------
uchar *strlwr(uchar *str)
    { return((uchar *)strlwr((char *)str)); }


// --------------------------------------------------
void KpStripTrailing(uchar *lpszString, /* const */ uchar *lpszSpcs)
{
uchar *pnts = null;

    KP_ASSERT(lpszString, E_INVALIDARG, null);

    pnts = lpszString + strlen(lpszString);
    while (pnts > lpszString)
    {
        --pnts;
        if (strchr(lpszSpcs, *pnts) == null) // TODO: TvStrChr()
        {
            pnts++;
            break;
        }
    }

    *pnts = Nul;
}


void KpStripLeading(uchar *lpszString, /* const */ uchar *lpszSpcs)
{
uchar *pnts = null;
uchar *pntd = null;

    KP_ASSERT(lpszString, E_INVALIDARG, null);

    pntd = pnts = lpszString;
    while (strchr(lpszSpcs, *pnts)) pnts++;
    while (*pnts) *pntd++ = *pnts++;
    *pntd = Nul;
}


void KpStrip(uchar *lpszString, /* const */ uchar *lpszSpcs)
{
    KpStripLeading(lpszString, lpszSpcs);
    KpStripTrailing(lpszString, lpszSpcs);
}


void KpStripAll(uchar *lpszString, /* const */ uchar *lpszSpcs)
{
uchar *pnts = null;
uchar *pntd = null;

    KP_ASSERT(lpszString, E_INVALIDARG, null);

    pntd = pnts = lpszString;
    while (*pnts)
    {
        while (strchr(lpszSpcs, *pnts)) pnts++;
        *pntd++ = *pnts++;
    }
    *pntd = Nul;
}


// --------------------------------------------------
int UcStrCmp(const uchar *p_lpszStr1, const uchar *p_lpszStr2, bool p_bSkipSpc,
    int p_iSortLng, bool p_bCaseSens, bool p_bRoundFlg)
{
int retv = 0;
// TODO: const KpChar *pnts1, *pnts2;
const uchar *pnts1, *pnts2;
int wgt1, wgt2;

    KP_ASSERT(p_lpszStr1 && p_lpszStr2, E_INVALIDARG, null);

// TODO: convert p_lpszStr1 and p_lpszStr2 to KpChar*
    pnts1 = p_lpszStr1;
    pnts2 = p_lpszStr2;

    while (((*pnts1 != C_Nul) || (*pnts2 != C_Nul)) && (retv == 0))
    {
// TODO: išmest, kai perkonvertuosiu
KP_ASSERT((*pnts1 < KPT_FirstKptChar) && (*pnts2 < KPT_FirstKptChar), E_NOTIMPL, "UTF-8 character");

        if (p_bSkipSpc)
        {
            if (*pnts1 != C_Nul)
                while ((strchr(lpszSpCharsSpcEol, *pnts1) || (*pnts1 == '\'')) &&
                       (*pnts1 != C_Nul)) pnts1++;
            if (*pnts2 != C_Nul)
                while ((strchr(lpszSpCharsSpcEol, *pnts2) || (*pnts2 == '\'')) &&
                    (*pnts2 != C_Nul)) pnts2++;
        }

        if ((*pnts1 != C_Nul) && (*pnts2 != C_Nul))
        {
            wgt1 = iCharWeigths[*pnts1];
            wgt2 = iCharWeigths[*pnts2];

            if ((p_iSortLng == KP_LNG_LIT) || (p_iSortLng == KP_LNG_LIX) || (p_iSortLng == KP_LNG_LIS))
            {
                if (wgt1 / 10000 == C_Y) wgt1 = C_I * 10000 + wgt1 % 10000;
                if (wgt1 / 10000 == C_y) wgt1 = C_i * 10000 + wgt1 % 10000;
                if (wgt2 / 10000 == C_Y) wgt2 = C_I * 10000 + wgt2 % 10000;
                if (wgt2 / 10000 == C_y) wgt2 = C_i * 10000 + wgt2 % 10000;
            }

            if (!p_bCaseSens)
            {
                wgt1 = ToLowWgt(wgt1);
                wgt2 = ToLowWgt(wgt2);
            }

            if (p_bRoundFlg)
            {
                if (p_iSortLng != KP_LNG_LIS)
                {
                    wgt1 = RoundChWgt(wgt1);
                    wgt2 = RoundChWgt(wgt2);

                    if (p_iSortLng == KP_LNG_LIX)
                    {
                        wgt1 -= wgt1 % 10000;
                        wgt2 -= wgt2 % 10000;
                    }
                }
            }

            if (wgt1 > wgt2) retv = 1;
            if (wgt1 < wgt2) retv = (-1);

            pnts1++;
            pnts2++;
        }
        else break;
    }

    if (retv == 0)
    {
        if ((*pnts1 != C_Nul) && (*pnts2 == C_Nul)) retv = 1;
        if ((*pnts1 == C_Nul) && (*pnts2 != C_Nul)) retv = (-1);
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

    if (m_iazStr)
    {
const KpChar *pnts = m_iazStr;
        while (*pnts++ != C_Nul) chr_cnt++;
    }

return(chr_cnt);
}
