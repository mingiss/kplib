/* -----------------------------
 * fmtf.h
 *      formatted I/O file definitions
 *      supports output of XmlNode structure to various output formats:
 *          xml, json, csv, yaml, plist, etc. (may be to tex, rtf as well)
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-12  mp  tinyxml implemented
 *       
 */  

#ifndef fmtf_included
#define fmtf_included

class FmtFile
{
public:
    UCHAR m_lpszFileName[KP_MAX_FNAME_LEN + 1];
    UCHAR m_lpszFileMode[KP_MAX_FNAME_LEN + 1];
    FILE *m_pFileObj;
    bool m_bOutputEmpty; 
    int m_iIndent;
    
//  XmlTree *m_pXmlDoc; // suparsintas failo įrašas, gali būti ir visas failas
    TiXmlDocument m_XmlDoc;
    
    FmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode);
    ~FmtFile();
    
    void CloseOutFile(void); // close output file m_pFileObj

// ------------------------------
    // sukuria m_XmlDoc grupinį tagą vardu p_lpszTagName, tago p_lpszGrpTagName vaiką
    // jei p_lpszGrpTagName == null, kuria tagą dokumento šaknyje
    // jei tokiu vardu tagas jau yra, tada nekuria
    void CreateGrpNode(const UCHAR *p_lpszTagName, const UCHAR *p_lpszGrpTagName);

// ------------------------------
    virtual void ExportDoc(void) = 0; // išveda m_XmlDoc į m_pFileObj  

// ------------------------------
// seni drti related metodai

    // p_pbOutputEmpty == True -- first tag in the group, opening tag p_lpszGrpTagName should be output
    // in case of top level ungrouped tags p_lpszGrpTagName and p_pbOutputEmpty both should be NULL 
    void PrintOutput(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    
    // inherited part of PrintOutput()
    virtual void PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName) = 0;

    virtual void PrintOutputHead(void) = 0;
    virtual void PrintOutputTail(void) = 0;

    // puts out opening group tag
    virtual void OpenGrTag(const UCHAR *p_lpszGrpTagName);

    // puts out closing group tag
    virtual void CloseGrTag(const UCHAR *p_lpszGrpTagName) = 0;

// puts out indent spaces according to m_iIndent value
    virtual void MakeIndent(void) = 0;
// ------------------------------
};


typedef FmtFile * (*FmtFileForgeFptr)(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef fmtf_included
