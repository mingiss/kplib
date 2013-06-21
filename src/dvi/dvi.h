/* -----------------------------
 * dvi.h
 *  common dvi file definitions
 *    
 *      2013-06-07  mp  split off from dtl.h 
 *
 *  TODO: sutikrint dvread signed/unsigned parametrus
 *  TODO: surašyt/pervadint parametrų reikšmes iš dvi.html
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


/* beginning and end of a message string */
#define  BMES  "'"

#define  EMES  BMES

#define  BMES_CHAR  '\''
#define  EMES_CHAR  BMES_CHAR

/* escape and quote characters */
#define  ESC_CHAR  '\\'
#define  QUOTE_CHAR  '\"'

/* beginning and end of sequence of font characters */
#define  BSEQ  "("
#define  ESEQ  ")"

#define  BSEQ_CHAR  '('
#define  ESEQ_CHAR  ')'


// DVI commands
typedef enum
{
    // typeset a character and move right
    // opcode - DVI_set_char -- character code 
    DVI_set_char,   // 0...127     set_char_i         
        DVI_set_char_last = 127,
           
    // typeset a character and move right
    //  c -- character code
    DVI_set,        // 128     set1     c[1]     
                    // 129     set2     c[2]
                    // 130     set3     c[3]
                    // 131     set4     c[4]
        DVI_set_last = 131,                

    DVI_set_rule,   // 132     set_rule     a[4], b[4]     typeset a rule and move right
    
    // typeset a character
    // not move
    //  c -- character code
    DVI_put,        // 133     put1     c[1]     
                    // 134     put2     c[2]
                    // 135     put3     c[3]
                    // 136     put4     c[4]
        DVI_put_last = 136,

    DVI_put_rule,   // 137     put_rule     a[4], b[4]     typeset a rule
    
    DVI_nop,        // 138     nop         no operation
    
    // beginning of page
    //  c_0 -- page number
    //  p -- previous bop position (byte offset in the DVI file); -1 for first page
    DVI_bop,        // 139     bop     c_0[4]..c_9[4], p[4]     
    
    DVI_eop,        // 140     eop         ending of page
    DVI_push,       // 141     push         save the current positions
    DVI_pop,        // 142     pop         restore previous positions
    DVI_right,      // 143     right1     b[1]     move right
                    // 144     right2     b[2]
                    // 145     right3     b[3]
                    // 146     right4     b[4]
        DVI_right_last = 146,   
    DVI_w,          // 147     w0         move right by w
                    // 148     w1     b[1]     move right and set w
                    // 149     w2     b[2]
                    // 150     w3     b[3]
                    // 151     w4     b[4]
        DVI_w_last = 151,
    DVI_x,          // 152     x0         move right by x
                    // 153     x1     b[1]     move right and set x
                    // 154     x2     b[2]
                    // 155     x3     b[3]
                    // 156     x4     b[4]
        DVI_x_last = 156,                 
    DVI_down,       // 157     down1     a[1]     move down
                    // 158     down2     a[2]
                    // 159     down3     a[3]
                    // 160     down4     a[4]
        DVI_down_last = 160,                    
    DVI_y,          // 161     y0         move down by y
                    // 162     y1     a[1]     move down and set y
                    // 163     y2     a[2]
                    // 164     y3     a[3]
                    // 165     y4     a[4]
        DVI_y_last = 165,                    
    DVI_z,          // 166     z0         move down by z
                    // 167     z1     a[1]     move down and set z
                    // 168     z2     a[2]
                    // 169     z3     a[3]
                    // 170     z4     a[4]
        DVI_z_last = 170,

    // set current font to i
    // opcode - DVI_fnt_num -- font number 
    DVI_fnt_num,    // 171...234     fnt_num_i         
        DVI_fnt_num_last = 234, 
    
    // set current font
    // k -- font number 
    DVI_fnt,        // 235     fnt1     k[1]     
                    // 236     fnt2     k[2]
                    // 237     fnt3     k[3]
                    // 238     fnt4     k[4]
        DVI_fnt_last = 238,                    
    
    // extension to DVI primitives
    // \special
    //  k -- length of the special body
    //  x -- special body
    DVI_xxx,        // 239     xxx1     k[1], x[k]     
                    // 240     xxx2     k[2], x[k]
                    // 241     xxx3     k[3], x[k]
                    // 242     xxx4     k[4], x[k]
        DVI_xxx_last = 242,                    

    // define the meaning of a font number      
    //  k -- font number                       
    //  c -- check sum                         
    //  s -- scale factor                      
    //  d -- font size                         
    //  a -- length of font area (path, dirname) 
    //  l -- font name length
    //  p -- font area (path, dirname)
    //  n -- font name                                          
    DVI_fnt_def,    // 243     fnt_def1     k[1], c[4], s[4], d[4], a[1], l[1], p[a], n[l]
                    // 244     fnt_def2     k[2], c[4], s[4], d[4], a[1], l[1], p[a], n[l]
                    // 245     fnt_def3     k[3], c[4], s[4], d[4], a[1], l[1], p[a], n[l]
                    // 246     fnt_def4     k[4], c[4], s[4], d[4], a[1], l[1], p[a], n[l]
        DVI_fnt_def_last = 246,                                                       
                                                                                     
    // preamble
    //  i -- DVI format identification
    //  num -- numerator of DVI unit
    //  den -- denominator of DVI unit
    //  mag -- 1000 x magnification
    //  k -- length of comment
    //  x -- comment string
    DVI_pre,        // 247     pre     i[1], num[4], den[4], mag[4], k[1], x[k]
    
    // postamble beginning
    //  p -- last bop position
    //  num -- numerator of DVI unit, same as in preamble
    //  den -- denominator of DVI unit, same as in preamble
    //  mag -- 1000 x magnification, same as in preamble
    //  l -- height + depth of tallest page
    //  u -- width of widest page
    //  s -- maximum stack depth
    //  t -- total number of pages (bop commands)
    DVI_post,       // 248     post     p[4], num[4], den[4], mag[4], l[4], u[4], s[2], t[2] < font definitions >     
    
    // postamble ending
    //  q -- postamble beginning position (byte offset of the post command in the DVI file)
    //  i -- DVI format identification, same as in preamble
    DVI_post_post,  // 249     post_post     q[4], i[1]; 223's    
    
    // undefined
    DVI_undefined,  // 250...255     
        DVI_undefined_last = 255     

} DviCmds;
     
#define DVI_POST_SIGNATURE 223
