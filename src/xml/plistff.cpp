/* -----------------------------
 * plistff.cpp
 *      PLIST format file I/O implementation
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
#include "plistff.h"


// ---------------------------------
FmtFile *CreatePlistFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, PlistFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void PlistFmtFile::PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(p_pRti != NULL, E_INVALIDARG, null);
    KP_ASSERT(p_pbOutputEmpty != NULL, E_INVALIDARG, null);
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    if (m_bOutputEmpty) PrintOutputHead();

    if (p_lpszGrpTagName != null)
        if (*p_pbOutputEmpty) 
            OpenGrTag(p_lpszGrpTagName);

    MakeIndent();
    fprintf(m_pFileObj, "<key>%s</key>\n", p_pRti->name); 
    
    MakeIndent(); 
    fprintf(m_pFileObj, "<string>%s</string>\n", p_pRti->value);
}


void PlistFmtFile::PrintOutputHead(void)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    fprintf(m_pFileObj, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n<plist version=\"1.0\">\n<dict>\n"); 
    m_iIndent++;
}


void PlistFmtFile::PrintOutputTail(void)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    fprintf(m_pFileObj, "</dict>\n</plist>\n");
}


void PlistFmtFile::OpenGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    
    if (m_bOutputEmpty) PrintOutputHead();  
    m_bOutputEmpty = False; // Do not print OUPUT_HEAD

    MakeIndent(); 
    fprintf(m_pFileObj, "<key>%s</key>\n", p_lpszGrpTagName); 
    MakeIndent(); 
    fprintf(m_pFileObj, "<dict>\n"); 
    m_iIndent++;
}


void PlistFmtFile::CloseGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    m_iIndent--; 
    MakeIndent(); 
    fprintf(m_pFileObj, "</dict>\n");
}


// ---------------------------------
void PlistFmtFile::MakeIndent(void)
{
int ii;

    for(ii = 0; ii < m_iIndent; ii++)
        fprintf(m_pFileObj, "    ");
}        


// ---------------------------------
void PlistFmtFile::ExportDoc(void)
{
    KP_ERROR(E_NOTIMPL, null);
}
