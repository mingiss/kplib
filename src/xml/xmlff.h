/* -----------------------------
 * xmlff.h
 *      formatted XML I/O file definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


#ifndef xmlff_included
#define xmlff_included

class XmlFmtFile: public FmtFile
{
public:
    UCHAR m_lpszXmlFileName[KP_MAX_FNAME_LEN + 100]; // TODO: kelti į FmtFile::m_lpszFileName[] ir FmtFile::m_pFileObj 

    XmlFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode);

    void ExportDoc(void);  

    void PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    void PrintOutputHead(void);
    void PrintOutputTail(void);
    void OpenGrTag(const UCHAR *p_lpszGrpTagName);
    void CloseGrTag(const UCHAR *p_lpszGrpTagName);
    void MakeIndent(void);
};


extern FmtFile *CreateXmlFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef xmlff_included
