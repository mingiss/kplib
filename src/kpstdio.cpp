/* ---------------------------------------------------
 *
 * kpstdio.cpp
 *
 *    I/O tools
 *
 * 2013-04-04  mp  initial creation
 *
 */

// --------------------------------------
#include "envir.h"

#include <stdio.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpstdio.h"
#include "kpmsg.h"
#include "kperr.h"


void FnameSplit
(
    UCHAR *lpszDiskBuf,
    UCHAR *lpszPathBuf,
    UCHAR *lpszFNameBuf,
    UCHAR *lpszFTypeBuf,
    const UCHAR *lpszFullName
)
{
    KpStdIo::TvFnameSplit(lpszDiskBuf, lpszPathBuf, lpszFNameBuf, lpszFTypeBuf, lpszFullName);
}


void KpStdIo::TvFnameSplit
(
UCHAR *lpszDiskBuf,
UCHAR *lpszPathBuf,
UCHAR *lpszFNameBuf,
UCHAR *lpszFTypeBuf,
const UCHAR *lpszFullName
)
{
   KP_ASSERT((lpszDiskBuf != NULL) && (lpszPathBuf != NULL) && (lpszFNameBuf != NULL) &&
      (lpszFTypeBuf != NULL) && (lpszFullName != NULL), E_INVALIDARG, null);

   KP_ASSERT(strlen(lpszFullName) < KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, lpszFullName);

UCHAR str_buf[KP_MAX_FNAME_LEN + 1];
   strcpy(str_buf, lpszFullName);

UCHAR *disk_ptr;
UCHAR *path_ptr;
UCHAR *fnam_ptr;
UCHAR *typ_ptr;
UCHAR *pnts;
   disk_ptr = pnts = path_ptr = fnam_ptr = typ_ptr = str_buf;

   do
   {
      if(*pnts == ':') path_ptr = pnts + 1;
      if((*pnts == '\\') || (*pnts == '/')) fnam_ptr = pnts + 1;
      if(*pnts == '.') typ_ptr = pnts;
      pnts++;
   } while(*pnts);

// type
   if(typ_ptr <= fnam_ptr) typ_ptr=(UCHAR *)"";
   else *(typ_ptr++) = Nul;
   
   KP_ASSERT(strlen(typ_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(lpszFTypeBuf, typ_ptr);

// fname
   if(fnam_ptr < path_ptr) fnam_ptr = path_ptr;
   KP_ASSERT(strlen(fnam_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(lpszFNameBuf, fnam_ptr);

// path
   if(fnam_ptr == path_ptr) strcpy(lpszPathBuf, KP_CUR_DIR_STR);
   else /* if(fnam_ptr > path_ptr) */
   {
      *fnam_ptr-- = Nul;
      if((*fnam_ptr=='\\') || (*fnam_ptr=='/')) *fnam_ptr = Nul;
      else KP_THROW(KP_E_SYSTEM_ERROR, null);

      KP_ASSERT(strlen(path_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
      strcpy(lpszPathBuf, path_ptr);
   }

// disk
   *path_ptr = Nul;
   KP_ASSERT(strlen(disk_ptr) < KP_MAX_FTYPE_LEN, KP_E_BUFFER_OVERFLOW, null);
   strcpy(lpszDiskBuf, disk_ptr);
}
