/* -----------------------------------------------
 *
 * kpstdlib.h
 *
 *    common definitions for all KpLib driven projects
 *
 * 2013-02-22  mp  initial creation
 *
 */

#ifndef kpstdlib_included
#define kpstdlib_included



// ========================================= kptt
#ifndef __WIN32__
// typedef char CHAR;
// typedef unsigned char UCHAR;
typedef unsigned long DWORD;
#endif
typedef unsigned char uchar;

// ------------------------------
#define Nul ((uchar)0)
#define Soh ((uchar)1)
#define Stx ((uchar)2)
#define Etx ((uchar)3)
#define Eot ((uchar)4)
#define Enq ((uchar)5)
#define Ack ((uchar)6)
#define Bel ((uchar)7)
#define Bs  ((uchar)('\b'))
#define Ht  ((uchar)('\t'))
#define Tab Ht
#define Lf  ((uchar)('\n'))
#define Vt ((uchar)('\v'))
#define Ff ((uchar)('\f'))
#define Cr ((uchar)('\r')) // 0x0D
#define So  ((uchar)016)
#define Si  ((uchar)017)
#define Dle ((uchar)020)
#define Dc1 ((uchar)021)
#define Dc2 ((uchar)022)
#define Dc3 ((uchar)023)
#define Dc4 ((uchar)024)
#define Nak ((uchar)025)
#define Syn ((uchar)026)
#define Etb ((uchar)027)
#define Can ((uchar)030)
#define Em  ((uchar)031) // 0x19
#define Sub ((uchar)032)
#define Esc ((uchar)033)
#define Fs  ((uchar)034)
#define Gs  ((uchar)035)
#define Rs  ((uchar)036)
#define Us  ((uchar)037)
#define Spc ((uchar)(' '))


// ----------------------------------
// TODO: apjungti abejus kalbø kodus

// ----------------------------------
// Languages for messages
// #define MsgLang â€“ constant defined during compilation 

typedef enum
{
   KpLangNo    = -1, // -1 - neapibrÄ—Å¾ta - iMsgLangOff nustatom Ä¯ KpLangEn 
#define KpLangNo_p   (-1)
   
   KpLangEn,         // 0 - anglÅ³
#define KpLangEn_p   0
   KpLangLt,         // 1 - lietuviÅ³
#define KpLangLt_p   1
   KpLangPl_1250,    // 2 - lenkÅ³ Central European
#define KpLangPl_1250_p 2
   KpLangPl_1257,    // 3 - lenkÅ³ Windows Baltic
#define KpLangPl_1257_p 3
   KpLangRu_1251,    // 4 - rusÅ³
#define KpLangRu_1251_p 4
   KpLangRu_0,       // 5 - rusÅ³ su angliÅkais mygtukÅ³ tekstais â€“ kai regional Settings ne rusiÅki
#define KpLangRu_0_p 5

   KpNumOfLangs,
#define KpNumOfLangs_p 6

   KpLangRu    = 97, // 97 - iÅsitraukti iÅ registro Regional Setting'Å³ â€“ KpLangRu_0 arba KpLangRu_1251 (jei rusiÅki)
#define KpLangRu_p   97
   KpLangPl    = 98, // 98 - iÅsitraukti iÅ registro Regional Setting'Å³ â€“ KpLangPl_1250 arba KpLangPl_1257 (jei lietuviÅki/Baltic)
#define KpLangPl_p   98
   KpLangSel,        // 99 - iÅsitraukti iÅ registro Regional Setting'Å³
#define KpLangSel_p  99

} KpLang;

#define KpNumOfLangs_2 KpNumOfLangs // masyvÅ³ riboms, padidinti kiekvienÄ… kartÄ…, pasikeitus kalbÅ³ skaiÄiui


// ----------------------------------
// Languages for SortMode
#define KP_LNG_LIT ('l')       // lithuanian, former TV_XE_LIT, (former #define Lit 1)
#define KP_LNG_LIX ('x')       // lithuanian sorting regardless of diacrytics, i.e., è==c, ð==s, þ==z (for lzdsh.exe and main index generation)
#define KP_LNG_LIS ('s')       // lithuanian straigth sorting according to exact weights (for irregular form table generator - tvxmlecm.exe)
#define KP_LNG_ENG ('e')       // english, former TV_XE_ENG, (former #define Eng 0)
#define KP_LNG_GER ('v')       // german, former TV_XE_GER, former 'g'
#define KP_LNG_FRE ('f')       // french, former KP_LNG_FRA, TV_XE_FRA
#define KP_LNG_RUS ('r')       // russian, former TV_XE_RUS
#define KP_LNG_POL ('p')       // polish
#define KP_LNG_LAT ('n')       // latin

