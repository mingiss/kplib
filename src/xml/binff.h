/* -----------------------------
 * binff.h
 *      binary format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  

#ifndef binff_included
#define binff_included

class BinFmtFile: public FmtFile
{
public:
    BinFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode) 
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    void ExportDoc(void);  

    void PrintOutput(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    void PrintOutputHead(void);
    void PrintOutputTail(void);
    void OpenGrTag(const UCHAR *p_lpszGrpTagName);
    void CloseGrTag(const UCHAR *p_lpszGrpTagName);
    void MakeIndent(void);
};


extern FmtFile *CreateBinaryFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef plainff_included
