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
 */

#ifndef DVISP_INCLUDED
#define DVISP_INCLUDED

// ------------------------
#define DVISP_SPEC_PAPERSIZE_HEAD (const uchar *)"papersize="
#define DVISP_SPEC_HEADER_HEAD (const uchar *)"header="

// "mt:badrefs"
#define DVISP_SPEC_MT_HEAD (const uchar *)"mt:"

#define DVISP_SPEC_STAGE_HEAD (const uchar *)"mt:"
#define DVISP_SPEC_STAGE_HPROOF_HEAD (const uchar *)"mt:hproof"
#define DVISP_SPEC_STAGE_PROOF_HEAD (const uchar *)"mt:proof"
#define DVISP_SPEC_STAGE_PPROOF_HEAD (const uchar *)"mt:pproof"
#define DVISP_SPEC_STAGE_PRECRC_HEAD (const uchar *)"mt:s" // "mt:s250" 
#define DVISP_SPEC_STAGE_CRC_HEAD (const uchar *)"mt:crc" 

#define DVISP_SPEC_INFO_HEAD (const uchar *)"vtex:info."
#define DVISP_SPEC_RTI_HEAD (const uchar *)"vtex:info.runtime." // SPECIALHEAD

#define DVISP_SPEC_SETTINGS_HEAD (const uchar *)"vtex:settings."
// vtex:settings.runtool={tool=sometool}
// vtex:settings.runtool={version=1.1}
#define DVISP_SPEC_RUNTOOL_HEAD (const uchar *)"vtex:settings.runtool={"
// vtex:settings.sometool={cfg=configuration}
#define DVISP_SPEC_SOMETOOL_HEAD (const uchar *)"vtex:settings.sometool={"
// vtex:settings.imsref={+debug}
// vtex:settings.imsref={sources="mr"}
// vtex:settings.imsref={citation-type=nameyear}
// vtex:settings.imsref={bibstyle=ims-number}
// vtex:settings.imsref={sort-refs=sort}
#define DVISP_SPEC_IMSREF_HEAD (const uchar *)"vtex:settings.imsref={"
#define DVISP_SPEC_STRUCTPYB_HEAD (const uchar *)"vtex:settings.structpyb={"

#define DVISP_SPEC_PAGEINFO_HEAD (const uchar *)"MC:PageInfo "

#define DVISP_SPEC_XML_HEAD (const uchar *)"vtex:xml "
#define DVISP_SPEC_INFO_XML_HEAD (const uchar *)"vtex:xml <sec name=\"TeX info\">"
#define DVISP_SPEC_XML_KEY_HEAD (const uchar *)"<key name=\""

// -----------------------------
// list of \special tag headers to ignore tags 
extern const uchar *lpszaIgnoreSpecList[];
// list of full \special tags to ignore 
extern const uchar *lpszaIgnoreFullSpecList[];

// -----------------------------
class DviSpClass: public DviRead
{
// ReadFile() pats atsidaro ir vėl užsidaro reikiamus failus
// pranyksta galimybė skaityt iš stdin, ir nereikia
//  FILE *m_pInFile;
    
public:
    DviSpClass(void);

    virtual void Open(const uchar *p_lpszInFileName); // former OpenInFile()
    
    // skaito darbiniam aplanke rastą failą -- m_lpszInFileName[] + ".dvi" arba m_lpszInFileName[] + ".specials"
    // iškviečia DviRead::dvread() arba SpecRead() 
    void ReadFile(void);

    // process .specials file
    void SpecRead(FILE *p_pInFile);

    // DviRead::dvread() callbackai
    virtual void TransSpec(int p_iNumOfBytes);
};


// -----------------------------
// checks presence of p_lpszKwd in list p_lpszaKwdList
// p_lpszaKwdList should be terminated by null entry
extern bool kwd_in_plist(const uchar *p_lpszaKwdList[], const uchar *p_lpszKwd); 

    
// -----------------------------
// parsina \special{} turinį p_lpszSrcBuf[] ir prideda prie pRtiObjPtr->m_pFmtFileObj->m_XmlDoc
// XML-iniai tagai būna per kelias eilutes, todėl iškart į m_XmlDoc neperkeliami, kaupiami stringe,
//      o apdorojami tik gavus ne xml-inį \special-ą. Todėl failo parsinimo pabaigoje dar reikia 
//      iškviesti tuščią ProcessSpecial((const uchar *)""), kad išsiflushintų sukauptas XML-as
extern void ProcessSpecial(const uchar *p_lpszSrcBuf);

#endif // #ifndef DVISP_INCLUDED
