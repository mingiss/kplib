/*
 * kpfrtyp.h
 *  
 *    FreeType kp addons
 *
 *  2013-10-21  mp  Initial creation
 *   
 */   

#ifndef kpfrtyp_included
#define kpfrtyp_included

// -------------------------- FreeImage papildymai

typedef enum
{
KP_FT_Err_NoError = -1,
KP_FT_Err_FirstKpError = 0x1000,
KP_FT_Err_TooManyGlyphs = KP_FT_Err_FirstKpError,
KP_FT_Err_LastKpErr
} KP_FT_Error;

#define KP_FT_NumOfKpErrs (KP_FT_Err_LastKpErr - KP_FT_Err_FirstKpError)

class KpFreeType
{
public:
    static HRESULT GetKpErrCode(FT_Error p_iError); // konvertuoja FreeType klaidos kodą į KpError HRESULT
    static const uchar *GetFtErrMsg(FT_Error p_iError); // suformuoja FreeType klaidos pranešimą
};

#endif // #ifndef kpfrtyp_included


