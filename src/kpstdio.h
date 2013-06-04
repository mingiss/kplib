/* -----------------------------------------------
 *
 * kpstdio.h
 *
 *    I/O tools
 *
 * 2013-04-04  mp  initial creation
 *
 */

#ifndef kpstdio_included
#define kpstdio_included

// ------------------------
#define KP_LOG_EXT ((const UCHAR *)".log")

// --------------------------
extern PLAIN_C void FnameSplit // call to KpStdIo::TvFnameSplit()
(
    UCHAR *lpszDiskBuf,
    UCHAR *lpszPathBuf,
    UCHAR *lpszFNameBuf,
    UCHAR *lpszFTypeBuf,
    const UCHAR *lpszFullName
);

// --------------------------
#ifdef __cplusplus

class KpStdIo
{
public:
   static void TvFnameSplit          // splits lpszFullName to file name and file
   (                                 //    type parts lpszFNameBuf, lpszFTypeBuf.
      UCHAR *lpszDiskBuf,            // lpszDiskBuf, lpszPathBuf and lpszFNameBuf
      UCHAR *lpszPathBuf,            //    must be not shorter than
      UCHAR *lpszFNameBuf,           //    KP_MAX_FNAME_LEN + 1 bytes, lpszFTypeBuf
      UCHAR *lpszFTypeBuf,           //    - not shorter than KP_MAX_FTYPE_LEN + 1
      const UCHAR *lpszFullName      
   );
};

#endif // #ifdef __cplusplus

#endif // #ifndef kpstdio_included
