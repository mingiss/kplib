/* -----------------------------
 * fmtf.cpp
 *      formatted I/O file implementation
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-12  mp  tinyxml implemented
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *
 *  TODO: neveikia I/O su stdin/stdout: ExportDoc() pats failą ir atsidaro, ir uždaro pagal vardą m_lpszFileName
 *         
 */  


// ---------------------------
#include "envir.h"

#include <stdio.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "tinyxml.h"

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"
#include "txml.h"
#include "rtid.h"
#include "fmtf.h"


// ---------------------------
FmtFile::FmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
    m_lpszFileName[0] = Nul;
    m_lpszFileMode[0] = Nul;
//  m_pFileObj = NULL;

//  m_pXmlDoc = NULL;

    m_iIndent = 0;

    strcpy(m_lpszFileMode, "r");
    
    if(p_lpszFileMode != null)
    {
        KP_ASSERT(strlen(p_lpszFileMode) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszFileMode, p_lpszFileMode);
    }

#if FALSE
    if(strchr(m_lpszFileMode, 'b') == null)
    {
        if(strchr(m_lpszFileMode, 'w') != null) m_pFileObj = stdout;
        if(strchr(m_lpszFileMode, 'r') != null) m_pFileObj = stdin;
    }
#endif
    
    if(p_lpszFileName != null) if (p_lpszFileName[0] != Nul)
    {
        KP_ASSERT(strlen(p_lpszFileName) <= KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null);
        strcpy(m_lpszFileName, p_lpszFileName);
        
        // ExportDoc() pats failą ir atsidaro, ir uždaro
        // m_pFileObj = fopen((const CHAR *)m_lpszFileName, (const CHAR *)m_lpszFileMode);
        // KP_ASSERT(m_pFileObj != NULL, KP_E_DIR_ERROR, p_lpszFileName);
    }
}


FmtFile::~FmtFile()
{
    CloseOutFile();
}


// ------------------------------------  
void FmtFile::CloseOutFile(void)
{
// ExportDoc() pats failą ir atsidaro, ir uždaro
#if FALSE
    if(m_pFileObj != NULL)
    {
        if(m_pFileObj == stdout)
            KP_ASSERT(fflush(m_pFileObj) != EOF, KP_E_FERROR, null)
        else
            KP_ASSERT(fclose(m_pFileObj) != EOF, KP_E_FERROR, m_lpszFileName);
        
        m_pFileObj = NULL;
    } 
#endif
}



// ---------------------------------
void FmtFile::CreateGrpNode(const UCHAR *p_lpszTagName, const UCHAR *p_lpszGrpTagName)
{
    KP_ASSERT(p_lpszTagName != null, E_INVALIDARG, null);

TiXmlNode *grp_node = NULL;
TiXmlNode *cur_node = NULL;

    if (p_lpszGrpTagName != null)
    {
        grp_node = FindNodeByName(p_lpszGrpTagName, &m_XmlDoc);
    }
    if (grp_node == NULL)            
        grp_node = &m_XmlDoc;

    // tikrinam, gal jau toks yra
    cur_node = FindNodeByName(p_lpszTagName, grp_node);

    if(cur_node == NULL)
    {            
    TiXmlElement *element = NULL;
        KP_NEW(element, TiXmlElement((const CHAR *)p_lpszTagName));
        grp_node->LinkEndChild(element);
        element = NULL;
    }
}
