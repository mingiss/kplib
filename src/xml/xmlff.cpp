/* -----------------------------
 * xmlff.cpp
 *      formatted XMl I/O file implementation
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
void XmlFmtFile::ExportDoc(void)
{
//  dump_to_stdout(&m_XmlDoc);
    m_XmlDoc.SaveFile((const CHAR *)m_lpszFileName);
}
