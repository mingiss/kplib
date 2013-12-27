/*
 * kpfrtyp.cpp
 *  
 *    FreeType kp addons
 *
 *  2013-10-21  mp  Initial creation
 *   
 */   

#include "envir.h"

#ifdef __WIN32__
#include <windows.h>
#endif

#include "ft2build.h"
#include FT_FREETYPE_H

using namespace std;

#include "kperrno.h"
#include "kpstdlib.h"
#include "kpfrtyp.h"


// ---------------------------
HRESULT KpFreeType::GetKpErrCode(FT_Error p_iError)
{
HRESULT retc = S_OK;

    switch (p_iError)
    {
    case KP_FT_Err_NoError:                     // "error undefined"
    
    case FT_Err_Ok:                             // "no error" 
    case FT_Err_Ignore:                         // "ignore"
        retc = S_OK; 
        break;
    
    case FT_Err_Unknown_File_Format:            // "unknown file format"
    case FT_Err_Invalid_File_Format:            // "broken file"
    case FT_Err_Invalid_Version:                // "invalid FreeType version"
    case FT_Err_Lower_Module_Version:           // "module version is too low"
    case FT_Err_Invalid_Table:                  // "broken table"
    case FT_Err_Invalid_Offset:                 // "broken offset within table"
    case FT_Err_Missing_Module:                 // "missing module"
    case FT_Err_Missing_Property:               // "missing property"
    case FT_Err_Invalid_Glyph_Index:            // "invalid glyph index"
    case FT_Err_Invalid_Glyph_Format:           // "unsupported glyph image format"
    case FT_Err_Cannot_Render_Glyph:            // "cannot render this glyph format"
    case FT_Err_Invalid_Outline:                // "invalid outline"
    case FT_Err_Invalid_Composite:              // "invalid composite glyph"
    case FT_Err_Too_Many_Hints:                 // "too many hints"
    case FT_Err_Invalid_Pixel_Size:             // "invalid pixel size"
    case FT_Err_Invalid_Handle:                 // "invalid object handle"
    case FT_Err_Invalid_Library_Handle:         // "invalid library handle"
    case FT_Err_Invalid_Driver_Handle:          // "invalid module handle"
    case FT_Err_Invalid_Face_Handle:            // "invalid face handle"
    case FT_Err_Invalid_Size_Handle:            // "invalid size handle"
    case FT_Err_Invalid_Slot_Handle:            // "invalid glyph slot handle"
    case FT_Err_Invalid_CharMap_Handle:         // "invalid charmap handle"
    case FT_Err_Invalid_Cache_Handle:           // "invalid cache manager handle"
    case FT_Err_Invalid_Stream_Handle:          // "invalid stream handle"
    case FT_Err_Unlisted_Object:                // "unlisted object"
    case FT_Err_Nested_Frame_Access:            // "nested frame access"
    case FT_Err_Nested_DEFS:                    // "nested DEFS"
    case FT_Err_Table_Missing:                  // "SFNT font table missing"
    case FT_Err_Horiz_Header_Missing:           // "horizontal header (hhea) table missing" 
    case FT_Err_Locations_Missing:              // "locations (loca) table missing"
    case FT_Err_Name_Table_Missing:             // "name table missing"
    case FT_Err_CMap_Table_Missing:             // "character map (cmap) table missing"
    case FT_Err_Hmtx_Table_Missing:             // "horizontal metrics (hmtx) table missing"
    case FT_Err_Post_Table_Missing:             // "PostScript (post) table missing"
    case FT_Err_Invalid_Horiz_Metrics:          // "invalid horizontal metrics"
    case FT_Err_Invalid_CharMap_Format:         // "invalid character map (cmap) format"
    case FT_Err_Invalid_PPem:                   // "invalid ppem value"
    case FT_Err_Invalid_Vert_Metrics:           // "invalid vertical metrics"
    case FT_Err_Could_Not_Find_Context:         // "could not find context"
    case FT_Err_Invalid_Post_Table_Format:      // "invalid PostScript (post) table format" 
    case FT_Err_Invalid_Post_Table:             // "invalid PostScript (post) table"
    case FT_Err_Missing_Startfont_Field:        // "`STARTFONT' field missing"
    case FT_Err_Missing_Font_Field:             // "`FONT' field missing"
    case FT_Err_Missing_Size_Field:             // "`SIZE' field missing"
    case FT_Err_Missing_Fontboundingbox_Field:  // "`FONTBOUNDINGBOX' field missing"
    case FT_Err_Missing_Chars_Field:            // "`CHARS' field missing"
    case FT_Err_Missing_Startchar_Field:        // "`STARTCHAR' field missing"
    case FT_Err_Missing_Encoding_Field:         // "`ENCODING' field missing"
    case FT_Err_Missing_Bbx_Field:              // "`BBX' field missing"
    case FT_Err_Corrupted_Font_Header:          // "Font header corrupted or missing fields"
    case FT_Err_Corrupted_Font_Glyphs:          // "Font glyphs corrupted or missing fields"

    case KP_FT_Err_TooManyGlyphs:               // "too many glyphs"
    case KP_FT_Err_TooManyTypefaces:            // "too many typefaces"
    case KP_FT_Err_TooManyCharMaps:             // "too many charmaps"
        retc = KP_E_FILE_FORMAT;                        
        break;                                          
                                                        
    case FT_Err_Invalid_Argument:               // "invalid argument"
    case FT_Err_Too_Few_Arguments:              // "too few arguments"
    case FT_Err_Code_Overflow:                  // "code overflow"
    case FT_Err_Bad_Argument:                   // "bad argument"
    case FT_Err_Invalid_Reference:              // "invalid reference"
    case FT_Err_Debug_OpCode:                   // "found debug opcode"
    case FT_Err_Invalid_Frame_Operation:        // "invalid frame operation"
    case FT_Err_Invalid_Opcode:                 // "invalid opcode"
    case FT_Err_Invalid_CodeRange:              // "invalid code range"
    case FT_Err_Syntax_Error:                   // "opcode syntax error"
        retc = E_INVALIDARG;
        break;
    
    case FT_Err_Unimplemented_Feature:          // "unimplemented feature"
        retc = E_NOTIMPL;
        break;
    
    case FT_Err_Array_Too_Large:                // "array allocation size too large"
    case FT_Err_Raster_Overflow:                // "raster overflow"
    case FT_Err_Glyph_Too_Big:                  // "glyph to big for hinting"
    case FT_Err_Bbx_Too_Big:                    // "`BBX' too big"
        retc = KP_E_BUFFER_OVERFLOW;
        break;

    case FT_Err_Invalid_Character_Code:         // "invalid character code"
        retc = KP_E_UNKN_CHR;
        break;
        
    case FT_Err_Out_Of_Memory:                  // "out of memory"
    case FT_Err_Too_Many_Caches:                // "too many registered caches"
    case FT_Err_Stack_Overflow:                 // "stack overflow"
    case FT_Err_Too_Many_Function_Defs:         // "too many function definitions"
    case FT_Err_Too_Many_Instruction_Defs:      // "too many instruction definitions"
    case FT_Err_Stack_Underflow:                // "argument stack underflow"
        retc = E_OUTOFMEMORY;
        break;

    case FT_Err_Divide_By_Zero:                 // "division by zero"
        retc = KP_E_DIV_ZERO;                                                
        break;

    case FT_Err_Cannot_Open_Stream:             // "cannot open stream"
    case FT_Err_Cannot_Open_Resource:           // "cannot open resource"
        retc = KP_E_FILE_NOT_FOUND;
        break;

    case FT_Err_Invalid_Stream_Seek:            // "invalid stream seek"
    case FT_Err_Invalid_Stream_Skip:            // "invalid stream skip"
    case FT_Err_Invalid_Stream_Read:            // "invalid stream read"
    case FT_Err_Invalid_Stream_Operation:       // "invalid stream operation"
    case FT_Err_Invalid_Frame_Read:             // "invalid frame read"
        retc = KP_E_FERROR;
        break;

    case FT_Err_ENDF_In_Exec_Stream:            // "found ENDF opcode in execution stream"
        retc = KP_E_EOF;
        break;
        
    case FT_Err_Execution_Too_Long:             // "execution context too long"
        retc = KP_E_TIMEOUT;
        break;

    case FT_Err_No_Unicode_Glyph_Name:          // "no Unicode glyph name found"
        retc = KP_E_KWD_NOT_FOUND;
        break;

    case FT_Err_Too_Many_Drivers:               // "too many modules"
    case FT_Err_Too_Many_Extensions:            // "too many extensions"
    case FT_Err_Raster_Uninitialized:           // "raster uninitialized"
    case FT_Err_Raster_Corrupted:               // "raster corrupted"
    case FT_Err_Raster_Negative_Height:         // "negative height while rastering"
        retc = KP_E_SYSTEM_ERROR;                       
        break;                                          

    default:                                            
        retc = KP_E_UNHANDLED_EXCEPTION;                       
        break;                                          
    }

return(retc);
}


