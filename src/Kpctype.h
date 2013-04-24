/* ----------------------------------------------------
 *
 * kpctype.h
 *  
 *    type conversations & character processing for KP C++ projects 
 *
 */   

#ifndef kpctype_included
#define kpctype_included


// ================================================== predefined spec. character strings
extern unsigned char lpszSpaces[];
extern unsigned char lpszEols[];
extern unsigned char lpszSpcEol[];
extern unsigned char lpszSpcEolNotNBSP[];
extern unsigned char lpszSpcEolNotTabNotFF[];

extern unsigned char lpszIxSpcEol[]; // "/- \t\r\n" // characters converted to spaces in EC_ASCII indexes 
// extern unsigned char lpszIxSpcEolNoAlt[];    // "- \t\r\n";
#define lpszIxSpcEolNoAlt (lpszIxSpcEol+1)      // lpszIxSpcEol for indexes without alternate meanings xxx/yyy
extern unsigned char *lpszIxSpcEolPtr;          // current lpszIxSpcEol value

extern unsigned char lpszSpCharsSpcEol[]; // "/.,- \t\r\n"  // characters ignored by sorting/searching
                                                            //    former lpszSpChars

extern unsigned char lpszIxSpChars[]; // "/.,-" // characters ignored in indexes/sorting/searching
                                                //    left in non-EC_ASCII indexes (hx & tx)
                                                //    '/' mean full variant of alternate values xxx/yyy (MCM)
                                                //    former lpszSpChars, change to lpszIxSpCharsPtr  
// extern unsigned char lpszIxSpCharsNoAlt[];   // ".,-"
#define lpszIxSpCharsNoAlt (lpszIxSpChars+1)    // lpszIxSpChars for indexes without alternate meanings xxx/yyy
                                                //    '/' must be skipped (VLZ "Abessini/en")
extern unsigned char *lpszIxSpCharsPtr;         // current lpszIxSpChars value  

extern unsigned char lpszNotDigits[];
extern unsigned char lpszWordDelims[];
extern KpChar iazPunctuators[];
extern KpChar iazSimplySpaces[];
extern KpChar iazSpaces[];
extern KpChar iazSpcEol[];
extern KpChar iazSpCharsSpcEol[]; // former iazSpChars


// ================================================== character conversations, testing
extern KpChar TvKpToUpper(KpChar iCh); // former TvToUpper
extern KpChar TvKpToLower(KpChar iCh); // former TvToLower
extern unsigned char TvToUpper(unsigned char  cCh, int iCtbl); // former TvToUpper
extern unsigned char TvToLower(unsigned char  cCh, int iCtbl); // former TvToLower
extern unsigned char TvToUpperLat(unsigned char ucCh);
extern unsigned char TvToLowerLat(unsigned char ucCh);
extern bool TvIsDigit(KpChar iCh);
extern bool TvIsDecDigit(KpChar iCh); // TvIsDigit() + '+' ir '-' 
extern bool TvIsFloatDigit(KpChar iCh); // TvIsDecDigit() + '.' ir 'e'
extern bool TvIsRealDigit(KpChar iCh);
extern bool TvIsHexDigit(KpChar iCh);
extern bool TvIsAlpha(KpChar iCh);
extern bool TvIsAlpha8(unsigned char cCh, int iCtbl);
extern bool TvIsUpper(KpChar iCh);
extern bool TvIsLower(KpChar iCh);
extern bool TvIsLatinAlpha(KpChar iCh);
extern bool TvIsLatinUpper(KpChar iCh);
extern bool TvIsLatinLower(KpChar iCh);
extern bool TvIsDelim(KpChar iCh);

// --------------------------------------------- for compatibility with older kpx environment
// #define ctoupper(ch) (TvToUpperLat(ch))
#define ctoupper(ch) (TvToUpper(ch, TV_MAIN_CTBL)) // former kpx 43
// #define ctolower(ch) (TvToLowerLat(ch))
#define ctolower(ch) (TvToLower(ch, TV_MAIN_CTBL)) // former kpx 43

#define cisdigit(ch) TvIsDigit((KpChar)(ch))
#define cisalpha(ch) TvIsLatinAlpha((KpChar)(ch))
// #define cisnotalpha(ch) TvIsNotAlpha((KpChar)(ch)) // cisdigit || cisdelim
#define cisnotalpha(ch) ((!cisalpha(ch)) && ((ch)<KPT_FirstKptChar))
#define cisupper(ch) TvIsLatinUpper((KpChar)(ch))
#define cislower(ch) TvIsLatinLower((KpChar)(ch))
#define cisdelim(ch) TvIsDelim((KpChar)(ch))

extern bool TvIsLatStr(const unsigned char *lpszStr);

