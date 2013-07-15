/* -----------------------------
 * plainff.cpp
 *      plain format file I/O implementation
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
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
#include "plainff.h"


// ---------------------------------
FmtFile *CreatePlainFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, PlainFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void PlainFmtFile::ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile)
{
    KP_ASSERT(p_pCurNode != NULL, E_INVALIDARG, null);
    KP_ASSERT(p_pOutFile != NULL, KP_E_NO_FILE, null);

    if(p_pCurNode->Type() == TiXmlNode::TINYXML_ELEMENT)
    {
    const uchar *value = GetNodeVal(p_pCurNode);
        if(value != null)
        { 
            if(!m_bOutputEmpty) fprintf(p_pOutFile, "\n");
            m_bOutputEmpty = False;
            fprintf(p_pOutFile, "%s", value);
        }
    }
    
    TiXmlNode *cur_child = NULL;
    for (cur_child = p_pCurNode->FirstChild(); (cur_child != NULL); cur_child = cur_child->NextSibling())
        if(cur_child->Type() == TiXmlNode::TINYXML_ELEMENT)
            ExportNode(cur_child, p_pOutFile);
}


void PlainFmtFile::ExportDoc(void)
{
FILE *out_file = fopen((const char *)m_lpszFileName, "w");
    KP_ASSERT(out_file != NULL, KP_E_DIR_ERROR, m_lpszFileName);

    m_bOutputEmpty = True;
    ExportNode(&m_XmlDoc, out_file);

    KP_ASSERT(fclose(out_file) != EOF, KP_E_FERROR, m_lpszFileName);
}
