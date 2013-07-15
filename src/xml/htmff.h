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
    HtmFmtFile(const uchar *p_lpszOutFileName, const uchar *p_lpszFileMode)
        : XmlFmtFile(p_lpszOutFileName, p_lpszFileMode) 
        {}

    // formuoja xhtml kepurę; m_XmlDoc turi būti tuščias
    // grąžina pointerį į <html> tago mazgą
    // p_HeadNode – <head> mazgas, gali būti NULL
    TiXmlElement *CreateHtmHead(TiXmlElement *p_HeadNode); 
};


extern FmtFile *CreateHtmFmtFile(const uchar *p_lpszFileName, const uchar *p_lpszFileMode);

#endif // #ifndef htmff_included
