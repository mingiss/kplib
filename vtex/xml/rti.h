/* ----------------
 * rti.h
 *      {keyword, value} (DVI runtime info) tag processing
 *      control callback definitions for (DVI) converters (drti, etc.)
 *
 *  Changelog:
 *      2013-06-07  mp  split off from drti.c
 *
 */

#ifndef rti_included
#define rti_included


// ------------------------
#define RTI_EQ_SIGN C_Eq // 61 // '='
#define RTI_OPENING_BRACE C_Lcurl // '{'
#define RTI_CLOSING_BRACE C_Rcurl // '}'


// -----------------------------
#define RTI_KWD_LEN KP_MAX_FILE_LIN_LEN // 200
#define RTI_NUM_OF_KWDS 500 // max size of rti array

typedef struct runtimeinfo
{
  UCHAR name[RTI_KWD_LEN + 1];
  UCHAR value[RTI_KWD_LEN + 1];
} rti;

typedef rti *prti;


// --------------------------
#define DRTI_STAGE_TAG (const UCHAR *)"mt:stage"
#define DRTI_INFO_GRP_TAG (const UCHAR *)"vtex:info"
#define DRTI_SETTINGS_GRP_TAG (const UCHAR *)"vtex:settings"
#define DRTI_OPTION_TAG (const UCHAR *)"option"
#define DRTI_RUNTOOL_GRP_TAG (const UCHAR *)"runtool"
#define DRTI_SOMETOOL_GRP_TAG (const UCHAR *)"sometool"
#define DRTI_IMSREF_GRP_TAG (const UCHAR *)"imsref"
#define DRTI_STRUCTPYB_GRP_TAG (const UCHAR *)"structpyb"
#define DRTI_PAGEINFO_GRP_TAG (const UCHAR *)"MC:PageInfo"

#define DRTI_CHKSUM_TAG_PREF (const UCHAR *)"chksum:"
#define DRTI_CHKSUM_GRP_TAG (const UCHAR *)"chksums"

#define DRTI_ALL_GRP_TAG (const UCHAR *)"all"


// -----------------------------
// list of group tags processed (possible values -- DRTI_*_GRP_TAG) 
extern UCHAR grp_list_e[RTI_NUM_OF_KWDS][RTI_KWD_LEN + 1];
extern int grp_list_n;


// --------------------------
extern rti InfoRtiArr[RTI_NUM_OF_KWDS + 1]; // papildomi vtex:info grupės tagai
extern rti SettingsRtiArr[RTI_NUM_OF_KWDS + 1]; // palaidi vtex:settings grupės tagai
extern rti RunToolRtiArr[RTI_NUM_OF_KWDS + 1]; // vtex:settings.runtool grupės tagai
extern rti SomeToolRtiArr[RTI_NUM_OF_KWDS + 1]; // vtex:settings.sometool grupės tagai
extern rti ImsRefRtiArr[RTI_NUM_OF_KWDS + 1]; // vtex:settings.imsref grupės tagai
extern rti StructPybRtiArr[RTI_NUM_OF_KWDS + 1]; // vtex:settings.structpyb grupės tagai
extern rti PageInfoRtiArr[RTI_NUM_OF_KWDS + 1]; // MC:PageInfo grupės tagai


// -----------------------------
// parse comma separated keyword list p_lpszKwdStr to array of strings 
// p_szaKwdList[RTI_NUM_OF_KWDS][RTI_KWD_LEN + 1] 
extern void scan_kwd_list(UCHAR p_szaKwdList[][RTI_KWD_LEN + 1], int *p_piKwdListSize, const UCHAR *p_lpszKwdStr); 

// checks presence of p_lpszKwd in list p_szaKwdList
// p_szaKwdList[p_iKwdListSize][RTI_KWD_LEN + 1] 
extern PLAIN_C bool kwd_in_list(/* const */ UCHAR p_szaKwdList[][RTI_KWD_LEN + 1], int p_iKwdListSize, const UCHAR *p_lpszKwd); 


// -----------------------------
extern PLAIN_C void str_del(UCHAR *t, UCHAR *s, const UCHAR *p_lpszHead);

// adds tag string to the end of array pointed by p_pRti
// checks array p_pRti[] size not to cross RTI_MAX_NUM_OF_RTIS + 1 boundary
// end of the elements in p_pRti[] is marked by {"", ""} record
// multiple tag string is split into individual tags:
//  "voffset={-72.26999pt} hoffset={-72.26999pt} topmargin={29.98857pt} headheight={12.0pt} headsep={14.0pt} textheight={540.60236pt} textwidth={332.89723pt} oddsidemargin={54.0pt} evensidemargin={54.0pt} footskip={20.0pt} baselineskip={12.0pt plus 0.3pt minus 0.3pt} headmargin={29.98857pt} backmargin={54.0pt} columnwidth={332.89723pt} trimbox={0 0 439.3701 666.1417}"
extern PLAIN_C void add_to_rti(const UCHAR *p_lpszKwdStr, prti p_pRti);

// split 's' into 't' and 'tt'
extern int split_strings(UCHAR *t, UCHAR *tt, /* const */ UCHAR *s);


// --------------------------- converter callbacks
extern PLAIN_C void RtiCmdOpen(void);   /* start of command and parameters */
extern PLAIN_C void RtiCmdClose(void);  /* end of command and parameters */

extern PLAIN_C void RtiTransPreamble(int p_iNumOfBytes, FILE *p_pDviFile);
extern PLAIN_C void RtiTransFontDef(int p_iNumOfBytes, FILE *p_pDviFile);
extern PLAIN_C void RtiTransSpec(int p_iNumOfBytes, FILE *p_pDviFile);

// skips p_iNumOfBytes of p_pDviFile
// can be used as void substitutes for other RtiTrans*() 
extern PLAIN_C void RtiSkipInBytes(int p_iNumOfBytes, FILE *p_pDviFile);

// prints array of low level tags 
// with checking for corespondence to the list of output tags (drtim option "-e")
extern void OutputRtiArr(const prti p_pRti); 

#endif // #ifndef rti_included
