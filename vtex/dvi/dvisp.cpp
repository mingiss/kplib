/* ----------------
 * dvisp.cpp
 *      reading of .dvi file special tags
 *      implementation (of the class DviSp) 
 *
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


// -----------------------------
Void 
str_del(UCHAR *t, UCHAR *s, const UCHAR *p_lpszHead)
{
  int iC, iB; 
  iC = strlen(p_lpszHead);
  iB = strlen(s) - iC;
  //  printf("%d-%d\n", iC, iB);
  memcpy(&t[0], &s[iC], iB);
  t[iB] = '\0';
  //  printf("%s\n", t);
}


Void add_to_rti(const UCHAR *p_lpszKwdStr, prti p_pRti)
{
HRESULT retc = S_OK;
prti rti_ptr = p_pRti;
UCHAR kwd_str_buf[DRTI_KWD_LEN + 1];
/* const */ UCHAR *cur_kwd = null;
UCHAR tag_name[KP_MAX_FILE_LIN_LEN + 1];
UCHAR tag_val[KP_MAX_FILE_LIN_LEN + 1];

    KP_ASSERT((p_lpszKwdStr != null) && (p_pRti != NULL), E_INVALIDARG, null);

// ieškom p_pRti galo
    rti_ptr = p_pRti;
    while (rti_ptr->name[0] != Nul) rti_ptr++;
    
// pradedam tagų skanavimą    
    KP_ASSERTW(strlen(p_lpszKwdStr) <= DRTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
    if (SUCCEEDED(retc))
    { 
        strcpy(kwd_str_buf, p_lpszKwdStr);
        cur_kwd = (/* const */ UCHAR *)strtok((CHAR *)kwd_str_buf, "}"); // DVISP_CLOSING_BRACE
    }
        
// pildom p_pRti
    while ((cur_kwd != null) && SUCCEEDED(retc))
    {
        // valom tarpus pradžioj
        while(*cur_kwd == Spc) cur_kwd++;
        // ar ne tuščia eilutė?
        if(*cur_kwd != Nul)
        {
            KP_ASSERTW(rti_ptr - p_pRti < DRTI_NUM_OF_KWDS, KP_E_BUFFER_OVERFLOW, null);
            if(SUCCEEDED(retc))
            {
                split_strings(tag_name, tag_val, cur_kwd);
                // printf("RTI:%s:\n", tag_name);
 
                strcpy(rti_ptr->name, tag_name); 
                strcpy(rti_ptr->value, tag_val);
                //  printf("RTI:%s:%s\n", tag_val, tag_val);

                rti_ptr++;
        
                // add empty delimiter record
                rti_ptr->name[0] = Nul;
                rti_ptr->value[0] = Nul;
            }
        }
        
        // continue scanning
        cur_kwd = (/* const */ UCHAR *)strtok(NULL, "}"); // DVISP_CLOSING_BRACE
    }
}

int split_strings(UCHAR *t, UCHAR *tt, /* const */ UCHAR *s)
{
/* const */ UCHAR *ps; 
  ps = strchr(s, DVISP_EQ_SIGN); // '='
  int l, m;
  if (ps == NULL)
  {
   printf("Wrong format (no '=' sign) in special \'%s\'\n", s);
   return -1;
  }
  l = ps - s;
// m = strlen(s) - l;

  //  printf("-%i-\n", l);

  strncpy(&t[0], &s[0], l);
  *(&t[l]) = '\0';

// strncpy(&tt[0], &s[l+2], m - 3);
// *(&tt[m-3]) = '\0';
    ps++;
    if(*ps == DVISP_OPENING_BRACE) ps++; // '{'
    strcpy(tt, ps);
    m = strlen(tt);
    if(m > 0) if(tt[m - 1] == DVISP_CLOSING_BRACE) tt[m - 1] = Nul; // '}' 
  
  return 0;
}

