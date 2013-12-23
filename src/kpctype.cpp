// ==================================================
// kpctype.cpp
// type conversations & character processing for KP C++ projects
//


// ======================================= definitions
#include "envir.h"

#include <ctype.h>
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


// -------------------------------------------
// predefined spec. character strings
uchar lpszSpaces[] = " \t\xA0"; // C_NBSP
uchar lpszEols[] =   "\r\n";      // "\r\n\f";
uchar lpszSpcEol[] = " \t\xA0\r\n"; // C_NBSP // " \t\r\n\f";
uchar lpszSpcEolNotNBSP[] = " \t\r\n";
uchar lpszSpcEolNotTabNotFF[] = " \r\n";

uchar lpszSpCharsSpcEol[] = "/.,- \t\r\n";


// --------------------------------------------------
bool KpIsDigit(KpChar p_uiCh)
{
bool retv = False;

   switch(p_uiCh)
   {
      case C_0:
      case C_1:
      case C_2:
      case C_3:
      case C_4:
      case C_5:
      case C_6:
      case C_7:
      case C_8:
      case C_9:
         retv = True;
         break;
   }

return(retv);
}


// --------------------------------------------------
HRESULT TestAllowed
(
const uchar *p_lpszCheckString,
const uchar *p_lpszCharsAllowed
)
{
HRESULT retc = S_OK;

    KP_ASSERT(p_lpszCheckString, E_INVALIDARG, null);
    KP_ASSERT(p_lpszCharsAllowed, E_INVALIDARG, null);

const uchar *pntc = p_lpszCheckString;
    while ((*pntc) && SUCCEEDED(retc))
        if (strchr(p_lpszCharsAllowed, *pntc++) == NULL)
            retc = KP_E_UNKN_CHR;

return(retc);
}


// ----------------------------
bool KpIsNumber(const uchar *p_lpszString)
{
bool retv = True;

    KP_ASSERT(p_lpszString, E_INVALIDARG, null);

uchar *buf = null;
    KP_NEWA(buf, uchar, strlen(p_lpszString) + 1);
    strcpy(buf, p_lpszString);
    KpStripLeading(buf);

const uchar *pntc = buf;
    if (*pntc == Nul) retv = False;
    else
        while ((*pntc) && retv)
            if (!isdigit(*pntc++))
            {
                retv = False;
                break;
            }

   KP_DELETEA(buf);

return(retv);
}


bool KpIsHexNum(const uchar *p_lpszHexString)
{
return (SUCCEEDED(TestAllowed(p_lpszHexString, (const uchar *)"0123456789ABCDEFabcdef")));
}


bool KpIsOctNum(const uchar *p_lpszOctString)
{
return (SUCCEEDED(TestAllowed(p_lpszOctString, (const uchar *)"01234567")));
}


bool KpIsRomNum(const uchar *p_lpszRomanString)
{
return (SUCCEEDED(TestAllowed(p_lpszRomanString, (const uchar *)"IVXLCM")));
}
