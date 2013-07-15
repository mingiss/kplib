/* -----------------------------
 * plistff.h
 *      YAML format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *       
 */  


#ifndef plistff_included
#define plistff_included

class PlistFmtFile: public FmtFile
{
public:
    TiXmlDocument m_PlistDoc;

    PlistFmtFile(const uchar *p_lpszOutFileName, const uchar *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    // transfers current node p_pSrcNode of m_XmlDoc to pair of nodes as children of current parrent p_pDestParNode in m_PlistDoc
    void TransferNode(TiXmlNode *p_pSrcNode, TiXmlNode *p_pDestParNode);
    void ExportDoc(void);  
};


extern FmtFile *CreatePlistFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode);

#endif // #ifndef plistff_included
