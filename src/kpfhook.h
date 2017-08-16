/* -----------------------------------------------
 *
 * kpfhook.h
 *
 *    file I/O hook/tracer
 *
 * 2016-09-07  mp  split from kpstdio
 *
 */

#ifndef KPFHOOK_INCLUDED
#define KPFHOOK_INCLUDED

// ------------------------ opcijos
// #define KPSTDIO_FULL_LOG // former TEXTRC_FULL_LOG


// ------------------------
#define KP_LOG_EXT ((const uchar *)".log")
#define KPTRC_LOG_SUFF ((const uchar *)".kptrc") // log file extension // former TEXTRC_LOG_EXT ".textrc"


// --------------------------------------
// PLAIN_C wrapperiai į KpFileDesc ir KpFileDescList (*KpFileDescListPtr) metodus

#define KPADD_FOPEN(fname, fmode) kpadd_fopen(fname, fmode, __FILE__, __LINE__)
#define KPADD_WFOPEN(fname, fmode) kpadd_wfopen(fname, fmode, __FILE__, __LINE__)
#define KPADD_FDOPEN(fname, fd, fmode) kpadd_fdopen(fname, fd, fmode, __FILE__, __LINE__)
#define KPADD_OPEN(file, flag, mode) kpadd_open(file, flag, mode, __FILE__, __LINE__)
#define KPADD_WOPEN(file, flag, mode) kpadd_wopen(file, flag, mode, __FILE__, __LINE__)
#define KPADD_CreateFileA(file, access, share_mode, attrs, cr_disp, flags, temp_file) \
    kpadd_CreateFileA(file, access, share_mode, attrs, cr_disp, flags, temp_file, __FILE__, __LINE__)
#define KPADD_CreateFileW(file, access, share_mode, attrs, cr_disp, flags, temp_file) \
    kpadd_CreateFileW(file, access, share_mode, attrs, cr_disp, flags, temp_file, __FILE__, __LINE__)
#ifdef UNICODE
#define KPADD_CreateFile(file, access, share_mode, attrs, cr_disp, flags, temp_file) \
    kpadd_CreateFileW(file, access, share_mode, attrs, cr_disp, flags, temp_file, __FILE__, __LINE__)
#else
#define KPADD_CreateFile(file, access, share_mode, attrs, cr_disp, flags, temp_file) \
    kpadd_CreateFileA(file, access, share_mode, attrs, cr_disp, flags, temp_file, __FILE__, __LINE__)
#endif
#define KPADD_FOPEN_CHKIN(fhandle, fname, fmode) kpadd_fopen_chkin(fname, \
    kpadd_fmode_to_flags(fmode), fhandle, NO_FILE_DESC, NULL, __FILE__, __LINE__)

#define KPADD_FCLOSE(fh) kpadd_fclose(fh, __FILE__, __LINE__)
#define KPADD_CLOSE(fd) kpadd_close(fd, __FILE__, __LINE__)
#define KPADD_CloseHandle(fh) kpadd_CloseHandle(fh, __FILE__, __LINE__)    

#define KPADD_FCLOSE_CHKIN(fhandle) kpadd_fclose_chkin(fhandle, NO_FILE_DESC, NULL, __FILE__, __LINE__)
// #define KPADD_FGETC(fname, fmode) kpadd_fgetc(fname, fmode, __FILE__, __LINE__)

// converts fopen() style mode string to open() style flags
extern PLAIN_C KPADDSHARED int kpadd_fmode_to_flags(const uchar *p_lpszOpenMode);
// converts _wfopen() style mode string to open() style flags
extern int kpadd_wfmode_to_flags(const wchar_t *p_lpwszOpenMode);
// converts CreateFile() dwDesiredAccess parameter to open() style flags
extern int kpadd_acc_to_flags(DWORD p_dwDesiredAccess);
// creates fopen() style mode string from open() flags parameter
// returned string should be free()'ed after use
extern uchar *kpadd_open_flags_to_str(int p_iFlags);

// input failo atidarymo hookai; sukuria nauja KpFileDesc objektą ir 
//      įtraukia i KpFileDescListPtr->m_pFileList
// fopen() wrapper
extern PLAIN_C KPADDSHARED FILE *kpadd_fopen(
    const char *p_lpszFname, const char *p_lpszOpenMode, 
    const char *p_lpszSrcFile, int p_iSrcLine);
// _wfopen() wrapper    
extern PLAIN_C KPADDSHARED FILE *kpadd_wfopen( 
    const wchar_t *p_lpwszFname, const wchar_t *p_lpwszOpenMode, 
    const char *p_lpszSrcFile, int p_iSrcLine);
