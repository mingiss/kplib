/* dtl.h
   
   This file is public domain.
   Originally written 1995, Geoffrey Tobin.
   The author has expressed the hope that any modification will retain enough content to remain useful. He would also appreciate being acknowledged as the original author in the documentation.
   This declaration added 2008/11/14 by Clea F. Rees with the permission of Geoffrey Tobin.

   - header for dv2dt.c and dt2dv.c, conversion programs
     for human-readable "DTL" <-> DVI.
   - (ANSI C) version 0.6.0 - 18:31 GMT +11  Wed 8 March 1995
   - author: Geoffrey Tobin    G.Tobin@ee.latrobe.edu.au
   - patch:  Michal Tomczak-Jaegermann   ntomczak@vm.ucs.ualberta.ca
   - Reference:  "The DVI Driver Standard, Level 0",
                 by  The TUG DVI Driver Standards Committee.
                 Appendix A, "Device-Independent File Format".
*/

/*
 *  2013-06-07  mp  common dvi file definitions split off to dvi.h 
 *
 */
 
      
// ----------------------   
/* Is each DTL command parenthesised by a BCOM and an ECOM? */
extern int group;

/* signals of beginning and end of a command and its arguments */
/* these apply only if group is nonzero */

# define  BCOM  "{"
# define  ECOM  "}"

# define BCOM_CHAR '{'
# define ECOM_CHAR '}'

#define PRINT_BCOM   if (group) fprintf (dtl, "%s", BCOM)
#define PRINT_ECOM   if (group) fprintf (dtl, "%s", ECOM)

/* beginning and end of a message string */
#define  BMES  "'"

#define  EMES  BMES

#define  BMES_CHAR  '\''
#define  EMES_CHAR  BMES_CHAR

/* beginning and end of sequence of font characters */

#define  BSEQ  "("
#define  ESEQ  ")"

#define  BSEQ_CHAR  '('
#define  ESEQ_CHAR  ')'

/* escape and quote characters */

#define  ESC_CHAR  '\\'
#define  QUOTE_CHAR  '\"'

/* command names in DTL */

#define  SETCHAR  "\\"
#define  SET      "s"
#define  SET1     "s1"
#define  SET2     "s2"
#define  SET3     "s3"
#define  SET4     "s4"
#define  SETRULE  "sr"
#define  PUT      "p"
#define  PUT1     "p1"
#define  PUT2     "p2"
#define  PUT3     "p3"
#define  PUT4     "p4"
#define  PUTRULE  "pr"
#define  NOP      "nop"
#define  BOP      "bop"
#define  EOP      "eop"
#define  PUSH     "["
#define  POP      "]"
#define  RIGHT    "r"
#define  RIGHT1   "r1"
#define  RIGHT2   "r2"
#define  RIGHT3   "r3"
#define  RIGHT4   "r4"
#define  W        "w"
#define  W0       "w0"
#define  W1       "w1"
#define  W2       "w2"
#define  W3       "w3"
#define  W4       "w4"
#define  X        "x"
#define  X0       "x0"
#define  X1       "x1"
#define  X2       "x2"
#define  X3       "x3"
#define  X4       "x4"
#define  DOWN     "d"
#define  DOWN1    "d1"
#define  DOWN2    "d2"
#define  DOWN3    "d3"
#define  DOWN4    "d4"
#define  Y        "y"
#define  Y0       "y0"
#define  Y1       "y1"
#define  Y2       "y2"
#define  Y3       "y3"
#define  Y4       "y4"
#define  Z        "z"
#define  Z0       "z0"
#define  Z1       "z1"
#define  Z2       "z2"
#define  Z3       "z3"
#define  Z4       "z4"
#define  FONT     "f"
#define  FONT1    "f1"
#define  FONT2    "f2"
#define  FONT3    "f3"
#define  FONT4    "f4"
#define  FONTDEF  "fd"
#define  FONTNUM  "fn"
#define  SPECIAL  "special"
#define  PRE      "pre"
#define  POST     "post"
#define  POSTPOST "post_post"
#define  OPCODE   "opcode"

/* string s of length l and maximum length m */
typedef struct {int l; int m; char * s;} Lstring;


/* end dtl.h */