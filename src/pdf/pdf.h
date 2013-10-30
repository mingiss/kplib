/* -----------------------------
 * pdf.h
 *  common ps/pdf file definitions
 *    
 *      2013-06-28  mp  initial creation 
 *
 *     
 */


#ifndef PDF_INCLUDED
#define PDF_INCLUDED

#define PS_PT_PER_INCH 72

#define A4_INCH_PER_PAGE_WDT 8.27
#define A4_INCH_PER_PAGE_HGT 11.69

#define PS_VERT_MARGIN PS_PT_PER_INCH // 1 inch, in pt's
#define PS_HOR_MARGIN PS_PT_PER_INCH // 1 inch, in pt's

// PostScript simbolių vardų įrašai faile psc.cpp
struct PsChName
{
    uchar m_lpszName[80];
    UniChar m_iCode;
};

extern PsChName PsChNames[];

#endif // #ifndef PDF_INCLUDED
