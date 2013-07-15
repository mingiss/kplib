// ==================================================
// kpctype.cpp
// type conversations & character processing for KP C++ projects
//


// ======================================= definitions
#include "envir.h"

#include <ctype.h>
#ifdef __WIN32__
#include <windows.h>
#endif

using namespace std;

#include "kperrno.h"
#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"


// =========================================== predefined spec. character strings
uchar lpszSpaces[] = " \t\xA0"; // C_NBSP
uchar lpszEols[] =   "\r\n";      // "\r\n\f";
uchar lpszSpcEol[] = " \t\xA0\r\n"; // C_NBSP // " \t\r\n\f";
uchar lpszSpcEolNotNBSP[] = " \t\r\n";
uchar lpszSpcEolNotTabNotFF[] = " \r\n";

uchar lpszSpCharsSpcEol[] = "/.,- \t\r\n";
