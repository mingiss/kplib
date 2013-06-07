/* ----------------
 * dvisp.cpp
 *      reading of .dvi file special tags
 *      definitions (of the class DviSp) 
 *
 *
 *  Changelog:
 *      2013-06-07  mp  split from drti.c
 *
 * TODO: po pilno atskyrimo išmest visus PLAIN_C
 *  
 */

#ifndef dvisp_included
#define dvisp_included

// ------------------------
#define DVISP_EQ_SIGN C_Eq // 61 // '='
#define DVISP_OPENING_BRACE C_Lcurl // '{'
#define DVISP_CLOSING_BRACE C_Rcurl // '}'


// ------------------------
#define DRTI_SPEC_PAPERSIZE_HEAD "papersize="
#define DRTI_SPEC_HEADER_HEAD "header="

// "mt:badrefs"
#define DRTI_SPEC_MT_HEAD "mt:"

#define DRTI_SPEC_STAGE_HEAD "mt:"
#define DRTI_SPEC_STAGE_HPROOF_HEAD "mt:hproof"
#define DRTI_SPEC_STAGE_PROOF_HEAD "mt:proof"
#define DRTI_SPEC_STAGE_PPROOF_HEAD "mt:pproof"
#define DRTI_SPEC_STAGE_PRECRC_HEAD "mt:s" // "mt:s250" 
#define DRTI_SPEC_STAGE_CRC_HEAD "mt:crc" 

#define DRTI_SPEC_INFO_HEAD "vtex:info."
#define DRTI_SPEC_RTI_HEAD "vtex:info.runtime." // SPECIALHEAD

#define DRTI_SPEC_SETTINGS_HEAD "vtex:settings."
// vtex:settings.runtool={tool=sometool}
// vtex:settings.runtool={version=1.1}
#define DRTI_SPEC_RUNTOOL_HEAD "vtex:settings.runtool={"
// vtex:settings.sometool={cfg=configuration}
#define DRTI_SPEC_SOMETOOL_HEAD "vtex:settings.sometool={"
// vtex:settings.imsref={+debug}
// vtex:settings.imsref={sources="mr"}
// vtex:settings.imsref={citation-type=nameyear}
// vtex:settings.imsref={bibstyle=ims-number}
// vtex:settings.imsref={sort-refs=sort}
#define DRTI_SPEC_IMSREF_HEAD "vtex:settings.imsref={"
#define DRTI_SPEC_STRUCTPYB_HEAD "vtex:settings.structpyb={"

#define DRTI_SPEC_PAGEINFO_HEAD "MC:PageInfo "

#define DRTI_CHKSUM_TAG_PREF "chksum:"


// -----------------------
extern const UCHAR *input_file;


// -----------------------------
// list of \special tag headers to ignore tags 
extern const UCHAR *lpszaIgnoreSpecList[];
// list of full \special tags to ignore 
extern const UCHAR *lpszaIgnoreFullSpecList[];

// checks presence of p_lpszKwd in list p_lpszaKwdList
// p_lpszaKwdList should be terminated by null entry
extern PLAIN_C bool kwd_in_plist(const UCHAR *p_lpszaKwdList[], const UCHAR *p_lpszKwd); 


// -----------------------------
extern PLAIN_C Void str_del(UCHAR *t, UCHAR *s, const UCHAR *p_lpszHead);

// adds tag string to the end of array pointed by p_pRti
// checks array p_pRti[] size not to cross DRTI_MAX_NUM_OF_RTIS + 1 boundary
// end of the elements in p_pRti[] is marked by {"", ""} record
// multiple tag string is split into individual tags:
//  "voffset={-72.26999pt} hoffset={-72.26999pt} topmargin={29.98857pt} headheight={12.0pt} headsep={14.0pt} textheight={540.60236pt} textwidth={332.89723pt} oddsidemargin={54.0pt} evensidemargin={54.0pt} footskip={20.0pt} baselineskip={12.0pt plus 0.3pt minus 0.3pt} headmargin={29.98857pt} backmargin={54.0pt} columnwidth={332.89723pt} trimbox={0 0 439.3701 666.1417}"
extern PLAIN_C Void add_to_rti(const UCHAR *p_lpszKwdStr, prti p_pRti);

// split 's' into 't' and 'tt'
extern int split_strings(UCHAR *t, UCHAR *tt, /* const */ UCHAR *s);

#endif // #ifndef dvisp_included
