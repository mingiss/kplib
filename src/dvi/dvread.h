/* ----------------
 * dvread.h
 *      reading of .dvi file
 *      definition of DviRead class 
 *
 *
 *  Changelog:
 *      2013-06-07  mp  split off from drti.c
 *      2013-06-20  mp  DviRead class implemented 
 *
 */

#ifndef dvread_included
#define dvread_included

// -----------------------------
#define DVREAD_MAX_NUM_OF_ARGS 11 // max value of op_info_st.nargs

typedef enum
{
    DVREAD_TransExtChar_NoIx = -1, // no processing of the opcode
    
    DVREAD_TransExtChar_Ix = 3,
    
} TransFunIxes;


struct op_info_st {int code; const char * name; int nargs; const char * args; 
    TransFunIxes m_iCallbackIx; // index of the callback method in the vtable 
    };

typedef  struct op_info_st  op_info;


// -----------------------------
/*
  table's:
     name,
     first opcode,
     last opcode,
     pointer to opcode info.
*/
typedef struct {const char * name; int first; int last; op_info * list; } op_table;

/* Table for opcodes 128 to 170 inclusive. */
extern op_info  op_info_128_170 [];

extern op_table  op_128_170;

/* Table for font with 1 to 4 bytes (opcodes 235 to 238) inclusive. */

extern op_info  fnt_n [];

extern op_table  fnt;


// ---------------------------
class DviRead
{
    UCHAR m_lpszInFileName[KP_MAX_FNAME_LEN + 1]; // input DVI file name
public:
    FILE *m_pDviFile; // input DVI file object

    DviRead(void);
    virtual ~DviRead();
    
    virtual void Open(const UCHAR *p_lpszDviFileName);
    void Close(void);
    
    int dvread(void);

    COUNT wunsigned(int n);
    COUNT wsigned(int n);
    S4 rsigned(int n);
    U4 runsigned(int n);
    
    COUNT wtable(op_table table, int opcode);
    
    COUNT setseq(int opcode);
    Void setpchar(int charcode);
    
    COUNT special(int n);
    COUNT fontdef(int n);
    COUNT preamble(void);
    COUNT postamble(void);
    COUNT postpost(void);

    // skips p_iNumOfBytes of m_pDviFile
    // can be used as void substitutes for other RtiTrans*()
    // former RtiSkipInBytes() 
    void SkipInBytes(int p_iNumOfBytes); 
    
    // ------------------------
    // dvread() callbacks of the inherited parser
    
    // --------------------------
    // variable args callbacks, starting from the 2-nd (3-d?) record of vtable (after ~DviRead() and Open())
    // order of appearance should correspond to entries of TransFunIxes 
    virtual void TransExtChar(int p_iCharCode) {};

    // --------------------------
    // other callbacks
    virtual void CmdOpen(void){}   /* start of command and parameters */ // former RtiCmdOpen()
    virtual void CmdClose(void){}  /* end of command and parameters */ // former RtiCmdClose()
    
    virtual void TransPreamble(int p_iDviId, int p_iDviNum, int p_iDviDenom, int p_iMagn, int p_iNumOfBytes)\
        { SkipInBytes(p_iNumOfBytes); } // former RtiTransPreamble()
    
    // p_iFontNumLen - fonto numerio ilgis baitais, DVI komandos fnt_defK numeris
    // dar reikia iš failo m_pDviFile perskaityt p_iFontDirLen + p_iFontNameLen baitų --
    // font area (path, dirname) ir font name
    // former RtiTransFontDef()
    virtual void TransFontDef(int p_iFontNumLen, int p_iFontNum, int p_iCheckSum, 
        int p_iScaleFactor, int p_iFontSize, 
        int p_iFontDirLen, int p_iFontNameLen){ SkipInBytes(p_iFontDirLen + p_iFontNameLen); }

    virtual void TransText(const UCHAR *p_lpszStr) {};
    
    // \special{} tag processing
    // dar reikia iš failo m_pDviFile perskaityt p_iNumOfBytes baitų -- \special komandos kūną
    // former RtiTransSpec() 
    virtual void TransSpec(int p_iNumOfBytes){ SkipInBytes(p_iNumOfBytes); }
};

// vtable entry to the virtual callback method
typedef void (*TransFunPtr)(
    DviRead *p_pThisPtr,    // this -- first parameter to the class methods 
    ...);                   // the rest -- variable amount of int's, depending on DVI opcode 

#endif // #ifndef dvread_included
