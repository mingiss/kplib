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

#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"


// =========================================== predefined spec. character strings
UCHAR lpszSpaces[] = " \t\xA0"; // C_NBSP
UCHAR lpszEols[] =   "\r\n";      // "\r\n\f";
UCHAR lpszSpcEol[] = " \t\xA0\r\n"; // C_NBSP // " \t\r\n\f";
UCHAR lpszSpcEolNotNBSP[] = " \t\r\n";
UCHAR lpszSpcEolNotTabNotFF[] = " \r\n";
