/* -----------------------------
 * yamlff.cpp
 *      YAML format file I/O implementation
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
#include "yamlff.h"


// ---------------------------------
FmtFile *CreateYamlFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, YamlFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void YamlFmtFile::MakeIndent(FILE *p_pOutFile)
{
int ii;

    for (ii = 0; ii < m_iIndent; ii++)
        fprintf(p_pOutFile, "    ");
}        


// ---------------------------------
void YamlFmtFile::ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile)
{
int indent = 0;

    KP_ASSERT(p_pCurNode, E_INVALIDARG, null);
    KP_ASSERT(p_pOutFile, KP_E_NO_FILE, null);

    if (p_pCurNode->Type() == TiXmlNode::TINYXML_ELEMENT)
    {
    const uchar *tag_name = (const uchar *)p_pCurNode->Value();
        KP_ASSERT(tag_name, E_POINTER, null);

        if (strcmp(tag_name, DRTI_XML_GRP_TAG)) // "xml"
        {
            indent = 1;
            
            MakeIndent(p_pOutFile);
            fprintf(p_pOutFile, "%s:", (const char *)tag_name);

const uchar *value = GetNodeVal(p_pCurNode);
            if (value) fprintf(p_pOutFile, " %s", value);

            fprintf(p_pOutFile, "\n");
        }
    }
    
    m_iIndent += indent;
    
    TiXmlNode *cur_child = NULL;
    for (cur_child = p_pCurNode->FirstChild(); cur_child; cur_child = cur_child->NextSibling())
        if (cur_child->Type() == TiXmlNode::TINYXML_ELEMENT)
            ExportNode(cur_child, p_pOutFile);
    
    m_iIndent -= indent;
}


void YamlFmtFile::ExportDoc(void)
{
FILE *out_file = fopen((const char *)m_lpszFileName, "w");
    KP_ASSERT(out_file, KP_E_DIR_ERROR, m_lpszFileName);

    fprintf(out_file, "---\n");

    ExportNode(&m_XmlDoc, out_file);

    KP_ASSERT(fclose(out_file) != EOF, KP_E_FERROR, m_lpszFileName);
}
