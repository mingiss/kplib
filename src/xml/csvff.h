/* -----------------------------
 * csvff.h
 *      CSV format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


#ifndef csvff_included
#define csvff_included

class CsvFmtFile: public FmtFile
{
public:
    UCHAR m_lpszCsvFileName[KP_MAX_FNAME_LEN + 100]; // TODO: kelti į FmtFile::m_lpszFileName[] ir FmtFile::m_pFileObj 

    CsvFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode);

    // p_bLowest: True -- išvedinėti tik žemiausio lygio tagus, p_pBaseNode vaikus
    //            False -- tik gilesnius
    void ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile, bool bLowest, TiXmlNode *p_pBaseNode);
    void ExportDoc(void);  

    void PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    void PrintOutputHead(void);
    void PrintOutputTail(void);
    void OpenGrTag(const UCHAR *p_lpszGrpTagName);
    void CloseGrTag(const UCHAR *p_lpszGrpTagName);
    void MakeIndent(void);
};


extern FmtFile *CreateCsvFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef csvff_included
