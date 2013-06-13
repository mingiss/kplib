/* -----------------------------
 * jsonff.h
 *      JSON format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *       
 */  


#ifndef jsonff_included
#define jsonff_included

class JsonFmtFile: public FmtFile
{
public:
    JsonFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    // p_pbOutputEmpty -- išorinė vėliavėlė, kad prieš pirmą eilutę nebūtų tuščios
    // įeinant į rekursiją *p_pbOutputEmpty turi būti True
    void ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile, bool *p_pbOutputEmpty);
    void ExportDoc(void);  

    void MakeIndent(FILE *p_pOutFile);
};


extern FmtFile *CreateJsonFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef jsonff_included
