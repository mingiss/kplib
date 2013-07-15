/* -----------------------------
 * plistff.cpp
 *      PLIST format file I/O implementation
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
#include "plistff.h"


// ---------------------------------
FmtFile *CreatePlistFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;
    KP_NEW(fmt_file, PlistFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// ---------------------------------
void PlistFmtFile::TransferNode(TiXmlNode *p_pSrcNode, TiXmlNode *p_pDestParNode)
{
    KP_ASSERT((p_pSrcNode != NULL) && (p_pDestParNode != NULL), E_INVALIDARG, null);

TiXmlElement *dest_child = NULL;

    if(p_pSrcNode->Type() == TiXmlNode::TINYXML_ELEMENT)
    {
    const uchar *tag_name = (const uchar *)p_pSrcNode->Value();
        KP_ASSERT(tag_name != null, E_POINTER, null);

        if(strcmp(tag_name, DRTI_XML_GRP_TAG) != 0) // "xml"
        {
            KP_NEW(dest_child, TiXmlElement("key"));

TiXmlText *text = NULL;
            KP_NEW(text, TiXmlText((const char *)tag_name));
            dest_child->LinkEndChild(text);
            text = NULL;

            p_pDestParNode->LinkEndChild(dest_child);
            dest_child = NULL;

const uchar *value = GetNodeVal(p_pSrcNode);
            if(value != null)
            {
                KP_NEW(dest_child, TiXmlElement("string"));
                
                KP_NEW(text, TiXmlText((const char *)value));
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

    m_PlistDoc.SaveFile((const char *)m_lpszFileName);
}
