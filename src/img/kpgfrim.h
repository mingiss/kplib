/*
 * kpgfrim.h
 *  
 *    FreeImage kp addons
 *
 *  2013-06-20  mp  Initial creation
 *   
 */   

#ifndef KPGFRIM_INCLUDED
#define KPGFRIM_INCLUDED

// -------------------------- FreeImage papildymai
extern const uchar *plpszPictExt[]; // paveikslų failų prievardžių atitinkamybė failų formatams FREE_IMAGE_FORMAT

extern void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message); 
extern void KpFreeImageInit(void);

class fipWinImageKp: public fipWinImage
{
public:
    // ištraukia pikselio spalvos reikšmę, gal būt, per paletę; nuliai visada juodi (invertuoja į FIC_MINISBLACK jeigu ką)
    void getPixelColorKp(unsigned p_iX, unsigned p_iY, RGBQUAD *p_pValue) const;
    // ištraukia pikselio šviesumo reikšmę 0-765 
    // iškviečia getPixelColorKp(), spalvas susumuoja (3 * 255 = 765)
    int getPixelGreyVal(unsigned p_iX, unsigned p_iY) const;
};

#endif // #ifndef KPGFRIM_INCLUDED
