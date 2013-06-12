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
JsonFmtFile::JsonFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode)
    : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
{
    strcpy(m_lpszJsonFileName, m_lpszFileName);
    strcat(m_lpszJsonFileName, ".json");
}


// ---------------------------------
// char jsonsep = ',';
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
void JsonFmtFile::MakeIndent(FILE *p_pOutFile)
{
int ii;

    for(ii = 0; ii < m_iIndent; ii++)
        fprintf(p_pOutFile, "    ");
}        


void JsonFmtFile::MakeIndent(void)
{
    MakeIndent(m_pFileObj);
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
FILE *out_file = fopen((const CHAR *)m_lpszJsonFileName, "w");
    KP_ASSERT(out_file != NULL, KP_E_DIR_ERROR, m_lpszJsonFileName);

    m_iIndent = 0;

bool output_empty = True;
    ExportNode(&m_XmlDoc, out_file, &output_empty);

    fprintf(out_file, "\n");

    KP_ASSERT(fclose(out_file) != EOF, KP_E_FERROR, m_lpszJsonFileName);
}
