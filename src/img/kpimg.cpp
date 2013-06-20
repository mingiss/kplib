/*
 * kpimg.cpp
 *  
 *    image commons
 *
 *  2013-06-20  mp  Initial creation
 *   
 */   

#include "envir.h"

#ifdef __WIN32__
#include <windows.h>
#endif

#include "kpstdlib.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpimg.h"


const UCHAR *plpszPictExt[] =
{
    (const UCHAR *)"bmp", // FIF_BMP  = 0,
    (const UCHAR *)"ico", // FIF_ICO    = 1,
    (const UCHAR *)"jp",  // "jpg", // "jpeg", FIF_JPEG   = 2,
    (const UCHAR *)"jng", // FIF_JNG    = 3,
    (const UCHAR *)"koala",   // FIF_KOALA  = 4,
    (const UCHAR *)"lbm", // FIF_LBM    = 5,  FIF_IFF = FIF_LBM,
    (const UCHAR *)"mng", // FIF_MNG    = 6,
    (const UCHAR *)"pbm", // FIF_PBM    = 7,
    (const UCHAR *)"pbmraw",  // FIF_PBMRAW = 8,
    (const UCHAR *)"pcd", // FIF_PCD    = 9,
    (const UCHAR *)"pcx", // FIF_PCX    = 10,
    (const UCHAR *)"pgm", // FIF_PGM    = 11,
    (const UCHAR *)"pgmraw",  // FIF_PGMRAW = 12,
    (const UCHAR *)"png", // FIF_PNG    = 13,
    (const UCHAR *)"ppm", // FIF_PPM    = 14,
    (const UCHAR *)"ppmraw",  // FIF_PPMRAW = 15,
    (const UCHAR *)"ras", // FIF_RAS    = 16,
    (const UCHAR *)"targa",   // FIF_TARGA  = 17,
    (const UCHAR *)"tif", // "tiff", // FIF_TIFF   = 18,
    (const UCHAR *)"wbmp",    // FIF_WBMP   = 19,
    (const UCHAR *)"psd", // FIF_PSD    = 20,
    (const UCHAR *)"cut", // FIF_CUT    = 21,
    (const UCHAR *)"xbm", // FIF_XBM    = 22,
    (const UCHAR *)"xpm", // FIF_XPM    = 23,
    (const UCHAR *)"dds", // FIF_DDS    = 24,
    (const UCHAR *)"gif", // FIF_GIF    = 25,
    (const UCHAR *)"hdr", // FIF_HDR    = 26,
    (const UCHAR *)"faxg3",   // FIF_FAXG3  = 27,
    (const UCHAR *)"sgi", // FIF_SGI    = 28,
    (const UCHAR *)"exr", // FIF_EXR    = 29,
    (const UCHAR *)"j2k", // FIF_J2K    = 30,
    (const UCHAR *)"jp2", // FIF_JP2    = 31,
    (const UCHAR *)"pfm", // FIF_PFM    = 32,
    (const UCHAR *)"pict",    // FIF_PICT   = 33,
    (const UCHAR *)"raw", // FIF_RAW    = 34

    null
};
