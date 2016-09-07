/* -----------------------------
 * yamlff.h
 *      YAML format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *       
 */  


#ifndef YAMLFF_INCLUDED
#define YAMLFF_INCLUDED

class YamlFmtFile: public FmtFile
{
public:
    YamlFmtFile(const uchar *p_lpszOutFileName, const uchar *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    void ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile);
    void ExportDoc(void);  

    void MakeIndent(FILE *p_pOutFile);
};


extern FmtFile *CreateYamlFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode);

#endif // #ifndef YAMLFF_INCLUDED
