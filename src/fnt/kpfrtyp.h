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

#include "kpstdlib.h"
#include "kperrno.h"

// -------------------------- FreeImage papildymai
// copied from freetype2/freetype-src/include/freetype/fterrors.h
#define FT_ERRORDEF(fullname, code, msg) fullname = code,
// #define FT_ERR_BASE FT_ERR_MOD(FT_ERR_MOD_NAME) // not an error base code, rather a module part of an error code actually
#define FT_ERR_BASE 0
#define FT_ERR_PREFIX FT_Err_
#define FT_ERRORDEF_(basename, base, msg) FT_ERRORDEF(FT_ERR_CAT(FT_ERR_PREFIX, basename), base + FT_ERR_BASE, msg)
#define FT_NOERRORDEF_(basename, base, msg) FT_ERRORDEF(FT_ERR_CAT(FT_ERR_PREFIX, basename), base, msg)

// #include FT_ERRORS_H
enum
{
// #include FT_ERROR_DEFINITIONS_H
#include "kpft_errdef.h" // TODO: try to define as an FT_ERROR_END_LIST and use fterrors.h
};

// TODO: define fterrors.h and kpft_errdef.h errors as belonging to module KpFrTyp as well

#undef FT_ERRORDEF_
#undef FT_NOERRORDEF_
#undef FT_ERR_PREFIX

// -------------------------------------
#define FT_CONFIG_OPTION_USE_MODULE_ERRORS 1 // TODO: move to config.h
#define FT_ERR_MOD_NAME KpFrTyp

// TODO: these actually should be moved to freetype2/freetype-src/include/freetype/fttypes.h
#define FT_ERR_PREFIX FT_ERR_MOD_NAME ## _
#define FT_ERR_MOD_CAT(modname) FT_Mod_Err_ ## modname
#define FT_ERR_MOD(modname) FT_ERR_MOD_CAT(modname)
#define FT_ERR_CODE(base) (FT_ERR_MOD(FT_ERR_MOD_NAME) | FT_Err_ ## base) // module and base to combined error code // TODO: define as belonging to current module

#include FT_MODULE_ERRORS_H
#define FT_MODERRDEF(modname, mod, msg) FT_ERR_MOD(modname) = mod,
enum
{
#include "kpft_moderr.h"
};
#undef FT_MODERRDEF

class KpFreeType
{
public:
    static HRESULT GetKpErrCode(FT_Error p_iError); // konvertuoja FreeType klaidos kodą į KpError HRESULT
    static FT_Error GetFtErrCode(HRESULT p_lKpErr); // atvirkščias GetKpErrCode() – konvertuoja KpError HRESULT į FreeType FT_Error  
    static const uchar *GetFtErrMsg(FT_Error p_iError); // suformuoja FreeType klaidos pranešimą
};

#endif // #ifndef KPFRTYP_INCLUDED
