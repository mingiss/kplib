/* -----------------------------
 * yamlff.h
 *      YAML format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *       
 */  


#ifndef yamlff_included
#define yamlff_included

class YamlFmtFile: public FmtFile
{
public:
    YamlFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    void ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile);
    void ExportDoc(void);  

    void MakeIndent(FILE *p_pOutFile);
};


extern FmtFile *CreateYamlFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef yamlff_included
