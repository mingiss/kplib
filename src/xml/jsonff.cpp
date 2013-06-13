/* -----------------------------
 * jsonff.cpp
 *      JSON format file I/O implementation
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
#include "jsonff.h"


// ---------------------------------
FmtFile *CreateJsonFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, JsonFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void JsonFmtFile::MakeIndent(FILE *p_pOutFile)
{
int ii;

    for(ii = 0; ii < m_iIndent; ii++)
        fprintf(p_pOutFile, "    ");
}        


// ---------------------------------
void JsonFmtFile::ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile, bool *p_pbOutputEmpty)
{
    KP_ASSERT((p_pCurNode != NULL) && (p_pbOutputEmpty != NULL), E_INVALIDARG, null);
    KP_ASSERT(p_pOutFile != NULL, KP_E_NO_FILE, null);

    if(p_pCurNode->Type() == TiXmlNode::TINYXML_ELEMENT)
    {
    const UCHAR *tag_name = (const UCHAR *)p_pCurNode->Value();
        KP_ASSERT(tag_name != null, E_POINTER, null);

        if(strcmp(tag_name, DRTI_XML_GRP_TAG) != 0) // "xml"
        {
            if(p_pCurNode->PreviousSibling() != NULL) fprintf(p_pOutFile, ",");
            fprintf(p_pOutFile, "\n");
    
            MakeIndent(p_pOutFile);
            fprintf(p_pOutFile, "\"%s\":", (const CHAR *)tag_name);

const UCHAR *value = GetNodeVal(p_pCurNode);
            if(value != null) fprintf(p_pOutFile, " \"%s\"", value);
        }
    }
    
bool children_put_out = False;    
    
    TiXmlNode* cur_child = NULL;
    for (cur_child = p_pCurNode->FirstChild(); (cur_child != NULL); cur_child = cur_child->NextSibling())
        if(cur_child->Type() == TiXmlNode::TINYXML_ELEMENT)
        {
bool make_indent = (p_pCurNode->Type() == TiXmlNode::TINYXML_ELEMENT); // dokumentui nereikia, užteks nuo <xml>        
            if (make_indent)
            {
                if((!children_put_out))
                {
                    children_put_out = True;
                    
                    if(!*p_pbOutputEmpty)
                        fprintf(p_pOutFile, "\n");
                    *p_pbOutputEmpty = False;
                                            
                    MakeIndent(p_pOutFile);
                    fprintf(p_pOutFile, "{");
                }
                m_iIndent ++;
            }
        
            ExportNode(cur_child, p_pOutFile, p_pbOutputEmpty);
    
            if (make_indent) m_iIndent --;
        }
        
    if (children_put_out)
    {
        fprintf(p_pOutFile, "\n");
        MakeIndent(p_pOutFile);
        fprintf(p_pOutFile, "}");
    }
}


void JsonFmtFile::ExportDoc(void)
{
FILE *out_file = fopen((const CHAR *)m_lpszFileName, "w");
    KP_ASSERT(out_file != NULL, KP_E_DIR_ERROR, m_lpszFileName);

    m_iIndent = 0;

bool output_empty = True;
    ExportNode(&m_XmlDoc, out_file, &output_empty);

    fprintf(out_file, "\n");

    KP_ASSERT(fclose(out_file) != EOF, KP_E_FERROR, m_lpszFileName);
}