FT_Error KpFreeType::GetFtErrCode(HRESULT p_lKpErr)
{
FT_Error retv = FT_Err_Ok;

    switch (p_lKpErr)
    {
    case S_OK:
        retv = FT_Err_Ok;
        break;
        
    case E_NOTIMPL:
        retv = FT_Err_Unimplemented_Feature;
        break;

    case E_INVALIDARG:
        retv = FT_Err_Invalid_Argument;
        break;

    case KP_E_FILE_FORMAT:
        retv = FT_Err_Unknown_File_Format;
        break;

    case KP_E_DIV_ZERO:
        retv = FT_Err_Divide_By_Zero;
        break;

    case E_OUTOFMEMORY:
        retv = FT_Err_Out_Of_Memory;
        break;

    case KP_E_BUFFER_OVERFLOW:
        retv = FT_Err_Array_Too_Large;
        break;

    case KP_E_DIR_ERROR:
    case KP_E_FILE_NOT_FOUND:
        retv = FT_Err_Cannot_Open_Stream;
        break;

    case KP_E_EOF:
        retv = FT_Err_ENDF_In_Exec_Stream;
        break;

    case KP_E_KWD_NOT_FOUND:
        retv = FT_Err_No_Unicode_Glyph_Name;
        break;

    case KP_E_UNKN_CHR:
        retv = FT_Err_Invalid_Character_Code;
        break;

    case KP_E_TIMEOUT:
        retv = FT_Err_Execution_Too_Long;
        break;

    case E_UNEXPECTED:
    case E_NOINTERFACE:
    case E_POINTER:
    case E_HANDLE:
    case E_ABORT:
    case E_FAIL:
    case E_ACCESSDENIED:
    case E_PENDING:
    // case E_OBJECT_BUSY:
    // case KP_E_OUTOFMEM:
    case KP_E_DOUBLE_UNGET:
    case KP_E_FERROR:
    case KP_E_SYSTEM_ERROR:
    case KP_E_NO_FILE:
    case KP_E_COMMAND_ERROR:
    case KP_E_FONT_UNDEF:
    case KP_E_UNKNOWN_SYSTEM:
    case KP_E_ILL_CODE:
    // case KP_E_CANCEL:
    // case KP_E_DOUBLE_CALL:
    case KP_E_OBJ_NOT_FOUND:
    case KP_E_NO_CONN:
    case KP_E_TRANS_ERR:
    case KP_E_REFUSED:
    // case KP_E_ACCESS_DENIED:
    case KP_E_ILL_CHR:
    case KP_E_SKIP:
    case KP_E_ILLMATHARG:
    case KP_E_ILLFUNC:
    case KP_E_NOTINST:
    case KP_E_MSG_FORMAT:
    case KP_E_OBSOLETE:
    case KP_E_HELP:
    case KP_E_NEG_ANSW:
    case KP_E_FILE_CHANGED:
    case KP_S_DIAG_MSG:
    case KP_E_BAD_EMAIL:
    case KP_S_LOGOFF:
    case KP_S_DONE:
    case KP_E_EXPIRED:
    case KP_E_UNHANDLED_EXCEPTION:
        retv = KP_FT_Err_UnknownFtError;
        break;

    default:
        retv = KP_FT_Err_UnknownFtError;
        break;
    }
    
return(retv);    
}  


// ---------------------------
#define FT_ERRORDEF_(name, code, msg) case FT_Err_##name: ret_msg = (const uchar *)msg; break;
#define FT_NOERRORDEF_(name, code, msg) FT_ERRORDEF_(name, code, msg)

const uchar *KpFreeType::GetFtErrMsg(FT_Error p_iError)
{
const uchar *ret_msg = (const uchar *)"unknown FreeType error";

    switch (p_iError)
    {
#include "fterrdef.h"

    case KP_FT_Err_TooManyGlyphs:       ret_msg = (const uchar *)"kpfrtyp: too many glyphs"; break;
    case KP_FT_Err_TooManyTypefaces:    ret_msg = (const uchar *)"kpfrtyp: too many typefaces"; break;
    case KP_FT_Err_TooManyCharMaps:     ret_msg = (const uchar *)"too many charmaps"; break;
    case KP_FT_Err_UnknownFtError:      ret_msg = (const uchar *)"unknown error"; break;
    }

return(ret_msg);
}