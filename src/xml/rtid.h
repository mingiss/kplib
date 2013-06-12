/* ----------------
 * rtid.h
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
} RtInfo;

typedef RtInfo *pRtInfo;


// --------------------------
#define DRTI_XML_GRP_TAG (const UCHAR *)"xml"
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


// --------------------------
extern RtInfo InfoRtiArr[RTI_NUM_OF_KWDS + 1]; // papildomi vtex:info grupės tagai
extern RtInfo SettingsRtiArr[RTI_NUM_OF_KWDS + 1]; // palaidi vtex:settings grupės tagai
extern RtInfo RunToolRtiArr[RTI_NUM_OF_KWDS + 1]; // vtex:settings.runtool grupės tagai
extern RtInfo SomeToolRtiArr[RTI_NUM_OF_KWDS + 1]; // vtex:settings.sometool grupės tagai
extern RtInfo ImsRefRtiArr[RTI_NUM_OF_KWDS + 1]; // vtex:settings.imsref grupės tagai
extern RtInfo StructPybRtiArr[RTI_NUM_OF_KWDS + 1]; // vtex:settings.structpyb grupės tagai
extern RtInfo PageInfoRtiArr[RTI_NUM_OF_KWDS + 1]; // MC:PageInfo grupės tagai


#endif // #ifndef rti_included
