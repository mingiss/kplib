/* -----------------------------------------------
 *
 * kpstring.cpp
 *
 *    string tools
 *
 * 2013-04-05  mp  initial creation
 *
 */

#include "envir.h"

#include <string.h>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "kpstring.h"

size_t strlen(const UCHAR *src){ return(strlen((const CHAR *)src)); }

UCHAR *strcpy(UCHAR *dest, const UCHAR *src)
   { return((UCHAR *)strcpy((CHAR *)dest, (const CHAR *)src)); }
UCHAR *strcpy(UCHAR *dest, const CHAR *src)
   { return((UCHAR *)strcpy((CHAR *)dest, src)); }

UCHAR *strncpy(UCHAR *dest, const UCHAR *src, size_t nbytes)
   { return((UCHAR *)strncpy((CHAR *)dest, (const CHAR *)src, nbytes)); }

UCHAR *strcat(UCHAR *dest, const UCHAR *src)
   { return((UCHAR *)strcat((CHAR *)dest, (const CHAR *)src)); }
UCHAR *strcat(UCHAR *dest, const CHAR *src)
   { return((UCHAR *)strcat((CHAR *)dest, src)); }
   
/* const */ UCHAR *strchr(/* const */ UCHAR *src, UCHAR ch)
   { return((/* const */ UCHAR *)strchr((/* const */ CHAR *)src, ch)); }

int strcmp(const UCHAR *str1, const UCHAR *str2)
   { return(strcmp((const CHAR *)str1, (const CHAR *)str2)); }
