/* -----------------------------
 * plainff.cpp
 *      plain format file I/O implementation
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

#include "rti.h"
#include "fmtf.h"
#include "plainff.h"


// ---------------------------------
FmtFile *CreatePlainFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, PlainFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void PlainFmtFile::PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(p_pRti != NULL, E_INVALIDARG, null);
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    fprintf(m_pFileObj, "%s", p_pRti->value);
}


void PlainFmtFile::PrintOutputHead(void){}
void PlainFmtFile::PrintOutputTail(void){}
void PlainFmtFile::OpenGrTag(const UCHAR *p_lpszGrpTagName){}
void PlainFmtFile::CloseGrTag(const UCHAR *p_lpszGrpTagName){}
void PlainFmtFile::MakeIndent(void){}        


// ---------------------------------
void PlainFmtFile::ExportDoc(void)
{
    KP_ERROR(E_NOTIMPL, null);
}
