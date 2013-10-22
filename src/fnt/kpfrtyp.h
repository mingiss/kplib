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

#define KP_FT_Err_NoError -1

class KpFreeType
{
public:
    static HRESULT GetKpErrCode(FT_Error p_iError); // konvertuoja FreeType klaidos kodą į KpError HRESULT
    static const uchar *GetFtErrMsg(FT_Error p_iError); // suformuoja FreeType klaidos pranešimą
};

#endif // #ifndef kpfrtyp_included


