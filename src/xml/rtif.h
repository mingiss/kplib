/* ----------------
 * rtif.h
 *      Runtime info, DVI parser output end 
 *      RtiClass definition
 *
 *  Changelog:
 *      2013-06-10  mp  split off from rti.h
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *      2013-06-13  mp  pridėtas .special failo parsinimas
 *      2013-06-20  mp  DVI parserio callbackai perkelti į DviRead
 *
 */

#ifndef rtif_included
#define rtif_included


#ifdef __cplusplus

// -----------------------------
class RtiClass
{
public:
    FmtFile *m_pFmtFileObj; // output RTI file object

    uchar m_szaOutputList[RTI_NUM_OF_KWDS][RTI_KWD_LEN + 1];  // išvedamų žemutinio lygio tagų sąrašas
    int m_iOutputListSize;  // m_szaOutputList[] elementų skaičius, jei m_szaOutputList[] tuščias -- išvedam viską

    // list of group tags processed (possible values -- DRTI_*_GRP_TAG) 
    uchar m_szaGrpList[RTI_NUM_OF_KWDS][RTI_KWD_LEN + 1];
    int m_iGrpListSize;
    
    RtiClass(void);
    ~RtiClass();
    
    void OpenOutFile(const uchar *p_lpszOutFileName, FmtFileForgeFptr p_FmtFileForge); // open output RTI file m_pFmtFileObj
    void CloseOutFile(void); // close output RTI file m_pFmtFileObj
    const uchar *GetFileName(void); // TODO: not yet implemented

    void ScanOutputList(const uchar *p_lpszKwdStr); // fills m_szaOutputList[] from comma-separated keyword list 
    void ScanGrpList(const uchar *p_lpszKwdStr); // fills m_szaGrpList[] from comma-separated keyword list
};


// TODO: globalų pointerį naikint, perdaryt per parametrą
extern RtiClass *pRtiObjPtr; // pointer to current RtiClass object for plain C callback RtiTransSpec()


// -----------------------------
// parse comma separated keyword list p_lpszKwdStr to array of strings 
// p_szaKwdList[RTI_NUM_OF_KWDS][RTI_KWD_LEN + 1] 
extern void scan_kwd_list(uchar p_szaKwdList[][RTI_KWD_LEN + 1], int *p_piKwdListSize, const uchar *p_lpszKwdStr); 

#endif // #ifdef __cplusplus

// -----------------------------
// checks presence of p_lpszKwd in list p_szaKwdList
// p_szaKwdList[p_iKwdListSize][RTI_KWD_LEN + 1] 
extern bool kwd_in_list(/* const */ uchar p_szaKwdList[][RTI_KWD_LEN + 1], int p_iKwdListSize, const uchar *p_lpszKwd); 


// -----------------------------
extern void str_del(uchar *t, uchar *s, const uchar *p_lpszHead);

// kuria pRtiObjPtr->m_pFmtFileObj->m_XmlDoc tagus, p_lpszGrpTagName vaikus
// jei p_lpszGrpTagName, kuria m_XmlDoc šaknies vaikus
// jei dar nėra, susikuria ir grupinį tagą p_lpszGrpTagName
// jei p_lpszGrpGrpTagName, grupinį tagą p_lpszGrpTagName kuria jame
// multiple tag string is split into individual tags:
//  "voffset={-72.26999pt} hoffset={-72.26999pt} topmargin={29.98857pt} headheight={12.0pt} headsep={14.0pt} textheight={540.60236pt} textwidth={332.89723pt} oddsidemargin={54.0pt} evensidemargin={54.0pt} footskip={20.0pt} baselineskip={12.0pt plus 0.3pt minus 0.3pt} headmargin={29.98857pt} backmargin={54.0pt} columnwidth={332.89723pt} trimbox={0 0 439.3701 666.1417}"
extern void add_to_rti(const uchar *p_lpszKwdStr, const uchar *p_lpszGrpTagName, const uchar *p_lpszGrpGrpTagName);

// like add_to_rti() adds xml formatted parameter string to pRtiObjPtr->m_pFmtFileObj->m_XmlDoc
// <key name="voffset">-72.26999pt</key><key name="hoffset">-72.26999pt</key><key name="topmargin">36.0pt</key><key name="headheight">11.0pt</key><key name="headsep">12.0pt</key><key name="textheight">560.51929pt</key><key name="textwidth">364.19527pt</key><key name="oddsidemargin">39.83386pt</key><key name="evensidemargin">36.98859pt</key><key name="footskip">12.0pt</key><key name="columnwidth">364.19527pt</key><key name="baselineskip">13.0pt plus 0.1pt minus 0.1pt</key>
// destroys p_lpszKwdStr[]
void add_xml_to_rti(const string *p_psKwdStr, const uchar *p_lpszGrpTagName, const uchar *p_lpszGrpGrpTagName);

#ifdef __cplusplus
// split 's' into 't' and 'tt'
extern int split_strings(uchar *t, uchar *tt, /* const */ uchar *s);
#endif // #ifdef __cplusplus

#endif // #ifndef rtif_included
