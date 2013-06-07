/* ----------------
 * dvisp.h
 *      reading of .dvi file special tags
 *      definitions (of the class DviSp) 
 *
 *  Changelog:
 *      2013-06-07  mp  split off from drti.c
 *
 * TODO: po pilno atskyrimo išmest visus PLAIN_C
 *  
 */

#ifndef dvisp_included
#define dvisp_included

// ------------------------
#define DVISP_SPEC_PAPERSIZE_HEAD "papersize="
#define DVISP_SPEC_HEADER_HEAD "header="

// "mt:badrefs"
#define DVISP_SPEC_MT_HEAD "mt:"

#define DVISP_SPEC_STAGE_HEAD "mt:"
#define DVISP_SPEC_STAGE_HPROOF_HEAD "mt:hproof"
#define DVISP_SPEC_STAGE_PROOF_HEAD "mt:proof"
#define DVISP_SPEC_STAGE_PPROOF_HEAD "mt:pproof"
#define DVISP_SPEC_STAGE_PRECRC_HEAD "mt:s" // "mt:s250" 
#define DVISP_SPEC_STAGE_CRC_HEAD "mt:crc" 

#define DVISP_SPEC_INFO_HEAD "vtex:info."
#define DVISP_SPEC_RTI_HEAD "vtex:info.runtime." // SPECIALHEAD

#define DVISP_SPEC_SETTINGS_HEAD "vtex:settings."
// vtex:settings.runtool={tool=sometool}
// vtex:settings.runtool={version=1.1}
#define DVISP_SPEC_RUNTOOL_HEAD "vtex:settings.runtool={"
// vtex:settings.sometool={cfg=configuration}
#define DVISP_SPEC_SOMETOOL_HEAD "vtex:settings.sometool={"
// vtex:settings.imsref={+debug}
// vtex:settings.imsref={sources="mr"}
// vtex:settings.imsref={citation-type=nameyear}
// vtex:settings.imsref={bibstyle=ims-number}
// vtex:settings.imsref={sort-refs=sort}
#define DVISP_SPEC_IMSREF_HEAD "vtex:settings.imsref={"
#define DVISP_SPEC_STRUCTPYB_HEAD "vtex:settings.structpyb={"

#define DVISP_SPEC_PAGEINFO_HEAD "MC:PageInfo "


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


#endif // #ifndef dvisp_included
