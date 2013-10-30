/* -----------------------------
 * xmlff.h
 *      formatted XML I/O file definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *      2013-06-13  mp  išmesti RtInfo related drti daiktai
 *       
 */  


#ifndef XMLFF_INCLUDED
#define XMLFF_INCLUDED

class XmlFmtFile: public FmtFile
{
public:
    XmlFmtFile(const uchar *p_lpszOutFileName, const uchar *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    void ExportDoc(void);  
};


extern FmtFile *CreateXmlFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode);

#endif // #ifndef XMLFF_INCLUDED