// fdopen()/_fdopen() wrapper
extern PLAIN_C KPADDSHARED FILE *kpadd_fdopen(
    const char *p_lpszFname, int p_iFileDesc, const char *p_lpszOpenMode, 
    const char *p_lpszSrcFile, int p_iSrcLine);
// open()/_open() wrapper
extern PLAIN_C KPADDSHARED int kpadd_open(
    const char *p_lpszFname, int p_iFlags, int p_iPerm, 
    const char *p_lpszSrcFile, int p_iSrcLine);
// _wopen() wrapper
extern PLAIN_C KPADDSHARED int kpadd_wopen(
    const wchar_t *p_lpwszFname, int p_iFlags, int p_iPerm, 
    const char *p_lpszSrcFile, int p_iSrcLine);
#ifdef __WIN32__
// CreateFile() wrappers    
extern PLAIN_C KPADDSHARED HANDLE kpadd_CreateFileA(const char *p_lpFileName,
    DWORD p_dwDesiredAccess, DWORD p_dwShareMode, LPSECURITY_ATTRIBUTES p_lpSecurityAttributes,
    DWORD p_dwCreationDisposition, DWORD p_dwFlagsAndAttributes, HANDLE p_hTemplateFile,
    const char *p_lpszSrcFile, int p_iSrcLine);
extern PLAIN_C KPADDSHARED HANDLE kpadd_CreateFileW(const wchar_t *p_lpFileName,
    DWORD p_dwDesiredAccess, DWORD p_dwShareMode, LPSECURITY_ATTRIBUTES p_lpSecurityAttributes,
    DWORD p_dwCreationDisposition, DWORD p_dwFlagsAndAttributes, HANDLE p_hTemplateFile,
    const char *p_lpszSrcFile, int p_iSrcLine);
#endif
// KpFileDesc objekto įtraukimas į KpFileDescListPtr->m_pFileList
extern PLAIN_C KPADDSHARED void kpadd_fopen_chkin(const char *p_lpszFname, int p_iFlags,
    /* const */ FILE *p_pFile /* = NULL */, int p_iFileDesc /* = NO_FILE_DESC */, HANDLE p_hFile /* = NULL */, 
    const char *p_lpszSrcFile, int p_iSrcLine);
extern PLAIN_C KPADDSHARED void kpadd_wfopen_chkin(const wchar_t *p_lpwszFname, int p_iFlags,
    /* const */ FILE *p_pFile /* = NULL */, int p_iFileDesc /* = NO_FILE_DESC */, HANDLE p_hFile /* = NULL */, 
    const char *p_lpszSrcFile, int p_iSrcLine);
    
// failo uždarymo hookai; naikina KpFileDescListPtr->m_pFileList objektą
// fclose() wrapper
extern PLAIN_C KPADDSHARED int kpadd_fclose(FILE *p_pFile, 
    const char *p_lpszSrcFile, int p_iSrcLine);
// tikslus fopen() wrapperis pakišimui vietoj fopen() adreso 
// Python: Objects/fileobject.c: PyFile_FromFile(), fill_file_fields(), PyFileObject::f_close 
extern PLAIN_C KPADDSHARED int kpadd_fclose_plain(FILE *p_pFile); 
// close()/_close() wrapper
extern PLAIN_C KPADDSHARED int kpadd_close(int p_iFileDesc, 
    const char *p_lpszSrcFile, int p_iSrcLine);
#ifdef __WIN32__
// CloseHandle() wrapper    
extern PLAIN_C KPADDSHARED BOOL kpadd_CloseHandle(HANDLE p_hFile,
    const char *p_lpszSrcFile, int p_iSrcLine);    
#endif
// KpFileDesc objekto naikinimas iš KpFileDescListPtr->m_pFileList
extern PLAIN_C KPADDSHARED void kpadd_fclose_chkin(
    const FILE *p_pFile /* = NULL */, int p_iFileDesc /* = NO_FILE_DESC */, HANDLE p_hFile /* = NULL */,
    const char *p_lpszSrcFile, int p_iSrcLine);


// --------------------------
#ifdef __cplusplus

// --------------------------
// failų aprašų klasės
// naudojamos luatex ir python failų I/O hookinimui

