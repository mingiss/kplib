/* -----------------------------------------------
 *
 * kpstring.h
 *
 *    string tools
 *
 * 2013-04-04  mp  initial creation
 *
 */

#ifndef kpstring_included
#define kpstring_included

// -------------------------
typedef UCHAR * KpStrPtr;
#define null ((const KpStrPtr)NULL) // null pointer to the string

// #ifdef __GNUC__
// #define memmove memcpy
// #endif

// -------------------------
#ifdef __cplusplus

// -------------------------
// TODO: kelt į KpPlainStr klasę?
extern size_t strlen(const UCHAR *src);

extern UCHAR *strcpy(UCHAR *dest, const UCHAR *src);
extern UCHAR *strcpy(UCHAR *dest, const CHAR *src);
   
extern UCHAR *strncpy(UCHAR *dest, const UCHAR *src, size_t nbytes);

extern UCHAR *strcat(UCHAR *dest, const UCHAR *src);
extern UCHAR *strcat(UCHAR *dest, const CHAR *src);
   
extern UCHAR *strchr(UCHAR *p_lpszString, KpChar p_iCh);
extern const UCHAR *strchr(const UCHAR *p_lpszString, KpChar p_iCh);

extern UCHAR *strstr(UCHAR *p_lpszString, const CHAR *p_lpszPattern);
extern const UCHAR *strstr(const UCHAR *p_lpszString, const CHAR *p_lpszPattern);
extern UCHAR *strstr(UCHAR *p_lpszString, const UCHAR *p_lpszPattern);
extern const UCHAR *strstr(const UCHAR *p_lpszString, const UCHAR *p_lpszPattern);

extern int strcmp(const UCHAR *str1, const UCHAR *str2);
extern int strcmp(const UCHAR *str1, const CHAR *str2);

extern int strncmp(const UCHAR *str1, const UCHAR *str2, size_t nbytes);

extern UCHAR *strlwr(UCHAR *str);


// ------------------------- UTF-8 functions
// compares UTF-8 strings using certain sorting order
// TODO: accented letters are treated as normal, and Y treated as I
// p_bSkipSpc - ignore all spaces
// TODO: p_iSortLng - letter order (look envir.h for SortMode)
// p_bCaseSens - case sensitivity flag
// TODO: p_bCaseSens for UTF-8
// TODO: if p_bRoundFlg == False, accented letters and Y are theyr own wage and are sorted separatelly
// 0: p_lpszStr1 == p_lpszStr2
// 1: p_lpszStr1 > p_lpszStr2
// -1: p_lpszStr1 > p_lpszStr2
extern int UcStrCmp(const UCHAR *p_lpszStr1, const UCHAR *p_lpszStr2, bool p_bSkipSpc, 
    int p_iSortLng, bool p_bCaseSens, bool p_bRoundFlg);

// -------------------------
// TODO: kelt į KpPlainStr klasę
void KpStripTrailing(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs = lpszSpcEol); // numeta tarpus gale // former CutTrailSpcs
void KpStripLeading(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs = lpszSpcEol); // numeta tarpus pradžioj
void KpStrip(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs = lpszSpcEol); // numeta tarpus pradžioj ir gale 
void KpStripAll(UCHAR *lpszString, /* const */ UCHAR *lpszSpcs = lpszSpcEol); // išmeta visus tarpus


// -------------------------
// static C_Nul-terminated KpChar character array, no deletion required
class KpChStrStatic
{
public:
    KpChar *m_iazStr;
    
    KpChStrStatic();
    KpChStrStatic(KpChar *iazKpChArr);
    
    int Len(void) const; // returns number of KpChar characters in m_iazStr[] 
};

// dynamically allocated C_Nul-terminated KpChar character array
class KpChStr : public KpChStrStatic 
{
public:
    ~KpChStr();
};

#endif // #ifdef __cplusplus
#endif // #ifndef kpstring_included
