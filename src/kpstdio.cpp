/* ---------------------------------------------------
 *
 * kpstdio.cpp
 *
 *    I/O tools
 *
 * 2013-04-04  mp  initial creation
 * 2013-10-29  mp  KpFileDesc and KpFileDescList split of TeXtrcFileDesc and TeXtrcClass  
 *
 */

// --------------------------------------
#include "envir.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <fcntl.h>
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kptree.h"
#include "kpstdio.h"


void FnameSplit
(
    uchar *p_lpszDiskBuf,
    uchar *p_lpszPathBuf,
    uchar *p_lpszFNameBuf,
    uchar *p_lpszFTypeBuf,
    const uchar *p_lpszFullName
)
{
    KpStdIo::TvFnameSplit(p_lpszDiskBuf, p_lpszPathBuf, p_lpszFNameBuf, p_lpszFTypeBuf, p_lpszFullName);
}


void KpStdIo::TvFnameSplit
(
uchar *p_lpszDiskBuf,
uchar *p_lpszPathBuf,
uchar *p_lpszFNameBuf,
uchar *p_lpszFTypeBuf,
const uchar *p_lpszFullName
)
{
   KP_ASSERT(p_lpszDiskBuf && p_lpszPathBuf && p_lpszFNameBuf &&
      p_lpszFTypeBuf && p_lpszFullName, E_INVALIDARG, null);

   KP_ASSERT(strlen(p_lpszFullName) < KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, p_lpszFullName);

uchar str_buf[KP_MAX_FNAME_LEN + 1];
   strcpy(str_buf, p_lpszFullName);

uchar *disk_ptr;
uchar *path_ptr;
uchar *fnam_ptr;
uchar *typ_ptr;
uchar *pnts;
   disk_ptr = pnts = path_ptr = fnam_ptr = typ_ptr = str_buf;

   do
   {
      if (*pnts == ':') path_ptr = pnts + 1;
      if ((*pnts == '\\') || (*pnts == '/')) fnam_ptr = pnts + 1;
      if (*pnts == '.') typ_ptr = pnts;
      pnts++;
   } while (*pnts);

// type
   if (typ_ptr <= fnam_ptr) typ_ptr=(uchar *)"";
   else *(typ_ptr++) = Nul;
   
   KP_ASSERT(strlen(typ_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(p_lpszFTypeBuf, typ_ptr);

// fname
   if (fnam_ptr < path_ptr) fnam_ptr = path_ptr;
   KP_ASSERT(strlen(fnam_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(p_lpszFNameBuf, fnam_ptr);

// path
   if (fnam_ptr == path_ptr) strcpy(p_lpszPathBuf, KP_CUR_DIR_STR);
   else /* if (fnam_ptr > path_ptr) */
   {
      *fnam_ptr-- = Nul;
      if ((*fnam_ptr=='\\') || (*fnam_ptr=='/')) *fnam_ptr = Nul;
      else KP_THROW(KP_E_SYSTEM_ERROR, null);

      KP_ASSERT(strlen(path_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
      strcpy(p_lpszPathBuf, path_ptr);
   }

// disk
   *path_ptr = Nul;
   KP_ASSERT(strlen(disk_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(p_lpszDiskBuf, disk_ptr);
}


// -------------------------------------- File I/O traceris
// *KpFileDescListPtr metodų PLAIN_C wrapperiai

int kpadd_fmode_to_flags(const uchar *p_lpszOpenMode)
{
    KP_ASSERT(p_lpszOpenMode, E_INVALIDARG, null);
int fflags = 0;
    if (strchr(p_lpszOpenMode, 'r')) fflags |= _O_RDONLY;
    if (strchr(p_lpszOpenMode, 'w'))
    {
        if (fflags & _O_RDONLY) fflags = (fflags & ~_O_RDONLY) | _O_RDWR | _O_CREAT;
        else fflags |= _O_WRONLY | _O_CREAT;
    }
    if (strchr(p_lpszOpenMode, 'a')) fflags = (fflags & ~(_O_RDONLY | _O_RDWR | _O_CREAT)) | _O_WRONLY | _O_APPEND;
    if (strchr(p_lpszOpenMode, 'b')) fflags |= _O_BINARY;
    else fflags |= _O_TEXT;

return(fflags);
}


int kpadd_wfmode_to_flags(const wchar_t *p_lpwszOpenMode)
{
    KP_ASSERT(p_lpwszOpenMode, E_INVALIDARG, null);
int fflags = 0;
    if (wcschr(p_lpwszOpenMode, 'r')) fflags |= _O_RDONLY;
    if (wcschr(p_lpwszOpenMode, 'w'))
    {
        if (fflags & _O_RDONLY) fflags = (fflags & ~_O_RDONLY) | _O_RDWR | _O_CREAT;
        else fflags |= _O_WRONLY | _O_CREAT;
    }
    if (wcschr(p_lpwszOpenMode, 'a')) fflags = (fflags & ~(_O_RDONLY | _O_RDWR | _O_CREAT)) | _O_WRONLY | _O_APPEND;
    if (wcschr(p_lpwszOpenMode, 'b')) fflags |= _O_BINARY;
    else fflags |= _O_TEXT;

return(fflags);
}


int kpadd_acc_to_flags(DWORD p_dwDesiredAccess)
{
int fflags = 0;
    if (p_dwDesiredAccess & FILE_READ_DATA) fflags |= _O_RDONLY;
    if (p_dwDesiredAccess & FILE_WRITE_DATA)  
    {
        if (fflags & _O_RDONLY) fflags = (fflags & ~_O_RDONLY) | _O_RDWR | _O_CREAT;
        else fflags |= _O_WRONLY | _O_CREAT;
    }
    if (p_dwDesiredAccess & FILE_APPEND_DATA) fflags = (fflags & ~(_O_RDONLY | _O_RDWR | _O_CREAT)) | _O_WRONLY | _O_APPEND;
    fflags |= _O_BINARY;

return(fflags);
}


uchar *kpadd_open_flags_to_str(int p_iFlags)
{
uchar *fmode = null;
    KP_NEWA(fmode, uchar, 20);
    fmode[0] = Nul;
    
    if (p_iFlags & _O_RDONLY) strcat(fmode, "r");
    if (p_iFlags & (_O_WRONLY | _O_CREAT | _O_TRUNC | _O_RDWR)) strcat(fmode, "w");
    if (p_iFlags & _O_APPEND) strcat(fmode, "a");
    if (p_iFlags & _O_BINARY) strcat(fmode, "b");
    
return(fmode);
}


FILE *kpadd_fopen(const char *p_lpszFname, const char *p_lpszOpenMode,
    const char *p_lpszSrcFile, int p_iSrcLine)
{
FILE *ret_file = NULL;

    try
    {
        KP_ASSERT(p_lpszFname, E_INVALIDARG, null);
        KP_ASSERT(p_lpszOpenMode, E_INVALIDARG, null);
        
    uchar *fmode = null;
        KP_NEWA(fmode, uchar, strlen(p_lpszOpenMode) + 10);
        strcpy(fmode, p_lpszOpenMode);
        if(strchr(fmode, 'b') == null) strcat(fmode, "b"); // atidarinėjam visada binary mode, į tekstą vers I/O wrapperiai 
                
        ret_file = fopen(p_lpszFname, (const char *)fmode);
        
    int fflags = kpadd_fmode_to_flags((const uchar *)p_lpszOpenMode);
        kpadd_fopen_chkin(p_lpszFname, fflags, ret_file, NO_FILE_DESC, NULL, p_lpszSrcFile, p_iSrcLine);
        
        KP_DELETEA(fmode);
    }
    KP_CATCH_ALL; 

return(ret_file); 
}


FILE *kpadd_wfopen(const wchar_t *p_lpwszFname, const wchar_t *p_lpwszOpenMode, 
    const char *p_lpszSrcFile, int p_iSrcLine)
{
FILE *ret_file = NULL;

    try
    {
        KP_ASSERT(p_lpwszFname, E_INVALIDARG, null);
        KP_ASSERT(p_lpwszOpenMode, E_INVALIDARG, null);
    
    wchar_t *fmode = NULL;
        KP_NEWA(fmode, wchar_t, wcslen(p_lpwszOpenMode) + 10);
        wcscpy(fmode, p_lpwszOpenMode);
        if(wcschr(fmode, 'b')) wcscat(fmode, L"b"); // atidarinėjam visada binary mode, į tekstą vers I/O wrapperiai
                
        ret_file = _wfopen(p_lpwszFname, fmode);
        
    int fflags = kpadd_wfmode_to_flags(p_lpwszOpenMode);
        kpadd_wfopen_chkin(p_lpwszFname, fflags, ret_file, NO_FILE_DESC, NULL, p_lpszSrcFile, p_iSrcLine);
        
        KP_DELETEA(fmode);
    }
    KP_CATCH_ALL; 

return(ret_file); 
}


FILE *kpadd_fdopen(const char *p_lpszFname, int p_iFileDesc, const char *p_lpszOpenMode, 
    const char *p_lpszSrcFile, int p_iSrcLine)
{
FILE *ret_file = NULL;

    try
    {
        KP_ASSERT(p_lpszFname, E_INVALIDARG, null);
        KP_ASSERT(p_lpszOpenMode, E_INVALIDARG, null);
        
    uchar *fmode = null;
        KP_NEWA(fmode, uchar, strlen(p_lpszOpenMode) + 10);
        strcpy(fmode, p_lpszOpenMode);
        if(strchr(fmode, 'b') == null) strcat(fmode, "b"); // atidarinėjam visada binary mode, į tekstą vers I/O wrapperiai 
                
        ret_file = fdopen(p_iFileDesc, (const char *)fmode);
        
    int fflags = kpadd_fmode_to_flags((const uchar *)p_lpszOpenMode);
        kpadd_fopen_chkin(p_lpszFname, fflags, ret_file, p_iFileDesc, NULL, p_lpszSrcFile, p_iSrcLine);
        
        KP_DELETEA(fmode);
    }
    KP_CATCH_ALL; 

return(ret_file); 
}


int kpadd_open(const char *p_lpszFname, int p_iFlags, int p_iPerm, 
    const char *p_lpszSrcFile, int p_iSrcLine)
{
int ret_fdesc = NO_FILE_DESC;

    try
    {
        KP_ASSERT(p_lpszFname, E_INVALIDARG, null);
        
    int fflags = (p_iFlags & ~_O_TEXT) | _O_BINARY; // atidarinėjam visada binary mode, į tekstą vers I/O wrapperiai 
        ret_fdesc = open(p_lpszFname, fflags, p_iPerm);
        
        kpadd_fopen_chkin(p_lpszFname, p_iFlags, NULL, ret_fdesc, NULL, p_lpszSrcFile, p_iSrcLine);
    }
    KP_CATCH_ALL; 

return(ret_fdesc); 
}


int kpadd_wopen(const wchar_t *p_lpwszFname, int p_iFlags, int p_iPerm, 
    const char *p_lpszSrcFile, int p_iSrcLine)
{
int ret_fdesc = NO_FILE_DESC;

    try
    {
        KP_ASSERT(p_lpwszFname, E_INVALIDARG, null);
        
    int fflags = (p_iFlags & ~_O_TEXT) | _O_BINARY; // atidarinėjam visada binary mode, į tekstą vers I/O wrapperiai 
        ret_fdesc = _wopen(p_lpwszFname, fflags, p_iPerm);

        kpadd_wfopen_chkin(p_lpwszFname, p_iFlags, NULL, ret_fdesc, NULL, p_lpszSrcFile, p_iSrcLine);
    }
    KP_CATCH_ALL; 

return(ret_fdesc); 
}


HANDLE kpadd_CreateFileA(const char *p_lpFileName,
    DWORD p_dwDesiredAccess, DWORD p_dwShareMode, LPSECURITY_ATTRIBUTES p_lpSecurityAttributes,
    DWORD p_dwCreationDisposition, DWORD p_dwFlagsAndAttributes, HANDLE p_hTemplateFile,
    const char *p_lpszSrcFile, int p_iSrcLine)
{
HANDLE retv = NULL;

    try
    {
        retv = CreateFileA(p_lpFileName, p_dwDesiredAccess, p_dwShareMode, p_lpSecurityAttributes,
            p_dwCreationDisposition, p_dwFlagsAndAttributes, p_hTemplateFile);

    int fflags = kpadd_acc_to_flags(p_dwDesiredAccess);
        kpadd_fopen_chkin(p_lpFileName, fflags, NULL, NO_FILE_DESC, retv, 
            p_lpszSrcFile, p_iSrcLine);
    }
    KP_CATCH_ALL; 

return(retv);
}
    
    
HANDLE kpadd_CreateFileW(const wchar_t *p_lpFileName,
    DWORD p_dwDesiredAccess, DWORD p_dwShareMode, LPSECURITY_ATTRIBUTES p_lpSecurityAttributes,
    DWORD p_dwCreationDisposition, DWORD p_dwFlagsAndAttributes, HANDLE p_hTemplateFile,
    const char *p_lpszSrcFile, int p_iSrcLine)
{
HANDLE retv = NULL;
    
    try
    {
        retv = CreateFileW(p_lpFileName, p_dwDesiredAccess, p_dwShareMode, p_lpSecurityAttributes,
            p_dwCreationDisposition, p_dwFlagsAndAttributes, p_hTemplateFile);

    int fflags = kpadd_acc_to_flags(p_dwDesiredAccess);
        kpadd_wfopen_chkin(p_lpFileName, fflags, NULL, NO_FILE_DESC, retv, 
            p_lpszSrcFile, p_iSrcLine);
    }
    KP_CATCH_ALL; 

return(retv);
}    


void kpadd_wfopen_chkin(const wchar_t *p_lpwszFname, int p_iFlags,
    const FILE *p_pFile, int p_iFileDesc, HANDLE p_hFile, 
    const char *p_lpszSrcFile, int p_iSrcLine)
{
    try
    {
    uchar fname_utf8[KP_MAX_FNAME_LEN + 1];
        // TODO: konvertuoti p_lpwszFname į UTF-8
        KP_THROW(E_NOTIMPL, null);
        
    kpadd_fopen_chkin((const char *)fname_utf8, p_iFlags, p_pFile, p_iFileDesc, p_hFile,
        p_lpszSrcFile, p_iSrcLine);
    }
    KP_CATCH_ALL; 
}


void kpadd_fopen_chkin(const char *p_lpszFname, int p_iFlags,
    const FILE *p_pFile, int p_iFileDesc, HANDLE p_hFile, 
    const char *p_lpszSrcFile, int p_iSrcLine)
{
    try
    {
        KP_ASSERT(KpFileDescListPtr, E_POINTER, null);
        
        KpFileDescListPtr->RegNewFile((const uchar *)p_lpszFname, p_iFlags,
            p_pFile, p_iFileDesc, p_hFile);
#ifdef KPSTDIO_FULL_LOG
        KpFileDescListPtr->PutLogMessage(p_pFile, "Opened: %s", p_lpszFname);
#endif

#ifdef Debug
uchar str_buf[KP_MAX_FILE_LIN_LEN + 1];    
        sprintf((char *)str_buf, "kpadd:kpadd_fopen_chkin(\"%s\") %lx; %d; %lx; file: %s line: %d\n", 
            p_lpszFname, 
            p_pFile, p_iFileDesc, p_hFile, 
            p_lpszSrcFile, p_iSrcLine);
//      cout << endl << str_buf;
        printf("\n"); printf((const char *)str_buf);
        KpError.PutLogMessage(str_buf);
//      KpError.StackDump();
#endif      
    }
    KP_CATCH_ALL; 
}


int kpadd_fclose(FILE *p_pFile, const char *p_lpszSrcFile, int p_iSrcLine)
{
    kpadd_fclose_chkin(p_pFile, NO_FILE_DESC, NULL, p_lpszSrcFile, p_iSrcLine);
return(fclose(p_pFile));
}      


int kpadd_fclose_plain(FILE *p_pFile)
{
return(kpadd_fclose(p_pFile, __FILE__, __LINE__));
}      


int kpadd_close(int p_iFileDesc, const char *p_lpszSrcFile, int p_iSrcLine)
{
int retv = -1;
    
    try
    {
        retv = close(p_iFileDesc);

        kpadd_fclose_chkin(NULL, p_iFileDesc, NULL, p_lpszSrcFile, p_iSrcLine);
    }
    KP_CATCH_ALL; 

return(retv);
}    


BOOL kpadd_CloseHandle(HANDLE p_hFile, const char *p_lpszSrcFile, int p_iSrcLine)
{
BOOL retv = False;
    
    try
    {
        retv = CloseHandle(p_hFile);

        kpadd_fclose_chkin(NULL, NO_FILE_DESC, p_hFile, p_lpszSrcFile, p_iSrcLine);
    }
    KP_CATCH_ALL; 

return(retv);
}    


void kpadd_fclose_chkin(const FILE *p_pFile, int p_iFileDesc, HANDLE p_hFile, 
    const char *p_lpszSrcFile, int p_iSrcLine)
{
    try
    {
        KP_ASSERT(KpFileDescListPtr, E_POINTER, null);

uchar str_buf[KP_MAX_FILE_LIN_LEN + 1];    
        sprintf((char *)str_buf, "kpadd:kpadd_fclose_chkin(%lx, %d, %lx); file: %s line: %d\n", 
            (unsigned long)p_pFile, p_iFileDesc, p_hFile, p_lpszSrcFile, p_iSrcLine);
        
#ifdef KPSTDIO_FULL_LOG
        KpFileDescListPtr->PutLogMessage(p_pFile, "Closed");
#endif
        KpFileDescListPtr->DelFile(p_pFile, p_iFileDesc, p_hFile);
        
#ifdef Debug
//      cout << endl << str_buf;
        printf("\n"); printf((const char *)str_buf);
        
        KpError.PutLogMessage(str_buf);
//      KpError.StackDump();
#endif
    }      
    KP_CATCH_ALL; 
}


// -----------------------------------------
void KpFileDesc::InitMembers(void)
{
#ifdef Debug
printf("KpFileDesc::InitMembers(%x)\n", this);
#endif

    m_pFile = NULL;
    m_iFileDesc = NO_FILE_DESC;
    m_hFile = NULL;

    m_lpszFileName[0] = Nul;
    m_iFlags = 0;

#ifdef KPSTDIO_FULL_LOG
    m_lpszLogFileName[0] = Nul;
#endif

    m_iCurLine = 0;
    m_iCurLpos = 0;
}


KpFileDesc::KpFileDesc(const uchar *p_lpszFileName, int p_iFlags, 
    const FILE *p_pFile, int p_iFileDesc, HANDLE p_hFile)
{
    InitMembers();

    // ------
    KP_ASSERT((p_pFile != NULL)  || (p_iFileDesc != NO_FILE_DESC) || (p_hFile != NULL),
        E_INVALIDARG, null);
    KP_ASSERT(p_lpszFileName, E_INVALIDARG, null);
    
    m_pFile = p_pFile;
    m_iFileDesc = p_iFileDesc;
    m_hFile = p_hFile;

    // -------
    if (m_pFile)
    {
    int fd = fileno(m_pFile);
        if (m_iFileDesc == NO_FILE_DESC) m_iFileDesc = fd;
        KP_ASSERTW0(m_iFileDesc == fd, E_INVALIDARG, null);
    }

    if (m_iFileDesc != NO_FILE_DESC)
    {
    HANDLE fh = (HANDLE)_get_osfhandle(m_iFileDesc);
        if (m_hFile == NULL) m_hFile = fh;
        KP_ASSERTW0(m_hFile == fh, E_INVALIDARG, null);
    }
    
    // ------
    KP_ASSERT(strlen(p_lpszFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
    strcpy(m_lpszFileName, p_lpszFileName);
    
    strlwr(m_lpszFileName);

    // ------
    m_iFlags = p_iFlags;

    // ------
#ifdef KPSTDIO_FULL_LOG
uchar disk[KP_MAX_FNAME_LEN + 1];
uchar path[KP_MAX_FNAME_LEN + 1];
uchar fname[KP_MAX_FNAME_LEN + 1];
uchar ftype[KP_MAX_FNAME_LEN + 1];
    KpStdIo::TvFnameSplit(disk, path, fname, ftype, m_lpszFileName); 
    
    KP_ASSERT(strlen(fname) + 1 + strlen(ftype) + strlen(KPTRC_LOG_SUFF) + strlen(KP_LOG_EXT) <= 
        KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
    strcpy(m_lpszLogFileName, fname);
    strcat(m_lpszLogFileName, ".");
    strcat(m_lpszLogFileName, ftype);
    strcat(m_lpszLogFileName, KPTRC_LOG_SUFF);
    strcat(m_lpszLogFileName, KP_LOG_EXT);
    
    remove((const char *)m_lpszLogFileName);
#endif
}


// -----------------------------------------
void KpFileDesc::PullData(const KpFileDesc *p_pDescObj)
{
    KP_ASSERT(p_pDescObj, E_INVALIDARG, null);

    m_pFile = p_pDescObj->m_pFile;
    strcpy(m_lpszFileName, p_pDescObj->m_lpszFileName);
#ifdef KPSTDIO_FULL_LOG
    strcpy(m_lpszLogFileName, p_pDescObj->m_lpszLogFileName);
#endif
}


// -----------------------------------------
#ifdef KPSTDIO_FULL_LOG
void KpFileDesc::PutLogMessage(const uchar *p_lpszFmt, va_list p_Args)
{
uchar *out_str = null;   
    KP_NEWA(out_str, uchar, KP_MAX_FILE_LIN_LEN + strlen(p_lpszFmt) * 10 + 1);
    vsprintf((char *)out_str, (const char *)p_lpszFmt, p_Args);
    strcat(out_str, "\n");

FILE *log_file = fopen((const char *)m_lpszLogFileName, "a");
    KP_ASSERT(log_file != NULL, KP_E_DIR_ERROR, m_lpszLogFileName);
     
    fputs((const char *)out_str, log_file);
    
    fclose(log_file);
    
    KP_DELETEA(out_str);
}
#endif



// -----------------------------------------
KpFileDescList *KpFileDescListPtr = NULL;

KpFileDescList::KpFileDescList(void)
{
#ifdef Debug
    KpError.PutLogMessage("KpFileDescList::KpFileDescList()");
#endif
    m_pFileList = NULL;
}


KpFileDescList::~KpFileDescList()
{
// ----------------
#ifdef Debug
    KpError.PutLogMessage("KpFileDescList::~KpFileDescList()");
#endif

KpTreeEntry<KpFileDesc> *cur_entry = m_pFileList;
    while (cur_entry != NULL)
    {
KpFileDesc *desc_ptr = cur_entry->GetValue();
        KP_ASSERT(desc_ptr != NULL, E_POINTER, null);
#ifdef Debug
        KpError.PutLogMessage("KpFileDescList::~KpFileDescList(): deleting object: %s", desc_ptr->m_lpszFileName);
#endif
        desc_ptr->LogLastCh();

        cur_entry = cur_entry->GetFirstChild();
    }

// ----------------
    KP_DELETE(m_pFileList);
}


// -----------------------------------------
KpFileDesc *KpFileDescList::KpFileDescFactory(const uchar *p_lpszFileName, int p_iFlags,
    const FILE *p_pFile, int p_iFileDesc, HANDLE p_hFile)
{
#ifdef Debug
    KpError.PutLogMessage("KpFileDescList::KpFileDescFactory()");
#endif

KpFileDesc *desc_obj_ptr = NULL;
    KP_NEW(desc_obj_ptr, KpFileDesc(p_lpszFileName, p_iFlags,
        p_pFile, p_iFileDesc, p_hFile));

return(desc_obj_ptr);
}


// -----------------------------------------
void KpFileDescList::RegNewFile(const uchar *p_lpszFileName, int p_iFlags,
    const FILE *p_pFile, int p_iFileDesc, HANDLE p_hFile)
{
HRESULT retc = S_OK;
KpFileDesc *desc_obj_ptr = NULL;
    if(p_pFile) desc_obj_ptr = FindFile(p_pFile);
    if(p_iFileDesc != NO_FILE_DESC) desc_obj_ptr = FindFileByDesc(p_iFileDesc);
    if(p_hFile) desc_obj_ptr = FindFileByHandle(p_hFile);
    KP_ASSERTW(desc_obj_ptr == NULL, KP_E_DOUBLE_CALL, p_lpszFileName);
    if(FAILED(retc))
    { 
        KpError.PutLogMessage("KpFileDescList::RegNewFile(): failas jau yra: %lx %d %x %s", 
            (DWORD)p_pFile, p_iFileDesc, p_hFile, desc_obj_ptr->m_lpszFileName);  
        DelFile(p_pFile, p_iFileDesc, p_hFile);
    }

    desc_obj_ptr = KpFileDescFactory(p_lpszFileName, p_iFlags, p_pFile, p_iFileDesc, p_hFile);

KpTreeEntry<KpFileDesc> *new_node = NULL;
    KP_NEW(new_node, KpTreeEntry<KpFileDesc>(desc_obj_ptr, NULL));    

    if (m_pFileList == NULL) m_pFileList = new_node;
    else m_pFileList->PutToEnd(new_node);
    new_node = NULL;
}


// -----------------------------------------
void KpFileDescList::DelFile(const FILE *p_pFile, int p_iFileDesc, HANDLE p_hFile)
{
uchar out_str[MAX_LONG_HEX_DIGITS + 10];
    sprintf((char *)out_str, "%lx", (DWORD)p_pFile);

HRESULT retc = S_OK;
KpTreeEntry<KpFileDesc> **node_ptr_ptr = NULL;
KpFileDesc *desc_obj_ptr = NULL;
    if(p_pFile) desc_obj_ptr = FindFile(p_pFile, &node_ptr_ptr);
    if(p_iFileDesc != NO_FILE_DESC) desc_obj_ptr = FindFileByDesc(p_iFileDesc, &node_ptr_ptr);
    if(p_hFile) desc_obj_ptr = FindFileByHandle(p_hFile, &node_ptr_ptr);
    KP_ASSERTW(desc_obj_ptr != NULL, KP_E_NO_FILE, out_str);
    if (SUCCEEDED(retc))
    {
        desc_obj_ptr->LogLastCh();

        KP_ASSERT(node_ptr_ptr != NULL, KP_E_NO_FILE, out_str);
        KP_ASSERT(*node_ptr_ptr != NULL, KP_E_NO_FILE, out_str);

KpTreeEntry<KpFileDesc> tmp_obj(NULL, NULL);
        tmp_obj.DeleteKpTreeNode(node_ptr_ptr);
//      KpTreeEntry<TeXtrcFileDesc>::DeleteKpTreeNode(node_ptr_ptr);
    } 
}


// -----------------------------------------
KpFileDesc *KpFileDescList::FindFile(const FILE *p_pFile, KpTreeEntry<KpFileDesc> ***pppNodePtr)
{
KpFileDesc *desc_obj_ptr = NULL;

    if (pppNodePtr != NULL) *pppNodePtr = &m_pFileList;
KpTreeEntry<KpFileDesc> *cur_entry = m_pFileList;
    
    while (cur_entry != NULL)
    {
KpFileDesc *desc_ptr = cur_entry->GetValue();
        KP_ASSERT(desc_ptr != NULL, E_POINTER, null);
        if (desc_ptr->m_pFile == p_pFile)
        {
            desc_obj_ptr = desc_ptr; 
            break;
        }
        
        if (pppNodePtr != NULL) *pppNodePtr = &(cur_entry->m_pFirstChild);
        cur_entry = cur_entry->GetFirstChild();
    }

return(desc_obj_ptr);
}


KpFileDesc *KpFileDescList::FindFileByDesc(int p_iFileDesc, KpTreeEntry<KpFileDesc> ***pppNodePtr)
{
KpFileDesc *desc_obj_ptr = NULL;

    if (pppNodePtr != NULL) *pppNodePtr = &m_pFileList;
KpTreeEntry<KpFileDesc> *cur_entry = m_pFileList;
    
    while (cur_entry != NULL)
    {
KpFileDesc *desc_ptr = cur_entry->GetValue();
        KP_ASSERT(desc_ptr != NULL, E_POINTER, null);
        if (desc_ptr->m_iFileDesc == p_iFileDesc)
        {
            desc_obj_ptr = desc_ptr; 
            break;
        }
        
        if (pppNodePtr != NULL) *pppNodePtr = &(cur_entry->m_pFirstChild);
        cur_entry = cur_entry->GetFirstChild();
    }

return(desc_obj_ptr);
}


KpFileDesc *KpFileDescList::FindFileByHandle(HANDLE p_hFile, KpTreeEntry<KpFileDesc> ***pppNodePtr)
{
KpFileDesc *desc_obj_ptr = NULL;

    if (pppNodePtr != NULL) *pppNodePtr = &m_pFileList;
KpTreeEntry<KpFileDesc> *cur_entry = m_pFileList;
    
    while (cur_entry != NULL)
    {
KpFileDesc *desc_ptr = cur_entry->GetValue();
        KP_ASSERT(desc_ptr != NULL, E_POINTER, null);
        if (desc_ptr->m_hFile == p_hFile)
        {
            desc_obj_ptr = desc_ptr; 
            break;
        }
        
        if (pppNodePtr != NULL) *pppNodePtr = &(cur_entry->m_pFirstChild);
        cur_entry = cur_entry->GetFirstChild();
    }

return(desc_obj_ptr);
}


// -----------------------------------------
void KpFileDescList::UpdateFile(const KpFileDesc *p_pDescObj)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_pDescObj, E_INVALIDARG, null);

KpFileDesc *desc_obj_ptr = NULL;
KpTreeEntry<KpFileDesc> *cur_entry = m_pFileList;
    while (cur_entry != NULL)
    {
        desc_obj_ptr = cur_entry->GetValue();
        KP_ASSERT(desc_obj_ptr != NULL, E_POINTER, null);
        
        if (desc_obj_ptr->m_pFile == p_pDescObj->m_pFile)
        {
            // radom – deskriptorių updeitinam, o desc_obj_ptr paliekam nustatytą
            desc_obj_ptr->PullData(p_pDescObj);
            break;
        }
        else
        {
            // neradom – valom desc_obj_ptr
            desc_obj_ptr = NULL;
        }
        
        cur_entry = cur_entry->GetFirstChild();
    }

    KP_ASSERTW(desc_obj_ptr != NULL, KP_E_NO_FILE, null); // neradom
}


// -----------------------------------------
#ifdef KPSTDIO_FULL_LOG
void KpFileDescList::PutLogMessage(const FILE *p_pFile, const uchar *p_lpszFmt, va_list p_Args)
{
HRESULT retc = S_OK;
uchar out_str[MAX_LONG_HEX_DIGITS + 10];
    sprintf((char *)out_str, "%lx", p_pFile);
KpFileDesc *desc_obj_ptr = FindFile(p_pFile);
    KP_ASSERTW(desc_obj_ptr != NULL, KP_E_NO_FILE, out_str);
    if (FAILED(retc)) KpError.PutLogMessage(p_lpszFmt, p_Args);
    else
        desc_obj_ptr->PutLogMessage(p_lpszFmt, p_Args);
}
#endif
