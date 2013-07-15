/* -----------------------------
 * xmln.h
 *      xml file record XmlNode definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  

// ----------------------------------------
class XmlNodeRec: public KpTreeRec // XmlNode elemento duomenų struktūra, XmlNode::m_lpRecord
{
public:
    int m_iNodeTag; // tago kodas  
                    // jei tarp XmlRecord::m_iFirstTag ir XmlRecord::m_iFirstTag + XmlRecord::m_iNumOfTags, 
                    // tada tago tekstas yra XmlRecord::m_plpszaTags[XmlNodeRec::m_iNodeTag - XmlRecord::m_iFirstTag]
                    // taip pat gali būti ir kodas iš intervalo XL_FirstSysTag .. XL_LastSysTag
                        
    XmlTagPars *m_pTagPars; // tag parameters

    uchar *m_lpszTagContents;  // text contents of the tag - null-terminated UTF-8 string, 
                            //      only for m_iNodeTag==XC_Text, 
                            //      if not null -- no subtags and m_pTagPars allowed
                            
    XmlNodeRec(int p_iNodeTag, XmlTagPars *p_pTagPars, uchar *p_lpszTagContents);
                // konstruktorius                    
                // p_pTagPars tiesiog priskiria m_pTagPars, todėl p_pTagPars turi būti dinamiškai išskirtas,
                //      po grįžimo trinti nebegalima
                // m_lpszTagContents sukuria iš naujo, todėl p_lpszContents galima perduoti literalus ar statines eilutes, 
                //      jei p_lpszContents buvo dinamiškai sukurtas, po grįžimo reikia trinti           

    ~XmlNodeRec();
};


// ----------------------------------------
// KpTree structure with XmlNodeRec data fields
class XmlNode : public KpTreeEntry
{
};


// ----------------------------------------
class XmlTree
{
public:
    XmlNode *m_pRootNode; // record tree entry point
    const uchar **m_plpszaTags; // pointeris į tagų vardų masyvą, pvz., plpszaXmlttDictTagsFull[]
                                // masyvo dydis -- XL_MaxNumOfTags
    int m_iFirstTag;    // tago kodas, atitinkantis m_plpszaTags[0]
    int m_iNumOfTags;   // m_plpszaTags[] elementų skaičius
    
    XmlTree(void);
    
    // kuria tago objektą pagal tago vardą, pakeliui sukuria m_plpszaTags[] įrašą, jei tokio tago dar nėra 
    XmlNodeRec *CreateTagNode(const uchar *p_lpszTagName, 
        const XmlTagPars *p_TagPars, const uchar *p_lpszTagContents);
};
