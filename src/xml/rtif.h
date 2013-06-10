/* ----------------
 * rtif.h
 *      RtiClass definition
 *
 *  Changelog:
 *      2013-06-10  mp  split off from rti.h
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

    UCHAR m_szaOutputList[RTI_NUM_OF_KWDS][RTI_KWD_LEN + 1];  // išvedamų žemutinio lygio tagų sąrašas
    int m_iOutputListSize;  // m_szaOutputList[] elementų skaičius, jei m_szaOutputList[] tuščias -- išvedam viską

    // list of group tags processed (possible values -- DRTI_*_GRP_TAG) 
    UCHAR m_szaGrpList[RTI_NUM_OF_KWDS][RTI_KWD_LEN + 1];
    int m_iGrpListSize;
    
    RtiClass(void);
    ~RtiClass();
    
    void OpenOutFile(const UCHAR *p_lpszOutFileName, FmtFileForgeFptr p_FmtFileForge); // open output RTI file m_pFmtFileObj
    void CloseOutFile(void); // close output RTI file m_pFmtFileObj
    const UCHAR *GetFileName(void);

    void PrintOutput(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    void PrintOutputHead(void);
    void PrintOutputTail(void);
    void OpenGrTag(const UCHAR *p_lpszGrpTagName);
    void CloseGrTag(const UCHAR *p_lpszGrpTagName);
    
    void ScanOutputList(const UCHAR *p_lpszKwdStr); // fills m_szaOutputList[] from comma-separated keyword list 
    void ScanGrpList(const UCHAR *p_lpszKwdStr); // fills m_szaGrpList[] from comma-separated keyword list
};


extern RtiClass *pRtiObjPtr; // pointer to current RtiClass object for plain C callback RtiTransSpec()


// -----------------------------
// parse comma separated keyword list p_lpszKwdStr to array of strings 
// p_szaKwdList[RTI_NUM_OF_KWDS][RTI_KWD_LEN + 1] 
extern void scan_kwd_list(UCHAR p_szaKwdList[][RTI_KWD_LEN + 1], int *p_piKwdListSize, const UCHAR *p_lpszKwdStr); 

#endif // #ifdef __cplusplus

// -----------------------------
// checks presence of p_lpszKwd in list p_szaKwdList
// p_szaKwdList[p_iKwdListSize][RTI_KWD_LEN + 1] 
extern PLAIN_C bool kwd_in_list(/* const */ UCHAR p_szaKwdList[][RTI_KWD_LEN + 1], int p_iKwdListSize, const UCHAR *p_lpszKwd); 


// -----------------------------
extern PLAIN_C void str_del(UCHAR *t, UCHAR *s, const UCHAR *p_lpszHead);

// adds tag string to the end of array pointed by p_pRti
// checks array p_pRti[] size not to cross RTI_MAX_NUM_OF_RTIS + 1 boundary
// end of the elements in p_pRti[] is marked by {"", ""} record
// multiple tag string is split into individual tags:
//  "voffset={-72.26999pt} hoffset={-72.26999pt} topmargin={29.98857pt} headheight={12.0pt} headsep={14.0pt} textheight={540.60236pt} textwidth={332.89723pt} oddsidemargin={54.0pt} evensidemargin={54.0pt} footskip={20.0pt} baselineskip={12.0pt plus 0.3pt minus 0.3pt} headmargin={29.98857pt} backmargin={54.0pt} columnwidth={332.89723pt} trimbox={0 0 439.3701 666.1417}"
extern PLAIN_C void add_to_rti(const UCHAR *p_lpszKwdStr, pRtInfo p_pRti);

#ifdef __cplusplus
// split 's' into 't' and 'tt'
extern int split_strings(UCHAR *t, UCHAR *tt, /* const */ UCHAR *s);
#endif // #ifdef __cplusplus


// --------------------------- converter callbacks
extern PLAIN_C void RtiCmdOpen(void);   /* start of command and parameters */
extern PLAIN_C void RtiCmdClose(void);  /* end of command and parameters */

extern PLAIN_C void RtiTransPreamble(int p_iNumOfBytes, FILE *p_pDviFile);
extern PLAIN_C void RtiTransFontDef(int p_iNumOfBytes, FILE *p_pDviFile);
extern PLAIN_C void RtiTransSpec(int p_iNumOfBytes, FILE *p_pDviFile);

// skips p_iNumOfBytes of p_pDviFile
// can be used as void substitutes for other RtiTrans*() 
extern PLAIN_C void RtiSkipInBytes(int p_iNumOfBytes, FILE *p_pDviFile);

#ifdef __cplusplus
// prints array of low level tags 
// with checking for corespondence to the list of output tags (drtim option "-e")
extern void OutputRtiArr(const pRtInfo p_pRti); 
#endif // #ifdef __cplusplus

#endif // #ifndef rtif_included
