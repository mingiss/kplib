/* -----------------------------
 * jsonff.cpp
 *      JSON format file I/O implementation
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
#include "jsonff.h"


// ---------------------------------
FmtFile *CreateJsonFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, JsonFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// char jsonsep = ',';

// ---------------------------------
void JsonFmtFile::PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(p_pRti != NULL, E_INVALIDARG, null);
    KP_ASSERT(p_pbOutputEmpty != NULL, E_INVALIDARG, null);
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    if (m_bOutputEmpty) PrintOutputHead();

    if (p_lpszGrpTagName != null)
        if (*p_pbOutputEmpty)
        { 
            OpenGrTagLocal(p_lpszGrpTagName);
            PrintOutputHead();
        }

//  fprintf(m_pFileObj, "%c-%i\n  \"%s\":\"%s\"", jsonsep, m_bOutputEmpty, p_pRti->name, p_pRti->value);

    if (!*p_pbOutputEmpty) fprintf(m_pFileObj, ",");
    fprintf(m_pFileObj, "\n"); 
    MakeIndent(); 
    fprintf(m_pFileObj, "\"%s\": \"%s\"", p_pRti->name, p_pRti->value);
}


void JsonFmtFile::PrintOutputHead(void)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    MakeIndent(); 
    fprintf(m_pFileObj, "{"); 
    m_iIndent++;
}


void JsonFmtFile::PrintOutputTail(void)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    CloseGrTag(null); 
    fprintf(m_pFileObj, "\n");
}


void JsonFmtFile::OpenGrTagLocal(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    if (!m_bOutputEmpty) fprintf(m_pFileObj, ",");
    fprintf(m_pFileObj, "\n");
    MakeIndent();
    fprintf(m_pFileObj, "\"%s\":\n", p_lpszGrpTagName);
    
    FmtFile::OpenGrTag(p_lpszGrpTagName);
}


void JsonFmtFile::OpenGrTag(const UCHAR *p_lpszGrpTagName)
{
    OpenGrTagLocal(p_lpszGrpTagName);
    m_bOutputEmpty = True;
}

void JsonFmtFile::CloseGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    m_iIndent--; 
    fprintf(m_pFileObj, "\n"); 
    MakeIndent(); 
    fprintf(m_pFileObj, "}");
}


// ---------------------------------
void JsonFmtFile::MakeIndent(void)
{
int ii;

    for(ii = 0; ii < m_iIndent; ii++)
        fprintf(m_pFileObj, "    ");
}        


// ---------------------------------
void JsonFmtFile::ExportDoc(void)
{
    KP_ERROR(E_NOTIMPL, null);
}
