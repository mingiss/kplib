/* -----------------------------
 * yamlff.cpp
 *      YAML format file I/O implementation
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
#include "yamlff.h"


// ---------------------------------
FmtFile *CreateYamlFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, YamlFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void YamlFmtFile::PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(p_pRti != NULL, E_INVALIDARG, null);
    KP_ASSERT(p_pbOutputEmpty != NULL, E_INVALIDARG, null);
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    // printf("m_bOutputEmpty = %i\n", m_bOutputEmpty);
    if (m_bOutputEmpty) PrintOutputHead();

    if (p_lpszGrpTagName != null)
        if (*p_pbOutputEmpty) 
            OpenGrTag(p_lpszGrpTagName);

    MakeIndent(); 
    fprintf(m_pFileObj, "%s: %s\n", p_pRti->name, p_pRti->value);
}


void YamlFmtFile::PrintOutputHead(void)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    fprintf(m_pFileObj, "---\n");
}


void YamlFmtFile::PrintOutputTail(void)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    fprintf(m_pFileObj, "\n");
}


void YamlFmtFile::OpenGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    
    if (m_bOutputEmpty) PrintOutputHead();  
    m_bOutputEmpty = False; // Do not print OUPUT_HEAD

    MakeIndent(); 
    fprintf(m_pFileObj, "%s:\n", p_lpszGrpTagName); 
    m_iIndent++;
}


void YamlFmtFile::CloseGrTag(const UCHAR *p_lpszGrpTagName)
{
    m_iIndent--; 
}


// ---------------------------------
void YamlFmtFile::MakeIndent(void)
{
int ii;

    for(ii = 0; ii < m_iIndent; ii++)
        fprintf(m_pFileObj, "    ");
}        


// ---------------------------------
void YamlFmtFile::ExportDoc(void)
{
    KP_ERROR(E_NOTIMPL, null);
}
