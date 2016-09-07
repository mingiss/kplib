/* ---------------------------------------------------
 *
 * kpstdio.cpp
 *
 *    I/O tools
 *
 * 2013-04-04  mp  initial creation
 * 2013-10-29  mp  KpFileDesc and KpFileDescList split of TeXtrcFileDesc and TeXtrcClass
 * 2016-09-06  mp  migration of kpsgrp from tv to kplib
 * 2016-09-07  mp  kpfhook split
 *
 */

// --------------------------------------
#include "envir.h"

#include <string.h>
#include <vector>
#include <string>
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
    KpStrPtr p_lpszDiskBuf,
    KpStrPtr p_lpszPathBuf,
    KpStrPtr p_lpszFNameBuf,
    KpStrPtr p_lpszFTypeBuf,
    const KpStrPtr p_lpszFullName
)
{
    KpStdIo::TvFnameSplit(p_lpszDiskBuf, p_lpszPathBuf, p_lpszFNameBuf, p_lpszFTypeBuf, p_lpszFullName);
}


void KpStdIo::TvFnameSplit
(
KpString& sDiskBuf,
KpString& sPathBuf,
KpString& sFNameBuf,
KpString& sFTypeBuf,
KpString sFullName
)
{
	// TODO: perdaryt per KpString::Split()
uchar disk[KP_MAX_FNAME_LEN + 1];
uchar path[KP_MAX_FNAME_LEN + 1];
uchar fname[KP_MAX_FNAME_LEN + 1];
uchar ftype[KP_MAX_FNAME_LEN + 1];
	TvFnameSplit(disk, path, fname, ftype, sFullName.c_str());
	sDiskBuf = disk;
	sPathBuf = path;
	sFNameBuf = fname;
	sFTypeBuf = ftype;
}


void KpStdIo::TvFnameSplit
(
KpStrPtr p_lpszDiskBuf,
KpStrPtr p_lpszPathBuf,
KpStrPtr p_lpszFNameBuf,
KpStrPtr p_lpszFTypeBuf,
const KpStrPtr p_lpszFullName
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


// --------------------------------------
#ifndef __WIN32__
FILE* _wfopen(const wchar_t* filename, const wchar_t* mode)
{
    KP_ERROR(E_NOTIMPL, null);
return NULL;
}

int _wopen(const wchar_t* filename, int oflag, ... /* int pmode */)
{
    KP_ERROR(E_NOTIMPL, null);
    return 0;
}
#endif

#ifndef HAVE__GET_OSFHANDLE
intptr_t __cdecl _get_osfhandle(int _FileHandle)
{
    KP_ERROR(E_NOTIMPL, null);
return 0;
}
#endif

