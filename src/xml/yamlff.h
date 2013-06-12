/* -----------------------------
 * yamlff.h
 *      YAML format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


#ifndef yamlff_included
#define yamlff_included

class YamlFmtFile: public FmtFile
{
public:
    UCHAR m_lpszYamlFileName[KP_MAX_FNAME_LEN + 100]; // TODO: kelti į FmtFile::m_lpszFileName[] ir FmtFile::m_pFileObj 

    YamlFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode);

    void ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile);
    void ExportDoc(void);  

    void PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    void PrintOutputHead(void);
    void PrintOutputTail(void);
    void OpenGrTag(const UCHAR *p_lpszGrpTagName);
    void CloseGrTag(const UCHAR *p_lpszGrpTagName);

    void MakeIndent(FILE *p_pOutFile);
    void MakeIndent(void);
};


extern FmtFile *CreateYamlFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef yamlff_included
