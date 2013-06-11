/* -----------------------------
 * plainff.h
 *      plain format file I/O definitions
 *      output of just tag values 
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  

#ifndef plainff_included
#define plainff_included

class PlainFmtFile: public FmtFile
{
public:
    PlainFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    void ExportDoc(void);  

    void PrintOutputLow(pRtInfo p_pRti, bool *p_pbOutputEmpty, const UCHAR *p_lpszGrpTagName);
    void PrintOutputHead(void);
    void PrintOutputTail(void);
    void OpenGrTag(const UCHAR *p_lpszGrpTagName);
    void CloseGrTag(const UCHAR *p_lpszGrpTagName);
    void MakeIndent(void);
};


extern FmtFile *CreatePlainFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef plainff_included