extern KpChar TvToLat(KpChar uiCh); // converts character to simple latin equivalent
extern KpChar *TvKpStrLat(KpChar *piazStr);  // converts Kpt string to simple latin equivalent // former TvIStrLat()
extern unsigned char *TvStrLat(unsigned char *lpszStr, int iCtbl);

extern KpChar TvClearAccent(KpChar uiCh);  // removes lithuanian accents
extern KpChar *TvKpStrClearAccents(KpChar *piazStr);    // removes lithuanian accents for Kpt string // former TvClearAccents()
extern unsigned char *TvStrClearAccents(unsigned char *lpszStr, int iCtbl);

extern KpChar *TvKpStrSpchLat(KpChar *piazStr); // spec. chars to latin equivalents ("–" --> "-", etc.)
extern unsigned char *TvStrSpchLat(unsigned char *lpszStr, int iCtbl);

extern unsigned char *TvStrUpr(unsigned char *lpszStr, int iCtbl); // converts string to uppercase
extern unsigned char *TvStrLwr(unsigned char *lpszStr, int iCtbl); // converts string to lowercase

extern unsigned char *TvStrUprLat(unsigned char *lpszStr); // converts latin string to uppercase, former TvStrUpr
extern unsigned char *TvStrLwrLat(unsigned char *lpszStr); // converts latin string to lowercase, former TvStrLwr 

extern KpChar *TvKpStrUpr(KpChar *piazStr); // converts Kpt string to uppercase // former TvIStrUpr
extern KpChar *TvKpStrLwr(KpChar *piazStr); // converts Kpt string to lowercase // former TvIStrLwr

#ifdef __GNUC__
#define strlwr(s) TvStrLwr((unsigned char *)(s, TV_MAIN_CTBL))
#define strupr(c) TvStrUpr((unsigned char *)(s, TV_MAIN_CTBL))
#else
extern unsigned char *strlwr(unsigned char *str);
extern unsigned char *strupr(unsigned char *str);
#endif

// --------------------------------------------- for compatibility with older kpx environment
#define cstrlwr(str) (TvStrLwr(str, TV_MAIN_CTBL)) // former kpx 43
#define cstrupr(str) (TvStrUpr(str, TV_MAIN_CTBL)) // former kpx 43

          
extern KpChar *TvCleanCtrls(KpChar *iazStr); // removes control characters
extern unsigned char *TvCleanSpch(unsigned char *lpszStr); // removes spec. chars (non-letters) and digits
          
extern HRESULT TestAllowed
(
const unsigned char *lpszCheckString,
const unsigned char *lpszCharsAllowed
);                                        // tests, whether lpszCheckString contains
                                          //    only characters from lpszCharsAllowed
                                          // does not execute TvErrorProc.OutputErrorMessage()

extern bool TvIsLatinLowerStr(const unsigned char *lpszString); // test whether lpszString consists only of lower latin letters
extern bool TvIsNumber(const unsigned char *lpszString); // tests whether lpszString is decimal integer number
extern bool TvIsHexNum(const unsigned char *lpszHexString); // tests whether lpszHexString is hex number
extern bool TvIsOctNum(const unsigned char *lpszOctString); // tests whether lpszOctString is octal number
extern bool TvIsRomanNumber(const unsigned char *lpszString); // tests whether lpszString is roman number
extern bool TvIsNumValue(const unsigned char *lpszString); // tests whether lpszString is HTML numeric value: 999, 999%, 999cm, 999mm, 999pt etc. (TEX glue value?)
extern bool TvIsColor(const unsigned char *lpszParVal); // tests whether lpszParVal is HTML color identifier ("#FFFAE6")



// ================================================== integer conversations
// extern long labs(long arg); // absolute value of long

extern unsigned char *itooct(unsigned long val, unsigned char *buf, int posnum);

extern HRESULT ScanRoman(const unsigned char *lpszRomanNumber, int *piArabicNumber);
                           // scan Roman number from string
extern HRESULT FormatRoman(unsigned char *lpszRomanNumber, int iArabicNumber);
                           // put Roman number to string
extern HRESULT ScanHexUrl(unsigned char *lpszURL); // converts %XX to hex byte values

extern HRESULT SkipCr(unsigned char *lpszString); // converts string  eol's to single Lf (skips all Cr's)
                         

// ================================================== encypherings
extern HRESULT EncodeText(unsigned char *lpszString); // simply string encyphering
extern HRESULT DecodeText(unsigned char *lpszString); // simply string decyphering

// ================================================== languages
extern KpChar iazLitChars[];
extern KpChar iazPolChars[];
extern KpChar iazGerChars[];
extern KpChar iazRusChars[];
extern HRESULT TestLang(const KpChar *piazInStr, int iLangId, bool *pbFound); // iLangId - KP_LNG_*

#endif // #ifndef kpctype_included