#define KP_LNG_NO  ('-')       // not applicable: text without any language specified, former TV_XE_NO
#define KP_LNG_UP  ('^')       // xml tags: language of the father tag should be inherited
#define KP_LNG_NA  ('@')       // not applicable: text not allowed; used for xml tags, excluded from index creation or non-text tags


// ========================================= KpLib 
// KpLib initialization/destruction procedures for plain C projects
#ifdef __cplusplus
#define PLAIN_C "C"
#else 
#define PLAIN_C
#endif

extern PLAIN_C void KpInit(const uchar *ProdName, const void *pStackTop);  // pStackTop â€“ caller stack top pointer, 
extern PLAIN_C void KpClose(void);                  // usually pointer to some local variable of the main() function
                                                    // could be NULL

// ========================================= data types
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE (!FALSE)
#endif

#define True ((bool)TRUE)
#define False ((bool)FALSE)

#ifdef __MINGW32__
#define va_list __VALIST 
#else
#   ifdef __GNUC__
#define va_list __gnuc_va_list 
#   endif
#endif
#ifndef va_start
#define va_start __builtin_va_start
#endif

#ifndef WIN32
typedef unsigned long HINSTANCE;
typedef long LONG;
#endif


//--------------------------- pointer processing
typedef void (*FuncPtr)(void);    /* funkcijos rodykles tipas */ // former Funpnt
#define Null ((FuncPtr)0)         /* nuline funkcijos rodykle */

typedef int (*CompareFuncPtr)(const void *pVal1, const void *pVal2);
      // lyginimo funkcijos rodyklÄ—s tipas, parametrai â€“ lyginamÅ³ objektÅ³ adresai
      // naudojama, pvz., SearchTreeEntry(); pvz. â€“ TvStrCmpStrict_(), KpCompareLong()
      // 0: *pVal1 == *pVal2
      // 1: *pVal1 > *pVal2
      // -1: *pVal1 > *pVal2

typedef int (*ComparePtrFuncPtr)(const void *ppVal1, const void *ppVal2);
      // lyginimo funkcijos rodykles tipas, parametrai - lyginamÅ³ objektÅ³ adresÅ³ adresai
      // pvz. â€“ TvStrPtrCmpStrict(), TvStrPtrCmpStrictRev()
      // 0: **ppVal1 == **ppVal2
      // 1: **ppVal1 > **ppVal2
      // -1: **ppVal1 > **ppVal2

// ========================================= file I/O
#define KP_MAX_FNAME_LEN 260 // MAX_PATH        // negalima keist/naudot neaiÅkios makrokomandos â€“ pasikeis kpstart.ini dydis
#define KP_MAX_FTYPE_LEN KP_MAX_FNAME_LEN // 4  // negalima keist â€“ pasikeis kpstart.ini dydis
#define KP_MAX_FILE_LIN_LEN 4096
#ifdef __WIN32__
#define KP_DIR_SEP '\\'
#define KP_DIR_SEP_STR (const uchar *)"\\"
#define KP_EXE_EXT (const uchar *)"exe"
#else
#define KP_DIR_SEP '/'
#define KP_DIR_SEP_STR (const uchar *)"/"
#define KP_EXE_EXT (const uchar *)""
#endif
#define KP_EXT_SEP '.'
#define KP_EXT_SEP_STR (const uchar *)"."
#define KP_CUR_DIR_STR (const uchar *)"."

// ========================================= malloc
#ifdef __cplusplus

#ifdef KP_ALLOC_TRACE
#define KP_ALLOC_SAFE
#endif

// -------------------------------------
// memory allocation control
// checks duplicate entries, deleting of non existing objects

#ifdef KP_ALLOC_SAFE

// entry of allocated object pointer
typedef struct
{
   const void *m_pAddress;
   bool m_bArrayFl;
} KpHeapEntry;

#define KP_HEAP_SIZE 10000 // size of heap pointers array; max number of simultaneously created objects

// heap testing class
class KpHeapClass
{
KpHeapEntry m_KpHeapArray[KP_HEAP_SIZE]; // array of currently allocated objects addresses
int m_iCurKpHeapIx; // current number of KpHeapArray elements

   int SearchHeapEntry(const void *pPtr); // -1 â€“ did not find

public:
   KpHeapClass(void)
   {
      m_iCurKpHeapIx = 0;
   }

   void InsertHeapPtr(const void *pNewPtr, bool bArrayFl); // called by KP_NEW()
   HRESULT RemoveHeapPtr(const void *pDelPtr, bool bArrayFl); // called by KP_DELETE()
};

extern KpHeapClass KpHeap;

#endif // #ifdef KP_ALLOC_SAFE


