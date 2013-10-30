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

#ifndef PLAINFF_INCLUDED
#define PLAINFF_INCLUDED

class PlainFmtFile: public FmtFile
{
public:
    bool m_bOutputEmpty; // paskutinio \n suvalgymui
    PlainFmtFile(const uchar *p_lpszOutFileName, const uchar *p_lpszFileMode)
        : FmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    void ExportNode(TiXmlNode *p_pCurNode, FILE *p_pOutFile);
    void ExportDoc(void);  
};


extern FmtFile *CreatePlainFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode);

#endif // #ifndef PLAINFF_INCLUDED
