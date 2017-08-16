/* -----------------------------------------------
 *
 * kpstring.cpp
 *
 *  string tools
 *
 * Changelog:
 *  2013-04-05  mp  initial creation
 *  2016-09-05  mp  migration of kpsgrp from tv to kplib
 *  2017-05-22  mp  build on Linux Mint 18.1 Serena 64
 *
 */

#include "envir.h"

// dėl *trim()
#include <algorithm> 
#include <functional> 
#include <cctype>
// #include <locale>

#include <stdlib.h>
#include <string.h>
#include <vector>
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
size_t strlen(const KpStrPtr src){ return(strlen((const char *)src)); }

KpStrPtr strcpy(KpStrPtr dest, const KpStrPtr src)
   { return ((KpStrPtr)strcpy((char *)dest, (const char *)src)); }
KpStrPtr strcpy(KpStrPtr dest, const char *src)
   { return ((KpStrPtr)strcpy((char *)dest, src)); }

KpStrPtr strncpy(KpStrPtr dest, const KpStrPtr src, size_t nbytes)
   { return ((KpStrPtr)strncpy((char *)dest, (const char *)src, nbytes)); }

KpStrPtr strcat(KpStrPtr dest, const KpStrPtr src)
   { return ((KpStrPtr)strcat((char *)dest, (const char *)src)); }
KpStrPtr strcat(KpStrPtr dest, const char *src)
   { return ((KpStrPtr)strcat((char *)dest, src)); }

int strcmp(const KpStrPtr str1, const KpStrPtr str2)
   { return (strcmp((const char *)str1, (const char *)str2)); }

int strcmp(const KpStrPtr str1, const char *str2)
   { return (strcmp((const char *)str1, str2)); }

int strncmp(const KpStrPtr str1, const KpStrPtr str2, size_t nbytes)
   { return (strncmp((const char *)str1, (const char *)str2, nbytes)); }

// --------------------------------------------------
KpStrPtr strchr(KpStrPtr p_pszString, KpChar p_iCh)
    { return((KpStrPtr)strchr((char *)p_pszString, p_iCh)); }

const KpStrPtr strchr(const KpStrPtr p_pszString, KpChar p_iCh)
{
const KpStrPtr str_ptr = p_pszString;

    while (*str_ptr && (*str_ptr != p_iCh)) str_ptr++;
    if (*str_ptr == Nul) str_ptr = null;

return(str_ptr);
}

// --------------------------------------------------
KpStrPtr strstr(KpStrPtr p_pszString, const char *p_pszPattern)
    { return ((KpStrPtr)strstr((char *)p_pszString, p_pszPattern)); }
    
const KpStrPtr strstr(const KpStrPtr p_pszString, const char *p_pszPattern)
    {
        KP_ASSERT(p_pszString, E_INVALIDARG, null);
    KpStrPtr str = null;
        KP_NEWA(str, uchar, strlen(p_pszString) + 1);
        strcpy(str, p_pszString);

    const KpStrPtr retv = null;
        retv = strstr(str, p_pszPattern);
        if (retv) retv = p_pszString + (retv - str);
        
        KP_DELETEA(str);
     return (retv); 
     }

KpStrPtr strstr(KpStrPtr p_pszString, const KpStrPtr p_pszPattern)
    { return(strstr(p_pszString, (const char *)p_pszPattern)); }
    
const KpStrPtr strstr(const KpStrPtr p_pszString, const KpStrPtr p_pszPattern)
    { return(strstr(p_pszString, (const char *)p_pszPattern)); }

// --------------------------------------------------
#ifndef HAVE_STRLWR
char *strlwr(char *str)
{
#ifdef __WIN32__
    return _strlwr(str);
#else
    KpStrPtr pstr = (KpStrPtr)str;
    while (*pstr)
    {
        *pstr = tolower(*pstr);
        pstr++;
    }

    return str;
#endif
}
#endif

KpStrPtr strlwr(KpStrPtr str)
    { return((KpStrPtr)strlwr((char *)str)); }


// --------------------------------------------------
void KpStripTrailing(KpStrPtr pszString, /* const */ KpStrPtr pszSpcs)
{
KpStrPtr pnts = null;

    KP_ASSERT(pszString, E_INVALIDARG, null);

    pnts = pszString + strlen(pszString);
    while (pnts > pszString)
    {
        --pnts;
        if (strchr(pszSpcs, *pnts) == null) // TODO: TvStrChr()
        {
            pnts++;
            break;
        }
    }

    *pnts = Nul;
}


