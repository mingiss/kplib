/* -----------------------------------------------
 *
 * kpstdio.h
 *
 *    I/O tools
 *
 * 2013-04-04  mp  initial creation
 *
 */

#ifndef KPSTDIO_INCLUDED
#define KPSTDIO_INCLUDED

// ------------------------ opcijos
// #define KPSTDIO_FULL_LOG // former TEXTRC_FULL_LOG

// ------------------------
#define KP_LOG_EXT ((const uchar *)".log")
#define KPTRC_LOG_SUFF ((const uchar *)".kptrc") // log file extension // former TEXTRC_LOG_EXT ".textrc"

// --------------------------
extern PLAIN_C void FnameSplit // call to KpStdIo::TvFnameSplit()
(
    uchar *lpszDiskBuf,
    uchar *lpszPathBuf,
    uchar *lpszFNameBuf,
    uchar *lpszFTypeBuf,
    const uchar *lpszFullName
);

// --------------------------
#ifdef __cplusplus

// --------------------------
// failų aprašų klasės
// naudojamos luatex ir python failų I/O hookinimui

// failo aprašo objekto klasė
class KpFileDesc
{
public:
const FILE *m_pFile;
uchar m_lpszFileName[KP_MAX_FNAME_LEN + 1];

#ifdef KPSTDIO_FULL_LOG
uchar m_lpszLogFileName[KP_MAX_FNAME_LEN + 1];
#endif

    KpFileDesc(void);
    KpFileDesc(const FILE *p_pFile, const uchar *p_lpszFileName);
    virtual void InitMembers(void);

    virtual void PullData(const KpFileDesc *pDescObj); // kopijuoja duomenis iš *pDescObj į *this

    // TeXtrcFileDesc: išveda dabartinės eilutės paskutinio simbolio pozicijos pranešimą        
    virtual void LogLastCh(void) {}

    // rašo pranešimą į m_lpszLogFileName
#ifdef KPSTDIO_FULL_LOG
    void PutLogMessage(const uchar *p_lpszFmt, va_list p_Args);
    void PutLogMessage(const char *p_lpszFmt, va_list p_Args) 
        { PutLogMessage((const uchar *)p_lpszFmt, p_Args); }
    void PutLogMessage(const uchar *p_lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, p_lpszFmt);
        PutLogMessage(p_lpszFmt, argptr);
    }
    void PutLogMessage(const char *p_lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, p_lpszFmt);
        PutLogMessage(p_lpszFmt, argptr);
    }
#endif

};


// failų aprašų objektų sąrašo klasė
class KpFileDescList
{
public:
KpTreeEntry<KpFileDesc> *m_pFileList; // list of file descriptors, m_pFileList->m_lpRecord points to KpFileDesc object 

public:
    KpFileDescList(void);
    ~KpFileDescList();

    // kuria naują KpFileDesc (iš KpFileDesc paveldėtą) objektą pridėjimui prie m_pFileList
    // paveldėtos iš KpFileDescList klasės turi perimti šitą metodą, 
    //      jeigu m_pFileList nori naudoti kaip paveldėtų objektų sąrašą 
    virtual KpFileDesc *KpFileDescFactory(const FILE *pFile, const uchar *lpszFileName);

    // įtraukia naują failą i m_pFileList
    void RegNewFile(const FILE *pFile, const uchar *lpszFileName);
    void RegNewFile(const FILE *pFile, const char *lpszFileName) 
        { RegNewFile(pFile, (const uchar *)lpszFileName); }

    // perrašo m_pFileList įrašą naujais duomenim
    // susiranda pagal pDescObj->m_pFile
    void UpdateFile(const KpFileDesc *pDescObj);

    // TODO: išmeta uždarytą failo deskriptorių is sąrašo m_pFileList
    void DelFile(const FILE *pFile);
        
    // ieško pFile atitinkančio m_pFileList įrašo
    // NULL -- nerado
    // *pppNodePtr (jei ppNodePtr != NULL) grąžina rasto elemento rodyklės adresą, 
    //      kad tą rodyklę būtų galima pakoreguoti, pvz., elementą po to išmetant su DelFile()
    //      *pppNodePtr rodo i rasto elemento tėvo lauką m_pFirstChild arba į m_pFileList (vyriausio tėvo atveju) 
    //      nesekmės atveju *pppNodePtr rodo į jauniausio anūko m_pFirstChild, kurio reikšmė yra NULL
    KpFileDesc *FindFile(const FILE *pFile, KpTreeEntry<KpFileDesc> ***pppNodePtr = NULL); 
                                            
    // rašo pranešimą į pFile elemento m_lpszLogFileName
#ifdef KPSTDIO_FULL_LOG
    void PutLogMessage(const FILE *pFile, const uchar *lpszFmt, va_list Args);
    void PutLogMessage(const FILE *pFile, const char *lpszFmt, va_list Args) 
        { PutLogMessage(pFile, (const uchar *)lpszFmt, Args); }
    void PutLogMessage(const FILE *pFile, const uchar *lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, lpszFmt);
        PutLogMessage(pFile, lpszFmt, argptr);
    }
    void PutLogMessage(const FILE *pFile, const char *lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, lpszFmt);
        PutLogMessage(pFile, lpszFmt, argptr);
    }
#endif

};


// --------------------------
// bendro pobūdžio statinės funkcijos
class KpStdIo
{
public:
   static void TvFnameSplit          // splits lpszFullName to file name and file
   (                                 //    type parts lpszFNameBuf, lpszFTypeBuf.
      uchar *lpszDiskBuf,            // lpszDiskBuf, lpszPathBuf and lpszFNameBuf
      uchar *lpszPathBuf,            //    must be not shorter than
      uchar *lpszFNameBuf,           //    KP_MAX_FNAME_LEN + 1 bytes, lpszFTypeBuf
      uchar *lpszFTypeBuf,           //    - not shorter than KP_MAX_FTYPE_LEN + 1
      const uchar *lpszFullName      
   );
};

#endif // #ifdef __cplusplus

#endif // #ifndef KPSTDIO_INCLUDED