// -------------
#ifdef KP_ALLOC_SAFE
#define KP_ALLOC_CHECK_DOUBLE_CALL(ptr) {{ KP_ASSERTW0((ptr) == NULL, KP_E_DOUBLE_CALL, null); }}
#define KP_ALLOC_INSERT_HEAP_PTR(ptr, arr_fl) {{ KpHeap.InsertHeapPtr(ptr, arr_fl); }}
#define KP_ALLOC_CHECK_REMOVE_HEAP_PTR(ptr, arr_fl) if (SUCCEEDED(KpHeap.RemoveHeapPtr(ptr, arr_fl)))
#else
#define KP_ALLOC_CHECK_DOUBLE_CALL(ptr)
#define KP_ALLOC_INSERT_HEAP_PTR(ptr, arr_fl)
#define KP_ALLOC_CHECK_REMOVE_HEAP_PTR(ptr, arr_fl)
#endif

#ifdef KP_ALLOC_TRACE
#define KP_ALLOC_TRACE_NEW_PTR(ptr, op) {{ KpError.PutLogMessage("KpAlloc:\t%08x\t%s\t%s\t%d", ptr, op, __FILE__, __LINE__); }}
#else
#define KP_ALLOC_TRACE_NEW_PTR(ptr, op) {}
#endif

// -------------------------------------
// object allocation
// KP_NEW(void &*ptr, (*constr)())
//    creates new object by calling the constructor constr
//    assigns new allocated object pointer to ptr
#define KP_NEW(ptr, constr) \
   {{ \
      KP_ALLOC_CHECK_DOUBLE_CALL(ptr); \
      (ptr) = new constr; \
      KP_ASSERT((ptr), KP_E_OUTOFMEM, null); \
      KP_ALLOC_TRACE_NEW_PTR(ptr, "new"); \
      KP_ALLOC_INSERT_HEAP_PTR(ptr, False); \
   }}

// without consistency check
#define KP_NEW0(ptr, constr) \
   {{ \
      KP_ALLOC_CHECK_DOUBLE_CALL(ptr); \
      (ptr) = new constr; \
      KP_ASSERT((ptr), KP_E_OUTOFMEM, null); \
   }}

// -------------------------------------
// object deleting
// KP_DELETE(void &*ptr)
//    if ptr != NULL deletes *ptr and clears ptr
#define KP_DELETE(ptr) \
   {{ \
      if (ptr) \
      { \
         KP_ALLOC_TRACE_NEW_PTR(ptr, "del"); \
         KP_ALLOC_CHECK_REMOVE_HEAP_PTR(ptr, False) delete (ptr); \
         (ptr) = NULL; \
	  } \
   }}

// without consistency check
#define KP_DELETE0(ptr) \
   {{ \
      if (ptr) \
      { \
         delete (ptr); \
         (ptr) = NULL; \
	  } \
   }}

// -------------------------------------
// array allocation
// KP_NEWA(void &ptr[], <scalar type>, int count)
//    creates new array
//    assigns new allocated array pointer to ptr
#define KP_NEWA(ptr, type, count) \
   {{ \
      KP_ALLOC_CHECK_DOUBLE_CALL(ptr); \
      (ptr) = new type[count]; \
      KP_ASSERT((ptr), KP_E_OUTOFMEM, null); \
      KP_ALLOC_TRACE_NEW_PTR(ptr, "new[]"); \
      KP_ALLOC_INSERT_HEAP_PTR(ptr, True); \
   }}


// -------------------------------------
// array deleting
// KP_DELETE(void &ptr[])
//    if ptr != NULL deletes *ptr and clears ptr
#define KP_DELETEA(ptr) \
   {{ \
      if (ptr) \
      { \
         KP_ALLOC_TRACE_NEW_PTR(ptr, "del[]"); \
         KP_ALLOC_CHECK_REMOVE_HEAP_PTR(ptr, True) delete [] (ptr); \
         (ptr) = NULL; \
	  } \
   }}

#endif // #ifdef __cplusplus


// ================================================== integer types and constants, math
#define MAX_UCHAR 0xFF
#ifndef __WIN32__
#define MAX_INT 0x7FFFFFFF // INT_MAX
#endif
#define MAX_LONG_HEX_DIGITS 8 /* num. of hex digits of MAXLONG */
#define MAX_LONG_DIGITS 11 /* num. of decimal digits of MAXLONG */

#define MAX_FLT (3.40282e+38) // FLT_MAX

// formats p_iVal as 16 bytes binary string
// p_lpszBinStrBuf[16 + 1]
void I2BinStr(uchar *p_lpszBinStrBuf, int p_iVal);  


// ================================================== searching and sorting
#define KP_KWD_LEN 400 // negalima keist – pasikeis susijusiø failø layout


// ----------------------------------------
#endif // #ifndef kpstdlib_included
