/* -----------------------------
 * xmlff.cpp
 *      formatted XMl I/O file implementation
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
#include "xmlff.h"


// ---------------------------------
FmtFile *CreateXmlFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, XmlFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
XmlFmtFile::XmlFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
{
    strcpy(m_lpszXmlFileName, m_lpszFileName);
    strcat(m_lpszXmlFileName, ".xml");
}


// ---------------------------------
void XmlFmtFile::PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(p_pRti != NULL, E_INVALIDARG, null);
    KP_ASSERT(p_pbOutputEmpty != NULL, E_INVALIDARG, null);
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);

    if (m_bOutputEmpty) PrintOutputHead();

    if (p_lpszGrpTagName != null)
        if (*p_pbOutputEmpty) 
            OpenGrTag(p_lpszGrpTagName);

    MakeIndent(); 
    fprintf(m_pFileObj, (p_pRti->value[0] != Nul)?"<%s>%s</%s>\n":"<%s/>\n", p_pRti->name, p_pRti->value, p_pRti->name);
}


void XmlFmtFile::PrintOutputHead(void)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    fprintf(m_pFileObj, "<xml>\n"); 
    m_iIndent++;
}


void XmlFmtFile::PrintOutputTail(void)
{
    KP_ASSERT(m_pFileObj != NULL, KP_E_NO_FILE, null);
    fprintf(m_pFileObj, "</xml>\n");
}


void XmlFmtFile::OpenGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFileObj != NULL, E_POINTER, null);
    
    if (m_bOutputEmpty) PrintOutputHead();  
    m_bOutputEmpty = False; // Do not print OUPUT_HEAD

    MakeIndent(); 
    fprintf(m_pFileObj, "<%s>\n", p_lpszGrpTagName); 
    m_iIndent++;
    
    FmtFile::OpenGrTag(p_lpszGrpTagName);
}


void XmlFmtFile::CloseGrTag(const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(m_pFileObj != NULL, E_POINTER, null);

    m_iIndent--; 
    MakeIndent(); 
    fprintf(m_pFileObj, "</%s>\n", p_lpszGrpTagName);
}


// ---------------------------------
void XmlFmtFile::MakeIndent(void)
{
int ii;

    for(ii = 0; ii < m_iIndent; ii++)
        fprintf(m_pFileObj, "    ");
}        


void XmlFmtFile::ExportDoc(void)
{
//  dump_to_stdout(&m_XmlDoc);
    m_XmlDoc.SaveFile((const CHAR *)m_lpszXmlFileName);
}
