/* -----------------------------------------------
 *
 * kpstring.h
 *
 *    string tools
 *
 * 2013-04-04  mp  initial creation
 *
 */

#ifndef kpstring_included
#define kpstring_included

extern size_t strlen(const UCHAR *src);

extern UCHAR *strcpy(UCHAR *dest, const UCHAR *src);
extern UCHAR *strcpy(UCHAR *dest, const CHAR *src);
   
extern UCHAR *strncpy(UCHAR *dest, const UCHAR *src, size_t nbytes);

extern UCHAR *strcat(UCHAR *dest, const UCHAR *src);
extern UCHAR *strcat(UCHAR *dest, const CHAR *src);
   
extern /* const */ UCHAR *strchr(/* const */ UCHAR *src, UCHAR ch);

extern int strcmp(const UCHAR *str1, const UCHAR *str2);

#endif // #ifndef kpstring_included
