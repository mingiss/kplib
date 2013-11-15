/* -----------------------------------------------
 *
 * kpstring.h
 *
 *    string tools
 *
 * 2013-04-04  mp  initial creation
 *
 */

#ifndef KPSTRING_INCLUDED
#define KPSTRING_INCLUDED

// -------------------------
typedef uchar * KpStrPtr;
#ifndef null
#define null ((const KpStrPtr)NULL) // null pointer to the string
#endif

// #ifdef __GNUC__
// #define memmove memcpy
// #endif


#ifndef KPSTDLIB_INCLUDED
typedef unsigned char uchar;
#endif

/* -----------------------
 * Macros to call kp_append_...()
 * ret_buf and cur_buf_len should be locally defined using KP_DEF_BUF   
 */
#define KP_DEF_BUF int cur_buf_len = 1000; uchar *ret_buf = malloc(cur_buf_len + 1); assert(ret_buf); ret_buf[0] = 0;
#define KP_APPEND_STR(out_str) kp_append_str((const uchar *)out_str, &ret_buf, &cur_buf_len)
#define KP_APPEND_STR_AND_FREE(out_str) kp_append_str_and_free(out_str, &ret_buf, &cur_buf_len)
#define KP_APPEND_CHR(out_chr) kp_append_chr(out_chr, &ret_buf, &cur_buf_len)

/* -----------
 * functions of kpstrapp.c *
 */
   
/* safe strcat() – appends out_str to the string buffer *str_buf_ptr */ 
extern void kp_append_str(const uchar *out_str, uchar **str_buf_ptr, int *buf_len_ptr);

/* appends out_str to *str_buf_ptr and free()'s */
extern void kp_append_str_and_free(uchar *out_str, uchar **str_buf_ptr, int *buf_len_ptr);

/* safely appends byte out_chr to the string buffer *str_buf_ptr */
extern void kp_append_chr(const uchar out_chr, uchar **str_buf_ptr, int *buf_len_ptr);


// -------------------------
#ifdef __cplusplus

// -------------------------
// TODO: kelt į KpPlainStr klasę?
extern size_t strlen(const uchar *src);

extern uchar *strcpy(uchar *dest, const uchar *src);
extern uchar *strcpy(uchar *dest, const char *src);
   
extern uchar *strncpy(uchar *dest, const uchar *src, size_t nbytes);

extern uchar *strcat(uchar *dest, const uchar *src);
extern uchar *strcat(uchar *dest, const char *src);
   
extern uchar *strchr(uchar *p_lpszString, KpChar p_iCh);
extern const uchar *strchr(const uchar *p_lpszString, KpChar p_iCh);

extern uchar *strstr(uchar *p_lpszString, const char *p_lpszPattern);
extern const uchar *strstr(const uchar *p_lpszString, const char *p_lpszPattern);
extern uchar *strstr(uchar *p_lpszString, const uchar *p_lpszPattern);
extern const uchar *strstr(const uchar *p_lpszString, const uchar *p_lpszPattern);

extern int strcmp(const uchar *str1, const uchar *str2);
extern int strcmp(const uchar *str1, const char *str2);

extern int strncmp(const uchar *str1, const uchar *str2, size_t nbytes);

extern uchar *strlwr(uchar *str);


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
extern int UcStrCmp(const uchar *p_lpszStr1, const uchar *p_lpszStr2, bool p_bSkipSpc, 
    int p_iSortLng, bool p_bCaseSens, bool p_bRoundFlg);

// -------------------------
// TODO: kelt į KpPlainStr klasę
void KpStripTrailing(uchar *lpszString, /* const */ uchar *lpszSpcs = lpszSpcEol); // numeta tarpus gale // former CutTrailSpcs
void KpStripLeading(uchar *lpszString, /* const */ uchar *lpszSpcs = lpszSpcEol); // numeta tarpus pradžioj
void KpStrip(uchar *lpszString, /* const */ uchar *lpszSpcs = lpszSpcEol); // numeta tarpus pradžioj ir gale 
void KpStripAll(uchar *lpszString, /* const */ uchar *lpszSpcs = lpszSpcEol); // išmeta visus tarpus


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
#endif // #ifndef KPSTRING_INCLUDED
