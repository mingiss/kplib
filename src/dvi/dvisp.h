/* ----------------
 * dvisp.h
 *      reading of .dvi and .special file \special tags
 *      definitions (of the class DviSp) 
 *
 *  Changelog:
 *      2013-06-07  mp  split off from drti.c
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *      2013-06-13  mp  pridėtas .special failo parsinimas
 *
 * TODO: po pilno atskyrimo išmest visus PLAIN_C
 *  
 */

#ifndef dvisp_included
#define dvisp_included

// ------------------------
#define DVISP_SPEC_PAPERSIZE_HEAD (const UCHAR *)"papersize="
#define DVISP_SPEC_HEADER_HEAD (const UCHAR *)"header="

// "mt:badrefs"
#define DVISP_SPEC_MT_HEAD (const UCHAR *)"mt:"

#define DVISP_SPEC_STAGE_HEAD (const UCHAR *)"mt:"
#define DVISP_SPEC_STAGE_HPROOF_HEAD (const UCHAR *)"mt:hproof"
#define DVISP_SPEC_STAGE_PROOF_HEAD (const UCHAR *)"mt:proof"
#define DVISP_SPEC_STAGE_PPROOF_HEAD (const UCHAR *)"mt:pproof"
#define DVISP_SPEC_STAGE_PRECRC_HEAD (const UCHAR *)"mt:s" // "mt:s250" 
#define DVISP_SPEC_STAGE_CRC_HEAD (const UCHAR *)"mt:crc" 

#define DVISP_SPEC_INFO_HEAD (const UCHAR *)"vtex:info."
#define DVISP_SPEC_RTI_HEAD (const UCHAR *)"vtex:info.runtime." // SPECIALHEAD

#define DVISP_SPEC_SETTINGS_HEAD (const UCHAR *)"vtex:settings."
// vtex:settings.runtool={tool=sometool}
// vtex:settings.runtool={version=1.1}
#define DVISP_SPEC_RUNTOOL_HEAD (const UCHAR *)"vtex:settings.runtool={"
// vtex:settings.sometool={cfg=configuration}
#define DVISP_SPEC_SOMETOOL_HEAD (const UCHAR *)"vtex:settings.sometool={"
// vtex:settings.imsref={+debug}
// vtex:settings.imsref={sources="mr"}
// vtex:settings.imsref={citation-type=nameyear}
// vtex:settings.imsref={bibstyle=ims-number}
// vtex:settings.imsref={sort-refs=sort}
#define DVISP_SPEC_IMSREF_HEAD (const UCHAR *)"vtex:settings.imsref={"
#define DVISP_SPEC_STRUCTPYB_HEAD (const UCHAR *)"vtex:settings.structpyb={"

#define DVISP_SPEC_PAGEINFO_HEAD (const UCHAR *)"MC:PageInfo "

#define DVISP_SPEC_XML_HEAD (const UCHAR *)"vtex:xml "
#define DVISP_SPEC_INFO_XML_HEAD (const UCHAR *)"vtex:xml <sec name=\"TeX info\">"
#define DVISP_SPEC_XML_KEY_HEAD (const UCHAR *)"<key name=\""

// -----------------------------
// list of \special tag headers to ignore tags 
extern const UCHAR *lpszaIgnoreSpecList[];
// list of full \special tags to ignore 
extern const UCHAR *lpszaIgnoreFullSpecList[];

// -----------------------------
class DviSpClass
{
public:
    UCHAR m_lpszInFileName[KP_MAX_FNAME_LEN + 1]; // input DVI file name

// ReadFile() pats atsidaro ir vėėl užsidaro reikiamus failus
// pranyksta galimybė skaityt iš stdin, ir nereikia
//  FILE *m_pInFile; // input DVI file object
    
    DviSpClass(void);

    void OpenInFile(const UCHAR *lpszInFileName);
    
    // skaito darbiniam aplanke rastą failą -- m_lpszInFileName[] + ".dvi" arba m_lpszInFileName[] + ".specials"
    // iškviečia dviread() arba SpecRead() 
    void ReadFile(void);

    void SpecRead(FILE *p_pInFile);
};


// -----------------------------
// checks presence of p_lpszKwd in list p_lpszaKwdList
// p_lpszaKwdList should be terminated by null entry
extern PLAIN_C bool kwd_in_plist(const UCHAR *p_lpszaKwdList[], const UCHAR *p_lpszKwd); 

    
// -----------------------------
// parsina \special{} turinį p_lpszSrcBuf[] ir prideda prie pRtiObjPtr->m_pFmtFileObj->m_XmlDoc
extern void ProcessSpecial(UCHAR *p_lpszSrcBuf);

#endif // #ifndef dvisp_included
