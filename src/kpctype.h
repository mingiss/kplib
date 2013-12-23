/* ----------------------------------------------------
 *
 * kpctype.h
 *  
 *    type conversations & character processing for KP C++ projects 
 *
 */   

#ifndef KPCTYPE_INCLUDED
#define KPCTYPE_INCLUDED


// ---------------------------------------
// predefined spec. character strings
// TODO: kelt į KpCtype klasę
extern uchar lpszSpaces[];
extern uchar lpszEols[];
extern uchar lpszSpcEol[];
extern uchar lpszSpcEolNotNBSP[];
extern uchar lpszSpcEolNotTabNotFF[];

extern unsigned char lpszSpCharsSpcEol[]; // "/.,- \t\r\n"
    // characters ignored by sorting/searching

// ----------------------
extern bool KpIsDigit(KpChar p_uiCh);

// ----------------------
extern HRESULT TestAllowed
(
const unsigned char *p_lpszCheckString,
const unsigned char *p_lpszCharsAllowed
);  // tests, whether p_lpszCheckString contains
    //    only characters from p_lpszCharsAllowed
    // returns KP_E_UNKN_CHR in case of failure

// ----------------------
extern bool KpIsNumber(const uchar *p_lpszString);
    // tests whether p_lpszString is decimal integer number

extern bool KpIsHexNum(const uchar *p_lpszHexString);
    // tests whether lpszHexString is hex number
extern bool KpIsOctNum(const uchar *p_lpszOctString);
    // tests whether lpszOctString is octal number
extern bool KpIsRomNum(const uchar *p_lpszString);
    // tests whether lpszString is roman number

#endif // #ifndef KPCTYPE_INCLUDED

