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


// ----------------------
// Calculates keyword index in keyword table.
//    returns TV_TG_NoKey (-1) if not found and return code KP_E_KWD_NOT_FOUND
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
