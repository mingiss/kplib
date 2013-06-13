/* -----------------------------
 * plainff.h
 *      plain format file I/O definitions
 *      output of just tag values 
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
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
};


extern FmtFile *CreatePlainFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef plainff_included