void KpStripLeading(KpStrPtr pszString, /* const */ KpStrPtr pszSpcs)
{
KpStrPtr pnts = null;
KpStrPtr pntd = null;

    KP_ASSERT(pszString, E_INVALIDARG, null);

    pntd = pnts = pszString;
    while (strchr(pszSpcs, *pnts)) pnts++;
    while (*pnts) *pntd++ = *pnts++;
    *pntd = Nul;
}


void KpStrip(KpStrPtr pszString, /* const */ KpStrPtr pszSpcs)
{
    KpStripLeading(pszString, pszSpcs);
    KpStripTrailing(pszString, pszSpcs);
}


void KpStripAll(KpStrPtr pszString, /* const */ KpStrPtr pszSpcs)
{
KpStrPtr pnts = null;
KpStrPtr pntd = null;

    KP_ASSERT(pszString, E_INVALIDARG, null);

    pntd = pnts = pszString;
    while (*pnts)
    {
        while (strchr(pszSpcs, *pnts)) pnts++;
        *pntd++ = *pnts++;
    }
    *pntd = Nul;
}


// --------------------------------------------------
void KpObfuscate(KpStrPtr p_lpszString)
{
    KP_ASSERT(p_lpszString, E_INVALIDARG, null);

KpStrPtr pnts = p_lpszString;
KpStrPtr pntd = p_lpszString;

    while (*pnts) switch (*pnts)
    {
    case Lf: *pntd++ = Spc; pnts++; break;
    case Cr: *pntd++ = Spc; if (*(++pnts) == Lf) pnts++; break;
    default: *pntd++ = *pnts++; break;
    }

    *pntd = Nul;
}


// --------------------------------------------------
int UcStrCmp(const KpStrPtr p_pszStr1, const KpStrPtr p_pszStr2, bool p_bSkipSpc,
    int p_iSortLng, bool p_bCaseSens, bool p_bRoundFlg)
{
int retv = 0;
// TODO: const KpChar *pnts1, *pnts2;
const KpStrPtr pnts1, pnts2;
int wgt1, wgt2;

    KP_ASSERT(p_pszStr1 && p_pszStr2, E_INVALIDARG, null);

// TODO: convert p_pszStr1 and p_pszStr2 to KpChar*
    pnts1 = p_pszStr1;
    pnts2 = p_pszStr2;

    while (((*pnts1 != C_Nul) || (*pnts2 != C_Nul)) && (retv == 0))
    {
// TODO: išmest, kai perkonvertuosiu
KP_ASSERT((*pnts1 < KPT_FirstKptChar) && (*pnts2 < KPT_FirstKptChar), E_NOTIMPL, "UTF-8 character");

        if (p_bSkipSpc)
        {
            if (*pnts1 != C_Nul)
                while ((strchr(pszSpCharsSpcEol, *pnts1) || (*pnts1 == '\'')) &&
                       (*pnts1 != C_Nul)) pnts1++;
            if (*pnts2 != C_Nul)
                while ((strchr(pszSpCharsSpcEol, *pnts2) || (*pnts2 == '\'')) &&
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

// -------------------------
// KpString

KpString &KpString::ltrim(KpString &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
return s;
}

KpString &KpString::rtrim(KpString &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
return s;
}

void KpString::Split(const KpStrPtr pszDelim, vector<KpString> &saOutArr)
{
    KP_ASSERT(pszDelim, E_INVALIDARG, null);

    saOutArr.clear();

    KpString tmp_str = *this;

    do
    {
        int delim_pos = tmp_str.find((const char *)pszDelim);
        if (delim_pos != npos)
        {
            saOutArr.push_back(KpString(tmp_str.substr(0, delim_pos)));
            tmp_str = tmp_str.substr(delim_pos + strlen(pszDelim));

            // paskutinis laukas tuščias
            if (tmp_str == "")
                saOutArr.push_back(tmp_str);
        }
        else
        {
            saOutArr.push_back(tmp_str);
            tmp_str = "";
        }

    } while (tmp_str.length() > 0);
}

KpString KpString::Join(const vector<KpString> &saStrArr)
{
    int len = saStrArr.size();
    KpString ret_str;

    for (int ii = 0; ii < len - 1; ii++) ret_str += saStrArr[ii] + *this;
    if (len > 0) ret_str += saStrArr[len - 1];

return ret_str;
}
