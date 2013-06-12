/* -----------------------------
 * jsonff.h
 *      JSON format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


#ifndef jsonff_included
#define jsonff_included

class JsonFmtFile: public FmtFile
{
public:
    UCHAR m_lpszJsonFileName[KP_MAX_FNAME_LEN + 100]; // TODO: kelti į FmtFile::m_lpszFileName[] ir FmtFile::m_pFileObj 

    JsonFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode);

    // p_pbOutputEmpty -- išorinė vėliavėlė, kad prieš pirmą eilutę nebūtų tuščios
    // įeinant į rekursiją *p_pbOutputEmpty turi būti True
    void ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile, bool *p_pbOutputEmpty);
    void ExportDoc(void);  

    void PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    void PrintOutputHead(void);
    void PrintOutputTail(void);
    void OpenGrTagLocal(const UCHAR *p_lpszGrpTagName); // kad nebūtų kablelių po PrintOutputLow() išvedamų OpenGrTagLocal() 
    void OpenGrTag(const UCHAR *p_lpszGrpTagName);
    void CloseGrTag(const UCHAR *p_lpszGrpTagName);

    void MakeIndent(FILE *p_pOutFile);
    void MakeIndent(void);
};


extern FmtFile *CreateJsonFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef jsonff_included
