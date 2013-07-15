/* -----------------------------
 * xmlx.h
 *      common xml definitions
 *      
 *  Changelog:
 *      2013-06-10  mp  initial creation
 *       
 */  


// ----------------------------------------
#define XL_MaxNumOfTags 1000

#define XM_FirstDictTagCode 5000 // pirmas vartotojo dtd tago kodas; iki 5999

#define XH_FirstHtmTagCode 6000 // pirmas HTML tago kodas; iki 6999

#define XL_FirstSysTagCode 7000 // pirmas sisteminio tago kodas (<!DOCTYPE>, <?xml ?>, etc.); iki 7999

#define XL_NumOfSysTags    (XL_LastSysTag - XL_FirstSysTag)
#define XL_NumOfSysTags5 XL_NumOfSysTags

enum XmlSysTagChars                          // XML system tag characters
{
   XL_FirstSysTag    = XL_FirstSysTagCode,   // =7000,

   XL_Version        = XL_FirstSysTagCode,   // =7000, // former XC_Version
   XL_DocType,       /*  7001 */
   XL_StyleSheet,    /*  7002 */
   XL_Comment,       /*  7003 */

   XL_IfComment,     /*  7004 */
   XL_EndIfComment,  /*  7005 */    // uždarantis tagas kitu kodu negu XL_IfComment, 
                                    // nes <!--[if ]> ir <![endif]--> nesinhronizuoti su kitais tagais
   XL_If,            /*  7006 */
   XL_EndIf,         /*  7007 */    // uždarantis tagas kitu kodu negu XL_If,
                                    // nes <![if ]> ir <![endif]> nesinhronizuoti su kitais tagais

   XL_Text,          /*  7008 */    // internal tag for keeping of free text

   XL_LastSysTag
};

extern const uchar *plpszaXmlSysTags[XL_NumOfSysTags + 1]; // XML system tag names without enclosing "<" and ">" 
