/* ----------------
 * rti.cpp
 *      {keyword, value} (runtime info) tag processing
 *      implementation
 *
 *  Changelog:
 *      2013-06-07  mp  split off from drti.c
 *
 */

#include "envir.h"

#include <stdio.h>
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

#include "rti.h"


// -----------------------------
void str_del(UCHAR *t, UCHAR *s, const UCHAR *p_lpszHead)
{
  int iC, iB; 
  iC = strlen(p_lpszHead);
  iB = strlen(s) - iC;
  //  printf("%d-%d\n", iC, iB);
  memcpy(&t[0], &s[iC], iB);
  t[iB] = '\0';
  //  printf("%s\n", t);
}


void add_to_rti(const UCHAR *p_lpszKwdStr, prti p_pRti)
{
HRESULT retc = S_OK;
prti rti_ptr = p_pRti;
UCHAR kwd_str_buf[RTI_KWD_LEN + 1];
/* const */ UCHAR *cur_kwd = null;
UCHAR tag_name[RTI_KWD_LEN + 1];
UCHAR tag_val[RTI_KWD_LEN + 1];

    KP_ASSERT((p_lpszKwdStr != null) && (p_pRti != NULL), E_INVALIDARG, null);

// ieškom p_pRti galo
    rti_ptr = p_pRti;
    while (rti_ptr->name[0] != Nul) rti_ptr++;
    
// pradedam tagų skanavimą    
    KP_ASSERTW(strlen(p_lpszKwdStr) <= RTI_KWD_LEN, KP_E_BUFFER_OVERFLOW, null);
    if (SUCCEEDED(retc))
    { 
        strcpy(kwd_str_buf, p_lpszKwdStr);
        cur_kwd = (/* const */ UCHAR *)strtok((CHAR *)kwd_str_buf, "}"); // RTI_CLOSING_BRACE
    }
        
// pildom p_pRti
    while ((cur_kwd != null) && SUCCEEDED(retc))
    {
        // valom tarpus pradžioj
        while(*cur_kwd == Spc) cur_kwd++;
        // ar ne tuščia eilutė?
        if(*cur_kwd != Nul)
        {
            KP_ASSERTW(rti_ptr - p_pRti < RTI_NUM_OF_KWDS, KP_E_BUFFER_OVERFLOW, null);
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
        cur_kwd = (/* const */ UCHAR *)strtok(NULL, "}"); // RTI_CLOSING_BRACE
    }
}

int split_strings(UCHAR *t, UCHAR *tt, /* const */ UCHAR *s)
{
/* const */ UCHAR *ps; 
  ps = strchr(s, RTI_EQ_SIGN); // '='
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
    if(*ps == RTI_OPENING_BRACE) ps++; // '{'
    strcpy(tt, ps);
    m = strlen(tt);
    if(m > 0) if(tt[m - 1] == RTI_CLOSING_BRACE) tt[m - 1] = Nul; // '}' 
  
  return 0;
}

