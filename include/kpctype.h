/* ----------------------------------------------------
 *
 * kpctype.h
 *
 *  type conversations & character processing for KP C++ projects
 *
 * Changelog:
 *  2017-05-22  mp  build on Linux Mint 18.1 Serena 64
 *
 */

#ifndef KPCTYPE_INCLUDED
#define KPCTYPE_INCLUDED


// ---------------------------------------
// predefined spec. character strings
// TODO: kelt į KpCtype klasę
extern uchar pszSpaces[];
extern uchar pszEols[];
extern uchar pszSpcEol[];
extern uchar pszSpcEolNotNBSP[];
extern uchar pszSpcEolNotTabNotFF[];

extern uchar pszSpCharsSpcEol[]; // "/.,- \t\r\n"  // characters ignored by sorting/searching
                                 //    former lpszSpChars

// ----------------------
extern bool KpIsDigit(KpChar p_uiCh);

// ----------------------
extern HRESULT TestAllowed
(
const KpStrPtr p_pszCheckString,
const KpStrPtr p_pszCharsAllowed
);  // tests, whether p_pszCheckString contains
    //    only characters from p_pszCharsAllowed
    // returns KP_E_UNKN_CHR in case of failure

// ----------------------
extern bool KpIsNumber(const KpStrPtr p_pszString);
    // tests whether p_pszString is decimal integer number

extern bool KpIsHexNum(const KpStrPtr p_pszHexString);
    // tests whether p_pszHexString is hex number
extern bool KpIsOctNum(const KpStrPtr p_pszOctString);
    // tests whether p_pszOctString is octal number
extern bool KpIsRomNum(const KpStrPtr p_pszString);
    // tests whether p_pszString is roman number

#endif // #ifndef KPCTYPE_INCLUDED

