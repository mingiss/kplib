/* -----------------------------
 * xmlff.h
 *      formatted XML I/O file definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *       
 */  


#ifndef xmlff_included
#define xmlff_included

class XmlFmtFile: public FmtFile
{
public:
    XmlFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    void ExportDoc(void);  
};


extern FmtFile *CreateXmlFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef xmlff_included
