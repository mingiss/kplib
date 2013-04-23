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
#ifndef WIN32
typedef char CHAR;
typedef unsigned char UCHAR;
typedef unsigned long DWORD;
#endif
#define Nul ((UCHAR)0)
#define Spc ((UCHAR)(' '))

// ----------------------------------
// Languages for messages
// #define MsgLang – constant defined during compilation 

typedef enum
{
   KpLangNo    = -1, // -1 - neapibrėžta - iMsgLangOff nustatom į KpLangEn 
#define KpLangNo_p   (-1)
   
   KpLangEn,         // 0 - anglų
#define KpLangEn_p   0
   KpLangLt,         // 1 - lietuvių
#define KpLangLt_p   1
   KpLangPl_1250,    // 2 - lenkų Central European
#define KpLangPl_1250_p 2
   KpLangPl_1257,    // 3 - lenkų Windows Baltic
#define KpLangPl_1257_p 3
   KpLangRu_1251,    // 4 - rusų
#define KpLangRu_1251_p 4
   KpLangRu_0,       // 5 - rusų su angliškais mygtukų tekstais – kai regional Settings ne rusiški
#define KpLangRu_0_p 5

   KpNumOfLangs,
#define KpNumOfLangs_p 6

   KpLangRu    = 97, // 97 - išsitraukti iš registro Regional Setting'ų – KpLangRu_0 arba KpLangRu_1251 (jei rusiški)
#define KpLangRu_p   97
   KpLangPl    = 98, // 98 - išsitraukti iš registro Regional Setting'ų – KpLangPl_1250 arba KpLangPl_1257 (jei lietuviški/Baltic)
#define KpLangPl_p   98
   KpLangSel,        // 99 - išsitraukti iš registro Regional Setting'ų
#define KpLangSel_p  99

} KpLang;

#define KpNumOfLangs_2 KpNumOfLangs // masyvų riboms, padidinti kiekvieną kartą, pasikeitus kalbų skaičiui


// ========================================= KpLib 
// KpLib initialization/destruction procedures for plain C projects
#ifdef __cplusplus
#define PLAIN_C "C"
#else 
#define PLAIN_C
#endif

extern PLAIN_C void KpInit(const UCHAR *ProdName, const void *pStackTop);  // pStackTop – caller stack top pointer, 
extern PLAIN_C void KpClose(void);                  // usually pointer to some local variable of the main() function
                                                    // could be NULL

// ========================================= data types
#ifndef TRUE
#define TRUE (~0)
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define True ((bool)TRUE)
#define False ((bool)FALSE)

#ifdef __MINGW32__
#define va_list __VALIST 
#endif
#ifdef __GNUC__
#define va_list __gnuc_va_list 
#endif
#ifndef va_start
#define va_start __builtin_va_start
#endif

#ifndef WIN32
typedef unsigned long HINSTANCE;
typedef long LONG;
#endif


// ========================================= file I/O
#define KP_MAX_FNAME_LEN 260 // MAX_PATH        // negalima keist/naudot neaiškios makrokomandos – pasikeis kpstart.ini dydis
#define KP_MAX_FTYPE_LEN KP_MAX_FNAME_LEN // 4  // negalima keist – pasikeis kpstart.ini dydis
#define KP_MAX_FILE_LIN_LEN 4096


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

   int SearchHeapEntry(const void *pPtr); // -1 – did not find

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
#define KP_ALLOC_CHECK_REMOVE_HEAP_PTR(ptr, arr_fl) if(SUCCEEDED(KpHeap.RemoveHeapPtr(ptr, arr_fl)))
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
      KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null); \
      KP_ALLOC_TRACE_NEW_PTR(ptr, "new"); \
      KP_ALLOC_INSERT_HEAP_PTR(ptr, False); \
   }}

// -------------------------------------
// object deleting
// KP_DELETE(void &*ptr)
//    if ptr != NULL deletes *ptr and clears ptr
#define KP_DELETE(ptr) \
   {{ \
      if((ptr) != NULL) \
      { \
         KP_ALLOC_TRACE_NEW_PTR(ptr, "del"); \
         KP_ALLOC_CHECK_REMOVE_HEAP_PTR(ptr, False) delete (ptr); \
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
      KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null); \
      KP_ALLOC_TRACE_NEW_PTR(ptr, "new[]"); \
      KP_ALLOC_INSERT_HEAP_PTR(ptr, True); \
   }}


// -------------------------------------
// array deleting
// KP_DELETE(void &ptr[])
//    if ptr != NULL deletes *ptr and clears ptr
#define KP_DELETEA(ptr) \
   {{ \
      if((ptr) != NULL) \
      { \
         KP_ALLOC_TRACE_NEW_PTR(ptr, "del[]"); \
         KP_ALLOC_CHECK_REMOVE_HEAP_PTR(ptr, True) delete [] (ptr); \
         (ptr) = NULL; \
	  } \
   }}

#endif // #ifdef __cplusplus


// ================================================== integer types and constants, math
#define MAX_LONG_HEX_DIGITS 8 /* num. of hex digits of MAXLONG */


// ----------------------------------------
#endif // #ifndef kpstdlib_included
