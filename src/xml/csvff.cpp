/* -----------------------------
 * csvff.cpp
 *      CSV format file I/O implementation
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
#include "csvff.h"


// ---------------------------------
FmtFile *CreateCsvFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, CsvFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void CsvFmtFile::PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(p_pRti != NULL, E_INVALIDARG, null);
    KP_ASSERT(p_pbOutputEmpty != NULL, E_INVALIDARG, null);
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    if (p_lpszGrpTagName != null)
        if (*p_pbOutputEmpty) 
            OpenGrTag(p_lpszGrpTagName);

    fprintf(m_pFileObj, "%s,%s\n", p_pRti->name, p_pRti->value);
    
    FmtFile::OpenGrTag(p_lpszGrpTagName);
}


void CsvFmtFile::PrintOutputHead(void){}
void CsvFmtFile::PrintOutputTail(void){}

void CsvFmtFile::OpenGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    
    if (m_bOutputEmpty) PrintOutputHead();  
    m_bOutputEmpty = False; // Do not print OUPUT_HEAD

    fprintf(m_pFileObj, "%s\n", p_lpszGrpTagName);
}


void CsvFmtFile::CloseGrTag(const UCHAR *p_lpszGrpTagName){}

void CsvFmtFile::MakeIndent(void){}        


// ---------------------------------
void CsvFmtFile::ExportDoc(void)
{
    KP_ERROR(E_NOTIMPL, null);
}
