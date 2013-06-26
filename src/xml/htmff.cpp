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
FmtFile *CreateHtmFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode)
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
    
// <!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
TiXmlElement* dest_child = NULL;
    KP_NEW(dest_child, TiXmlElement("!DOCTYPE"));
    dest_child->SetAttribute("html", "");
    dest_child->SetAttribute("PUBLIC", "");
    dest_child->SetAttribute("", "-//W3C//DTD XHTML 1.0 Strict//EN");
    dest_child->SetAttribute("", "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd");
    m_XmlDoc.LinkEndChild(dest_child);
    dest_child = NULL;

    if(p_HeadNode != NULL) m_XmlDoc.LinkEndChild(p_HeadNode);

    KP_NEW(dest_child, TiXmlElement("html"));
    dest_child->SetAttribute("xmlns", "http://www.w3.org/1999/xhtml");
    dest_child->SetAttribute("xml:lang", "en");
    dest_child->SetAttribute("lang", "en");
    m_XmlDoc.LinkEndChild(dest_child);
    
return(dest_child);
}
