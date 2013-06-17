/* -----------------------------
 * kptree.cpp
 *      tree-like structure implementation
 *      
 *  Changelog:
 *      2013-06-11  mp  initial creation
 *       
 */  

// --------------------------
#include "envir.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
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
#include "kptree.h"


// visi templatinti metodai iškelti į hederį

