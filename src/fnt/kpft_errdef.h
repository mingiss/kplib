/* --------------------
 *
 * kpft_errdef.h
 *
 *    supplement to the file freetype2/freetype-src/include/freetype/fterrdef.h
 *    look as well freetype2/freetype-src/include/freetype/ftmoderr.h for explanation and
 *    freetype2/freetype-src/include/freetype/fttypes.h for definitions of FT_ERR_CAT, FT_ERROR_BASE and FT_ERROR_MODULE
 */

/* generic errors 0x00--0x0F */

/*  FT_ERRORDEF_( Missing_Property,       0x0C, "missing property" ) */

    FT_ERRORDEF_(Unknown_Error,           0x0F, "unknown error") /* "error undefined" */

/* glyph/character errors 0x10--0x1F */

/*  FT_ERRORDEF_( Invalid_Pixel_Size,     0x17, "invalid pixel size" ) */

    FT_ERRORDEF_(Too_Many_Glyphs,         0x18, "too many glyphs")
    FT_ERRORDEF_(Too_Many_Typefaces,      0x19, "too many typefaces")

  /* handle errors 0x20--0x2F */

/*  FT_ERRORDEF_( Invalid_Stream_Handle,  0x28, "invalid stream handle" ) */

    FT_ERRORDEF_(Too_Many_Char_Maps,      0x29, "too many charmaps")

/* driver errors 0x30--0x3F */

/*  FT_ERRORDEF_( Too_Many_Extensions,    0x31, "too many extensions" ) */

/* memory errors 0x40--0x4F */

/*  FT_ERRORDEF_( Unlisted_Object,        0x41, "unlisted object" ) */

/* stream errors 0x50--0x5F */

/*  FT_ERRORDEF_( Invalid_Frame_Read,     0x58, "invalid frame read" ) */

/* raster errors 0x60--0x6F */

/*  FT_ERRORDEF_( Raster_Negative_Height, 0x63, "negative height while rastering" ) */

/* cache errors 0x70--0x7F */

/*  FT_ERRORDEF_( Too_Many_Caches,        0x70, "too many registered caches" ) */

/* TrueType and SFNT errors 0x80--0x9F */

/*  FT_ERRORDEF_( Invalid_Post_Table,     0x9B, "invalid PostScript (post) table" ) */

/* CFF, CID, and Type 1 errors 0xA0--0xAF */

/*  FT_ERRORDEF_( Glyph_Too_Big,          0xA4, "glyph too big for hinting" ) */

/* BDF errors 0xB0--0xBF */

/*  FT_ERRORDEF_( Corrupted_Font_Glyphs,  0xBA, "Font glyphs corrupted or missing fields" ) */

/* 0xC0--0xFF */

/* END */
