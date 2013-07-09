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


// ---------------------------
class DviRead;

typedef COUNT (DviRead::*DvTransFunPtr)(
    int p_iOpCode,      // DVI op. code (op_info_st.code)
    int p_iFirstArgLen, // (op_info_st.code - m_iFirstGrpOpcode + 1) 
    ...);               // the rest -- variable amount of int's, depending on DVI opcode

#if FALSE
// vtable entry to the virtual callback method
typedef COUNT (*TransFunPtr)(
    DviRead *p_pThisPtr,    // this -- very first hidden parameter to class methods 
    int p_iOpCode,
    int p_iFirstArgLen,
    ...); 
#endif

// -----------------------------
#define DVREAD_MAX_NUM_OF_ARGS 11 // max value of op_info_st.nargs

#if FALSE
typedef enum
{
    DVREAD_Trans_NoIx = -1, // no processing of the opcode
    
    DVREAD_TransExtChar_Ix = 3,
...
    
} TransFunIxes;
#endif

struct op_info_st {int code; const char * name; int nargs; const char * args; 
//  TransFunIxes m_iCallbackIx; // index of the callback method in the vtable, DVREAD_Trans_NoIx -- no callback
    DvTransFunPtr m_pTransFun;  // pointer to the callback methodm, NULL -- no callback
    int m_iFirstGrpOpcode;      // first opcode of the group, 
                                //      (code - m_iFirstGrpOpcode + 1) is passed as the first 
                                //      argument to the TransFunPtr callback
                                //      number of bytes in the very first argument in the commands 
                                //      of variable length argument as well (set1..set4, fnt1..fnt4, etc.)   
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
// extern op_info  fnt_n [];
// extern op_table  fnt;


/* Table for opcodes 235 to 248 inclusive. */
extern op_info op_info_235_248[];
extern op_table op_235_248;


class DviSteps
{
public:
    // horizontal steps in DVI units
    int m_iHorStepW; 
    int m_iHorStepX;
    
    // vertical steps in DVI units
    int m_iVertStepY; 
    int m_iVertStepZ;
    
    // current position in the document in DVI units
    int m_iCurHorPos;
    int m_iCurVertPos;

    DviSteps(void);
};


// ---------------------------
class DviRead
{
    UCHAR m_lpszInFileName[KP_MAX_FNAME_LEN + 1]; // input DVI file name
public:
    FILE *m_pDviFile; // input DVI file object

    KpTreeEntry<DviSteps> *m_pCurSteps; // top of the stack

    int m_iMagn; // magnification * 1000
    int m_iUnitsPerPt;

    // page size
    int m_iHorPtPerPage;
    int m_iVertPtPerPage;

//  int m_iSpaceThreshold; // in pt
//  int m_iEnWdt; // in pt
//  int m_iLineHgt; // in pt

    DviRead(void);
    virtual ~DviRead();
    
    virtual void Open(const UCHAR *p_lpszDviFileName);
    void Close(void);
    
    void SetHorStepW(int p_iHorStepW);
    int GetHorStepW(void);
    void SetHorStepX(int p_iHorStepX);
    int GetHorStepX(void);
    void SetVertStepY(int p_iVertStepY);
    int GetVertStepY(void);
    void SetVertStepZ(int p_iVertStepZ);
    int GetVertStepZ(void);

    void SetCurHorPos(int p_iHorPos);
    void IncCurHorPos(int p_iOffset);
    int GetCurHorPos(void);
    void SetCurVertPos(int p_iVertPos);
    void IncCurVertPos(int p_iOffset);
    int GetCurVertPos(void);

    int dvread(void);

    COUNT wunsigned(int n);
    COUNT wsigned(int n);
    S4 rsigned(int n);
    U4 runsigned(int n);
    
    COUNT wtable(op_table table, int opcode);
    
    COUNT setseq(int opcode);
    Void setpchar(int charcode);
    
//  COUNT special(int n);
//  COUNT fontdef(int n);
//  COUNT preamble(void);
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
    // both, set and put, come here, distinguish by value of the p_iOpCode
    virtual COUNT TransExtChar(int p_iOpCode, int p_iCharCodeLen, int p_iCharCode) { return (0); }

