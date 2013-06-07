/* ----------------
 * dvread.h
 *      reading of .dvi file
 *      definitions 
 *
 *
 *  Changelog:
 *      2013-06-07  mp  split off from drti.c
 *
 */

#ifndef dvread_included
#define dvread_included

// -----------------------------
struct op_info_st {int code; char * name; int nargs; char * args; };

typedef  struct op_info_st  op_info;


// -----------------------------
/*
  table's:
     name,
     first opcode,
     last opcode,
     pointer to opcode info.
*/
typedef struct {char * name; int first; int last; op_info * list; } op_table;

/* Table for opcodes 128 to 170 inclusive. */
extern op_info  op_info_128_170 [];

extern op_table  op_128_170;

/* Table for font with 1 to 4 bytes (opcodes 235 to 238) inclusive. */

extern op_info  fnt_n [];

extern op_table  fnt;


// ---------------------------
/* function prototypes */

extern PLAIN_C int open_dvi ARGS((const UCHAR * dvi_file, FILE ** dvi));
extern PLAIN_C int dvread ARGS((FILE * dvi, FILE * dtl));

extern PLAIN_C COUNT wunsigned ARGS((int n,  FILE * dvi,  FILE * dtl));
extern PLAIN_C COUNT wsigned   ARGS((int n,  FILE * dvi,  FILE * dtl));
extern PLAIN_C S4 rsigned   ARGS((int n,  FILE * dvi));
extern PLAIN_C U4 runsigned ARGS((int n,  FILE * dvi));

extern PLAIN_C COUNT wtable ARGS((op_table table, int opcode, FILE * dvi, FILE * dtl));

extern PLAIN_C COUNT setseq ARGS((int opcode, FILE * dvi, FILE * dtl));
extern PLAIN_C Void setpchar ARGS((int charcode, FILE * dtl));
extern PLAIN_C Void xferstring ARGS((int k, FILE * dvi, FILE * dtl));
extern PLAIN_C Void xxxferstring ARGS((int k, FILE * dvi, FILE * dtl));

extern PLAIN_C COUNT special ARGS((FILE * dvi,  FILE * dtl,  int n));
extern PLAIN_C COUNT fontdef ARGS((FILE * dvi,  FILE * dtl,  int n));
extern PLAIN_C COUNT preamble  ARGS((FILE * dvi,  FILE * dtl));
extern PLAIN_C COUNT postamble ARGS((FILE * dvi,  FILE * dtl));
extern PLAIN_C COUNT postpost  ARGS((FILE * dvi,  FILE * dtl));


#endif // #ifndef dvread_included
