/* ----------------
 * dvisp.cpp
 *      reading special tags of DVI file
 *      implementation (of the class DviSp) 
 *
 *  Changelog:
 *      2013-06-07  mp  split from drti.c
 *
 *  TODO: perdaryt į XML medį XmlNode su išvedimo draiveriais KpFile
 *  TODO: "vtex:settings.sometool" opcijas kaupt dinamiškai kuriant grupinius tagus bet kokioms "sometool"
 *                 
 */

#include "envir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <iostream>
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpmsg.h"
#include "kperr.h"

#include "dvi.h"
#include "rti.h"
#include "dvread.h"

// TODO: po pilno atskyrimo išmest 
#include "dtl.h"
#include "drtim.h"

#include "dvisp.h"


// -----------------------------
const UCHAR *lpszaIgnoreSpecList[] =
{
    (const UCHAR *)"\" ",
    (const UCHAR *)"!", 
    (const UCHAR *)"ps:", 
    (const UCHAR *)"PSfile=",

    (const UCHAR *)"color ",
    (const UCHAR *)"background ",
    
    (const UCHAR *)"em: graph ",
    (const UCHAR *)"mt:destination",

    (const UCHAR *)"vtex:bmc.artifact.",
    (const UCHAR *)"vtex:emc.artifact.",

    (const UCHAR *)"fp",
    (const UCHAR *)"bk",
    (const UCHAR *)"sp",
    (const UCHAR *)"pn ", // "pn 5"
    (const UCHAR *)"pa ", // "pa 639 -2122"
    (const UCHAR *)"ar ", // "ar 0 0 26 26 0 6.2832"
    
    null
};

const UCHAR *lpszaIgnoreFullSpecList[] =
{
    (const UCHAR *)"MC:Contents",
    
    (const UCHAR *)"BMC:Book/SpringerURL",
    (const UCHAR *)"BMC:BookCopyright/CopyrightHolderName",
    (const UCHAR *)"BMC:BookCopyright/CopyrightYear",
    (const UCHAR *)"BMC:BookCopyright/CopyrightYearFormerEditions",
    (const UCHAR *)"BMC:Contents",
    (const UCHAR *)"BMC:MyCopy/Intro",
    (const UCHAR *)"BMC:MyCopy/SpringerURL",
    (const UCHAR *)"BMC:text",
    (const UCHAR *)"BMC:VTEX/LCCN",
    (const UCHAR *)"EMC:Book/SpringerURL",
    (const UCHAR *)"EMC:BookCopyright/CopyrightHolderName",
    (const UCHAR *)"EMC:BookCopyright/CopyrightYear",
    (const UCHAR *)"EMC:BookCopyright/CopyrightYearFormerEditions",
    (const UCHAR *)"EMC:Contents",
    (const UCHAR *)"EMC:MyCopy/Intro",
    (const UCHAR *)"EMC:MyCopy/SpringerURL",
    (const UCHAR *)"EMC:text",
    (const UCHAR *)"EMC:VTEX/LCCN",

    (const UCHAR *)"BMC:BookInfo/BookDOI",
    (const UCHAR *)"BMC:BookInfo/BookElectronicISBN",
    (const UCHAR *)"BMC:BookInfo/BookPrintISBN",
    (const UCHAR *)"EMC:BookInfo/BookDOI",
    (const UCHAR *)"EMC:BookInfo/BookElectronicISBN",
    (const UCHAR *)"EMC:BookInfo/BookPrintISBN",
    (const UCHAR *)"BMC:SeriesInfo/SeriesElectronicISSN",
    (const UCHAR *)"BMC:SeriesInfo/SeriesPrintISSN",
    (const UCHAR *)"EMC:SeriesInfo/SeriesElectronicISSN",
    (const UCHAR *)"EMC:SeriesInfo/SeriesPrintISSN",
    
    null
};


// -------------------------
const UCHAR *input_file = null;


// -------------------------
bool kwd_in_plist(const UCHAR *p_lpszaKwdList[], const UCHAR *p_lpszKwd) 
{
HRESULT retc = S_OK;
bool retv = False;
const UCHAR **list_ptr = p_lpszaKwdList;

    KP_ASSERTW((p_lpszaKwdList != NULL) && (p_lpszKwd != null), E_INVALIDARG, null);
    if(SUCCEEDED(retc))
    {
        while (*list_ptr != null)
        {
            if (p_lpszaKwdList == lpszaIgnoreSpecList)
                retv = (strncmp((const CHAR *)p_lpszKwd, (const CHAR *)*list_ptr, strlen(*list_ptr)) == 0);
            else
	           retv = (strcmp(p_lpszKwd, *list_ptr) == 0);
            
            if (retv) break;
            
            list_ptr++;
        }
    }
          
return(retv);
}