    COUNT TransPreamble(int p_iOpCode, int p_iDviIdLen, int p_iDviId, // former RtiTransPreamble() 
        int p_iDviNum, int p_iDviDenom, int p_iMagn, 
        int p_iNumOfBytes);
    virtual COUNT TransPreambleLocal(int p_iOpCode, int p_iDviIdLen, int p_iDviId, 
        int p_iDviNum, int p_iDviDenom, int p_iMagn, 
        int p_iNumOfBytes)
            { SkipInBytes(p_iNumOfBytes); return (p_iNumOfBytes); }
    
    // p_iFontNumLen - fonto numerio ilgis baitais, DVI komandos fnt_defK numeris
    // dar reikia iš failo m_pDviFile perskaityt p_iFontDirLen + p_iFontNameLen baitų --
    // font area (path, dirname) ir font name
    // former RtiTransFontDef()
    virtual COUNT TransFontDef(int p_iOpCode, int p_iFontNumLen, 
        int p_iFontNum, int p_iCheckSum, 
        int p_iScaleFactor, int p_iFontSize, 
        int p_iFontDirLen, int p_iFontNameLen)
            { SkipInBytes(p_iFontDirLen + p_iFontNameLen); return (p_iFontDirLen + p_iFontNameLen); }
    
    // \special{} tag processing
    // dar reikia iš failo m_pDviFile perskaityt p_iNumOfBytes baitų -- \special komandos kūną
    // former RtiTransSpec() 
    virtual COUNT TransSpec(int p_iOpCode, int p_iNumOfBytesLen, int p_iNumOfBytes)
        { SkipInBytes(p_iNumOfBytes); return (p_iNumOfBytes); }

    // both, set_rule and put_rule, come here, distinguish by value of the p_iOpCode
    COUNT TransRule(int p_iOpCode, int p_iFirstArgLen, int p_iA, int p_iB);
    virtual COUNT TransRuleLocal(int p_iOpCode, int p_iFirstArgLen, int p_iA, int p_iB)
        { return (0); }

    COUNT TransPage(int p_iOpCode, int p_iFirstArgLen, 
        int p_iPageNum /* p_iC0 */, int p_iC1, int p_iC2, int p_iC3, int p_iC4, 
        int p_iC5, int p_iC6, int p_iC7, int p_iC8, int p_iC9, int p_iPrevBopPos);
    virtual COUNT TransPageLocal(int p_iOpCode, int p_iFirstArgLen, 
        int p_iPageNum /* p_iC0 */, int p_iC1, int p_iC2, int p_iC3, int p_iC4, 
        int p_iC5, int p_iC6, int p_iC7, int p_iC8, int p_iC9, int p_iPrevBopPos)
            { return (0); }

    COUNT TransPush(int p_iOpCode, int p_iFirstArgLen);
    virtual COUNT TransPushLocal(int p_iOpCode, int p_iFirstArgLen) { return (0); }
    COUNT TransPop(int p_iOpCode, int p_iFirstArgLen);
    virtual COUNT TransPopLocal(int p_iOpCode, int p_iFirstArgLen) { return (0); }

    // right, w, x, down, y and z all come here, distinguish by value of the p_iOpCode
    // fills values of m_iHorStepW, m_iHorStepX, m_iVertStepY and m_iVertStepZ
    COUNT TransMove(int p_iOpCode, int p_iFirstArgLen, int p_iOff);
    // supplement to TransMove() in inherited class
    virtual COUNT TransMoveLocal(int p_iOpCode, int p_iFirstArgLen, int p_iOff, 
        int p_iOrigOff) // testavimo tikslais – neperskaičiuotas p_iOpCode parametras
                        // taip pat bet koks kitas treisinimo duomenys 
            { return (0); }

    virtual COUNT TransSetFont(int p_iOpCode, int p_iFontNumLen, int p_iFontNum)
            { return (0); }

    virtual COUNT TransPost(int p_iOpCode, int p_iFirstArgLen, int p_iLastBopPos, 
        int p_iDviNum, int p_iDviDenom, int p_iMagn,
        int p_iMaxHeight, int p_iMaxWidth, int p_iMaxStack,
        int p_iNumOfPages) { return (0); }

    // --------------------------
    // other callbacks
    virtual void CmdOpen(void){}   /* start of command and parameters */ // former RtiCmdOpen()
    virtual void CmdClose(void){}  /* end of command and parameters */ // former RtiCmdClose()
    
    // accumulated set_char's into a string
    virtual void TransText(const UCHAR *p_lpszStr) {}
};

#endif // #ifndef dvread_included
