/* -----------------------------
 * kpsort.h
 *      searching and sorting definitions
 *      
 *  Changelog:
 *      2013-06-11  mp  initial creation
 *       
 */  

#ifndef kpsort_included
#define kpsort_included


// ----------------------
#define TV_TG_NoKey  (-1)


// ================================================== static fields for sorting
extern int iCharWeigths[C_CharSize0];        // sort order definition
                                             // third digit will be ignored for for TvStrCmp()
                                             // use RoundChWgt(iCharWeigths[ii]) for it
#define KpCharWgtElem(chr, dig2, dig3, dig4) (chr * 10000 + dig2 * 1000 + dig3 * 100 + dig4) 
                                             // former ChWgt()
                                             // dig2 - skirtingu abeceles poziuriu diakritiniu raidziu eil. nr. (C, Č, S, Š, etc.) eil. nr.
                                             // dig3 - didziosios raides pozymis
                                             // dig4 (former dig3) - abeceliskai to paties svorio diakritiniu raidziu eil. nr.
#define ToLowWgt(ii)   (ii-ii%1000+ii%100)   // numeta didziosios raides pozymi dig3
#define RoundChWgt(ii) (ii-ii%100)           // numeta diakrito eiles nr dig4


// ----------------------
// Calculates keyword index in keyword table.
//    returns TV_TG_NoKey (-1) if not found
// Input:
//    p_lpszKeywrd;
//    p_plpszKeytable - array of pointers to all
//       keywords - null terminated strings, not longer than KP_KWD_LEN bytes each;
//    if p_iTabSize <0, then end of keyword table
//       is marked by null pointer,
//    if p_iTabSize >=0, then all p_iTabSize records
//       will be tested, regardless if they are NULL
//       or not.
//    p_bCaseSens - case sensitivity flag
//    p_bWholeWords - search for p_lpszKeywrd as whole word,
//       otherwise - only starting characters up to checking keyword length
extern int GetKwrdIndex
(
const UCHAR *p_lpszKeywrd,
const UCHAR * const *p_plpszKeytable,
const int p_iTabSize,
bool p_bCaseSens,
bool p_bWholeWords
);  

#endif // #ifndef kpsort_included