// failo aprašo objekto klasė
class KpFileDesc
{
public:
/* const */ FILE *m_pFile; // in case the file is fopen()'ed or fdopen()'ed
int m_iFileDesc; // in case the file is open()'ed
HANDLE m_hFile; // in case the file is CreateFile()'ed
uchar m_lpszFileName[KP_MAX_FNAME_LEN + 1];
int m_iFlags; // open()/_open() style flags

#ifdef KPSTDIO_FULL_LOG
uchar m_lpszLogFileName[KP_MAX_FNAME_LEN + 1];
#endif

int m_iCurLine; // current line number 1..n
int m_iCurLpos; // current line byte position

    KpFileDesc(void)  { InitMembers(); }
    KpFileDesc(const uchar *p_lpszFileName, int p_iFlags,
        /* const */ FILE *p_pFile /* = NULL */, int p_iFileDesc /* = NO_FILE_DESC */, HANDLE p_hFile /* = NULL */);
    virtual void InitMembers(void);

    virtual void PullData(const KpFileDesc *p_pDescObj); // kopijuoja duomenis iš *p_pDescObj į *this

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
    virtual KpFileDesc *KpFileDescFactory(const uchar *p_lpszFileName, int p_iFlags,
        /* const */ FILE *p_pFile /* = NULL */, int p_iFileDesc /* = NO_FILE_DESC */, HANDLE p_hFile /* = NULL */);

    // įtraukia naują failą i m_pFileList
    void RegNewFile(const uchar *p_lpszFileName, int p_iFlags, 
        /* const */ FILE *p_pFile /* = NULL */, int p_iFileDesc /* = NO_FILE_DESC */, HANDLE p_hFile /* = NULL */);
    void RegNewFile(const char *p_lpszFileName, int p_iFlags,
        /* const */ FILE *p_pFile, int p_iFileDesc, HANDLE p_hFile)
        { RegNewFile((const uchar *)p_lpszFileName, p_iFlags, p_pFile, p_iFileDesc, p_hFile); }

    // perrašo m_pFileList įrašą naujais duomenim
    // susiranda pagal p_pDescObj->m_pFile
    void UpdateFile(const KpFileDesc *p_pDescObj);

    // TODO: išmeta uždarytą failo deskriptorių is sąrašo m_pFileList
    void DelFile(const FILE *p_pFile /* = NULL */, int p_iFileDesc /* = NO_FILE_DESC */, HANDLE p_hFile /* = NULL */);
        
    // ieško p_pFile atitinkančio m_pFileList įrašo
    // NULL -- nerado
    // *pppNodePtr (jei ppNodePtr != NULL) grąžina rasto elemento rodyklės adresą, 
    //      kad tą rodyklę būtų galima pakoreguoti, pvz., elementą po to išmetant su DelFile()
    //      *pppNodePtr rodo i rasto elemento tėvo lauką m_pFirstChild arba į m_pFileList (vyriausio tėvo atveju) 
    //      nesekmės atveju *pppNodePtr rodo į jauniausio anūko m_pFirstChild, kurio reikšmė yra NULL
    // ieško pagal m_pFileList[].GetValue()->m_pFile
    KpFileDesc *FindFile(const FILE *p_pFile, KpTreeEntry<KpFileDesc> ***pppNodePtr = NULL); 
    // ieško pagal m_pFileList[].GetValue()->m_iFileDesc
    KpFileDesc *FindFileByDesc(int p_iFileDesc, KpTreeEntry<KpFileDesc> ***pppNodePtr = NULL); 
    // ieško pagal m_pFileList[].GetValue()->m_hFile
    KpFileDesc *FindFileByHandle(HANDLE p_hFile, KpTreeEntry<KpFileDesc> ***pppNodePtr = NULL); 
                                            
    // rašo pranešimą į p_pFile elemento m_lpszLogFileName
#ifdef KPSTDIO_FULL_LOG
    void PutLogMessage(const FILE *p_pFile, const uchar *p_lpszFmt, va_list p_Args);
    void PutLogMessage(const FILE *p_pFile, const char *p_lpszFmt, va_list p_Args) 
        { PutLogMessage(p_pFile, (const uchar *)p_lpszFmt, p_Args); }
    void PutLogMessage(const FILE *p_pFile, const uchar *p_lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, p_lpszFmt);
        PutLogMessage(p_pFile, p_lpszFmt, argptr);
    }
    void PutLogMessage(const FILE *p_pFile, const char *p_lpszFmt, ...)
    {
va_list argptr;
        va_start(argptr, p_lpszFmt);
        PutLogMessage(p_pFile, p_lpszFmt, argptr);
    }
#endif

};


// pointer to the global KpFileDescList object
extern KpFileDescList *KpFileDescListPtr;


#endif // #ifdef __cplusplus

#endif // #ifndef KPFHOOK_INCLUDED

