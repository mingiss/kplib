/* -----------------------------------------------
 *
 * kpstdio.h
 *
 *    I/O tools
 *
 * 2013-04-04  mp  initial creation
 * 2013-10-29  mp  KpFileDesc and KpFileDescList split of TeXtrcFileDesc and TeXtrcClass  
 * 2016-09-06  mp  migration of kpsgrp from tv to kplib
 * 2016-09-07  mp  kpfhook split
 * 2016-09-08  mp  migration of kpsgrm from tv to kplib
 *
 */

#ifndef KPSTDIO_INCLUDED
#define KPSTDIO_INCLUDED

// ------------------------
#define NO_FILE_DESC (-1) // illegal file descriptor value for open() 

#ifndef _O_RDONLY
#define _O_RDONLY O_RDONLY
#endif
#ifndef _O_WRONLY
#define _O_WRONLY O_WRONLY
#endif
#ifndef _O_RDWR
#define _O_RDWR O_RDWR
#endif
#ifndef _O_CREAT
#define _O_CREAT O_CREAT
#endif
#ifndef _O_APPEND
#define _O_APPEND O_APPEND
#endif
#ifndef _O_TRUNC
#define _O_TRUNC O_TRUNC
#endif
#ifndef _O_TEXT
// #define _O_TEXT O_TEXT
#define _O_TEXT 0x4000
#endif
#ifndef _O_BINARY
// #define _O_BINARY O_BINARY
#define _O_BINARY 0x8000
#endif

#ifndef __WIN32__
#define FILE_READ_DATA (0x0001)
#define FILE_WRITE_DATA (0x0002)
#define FILE_APPEND_DATA (0x0004)

FILE* __cdecl _wfopen(const wchar_t* filename, const wchar_t* mode);
int __cdecl _wopen(const wchar_t* filename, int oflag, ... /* int pmode */);
#endif

#ifndef HAVE__FDOPEN
#define _fdopen fdopen
#endif

#ifndef HAVE__GET_OSFHANDLE
intptr_t __cdecl _get_osfhandle(int _FileHandle);
#endif


// --------------------------
extern PLAIN_C void FnameSplit // call to KpStdIo::TvFnameSplit()
(
    KpStrPtr p_lpszDiskBuf,
    KpStrPtr p_lpszPathBuf,
    KpStrPtr p_lpszFNameBuf,
    KpStrPtr p_lpszFTypeBuf,
    const KpStrPtr p_lpszFullName
);

// skaito eilutę iš failo, numeta Cr/Lf gale
uchar *fgetss(uchar *buf, int maxnum, FILE *fil);

#ifdef __cplusplus
// --------------------------
// bendro pobūdžio statinės funkcijos
class KpStdIo
{
public:
   static void TvFnameSplit          // splits p_lpszFullName to file name and file
   (                                 //    type parts p_lpszFNameBuf, p_lpszFTypeBuf.
      KpStrPtr p_lpszDiskBuf,            // p_lpszDiskBuf, p_lpszPathBuf and p_lpszFNameBuf
      KpStrPtr p_lpszPathBuf,            //    must be not shorter than
      KpStrPtr p_lpszFNameBuf,           //    KP_MAX_FNAME_LEN + 1 bytes, p_lpszFTypeBuf
      KpStrPtr p_lpszFTypeBuf,           //    - not shorter than KP_MAX_FTYPE_LEN + 1
      const KpStrPtr p_lpszFullName      
   );

   static void TvFnameSplit          // splits p_lpszFullName to file name and file
   (                                 //    type parts p_lpszFNameBuf, p_lpszFTypeBuf.
      KpString& sDiskBuf,            // p_lpszDiskBuf, p_lpszPathBuf and p_lpszFNameBuf
      KpString& sPathBuf,            //    must be not shorter than
      KpString& sFNameBuf,           //    KP_MAX_FNAME_LEN + 1 bytes, p_lpszFTypeBuf
      KpString& sFTypeBuf,           //    - not shorter than KP_MAX_FTYPE_LEN + 1
      KpString sFullName      
   );
};

#endif // #ifdef __cplusplus

#endif // #ifndef KPSTDIO_INCLUDED

