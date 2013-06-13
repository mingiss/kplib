/* -----------------------------
 * binff.h
 *      binary format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
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
};


extern FmtFile *CreateBinaryFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef plainff_included
