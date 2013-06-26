/* -----------------------------
 * htmff.h
 *      formatted XHTML I/O file definitions
 *      
 *  Changelog:
 *      2013-06-26  mp  initial creation
 *       
 */  


#ifndef htmff_included
#define htmff_included

class HtmFmtFile: public XmlFmtFile
{
public:
    HtmFmtFile(const UCHAR *p_lpszOutFileName, const UCHAR *p_lpszFileMode)
        : XmlFmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    // formuoja xhtml kepurę; m_XmlDoc turi būti tuščias
    // grąžina pointerį į <html> tago mazgą
    // p_HeadNode – <head> mazgas, gali būti NULL
    TiXmlElement *CreateHtmHead(TiXmlElement *p_HeadNode); 
};


extern FmtFile *CreateHtmFmtFile(const UCHAR *p_lpszFileName, const UCHAR *p_lpszFileMode);

#endif // #ifndef htmff_included
