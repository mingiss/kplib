/* -----------------------------
 * htmff.cpp
 *      formatted XHTML I/O file implementation
 *      
 *  Changelog:
 *      2013-06-26  mp  initial creation
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
#include "htmff.h"


// ---------------------------------
FmtFile *CreateHtmFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode)
{
FmtFile *fmt_file = NULL;

    KP_NEW(fmt_file, HtmFmtFile(p_lpszFileName, p_lpszFileMode));

return(fmt_file);
}


// -----------------------------
#if FALSE
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html 
     PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <title>Virtual Library</title>
  </head>
  <body>
    <p>Moved to <a href="http://example.org/">example.org</a>.</p>
  </body>
</html>
#endif

TiXmlElement *HtmFmtFile::CreateHtmHead(TiXmlElement *p_HeadNode)
{
// <?xml version="1.0" encoding="UTF-8"?>
TiXmlDeclaration *dest_decl = NULL;
    KP_NEW(dest_decl, TiXmlDeclaration("1.0", "UTF-8", ""));  
	m_XmlDoc.LinkEndChild(dest_decl);
    dest_decl = NULL; 
    
TiXmlElement* dest_node = NULL;

#if FALSE // neveikia pitstop.js: proc_resize()
// <!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
    KP_NEW(dest_node, TiXmlElement("!DOCTYPE"));
    dest_node->SetAttribute("html", "");
    dest_node->SetAttribute("PUBLIC", "");
    dest_node->SetAttribute("", "-//W3C//DTD XHTML 1.0 Strict//EN");
    dest_node->SetAttribute("", "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd");
    m_XmlDoc.LinkEndChild(dest_node);
    dest_node = NULL;
#endif

    KP_NEW(dest_node, TiXmlElement("html"));
    dest_node->SetAttribute("xmlns", "http://www.w3.org/1999/xhtml");
    dest_node->SetAttribute("xml:lang", "en");
    dest_node->SetAttribute("lang", "en");
    m_XmlDoc.LinkEndChild(dest_node);
    
// <META HTTP-EQUIV="CONTENT-TYPE" CONTENT="text/html; charset=UTF-8">
TiXmlElement* dest_child = NULL;
    KP_NEW(dest_child, TiXmlElement("META"));
    dest_child->SetAttribute("HTTP-EQUIV", "CONTENT-TYPE");
    dest_child->SetAttribute("CONTENT", "text/html; charset=UTF-8");
    dest_node->LinkEndChild(dest_child);

    if(p_HeadNode != NULL) dest_node->LinkEndChild(p_HeadNode);

return(dest_node);
}
