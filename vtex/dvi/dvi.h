/* -----------------------------
 * dvi.h
 *  common dvi file definitions
 *    
 *      2013-06-07  mp  split off from dtl.h 
 *
 */

/* variety of DTL produced */
#define  VARIETY  "sequences-6"

/* version of DTL programs */
#define VERSION "0.6.0"

/* Test for ANSI/ISO Standard C */
#if (defined(__cplusplus) || defined(__STDC__) || defined(c_plusplus))
#define STDC 1
#else
#define STDC 0
#endif

/* Version (Traditional or ANSI) of C affects prototype and type definitions */
#if STDC
#define ARGS(parenthesized_list) parenthesized_list
#else /* NOT STDC */
#define ARGS(parenthesized_list) ()
#endif /* NOT STDC */

#if STDC
#define Void void
#define VOID void
#ifndef FILE_BEGIN
#define FILE_BEGIN SEEK_SET
#endif
#else  /* NOT STDC */
#define Void int
#define VOID
#ifndef FILE_BEGIN
#define FILE_BEGIN 0
#endif
#endif /* NOT STDC */

/* types to store 4 byte signed and unsigned integers */
typedef long  S4;
typedef unsigned long  U4;
/* scanf and printf formats to read or write those */
#define SF4  "%ld"
#define UF4  "%lu"
/* 4 byte hexadecimal */
/* #define XF4  "%04lx" */
#define XF4  "%lx"
/* 4 byte octal */
#define OF4  "%lo"

/* type for byte count for DVI file */
/* COUNT must be large enough to hold a U4 (unsigned 4 byte) value */
typedef U4  COUNT;

/* size of a TeX and DVI word is 32 bits; in some systems a `long int' is needed */
typedef long int word_t;
/* format for a DVI word */
#define WF "%ld"

/* string of 8-bit characters for machine: keyboard, screen, memory */

#define MAXSTRLEN 256
typedef char String[MAXSTRLEN+1];

