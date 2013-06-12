/* -----------------------------
 * plistff.h
 *      YAML format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


#ifndef plistff_included
#define plistff_included

class PlistFmtFile: public FmtFile
{
public:
    UCHAR m_lpszPlistFileName[KP_MAX_FNAME_LEN + 100]; // TODO: kelti į FmtFile::m_lpszFileName[] ir FmtFile::m_pFileObj 
    TiXmlDocument m_PlistDoc;

    PlistFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode);

    // transfers current node p_pSrcNode of m_XmlDoc to pair of nodes as children of current parrent p_pDestParNode in m_PlistDoc
    void TransferNode(TiXmlNode *p_pSrcNode, TiXmlNode *p_pDestParNode);
    void ExportDoc(void);  

    void PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    void PrintOutputHead(void);
    void PrintOutputTail(void);
    void OpenGrTag(const UCHAR *p_lpszGrpTagName);
    void CloseGrTag(const UCHAR *p_lpszGrpTagName);
    void MakeIndent(void);
};


extern FmtFile *CreatePlistFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef plistff_included
