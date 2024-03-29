/* -----------------------------
 * binff.h
 *      binary format file I/O definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *       
 */  

#ifndef BINFF_INCLUDED
#define BINFF_INCLUDED

class BinFmtFile: public FmtFile
{
public:
    BinFmtFile(const uchar *p_lpszOutFileName, const uchar *p_lpszFileMode) 
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    void ExportDoc(void);  
};


extern FmtFile *CreateBinaryFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode);

#endif // #ifndef BINFF_INCLUDED
