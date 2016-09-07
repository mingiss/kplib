/* -----------------------------
 * xmlx.cpp
 *      common xml things
 *      
 *  Changelog:
 *      2013-06-11  mp  initial creation
 *       
 */  

// --------------------------------------------------
const uchar *plpszaXmlSysTags[XL_NumOfSysTags5 + 1] = // General XML tag names (native)
{
    (const uchar *)"?xml?",             // XL_Version
                // "<?xml ?>",
                // "<?xml version=\'1.0\' encoding=\"UTF-8\" ?>",
                // "<?XML VERSION=\"1.0\" RMD=\"ALL\" ?>",
                // "<?XML ENCODING=\"UTF-8\" ?>",

    (const uchar *)"!DOCTYPE",          // XL_DocType
                // "<!DOCTYPE di SYSTEM>",
                // "<!DOCTYPE di SYSTEM \"%s\">",

    (const uchar *)"?xml-stylesheet?",  // XL_StyleSheet
                // "<?xml-stylesheet ?>",
                // "<?xml-stylesheet href=\"%s\" type=\"text/css\" ?>",

    (const uchar *)"!----",             // XL_Comment // komentaro tekstas -- ne tago reikšmė XmlNodeRec::m_lpszContents, 
                // "<!-- komentaras -->"              // o parametrai XmlNodeRec::m_pTagPars                    

    (const uchar *)"!--[if]",           // XL_IfComment
                // "<!--[if ]>",

    (const uchar *)"![endif]--",        // XL_EndIfComment
                // "<![endif]-->"

    (const uchar *)"![if]",             // XL_If
                // "<![if ]>",

    (const uchar *)"![endif]",          // XL_EndIf
                // "<![endif]>",

    (const uchar *)"tx", // "",         // XL_Text // fiktyvus vardas tagintam išvedimui ir 
                // "<tx>",                         // kad ties tuščia eilute nesustotų tago vardo paieška
    null
};
