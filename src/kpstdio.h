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
#define KP_LOG_EXT ((const uchar *)".log")

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

#endif // #ifndef kpstdio_included
