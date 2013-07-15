/* -----------------------------
 * csvff.h
 *      CSV format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *       
 */  


#ifndef csvff_included
#define csvff_included

class CsvFmtFile: public FmtFile
{
public:
    CsvFmtFile(const uchar *p_lpszOutFileName, const uchar *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    // p_bLowest: True -- išvedinėti tik žemiausio lygio tagus, p_pBaseNode vaikus
    //            False -- tik gilesnius
    void ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile, bool bLowest, TiXmlNode *p_pBaseNode);
    void ExportDoc(void);  
};


extern FmtFile *CreateCsvFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode);

#endif // #ifndef csvff_included
