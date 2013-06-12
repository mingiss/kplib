/* -----------------------------
 * binff.cpp
 *      binary format file I/O implementation
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


// ---------------------------
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
#include "kpmsg.h"
#include "kperr.h"

#include "tinyxml.h"

#include "rtid.h"
#include "fmtf.h"
#include "binff.h"


// ---------------------------------
FmtFile *CreateBinaryFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, BinFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void BinFmtFile::PrintOutput(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
    KP_ERROR(E_NOTIMPL, null);
}

void BinFmtFile::PrintOutputHead(void)
{
    KP_ERROR(E_NOTIMPL, null);
}

void BinFmtFile::PrintOutputTail(void)
{
    KP_ERROR(E_NOTIMPL, null);
}

void BinFmtFile::OpenGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ERROR(E_NOTIMPL, null);
    
    FmtFile::OpenGrTag(p_lpszGrpTagName);
}

void BinFmtFile::CloseGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ERROR(E_NOTIMPL, null);
}

void BinFmtFile::MakeIndent(void)
{
    KP_ERROR(E_NOTIMPL, null);
}


// ---------------------------------
void BinFmtFile::ExportDoc(void)
{
    KP_ERROR(E_NOTIMPL, null);
}
