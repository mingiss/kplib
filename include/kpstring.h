/* -----------------------------------------------
 *
 * kpstring.h
 *
 *  string tools
 *
 * Changelog:
 *  2013-04-04  mp  initial creation
 *  2017-05-22  mp  build on Linux Mint 18.1 Serena 64
 *
 */

#ifndef KPSTRING_INCLUDED
#define KPSTRING_INCLUDED

// -------------------------
#ifndef null
#define null ((const KpStrPtr)NULL) // null pointer to the string
#endif

// #ifdef __GNUC__
// #define memmove memcpy
// #endif


/* -----------------------
 * Macros to call kp_append_...()
 * ret_buf and cur_buf_len should be locally defined using KP_DEF_BUF
 */
#define KP_DEF_BUF int cur_buf_len = 1000; KpStrPtr ret_buf = malloc(cur_buf_len + 1); assert(ret_buf); ret_buf[0] = 0;
#define KP_APPEND_STR(out_str) kp_append_str((const KpStrPtr)out_str, &ret_buf, &cur_buf_len)
#define KP_APPEND_STR_AND_FREE(out_str) kp_append_str_and_free(out_str, &ret_buf, &cur_buf_len)
#define KP_APPEND_CHR(out_chr) kp_append_chr(out_chr, &ret_buf, &cur_buf_len)

/* -----------
 * functions of kpstrapp.c *
 */

/* safe strcat() – appends out_str to the string buffer *str_buf_ptr */ 
extern void kp_append_str(const KpStrPtr out_str, KpStrPtr *str_buf_ptr, int *buf_len_ptr);

/* appends out_str to *str_buf_ptr and free()'s */
extern void kp_append_str_and_free(KpStrPtr out_str, KpStrPtr *str_buf_ptr, int *buf_len_ptr);

/* safely appends byte out_chr to the string buffer *str_buf_ptr */
extern void kp_append_chr(const uchar out_chr, KpStrPtr *str_buf_ptr, int *buf_len_ptr);


// -------------------------
#ifdef __cplusplus

// -------------------------
// TODO: kelt į KpPlainStr klasę?
extern size_t strlen(const KpStrPtr src);

extern KpStrPtr strcpy(KpStrPtr dest, const KpStrPtr src);
extern KpStrPtr strcpy(KpStrPtr dest, const char *src);

extern KpStrPtr strncpy(KpStrPtr dest, const KpStrPtr src, size_t nbytes);

extern KpStrPtr strcat(KpStrPtr dest, const KpStrPtr src);
extern KpStrPtr strcat(KpStrPtr dest, const char *src);

extern KpStrPtr strchr(KpStrPtr p_pszString, KpChar p_iCh);
extern const KpStrPtr strchr(const KpStrPtr p_pszString, KpChar p_iCh);

extern KpStrPtr strstr(KpStrPtr p_pszString, const char *p_pszPattern);
extern const KpStrPtr strstr(const KpStrPtr p_pszString, const char *p_pszPattern);
extern KpStrPtr strstr(KpStrPtr p_pszString, const KpStrPtr p_pszPattern);
extern const KpStrPtr strstr(const KpStrPtr p_pszString, const KpStrPtr p_pszPattern);

extern int strcmp(const KpStrPtr str1, const KpStrPtr str2);
extern int strcmp(const KpStrPtr str1, const char *str2);

extern int strncmp(const KpStrPtr str1, const KpStrPtr str2, size_t nbytes);

#ifndef HAVE_STRLWR
extern char *strlwr(char *str);
#endif
extern KpStrPtr strlwr(KpStrPtr str);


// ------------------------- string
class KpString : public string
{
public:
    KpString () : string() {}
    KpString (const KpStrPtr lpszStr) : string((const char *)lpszStr) {}
    KpString (string sStr) : string(sStr) {}
    KpString& operator=(const KpStrPtr lpszRight) { string::operator=((const char *)lpszRight); return *this; }
    KpString& operator=(const string& sRight) { string::operator=(sRight); return *this; }

    operator KpStrPtr() { return c_str(); }
    operator const char *() { return string::c_str(); }

    KpStrPtr c_str() { return (KpStrPtr)string::c_str(); }

    // trim from start
    static KpString &ltrim(KpString &s);
    // trim from end
    static KpString &rtrim(KpString &s);
    // trim from both ends
    static KpString &trim(KpString &s) { return ltrim(rtrim(s)); }

    /* Suskaldo stringą į stringų masyvą ties skirtukais
    * @param[in] pszDelim – skirtukas, ties kuriuo skaldoma eilutė
    * @param[in] this – eilutė, kurią reikia suskaldyti
    * @param[out] saOutArr – suskaldytų eilučių masyvas
    */
    void Split(const KpStrPtr pszDelim, vector<KpString>& saOutArr);
    void Split(const char *pszDelim, vector<KpString>& saOutArr) { Split((const KpStrPtr)pszDelim, saOutArr); }

    /* Apjungia stringų masyvą į vieną eilutę
    * @param[in] saStrArr – gabalai, kuriuos reikia apjungti
    * @param[in] this – jungtukas, kuris įterpiamas tarp visų apjungiamų elementų
    * @result – apjungta eilutė
    */
    KpString Join(const vector<KpString>& saStrArr);
};


// ------------------------- UTF-8 functions
// compares UTF-8 strings using certain sorting order
// TODO: accented letters are treated as normal, and Y treated as I
// p_bSkipSpc - ignore all spaces
// TODO: p_iSortLng - letter order (look envir.h for SortMode)
// p_bCaseSens - case sensitivity flag
// TODO: p_bCaseSens for UTF-8
// TODO: if p_bRoundFlg == False, accented letters and Y are theyr own wage and are sorted separatelly
// 0: p_pszStr1 == p_pszStr2
// 1: p_pszStr1 > p_pszStr2
// -1: p_pszStr1 > p_pszStr2
extern int UcStrCmp(const KpStrPtr p_pszStr1, const KpStrPtr p_pszStr2, bool p_bSkipSpc,
    int p_iSortLng, bool p_bCaseSens, bool p_bRoundFlg);

// -------------------------
// TODO: kelt į KpPlainStr klasę
extern void KpStripTrailing(KpStrPtr pszString, /* const */ KpStrPtr pszSpcs = pszSpcEol); // numeta tarpus gale // former CutTrailSpcs
extern void KpStripLeading(KpStrPtr pszString, /* const */ KpStrPtr pszSpcs = pszSpcEol); // numeta tarpus pradžioj
extern void KpStrip(KpStrPtr pszString, /* const */ KpStrPtr pszSpcs = pszSpcEol); // numeta tarpus pradžioj ir gale
extern void KpStripAll(KpStrPtr pszString, /* const */ KpStrPtr pszSpcs = pszSpcEol); // išmeta visus tarpus

extern void KpObfuscate(uchar *p_lpszString); // keičia visus eol į tarpus


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
