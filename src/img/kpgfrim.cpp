/*
 * kpgfrim.cpp
 *  
 *    FreeImage kp addons
 *
 *  2013-06-20  mp  Initial creation
 *   
 */   

#include "envir.h"

#include <stdio.h>
#include <iostream>
#include <math.h>
#ifdef __WIN32__
#include <windows.h>
#endif

#include "FreeImage.h"
#include "FreeImagePlus.h"

#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kperrno.h"
#include "kpmsg.h"
#include "kperr.h"
#include "kpimg.h"
#include "kpgfrim.h"


// -------------------------- FreeImage papildymai
const uchar *plpszPictExt[] =
{
    (const uchar *)"bmp", // FIF_BMP  = 0,
    (const uchar *)"ico", // FIF_ICO    = 1,
    (const uchar *)"jp",  // "jpg", // "jpeg", FIF_JPEG   = 2,
    (const uchar *)"jng", // FIF_JNG    = 3,
    (const uchar *)"koala",   // FIF_KOALA  = 4,
    (const uchar *)"lbm", // FIF_LBM    = 5,  FIF_IFF = FIF_LBM,
    (const uchar *)"mng", // FIF_MNG    = 6,
    (const uchar *)"pbm", // FIF_PBM    = 7,
    (const uchar *)"pbmraw",  // FIF_PBMRAW = 8,
    (const uchar *)"pcd", // FIF_PCD    = 9,
    (const uchar *)"pcx", // FIF_PCX    = 10,
    (const uchar *)"pgm", // FIF_PGM    = 11,
    (const uchar *)"pgmraw",  // FIF_PGMRAW = 12,
    (const uchar *)"png", // FIF_PNG    = 13,
    (const uchar *)"ppm", // FIF_PPM    = 14,
    (const uchar *)"ppmraw",  // FIF_PPMRAW = 15,
    (const uchar *)"ras", // FIF_RAS    = 16,
    (const uchar *)"targa",   // FIF_TARGA  = 17,
    (const uchar *)"tif", // "tiff", // FIF_TIFF   = 18,
    (const uchar *)"wbmp",    // FIF_WBMP   = 19,
    (const uchar *)"psd", // FIF_PSD    = 20,
    (const uchar *)"cut", // FIF_CUT    = 21,
    (const uchar *)"xbm", // FIF_XBM    = 22,
    (const uchar *)"xpm", // FIF_XPM    = 23,
    (const uchar *)"dds", // FIF_DDS    = 24,
    (const uchar *)"gif", // FIF_GIF    = 25,
    (const uchar *)"hdr", // FIF_HDR    = 26,
    (const uchar *)"faxg3",   // FIF_FAXG3  = 27,
    (const uchar *)"sgi", // FIF_SGI    = 28,
    (const uchar *)"exr", // FIF_EXR    = 29,
    (const uchar *)"j2k", // FIF_J2K    = 30,
    (const uchar *)"jp2", // FIF_JP2    = 31,
    (const uchar *)"pfm", // FIF_PFM    = 32,
    (const uchar *)"pict",    // FIF_PICT   = 33,
    (const uchar *)"raw", // FIF_RAW    = 34

    null
};


void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message) 
{
const uchar *fif_str = (const uchar *)"";
    if(fif != FIF_UNKNOWN) fif_str = (const uchar *)FreeImage_GetFormatFromFIF(fif);
    if(fif_str == null) fif_str = (const uchar *)"";
    if(message == NULL) message = "";

uchar *msg_str = null;
    KP_NEWA(msg_str, uchar, strlen(fif_str) + strlen(message) + 100);
    sprintf((char *)msg_str, "FreeImage error: %s; Image format: %s", message, fif_str);    
    KP_ERROR(KP_E_SYSTEM_ERROR, msg_str); 
    KP_DELETEA(msg_str);
}


void KpFreeImageInit(void)
{
    FreeImage_Initialise();
    FreeImage_SetOutputMessage(FreeImageErrorHandler);
    KpError.PutLogMessage("FreeImage: %s", FreeImage_GetVersion());
}


// ---------------------------
void fipWinImageKp::getPixelColorKp(unsigned p_iX, unsigned p_iY, RGBQUAD *p_pValue) const
{
    KP_ASSERT(p_pValue, E_INVALIDARG, null);
    
FREE_IMAGE_COLOR_TYPE col_type = getColorType();

RGBQUAD *palette = getPalette();
//  if(col_type == FIC_PALETTE)
    if(palette)
    {
//      KP_ASSERT(palette, E_POINTER, null);
        
    BYTE index;      
        KP_ASSERT(getPixelIndex(p_iX, p_iY, &index), KP_E_SYSTEM_ERROR, null);
        KP_ASSERT(index < getColorsUsed(), KP_E_SYSTEM_ERROR, null);
        
        memcpy(p_pValue, palette + index, sizeof(RGBQUAD));
    }
    else
        KP_ASSERT(getPixelColor(p_iX, p_iY, p_pValue), KP_E_SYSTEM_ERROR, null);

    if(col_type == FIC_MINISWHITE)
    {
        p_pValue->rgbRed = 0xFF - p_pValue->rgbRed; 
        p_pValue->rgbGreen = 0xFF - p_pValue->rgbGreen; 
        p_pValue->rgbBlue = 0xFF - p_pValue->rgbBlue; 
    }
}


int fipWinImageKp::getPixelGreyVal(unsigned p_iX, unsigned p_iY) const
{
RGBQUAD color;
    getPixelColorKp(p_iX, p_iY, &color);
return(color.rgbRed + color.rgbGreen + color.rgbBlue);
}
