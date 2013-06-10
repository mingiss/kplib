/* -----------------------------
 * fmtf.cpp
 *      formatted I/O file implementation
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

#include "rti.h"
#include "fmtf.h"


// ---------------------------
FmtFile::FmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
    m_lpszFileName[0] = Nul;
    m_lpszFileMode[0] = Nul;
    m_pFileObj = NULL;
    FileNode = NULL;

    m_bOutputEmpty = True; 
    m_iIndent = 0;

    strcpy(m_lpszFileMode, "r");
    
    if(p_lpszFileMode != null)
    {
        KP_ASSERT(strlen(p_lpszFileMode) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszFileMode, p_lpszFileMode);
    }

    if(strchr(m_lpszFileMode, 'b') == null)
    {
        if(strchr(m_lpszFileMode, 'w') != null) m_pFileObj = stdout;
        if(strchr(m_lpszFileMode, 'r') != null) m_pFileObj = stdin;
    }
    
    if(p_lpszFileName != null) if (p_lpszFileName[0] != Nul)
    {
        KP_ASSERT(strlen(p_lpszFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszFileName, p_lpszFileName);
        
        m_pFileObj = fopen((const CHAR *)m_lpszFileName, (const CHAR *)m_lpszFileMode);
        KP_ASSERT(m_pFileObj != NULL, KP_E_DIR_ERROR, p_lpszFileName);
    }
}


FmtFile::~FmtFile()
{
    CloseOutFile();
}


// ------------------------------------  
void FmtFile::CloseOutFile(void)
{
    if(m_pFileObj != NULL)
    {
        KP_ASSERT(!m_bOutputEmpty, KP_E_FILE_FORMAT, "Nothing found to print...\n");
        PrintOutputTail();
    
        if(m_pFileObj == stdout)
            KP_ASSERT(fflush(m_pFileObj) != EOF, KP_E_FERROR, null)
        else
            KP_ASSERT(fclose(m_pFileObj) != EOF, KP_E_FERROR, m_lpszFileName);
        
        m_pFileObj = NULL;
    } 
}


// ---------------------------------
void FmtFile::PrintOutput(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
bool *p_output_empty = p_pbOutputEmpty;
    if (p_pbOutputEmpty == NULL) p_output_empty = &m_bOutputEmpty;
    
    KP_ASSERT(p_pRti != NULL, E_INVALIDARG, null);
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    PrintOutputLow(p_pRti, p_output_empty, p_lpszGrpTagName);

    m_bOutputEmpty = False; // Do not print OUPUT_HEAD
    *p_output_empty = False; // no more output of parent group tag p_lpszGrpTagName
}
        