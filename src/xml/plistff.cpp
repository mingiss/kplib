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
#include "plistff.h"


// ---------------------------------
FmtFile *CreatePlistFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;
    KP_NEW(fmt_file, PlistFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
PlistFmtFile::PlistFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode)
    : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
{
    strcpy(m_lpszPlistFileName, m_lpszFileName);
    strcat(m_lpszPlistFileName, ".plist");
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
    
    FmtFile::OpenGrTag(p_lpszGrpTagName);
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
void PlistFmtFile::TransferNode(TiXmlNode *p_pSrcNode, TiXmlNode *p_pDestParNode)
{
    KP_ASSERT((p_pSrcNode != NULL) && (p_pDestParNode != NULL), E_INVALIDARG, null);

TiXmlElement *dest_child = NULL;

    if(p_pSrcNode->Type() == TiXmlNode::TINYXML_ELEMENT)
    {
    const UCHAR *tag_name = (const UCHAR *)p_pSrcNode->Value();
        KP_ASSERT(tag_name != null, E_POINTER, null);

        if(strcmp(tag_name, DRTI_XML_GRP_TAG) != 0) // "xml"
        {
            KP_NEW(dest_child, TiXmlElement("key"));

TiXmlText *text = NULL;
            KP_NEW(text, TiXmlText((const CHAR *)tag_name));
            dest_child->LinkEndChild(text);
            text = NULL;

            p_pDestParNode->LinkEndChild(dest_child);
            dest_child = NULL;

const UCHAR *value = GetNodeVal(p_pSrcNode);
            if(value != null)
            {
                KP_NEW(dest_child, TiXmlElement("string"));
                
                KP_NEW(text, TiXmlText((const CHAR *)value));
                dest_child->LinkEndChild(text);
                text = NULL;
                
                p_pDestParNode->LinkEndChild(dest_child);
                dest_child = NULL;
            }
        }
    }
    
    dest_child = NULL;
TiXmlNode* cur_child = NULL;
    for (cur_child = p_pSrcNode->FirstChild(); (cur_child != NULL); cur_child = cur_child->NextSibling())
        if(cur_child->Type() == TiXmlNode::TINYXML_ELEMENT)
        {
            if(dest_child == NULL)
            {
                KP_NEW(dest_child, TiXmlElement("dict"));
                p_pDestParNode->LinkEndChild(dest_child);
            }
            TransferNode(cur_child, dest_child);
        }
}


// ---------------------------------
void PlistFmtFile::ExportDoc(void)
{
// <?xml version="1.0" encoding="UTF-8"?>
TiXmlDeclaration *dest_decl = NULL;
    KP_NEW(dest_decl, TiXmlDeclaration("1.0", "UTF-8", ""));  
	m_PlistDoc.LinkEndChild(dest_decl);
    dest_decl = NULL; 
    
// <!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
TiXmlElement* dest_child = NULL;
    KP_NEW(dest_child, TiXmlElement("!DOCTYPE"));
    dest_child->SetAttribute("plist", "");
    dest_child->SetAttribute("PUBLIC", "");
    dest_child->SetAttribute("", "-//Apple Computer//DTD PLIST 1.0//EN");
    dest_child->SetAttribute("", "http://www.apple.com/DTDs/PropertyList-1.0.dtd");
    m_PlistDoc.LinkEndChild(dest_child);
    dest_child = NULL;

// <plist version="1.0">
    KP_NEW(dest_child, TiXmlElement("plist"));
    dest_child->SetAttribute("version", "1.0");
    m_PlistDoc.LinkEndChild(dest_child);
    
TiXmlNode *xml_node = FindNodeByName(DRTI_XML_GRP_TAG, &m_XmlDoc);
    TransferNode(xml_node, dest_child);
    dest_child = NULL;

    m_PlistDoc.SaveFile((const CHAR *)m_lpszPlistFileName);
}
