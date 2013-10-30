/*
 * kpfrtyp.h
 *  
 *    FreeType kp addons
 *
 *  2013-10-21  mp  Initial creation
 *   
 */   

#ifndef KPFRTYP_INCLUDED
#define KPFRTYP_INCLUDED

// -------------------------- FreeImage papildymai

typedef enum
{
KP_FT_Err_NoError = -1,
KP_FT_Err_FirstKpError = 0x1000,

KP_FT_Err_TooManyGlyphs = KP_FT_Err_FirstKpError,   // "too many glyphs"
KP_FT_Err_TooManyTypefaces,                         // "too many typefaces"
KP_FT_Err_TooManyCharMaps,                          // "too many charmaps"
KP_FT_Err_UnknownFtError,                           // "unknown error"

KP_FT_Err_LastKpErr
} KP_FT_Error;

#define KP_FT_NumOfKpErrs (KP_FT_Err_LastKpErr - KP_FT_Err_FirstKpError)

class KpFreeType
{
public:
    static HRESULT GetKpErrCode(FT_Error p_iError); // konvertuoja FreeType klaidos kodą į KpError HRESULT
    static FT_Error GetFtErrCode(HRESULT p_lKpErr); // atvirkščias GetKpErrCode() – konvertuoja KpError HRESULT į FreeType FT_Error  
    static const uchar *GetFtErrMsg(FT_Error p_iError); // suformuoja FreeType klaidos pranešimą
};

#endif // #ifndef KPFRTYP_INCLUDED
