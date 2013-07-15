/* ----------------------------------------------------
 *  psc.cpp
 *      PostScript character names
 *
 *      Do not edit, file generated automatically by psc.py (psc.bat)
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
#include "pdf.h"

PsChName PsChNames[] = {
    { ".notdef",                                0xfffd },  
    { "nbspace",                                0x00A0 },   // &nbsp;                // ----------------------- http://www.jdawiseman.com/papers/trivia/character-entities.html //
    { "nonbreakingspace",                       0x00A0 },   // &nbsp;               no-break space = non-breaking space, U+00A0 ISOnum //
    { "exclamdown",                             0x00A1 },   // &iexcl;      ¡      inverted exclamation mark, U+00A1 ISOnum //
    { "cent",                                   0x00A2 },   // &cent;       ¢      cent sign, U+00A2 ISOnum //
    { "sterling",                               0x00A3 },   // &pound;      £      pound sign, U+00A3 ISOnum //
    { "currency",                               0x00A4 },   // &curren;     ¤      currency sign, U+00A4 ISOnum //
    { "yen",                                    0x00A5 },   // &yen;        ¥      yen sign = yuan sign, U+00A5 ISOnum //
    { "brokenbar",                              0x00A6 },   // &brvbar;     ¦      broken bar = broken vertical bar, U+00A6 ISOnum //
    { "section",                                0x00A7 },   // &sect;       §      section sign, U+00A7 ISOnum //
    { "dieresis",                               0x00A8 },   // &uml;        ¨      diaeresis = spacing diaeresis, U+00A8 ISOdia //
    { "copyright",                              0x00A9 },   // &copy;       ©      copyright sign, U+00A9 ISOnum //
    { "ordfeminine",                            0x00AA },   // &ordf;       ª      feminine ordinal indicator, U+00AA ISOnum //
    { "guillemotleft",                          0x00AB },   // &laquo;      «      left-pointing double angle quotation mark = left pointing guillemet, U+00AB ISOnum //
    { "logicalnot",                             0x00AC },   // &not;        ¬      not sign, U+00AC ISOnum //
    { "sfthyphen",                              0x00AD },   // &shy;        ­       //
    { "softhyphen",                             0x00AD },   // &shy;        ­      soft hyphen = discretionary hyphen, U+00AD ISOnum //
    { "registered",                             0x00AE },   // &reg;        ®      registered sign = registered trade mark sign, U+00AE ISOnum //
    { "macron",                                 0x00AF },   // &macr;       ¯       //
    { "overscore",                              0x00AF },   // &macr;       ¯      macron = spacing macron = overline = APL overbar, U+00AF ISOdia //
    { "degree",                                 0x00B0 },   // &deg;        °      degree sign, U+00B0 ISOnum //
    { "plusminus",                              0x00B1 },   // &plusmn;     ±      plus-minus sign = plus-or-minus sign, U+00B1 ISOnum //
    { "twosuperior",                            0x00B2 },   // &sup2;       ²      superscript two = superscript digit two = squared, U+00B2 ISOnum //
    { "threesuperior",                          0x00B3 },   // &sup3;       ³      superscript three = superscript digit three = cubed, U+00B3 ISOnum //
    { "acute",                                  0x00B4 },   // &acute;      ´      acute accent = spacing acute, U+00B4 ISOdia //
    { "mu",                                     0x00B5 },   // &micro;      µ       //
    { "mu1",                                    0x00B5 },   // &micro;      µ      micro sign, U+00B5 ISOnum //
    { "paragraph",                              0x00B6 },   // &para;       ¶      pilcrow sign = paragraph sign, U+00B6 ISOnum //
    { "middot",                                 0x00B7 },   // &middot;     ·       //
    { "periodcentered",                         0x00B7 },   // &middot;     ·      middle dot = Georgian comma = Greek middle dot, U+00B7 ISOnum //
    { "cedilla",                                0x00B8 },   // &cedil;      ¸      cedilla = spacing cedilla, U+00B8 ISOdia //
    { "onesuperior",                            0x00B9 },   // &sup1;       ¹      superscript one = superscript digit one, U+00B9 ISOnum //
    { "ordmasculine",                           0x00BA },   // &ordm;       º      masculine ordinal indicator, U+00BA ISOnum //
    { "guillemotright",                         0x00BB },   // &raquo;      »      right-pointing double angle quotation mark = right pointing guillemet, U+00BB ISOnum //
    { "onequarter",                             0x00BC },   // &frac14;     ¼      vulgar fraction one quarter = fraction one quarter, U+00BC ISOnum //
    { "onehalf",                                0x00BD },   // &frac12;     ½      vulgar fraction one half = fraction one half, U+00BD ISOnum //
    { "threequarters",                          0x00BE },   // &frac34;     ¾      vulgar fraction three quarters = fraction three quarters, U+00BE ISOnum //
    { "questiondown",                           0x00BF },   // &iquest;     ¿      inverted question mark = turned question mark, U+00BF ISOnum //
    { "Agrave",                                 0x00C0 },   // &Agrave;     À      latin capital letter A with grave = latin capital letter A grave, U+00C0 ISOlat1 //
    { "Aacute",                                 0x00C1 },   // &Aacute;     Á      latin capital letter A with acute, U+00C1 ISOlat1 //
    { "Acircumflex",                            0x00C2 },   // &Acirc;      Â      latin capital letter A with circumflex, U+00C2 ISOlat1 //
    { "Atilde",                                 0x00C3 },   // &Atilde;     Ã      latin capital letter A with tilde, U+00C3 ISOlat1 //
    { "Adieresis",                              0x00C4 },   // &Auml;       Ä      latin capital letter A with diaeresis, U+00C4 ISOlat1 //
    { "Aring",                                  0x00C5 },   // &Aring;      Å      latin capital letter A with ring above = latin capital letter A ring, U+00C5 ISOlat1 //
    { "AE",                                     0x00C6 },   // &AElig;      Æ      latin capital letter AE = latin capital ligature AE, U+00C6 ISOlat1 //
    { "Ccedilla",                               0x00C7 },   // &Ccedil;     Ç      latin capital letter C with cedilla, U+00C7 ISOlat1 //
    { "Egrave",                                 0x00C8 },   // &Egrave;     È      latin capital letter E with grave, U+00C8 ISOlat1 //
    { "Eacute",                                 0x00C9 },   // &Eacute;     É      latin capital letter E with acute, U+00C9 ISOlat1 //
    { "Ecircumflex",                            0x00CA },   // &Ecirc;      Ê      latin capital letter E with circumflex, U+00CA ISOlat1 //
    { "Edieresis",                              0x00CB },   // &Euml;       Ë      latin capital letter E with diaeresis, U+00CB ISOlat1 //
    { "Igrave",                                 0x00CC },   // &Igrave;     Ì      latin capital letter I with grave, U+00CC ISOlat1 //
    { "Iacute",                                 0x00CD },   // &Iacute;     Í      latin capital letter I with acute, U+00CD ISOlat1 //
    { "Icircumflex",                            0x00CE },   // &Icirc;      Î      latin capital letter I with circumflex, U+00CE ISOlat1 //
    { "Idieresis",                              0x00CF },   // &Iuml;       Ï      latin capital letter I with diaeresis, U+00CF ISOlat1 //
    { "Eth",                                    0x00D0 },   // &ETH;        Ð      latin capital letter ETH, U+00D0 ISOlat1 //
    { "Ntilde",                                 0x00D1 },   // &Ntilde;     Ñ      latin capital letter N with tilde, U+00D1 ISOlat1 //
    { "Ograve",                                 0x00D2 },   // &Ograve;     Ò      latin capital letter O with grave, U+00D2 ISOlat1 //
    { "Oacute",                                 0x00D3 },   // &Oacute;     Ó      latin capital letter O with acute, U+00D3 ISOlat1 //
    { "Ocircumflex",                            0x00D4 },   // &Ocirc;      Ô      latin capital letter O with circumflex, U+00D4 ISOlat1 //
    { "Otilde",                                 0x00D5 },   // &Otilde;     Õ      latin capital letter O with tilde, U+00D5 ISOlat1 //
    { "Odieresis",                              0x00D6 },   // &Ouml;       Ö      latin capital letter O with diaeresis, U+00D6 ISOlat1 //
    { "multiply",                               0x00D7 },   // &times;      ×      multiplication sign, U+00D7 ISOnum //
    { "Oslash",                                 0x00D8 },   // &Oslash;     Ø      latin capital letter O with stroke = latin capital letter O slash, U+00D8 ISOlat1 //
    { "Ugrave",                                 0x00D9 },   // &Ugrave;     Ù      latin capital letter U with grave, U+00D9 ISOlat1 //
    { "Uacute",                                 0x00DA },   // &Uacute;     Ú      latin capital letter U with acute, U+00DA ISOlat1 //
    { "Ucircumflex",                            0x00DB },   // &Ucirc;      Û      latin capital letter U with circumflex, U+00DB ISOlat1 //
    { "Udieresis",                              0x00DC },   // &Uuml;       Ü      latin capital letter U with diaeresis, U+00DC ISOlat1 //
    { "Yacute",                                 0x00DD },   // &Yacute;     Ý      latin capital letter Y with acute, U+00DD ISOlat1 //
    { "Thorn",                                  0x00DE },   // &THORN;      Þ      latin capital letter THORN, U+00DE ISOlat1 //
    { "germandbls",                             0x00DF },   // &szlig;      ß      latin small letter sharp s = ess-zed, U+00DF ISOlat1 //
    { "Germandbls",                             0x00DF },   // &szlig;      ß      latin small letter sharp s = ess-zed, U+00DF ISOlat1 //
    { "agrave",                                 0x00E0 },   // &agrave;     à      latin small letter a with grave = latin small letter a grave, U+00E0 ISOlat1 //
    { "aacute",                                 0x00E1 },   // &aacute;     á      latin small letter a with acute, U+00E1 ISOlat1 //
    { "acircumflex",                            0x00E2 },   // &acirc;      â      latin small letter a with circumflex, U+00E2 ISOlat1 //
    { "atilde",                                 0x00E3 },   // &atilde;     ã      latin small letter a with tilde, U+00E3 ISOlat1 //
    { "adieresis",                              0x00E4 },   // &auml;       ä      latin small letter a with diaeresis, U+00E4 ISOlat1 //
    { "aring",                                  0x00E5 },   // &aring;      å      latin small letter a with ring above = latin small letter a ring, U+00E5 ISOlat1 //
    { "ae",                                     0x00E6 },   // &aelig;      æ      latin small letter ae = latin small ligature ae, U+00E6 ISOlat1 //
    { "ccedilla",                               0x00E7 },   // &ccedil;     ç      latin small letter c with cedilla, U+00E7 ISOlat1 //
    { "egrave",                                 0x00E8 },   // &egrave;     è      latin small letter e with grave, U+00E8 ISOlat1 //
    { "eacute",                                 0x00E9 },   // &eacute;     é      latin small letter e with acute, U+00E9 ISOlat1 //
    { "ecircumflex",                            0x00EA },   // &ecirc;      ê      latin small letter e with circumflex, U+00EA ISOlat1 //
    { "edieresis",                              0x00EB },   // &euml;       ë      latin small letter e with diaeresis, U+00EB ISOlat1 //
    { "igrave",                                 0x00EC },   // &igrave;     ì      latin small letter i with grave, U+00EC ISOlat1 //
    { "iacute",                                 0x00ED },   // &iacute;     í      latin small letter i with acute, U+00ED ISOlat1 //
    { "icircumflex",                            0x00EE },   // &icirc;      î      latin small letter i with circumflex, U+00EE ISOlat1 //
    { "idieresis",                              0x00EF },   // &iuml;       ï      latin small letter i with diaeresis, U+00EF ISOlat1 //
    { "eth",                                    0x00F0 },   // &eth;        ð      latin small letter eth, U+00F0 ISOlat1 //
    { "ntilde",                                 0x00F1 },   // &ntilde;     ñ      latin small letter n with tilde, U+00F1 ISOlat1 //
    { "ograve",                                 0x00F2 },   // &ograve;     ò      latin small letter o with grave, U+00F2 ISOlat1 //
    { "oacute",                                 0x00F3 },   // &oacute;     ó      latin small letter o with acute, U+00F3 ISOlat1 //
    { "ocircumflex",                            0x00F4 },   // &ocirc;      ô      latin small letter o with circumflex, U+00F4 ISOlat1 //
    { "otilde",                                 0x00F5 },   // &otilde;     õ      latin small letter o with tilde, U+00F5 ISOlat1 //
    { "odieresis",                              0x00F6 },   // &ouml;       ö      latin small letter o with diaeresis, U+00F6 ISOlat1 //
    { "divide",                                 0x00F7 },   // &divide;     ÷      division sign, U+00F7 ISOnum //
    { "oslash",                                 0x00F8 },   // &oslash;     ø      latin small letter o with stroke, = latin small letter o slash, U+00F8 ISOlat1 //
    { "ugrave",                                 0x00F9 },   // &ugrave;     ù      latin small letter u with grave, U+00F9 ISOlat1 //
    { "uacute",                                 0x00FA },   // &uacute;     ú      latin small letter u with acute, U+00FA ISOlat1 //
    { "ucircumflex",                            0x00FB },   // &ucirc;      û      latin small letter u with circumflex, U+00FB ISOlat1 //
    { "udieresis",                              0x00FC },   // &uuml;       ü      latin small letter u with diaeresis, U+00FC ISOlat1 //
    { "yacute",                                 0x00FD },   // &yacute;     ý      latin small letter y with acute, U+00FD ISOlat1 //
    { "thorn",                                  0x00FE },   // &thorn;      þ      latin small letter thorn, U+00FE ISOlat1 //
    { "ydieresis",                              0x00FF },   // &yuml;       ÿ      latin small letter y with diaeresis, U+00FF ISOlat1 //
    { "florin",                                 0x0192 },   // &fnof;       ƒ      latin small f with hook = function = florin, U+0192 ISOtech //
    { "Alpha",                                  0x0391 },   // &Alpha;      Α      greek capital letter alpha, U+0391 //
    { "Beta",                                   0x0392 },   // &Beta;       Β      greek capital letter beta, U+0392 //
    { "Gamma",                                  0x0393 },   // &Gamma;      Γ      greek capital letter gamma, U+0393 ISOgrk3 //
    { "Deltagreek",                             0x0394 },   // &Delta;      Δ      greek capital letter delta, U+0394 ISOgrk3 //
    { "Epsilon",                                0x0395 },   // &Epsilon;    Ε      greek capital letter epsilon, U+0395 //
    { "Zeta",                                   0x0396 },   // &Zeta;       Ζ      greek capital letter zeta, U+0396 //
    { "Eta",                                    0x0397 },   // &Eta;        Η      greek capital letter eta, U+0397 //
    { "Theta",                                  0x0398 },   // &Theta;      Θ      greek capital letter theta, U+0398 ISOgrk3 //
    { "Iota",                                   0x0399 },   // &Iota;       Ι      greek capital letter iota, U+0399 //
    { "Kappa",                                  0x039A },   // &Kappa;      Κ      greek capital letter kappa, U+039A //
    { "Lambda",                                 0x039B },   // &Lambda;     Λ      greek capital letter lambda, U+039B ISOgrk3 //
    { "Mu",                                     0x039C },   // &Mu;         Μ      greek capital letter mu, U+039C //
    { "Nu",                                     0x039D },   // &Nu;         Ν      greek capital letter nu, U+039D //
    { "Xi",                                     0x039E },   // &Xi;         Ξ      greek capital letter xi, U+039E ISOgrk3 //
    { "Omicron",                                0x039F },   // &Omicron;    Ο      greek capital letter omicron, U+039F //
    { "Pi",                                     0x03A0 },   // &Pi;         Π      greek capital letter pi, U+03A0 ISOgrk3 //
    { "Rho",                                    0x03A1 },   // &Rho;        Ρ      greek capital letter rho, U+03A1 //
    { "Sigma",                                  0x03A3 },   // &Sigma;      Σ      greek capital letter sigma, U+03A3 ISOgrk3 //
    { "Tau",                                    0x03A4 },   // &Tau;        Τ      greek capital letter tau, U+03A4 //
    { "Upsilon",                                0x03A5 },   // &Upsilon;    Υ      greek capital letter upsilon, U+03A5 ISOgrk3 //
    { "Phi",                                    0x03A6 },   // &Phi;        Φ      greek capital letter phi, U+03A6 ISOgrk3 //
    { "Chi",                                    0x03A7 },   // &Chi;        Χ      greek capital letter chi, U+03A7 //
    { "Psi",                                    0x03A8 },   // &Psi;        Ψ      greek capital letter psi, U+03A8 ISOgrk3 //
    { "Omegagreek",                             0x03A9 },   // &Omega;      Ω      greek capital letter omega, U+03A9 ISOgrk3 //
    { "alpha",                                  0x03B1 },   // &alpha;      α      greek small letter alpha, U+03B1 ISOgrk3 //
    { "beta",                                   0x03B2 },   // &beta;       β      greek small letter beta, U+03B2 ISOgrk3 //
    { "gamma",                                  0x03B3 },   // &gamma;      γ      greek small letter gamma, U+03B3 ISOgrk3 //
    { "delta",                                  0x03B4 },   // &delta;      δ      greek small letter delta, U+03B4 ISOgrk3 //
    { "epsilon",                                0x03B5 },   // &epsilon;    ε      greek small letter epsilon, U+03B5 ISOgrk3 //
    { "zeta",                                   0x03B6 },   // &zeta;       ζ      greek small letter zeta, U+03B6 ISOgrk3 //
    { "eta",                                    0x03B7 },   // &eta;        η      greek small letter eta, U+03B7 ISOgrk3 //
    { "theta",                                  0x03B8 },   // &theta;      θ      greek small letter theta, U+03B8 ISOgrk3 //
    { "iota",                                   0x03B9 },   // &iota;       ι      greek small letter iota, U+03B9 ISOgrk3 //
    { "kappa",                                  0x03BA },   // &kappa;      κ      greek small letter kappa, U+03BA ISOgrk3 //
    { "lambda",                                 0x03BB },   // &lambda;     λ      greek small letter lambda, U+03BB ISOgrk3 //
    { "mugreek",                                0x03BC },   // &mu;         μ      greek small letter mu, U+03BC ISOgrk3 //
    { "nu",                                     0x03BD },   // &nu;         ν      greek small letter nu, U+03BD ISOgrk3 //
    { "xi",                                     0x03BE },   // &xi;         ξ      greek small letter xi, U+03BE ISOgrk3 //
    { "omicron",                                0x03BF },   // &omicron;    ο      greek small letter omicron, U+03BF NEW //
    { "pi",                                     0x03C0 },   // &pi;         π      greek small letter pi, U+03C0 ISOgrk3 //
    { "rho",                                    0x03C1 },   // &rho;        ρ      greek small letter rho, U+03C1 ISOgrk3 //
    { "sigma1",                                 0x03C2 },   // &sigmaf;     ς       //
    { "sigmafinal",                             0x03C2 },   // &sigmaf;     ς      greek small letter final sigma, U+03C2 ISOgrk3 //
    { "sigma",                                  0x03C3 },   // &sigma;      σ      greek small letter sigma, U+03C3 ISOgrk3 //
    { "tau",                                    0x03C4 },   // &tau;        τ      greek small letter tau, U+03C4 ISOgrk3 //
    { "upsilon",                                0x03C5 },   // &upsilon;    υ      greek small letter upsilon, U+03C5 ISOgrk3 //
    { "phi1",                                   0x03C6 },   // &phi;        φ      // phi // greek small letter phi, U+03C6 ISOgrk3 // # texglyphlist.txt: TeX encodings such as 'texmital.enc' disagree with Unicode and the Adobe glyph list; in TeX, the "straight" form of phi takes the name "phi", whereas the more-common "loopy" form of phi, \varphi, takes the name "phi1". //
    { "chi",                                    0x03C7 },   // &chi;        χ      greek small letter chi, U+03C7 ISOgrk3 //
    { "psi",                                    0x03C8 },   // &psi;        ψ      greek small letter psi, U+03C8 ISOgrk3 //
    { "omega",                                  0x03C9 },   // &omega;      ω      greek small letter omega, U+03C9 ISOgrk3 //
    { "theta1",                                 0x03D1 },   // &thetasym;   ϑ       //
    { "thetasymbolgreek",                       0x03D1 },   // &thetasym;   ϑ      greek small letter theta symbol, U+03D1 NEW //
    { "Upsilon1",                               0x03D2 },   // &upsih;      ϒ       //
    { "Upsilonhooksymbol",                      0x03D2 },   // &upsih;      ϒ      greek upsilon with hook symbol, U+03D2 NEW //
    { "omega1",                                 0x03D6 },   // &piv;        ϖ       //
    { "pisymbolgreek",                          0x03D6 },   // &piv;        ϖ      greek pi symbol, U+03D6 ISOgrk3 //
    { "bullet",                                 0x2022 },   // &bull;       •     bullet = black small circle, U+2022 ISOpub [bullet is NOT the same as bullet operator, U+2219] //
    { "ellipsis",                               0x2026 },   // &hellip;     …     horizontal ellipsis = three dot leader, U+2026 ISOpub //
    { "minute",                                 0x2032 },   // &prime;      ′     prime = minutes = feet, U+2032 ISOtech //
    { "prime",                                  0x2032 },   // &prime;      ′     prime = minutes = feet, U+2032 ISOtech //
    { "second",                                 0x2033 },   // &Prime;      ″     double prime = seconds = inches, U+2033 ISOtech //
    { "overline",                               0x203E },   // &oline;      ‾     overline = spacing overscore, U+203E NEW //
    { "fraction",                               0x2044 },   // &frasl;      ⁄     fraction slash, U+2044 NEW //
    { "weierstrass",                            0x2118 },   // &weierp;     ℘     script capital P = power set = Weierstrass p, U+2118 ISOamso //
    { "Ifraktur",                               0x2111 },   // &image;      ℑ     blackletter capital I = imaginary part, U+2111 ISOamso //
    { "Rfraktur",                               0x211C },   // &real;       ℜ     blackletter capital R = real part symbol, U+211C ISOamso //
    { "trademark",                              0x2122 },   // &trade;      ™     trade mark sign, U+2122 ISOnum //
    { "aleph",                                  0x2135 },   // &alefsym;    ℵ     alef symbol = first transfinite cardinal, U+2135 NEW [alef symbol is NOT the same as hebrew letter alef, U+05D0 although the same glyph could be used to depict both characters] //
    { "arrowleft",                              0x2190 },   // &larr;       ←     leftwards arrow, U+2190 ISOnum //
    { "arrowup",                                0x2191 },   // &uarr;       ↑     upwards arrow, U+2191 ISOnum //
    { "arrowright",                             0x2192 },   // &rarr;       →     rightwards arrow, U+2192 ISOnum //
    { "arrowdown",                              0x2193 },   // &darr;       ↓     downwards arrow, U+2193 ISOnum //
    { "arrowboth",                              0x2194 },   // &harr;       ↔     left right arrow, U+2194 ISOamsa //
    { "carriagereturn",                         0x21B5 },   // &crarr;      ↵     downwards arrow with corner leftwards = carriage return, U+21B5 NEW //
    { "arrowdblleft",                           0x21D0 },   // &lArr;       ⇐      //
    { "arrowleftdbl",                           0x21D0 },   // &lArr;       ⇐     leftwards double arrow, U+21D0 ISOtech [ISO 10646 does not say that lArr is the same as the 'is implied by' arrow but also does not have any other character for that function. So ? lArr can be used for 'is implied by' as ISOtech suggests] //
    { "arrowdblup",                             0x21D1 },   // &uArr;       ⇑     upwards double arrow, U+21D1 ISOamsa //
    { "arrowdblright",                          0x21D2 },   // &rArr;       ⇒      //
    { "dblarrowright",                          0x21D2 },   // &rArr;       ⇒     rightwards double arrow, U+21D2 ISOtech [ISO 10646 does not say this is the 'implies' character but does not have another character with this function so ? rArr can be used for 'implies' as ISOtech suggests] //
    { "arrowdbldown",                           0x21D3 },   // &dArr;       ⇓     downwards double arrow, U+21D3 ISOamsa //
    { "arrowdblboth",                           0x21D4 },   // &hArr;       ⇔      //
    { "dblarrowleft",                           0x21D4 },   // &hArr;       ⇔     left right double arrow, U+21D4 ISOamsa <!-- Mathematical Operators //
    { "forall",                                 0x2200 },   // &forall;     ∀      //
    { "universal",                              0x2200 },   // &forall;     ∀     for all, U+2200 ISOtech //
    { "partialdiff",                            0x2202 },   // &part;       ∂     partial differential, U+2202 ISOtech //
    { "existential",                            0x2203 },   // &exist;      ∃      //
    { "thereexists",                            0x2203 },   // &exist;      ∃     there exists, U+2203 ISOtech //
    { "emptyset",                               0x2205 },   // &empty;      ∅     empty set = null set = diameter, U+2205 ISOamso //
    { "gradient",                               0x2207 },   // &nabla;      ∇      //
    { "nabla",                                  0x2207 },   // &nabla;      ∇     nabla = backward difference, U+2207 ISOtech //
    { "element",                                0x2208 },   // &isin;       ∈     element of, U+2208 ISOtech //
    { "notelement",                             0x2209 },   // &notin;      ∉      //
    { "notelementof",                           0x2209 },   // &notin;      ∉     not an element of, U+2209 ISOtech //
    { "suchthat",                               0x220B },   // &ni;         ∋     contains as member, U+220B ISOtech [should there be a more memorable name than 'ni'?] //
    { "product",                                0x220F },   // &prod;       ∏     n-ary product = product sign, U+220F ISOamsb [prod is NOT the same character as U+03A0 'greek capital letter pi' though the same glyph might be used for both] //
    { "summation",                              0x2211 },   // &sum;        ∑     n-ary sumation, U+2211 ISOamsb [sum is NOT the same character as U+03A3 'greek capital letter sigma' though the same glyph might be used for both] //
    { "minus",                                  0x2212 },   // &minus;      −     minus sign, U+2212 ISOtech //
    { "asteriskmath",                           0x2217 },   // &lowast;     ∗     asterisk operator, U+2217 ISOtech //
    { "radical",                                0x221A },   // &radic;      √     square root = radical sign, U+221A ISOtech //
    { "proportional",                           0x221D },   // &prop;       ∝     proportional to, U+221D ISOtech //
    { "infinity",                               0x221E },   // &infin;      ∞     infinity, U+221E ISOtech //
    { "angle",                                  0x2220 },   // &ang;        ∠     angle, U+2220 ISOamso //
    { "logicaland",                             0x2227 },   // &and;        ∧     logical and = wedge, U+2227 ISOtech //
    { "logicalor",                              0x2228 },   // &or;         ∨     logical or = vee, U+2228 ISOtech //
    { "intersection",                           0x2229 },   // &cap;        ∩     intersection = cap, U+2229 ISOtech //
    { "union",                                  0x222A },   // &cup;        ∪     union = cup, U+222A ISOtech //
    { "integral",                               0x222B },   // &int;        ∫     integral, U+222B ISOtech //
    { "therefore",                              0x2234 },   // &there4;     ∴     therefore, U+2234 ISOtech //
    { "similar",                                0x223C },   // &sim;        ∼      //
    { "tildeoperator",                          0x223C },   // &sim;        ∼     tilde operator = varies with = similar to, U+223C ISOtech [tilde operator is NOT the same character as the tilde, U+007E, although the same glyph might be used to represent both] //
    { "approximatelyequal",                     0x2245 },   // &cong;       ≅      //
    { "congruent",                              0x2245 },   // &cong;       ≅     approximately equal to, U+2245 ISOtech //
    { "approxequal",                            0x2248 },   // &asymp;      ≈     almost equal to = asymptotic to, U+2248 ISOamsr //
    { "notequal",                               0x2260 },   // &ne;         ≠     not equal to, U+2260 ISOtech //
    { "equivalence",                            0x2261 },   // &equiv;      ≡     identical to, U+2261 ISOtech //
    { "lessequal",                              0x2264 },   // &le;         ≤     less-than or equal to, U+2264 ISOtech //
    { "greaterequal",                           0x2265 },   // &ge;         ≥     greater-than or equal to, U+2265 ISOtech //
    { "propersubset",                           0x2282 },   // &sub;        ⊂      //
    { "subset",                                 0x2282 },   // &sub;        ⊂     subset of, U+2282 ISOtech //
    { "propersuperset",                         0x2283 },   // &sup;        ⊃      //
    { "superset",                               0x2283 },   // &sup;        ⊃     superset of, U+2283 ISOtech [note that nsup, 'not a superset of, U+2283' is not covered by the Symbol font encoding and is not included. Should it be, for symmetry? It is in ISOamsn] //
    { "notsubset",                              0x2284 },   // &nsub;       ⊄     not a subset of, U+2284 ISOamsn //
    { "reflexsubset",                           0x2286 },   // &sube;       ⊆      //
    { "subsetorequal",                          0x2286 },   // &sube;       ⊆     subset of or equal to, U+2286 ISOtech //
    { "reflexsuperset",                         0x2287 },   // &supe;       ⊇      //
    { "supersetorequal",                        0x2287 },   // &supe;       ⊇     superset of or equal to, U+2287 ISOtech //
    { "circleplus",                             0x2295 },   // &oplus;      ⊕      //
    { "pluscircle",                             0x2295 },   // &oplus;      ⊕     circled plus = direct sum, U+2295 ISOamsb //
    { "circlemultiply",                         0x2297 },   // &otimes;     ⊗      //
    { "timescircle",                            0x2297 },   // &otimes;     ⊗     circled times = vector product, U+2297 ISOamsb //
    { "perpendicular",                          0x22A5 },   // &perp;       ⊥     up tack = orthogonal to = perpendicular, U+22A5 ISOtech //
    { "dotmath",                                0x22C5 },   // &sdot;       ⋅     dot operator, U+22C5 ISOamsb [dot operator is NOT the same character as U+00B7 middle dot] //
    { " ",                                      0x2308 },   // &lceil;      ⌈     left ceiling = apl upstile, U+2308 ISOamsc //
    { " ",                                      0x2309 },   // &rceil;      ⌉     right ceiling, U+2309 ISOamsc //
    { " ",                                      0x230A },   // &lfloor;     ⌊     left floor = apl downstile, U+230A ISOamsc //
    { " ",                                      0x230B },   // &rfloor;     ⌋     right floor, U+230B ISOamsc //
    { "angleleft",                              0x2329 },   // &lang;       〈     left-pointing angle bracket = bra, U+2329 ISOtech [lang is NOT the same character as U+003C 'less than' or U+2039 'single left-pointing angle quotation mark'] //
    { "angleright",                             0x232A },   // &rang;       〉     right-pointing angle bracket = ket, U+232A ISOtech [rang is NOT the same character as U+003E 'greater than' or U+203A 'single right-pointing angle quotation mark'] //
    { "lozenge",                                0x25CA },   // &loz;        ◊     lozenge, U+25CA ISOpub <!-- Miscellaneous Symbols //
    { "spade",                                  0x2660 },   // &spades;     ♠      //
    { "spadesuitblack",                         0x2660 },   // &spades;     ♠     black spade suit, U+2660 ISOpub [black here seems to mean filled as opposed to hollow] //
    { "club",                                   0x2663 },   // &clubs;      ♣      //
    { "clubsuitblack",                          0x2663 },   // &clubs;      ♣     black club suit = shamrock, U+2663 ISOpub [black here seems to mean filled as opposed to hollow] //
    { "heart",                                  0x2665 },   // &hearts;     ♥      //
    { "heartsuitblack",                         0x2665 },   // &hearts;     ♥     black heart suit = valentine, U+2665 ISOpub [black here seems to mean filled as opposed to hollow] //
    { "diamond",                                0x2666 },   // &diams;      ♦     black diamond suit, U+2666 ISOpub [black here seems to mean filled as opposed to hollow] //
    { "quotedbl",                               0x0022 },   // &quot;       "       quotation mark = APL quote, U+0022 ISOnum //
    { "ampersand",                              0x0026 },   // &amp;        &       ampersand, U+0026 ISOnum //
    { "less",                                   0x003C },   // &lt;         <       less-than sign, U+003C ISOnum //
    { "greater",                                0x003E },   // &gt;         >       greater-than sign, U+003E ISOnum //
    { "OE",                                     0x0152 },   // &OElig;      Œ      latin capital ligature OE, U+0152 ISOlat2 //
    { "oe",                                     0x0153 },   // &oelig;      œ      latin small ligature oe, U+0153 ISOlat2 [ligature is a misnomer, this is a separate character in some languages] //
    { "Scaron",                                 0x0160 },   // &Scaron;     Š      latin capital letter S with caron, U+0160 ISOlat2 //
    { "scaron",                                 0x0161 },   // &scaron;     š      latin small letter s with caron, U+0161 ISOlat2 //
    { "Ydieresis",                              0x0178 },   // &Yuml;       Ÿ      latin capital letter Y with diaeresis, U+0178 ISOlat2 //
    { "circumflex",                             0x02C6 },   // &circ;       ˆ      modifier letter circumflex accent, U+02C6 ISOpub //
    { "ilde",                                   0x02DC },   // &tilde;      ˜       //
    { "tilde",                                  0x02DC },   // &tilde;      ˜      small tilde, U+02DC ISOdia //
    { "enspace",                                0x2002 },   // &ensp;             en space, U+2002 ISOpub //
    { " ",                                      0x2003 },   // &emsp;             em space, U+2003 ISOpub //
    { " ",                                      0x2009 },   // &thinsp;           thin space, U+2009 ISOpub //
    { "afii61664",                              0x200C },   // &zwnj;       ‌      //
    { "zerowidthnonjoiner",                     0x200C },   // &zwnj;       ‌     zero width non-joiner, U+200C NEW RFC 2070 //
    { "afii301",                                0x200D },   // &zwj;        ‍     zero width joiner, U+200D NEW RFC 2070 //
    { "afii299",                                0x200E },   // &lrm;        ‎     left-to-right mark, U+200E NEW RFC 2070 //
    { "afii300",                                0x200F },   // &rlm;        ‏     right-to-left mark, U+200F NEW RFC 2070 //
    { "endash",                                 0x2013 },   // &ndash;      –     en dash, U+2013 ISOpub //
    { "emdash",                                 0x2014 },   // &mdash;      —     em dash, U+2014 ISOpub //
    { "quoteleft",                              0x2018 },   // &lsquo;      ‘     left single quotation mark, U+2018 ISOnum //
    { "quoteright",                             0x2019 },   // &rsquo;      ’     right single quotation mark, U+2019 ISOnum //
    { "quotesinglbase",                         0x201A },   // &sbquo;      ‚     single low-9 quotation mark, U+201A NEW //
    { "quotedblleft",                           0x201C },   // &ldquo;      “     left double quotation mark, U+201C ISOnum //
    { "quotedblright",                          0x201D },   // &rdquo;      ”     right double quotation mark, U+201D ISOnum //
    { "quotedblbase",                           0x201E },   // &bdquo;      „     double low-9 quotation mark, U+201E NEW //
    { "dagger",                                 0x2020 },   // &dagger;     †     dagger, U+2020 ISOpub //
    { "daggerdbl",                              0x2021 },   // &Dagger;     ‡     double dagger, U+2021 ISOpub //
    { "perthousand",                            0x2030 },   // &permil;     ‰     per mille sign, U+2030 ISOtech //
    { "guilsinglleft",                          0x2039 },   // &lsaquo;     ‹     single left-pointing angle quotation mark, U+2039 ISO proposed [lsaquo is proposed but not yet ISO standardized] //
    { "guilsinglright",                         0x203A },   // &rsaquo;     ›     single right-pointing angle quotation mark, U+203A ISO proposed [rsaquo is proposed but not yet ISO standardized] //
    { "Euro",                                   0x20AC },   // &euro;       €     euro sign, U+20AC NEW //
    { "controlSTX",                             0x0001 },   //                      //
    { "controlSOT",                             0x0002 },   //                      //
    { "controlETX",                             0x0003 },   //                      //
    { "controlEOT",                             0x0004 },   //                      //
    { "controlENQ",                             0x0005 },   //                      //
    { "controlACK",                             0x0006 },   //                      //
    { "controlBEL",                             0x0007 },   //                      //
    { "controlBS",                              0x0008 },   //                      //
    { "controlHT",                              0x0009 },   //                       //
    { "controlLF",                              0x000A },   //                       //
    { "controlVT",                              0x000B },   //                      //
    { "controlFF",                              0x000C },   //                      //
    { "controlCR",                              0x000D },   //                       //
    { "controlSO",                              0x000E },   //                      //
    { "controlSI",                              0x000F },   //                      //
    { "controlDLE",                             0x0010 },   //                      //
    { "controlDC1",                             0x0011 },   //                      //
    { "controlDC2",                             0x0012 },   //                      //
    { "controlDC3",                             0x0013 },   //                      //
    { "controlDC4",                             0x0014 },   //                      //
    { "controlNAK",                             0x0015 },   //                      //
    { "controlSYN",                             0x0016 },   //                      //
    { "controlETB",                             0x0017 },   //                      //
    { "controlCAN",                             0x0018 },   //                      //
    { "controlEM",                              0x0019 },   //                      //
    { "controlSUB",                             0x001A },   //              ->       //
    { "controlESC",                             0x001B },   //                      //
    { "controlFS",                              0x001C },   //                      //
    { "controlGS",                              0x001D },   //                      //
    { "controlRS",                              0x001E },   //                      //
    { "controlUS",                              0x001F },   //                      //
    { "space",                                  0x0020 },   //                       //
    { "spacehackarabic",                        0x0020 },   //                       //
    { "exclam",                                 0x0021 },   //              !        //
    { "numbersign",                             0x0023 },   //              #        //
    { "dollar",                                 0x0024 },   //              $        //
    { "percent",                                0x0025 },   //              %        //
    { "quotesingle",                            0x0027 },   //              '        //
    { "parenleft",                              0x0028 },   //              (        //
    { "parenright",                             0x0029 },   //              )        //
    { "asterisk",                               0x002A },   //              *        //
    { "plus",                                   0x002B },   //              +        //
    { "comma",                                  0x002C },   //              ,        //
    { "hyphen",                                 0x002D },   //              -        //
    { "period",                                 0x002E },   //              .        //
    { "slash",                                  0x002F },   //              /        //
    { "zero",                                   0x0030 },   //              0        //
    { "one",                                    0x0031 },   //              1        //
    { "two",                                    0x0032 },   //              2        //
    { "three",                                  0x0033 },   //              3        //
    { "four",                                   0x0034 },   //              4        //
    { "five",                                   0x0035 },   //              5        //
    { "six",                                    0x0036 },   //              6        //
    { "seven",                                  0x0037 },   //              7        //
    { "eight",                                  0x0038 },   //              8        //
    { "nine",                                   0x0039 },   //              9        //
    { "colon",                                  0x003A },   //              :        //
    { "semicolon",                              0x003B },   //              ;        //
    { "equal",                                  0x003D },   //              =        //
    { "question",                               0x003F },   //              ?        //
    { "at",                                     0x0040 },   //              @        //
    { "A",                                      0x0041 },   //              A        //
    { "B",                                      0x0042 },   //              B        //
    { "C",                                      0x0043 },   //              C        //
    { "D",                                      0x0044 },   //              D        //
    { "E",                                      0x0045 },   //              E        //
    { "F",                                      0x0046 },   //              F        //
    { "G",                                      0x0047 },   //              G        //
    { "H",                                      0x0048 },   //              H        //
    { "I",                                      0x0049 },   //              I        //
    { "J",                                      0x004A },   //              J        //
    { "K",                                      0x004B },   //              K        //
    { "L",                                      0x004C },   //              L        //
    { "M",                                      0x004D },   //              M        //
    { "N",                                      0x004E },   //              N        //
    { "O",                                      0x004F },   //              O        //
    { "P",                                      0x0050 },   //              P        //
    { "Q",                                      0x0051 },   //              Q        //
    { "R",                                      0x0052 },   //              R        //
    { "S",                                      0x0053 },   //              S        //
    { "T",                                      0x0054 },   //              T        //
    { "U",                                      0x0055 },   //              U        //
    { "V",                                      0x0056 },   //              V        //
    { "W",                                      0x0057 },   //              W        //
    { "X",                                      0x0058 },   //              X        //
    { "Y",                                      0x0059 },   //              Y        //
    { "Z",                                      0x005A },   //              Z        //
    { "bracketleft",                            0x005B },   //              [        //
    { "backslash",                              0x005C },   //              \        //
    { "bracketright",                           0x005D },   //              ]        //
    { "asciicircum",                            0x005E },   //              ^        //
    { "underscore",                             0x005F },   //              _        //
    { "grave",                                  0x0060 },   //              `        //
    { "a",                                      0x0061 },   //              a        //
    { "b",                                      0x0062 },   //              b        //
    { "c",                                      0x0063 },   //              c        //
    { "d",                                      0x0064 },   //              d        //
    { "e",                                      0x0065 },   //              e        //
    { "f",                                      0x0066 },   //              f        //
    { "g",                                      0x0067 },   //              g        //
    { "h",                                      0x0068 },   //              h        //
    { "i",                                      0x0069 },   //              i        //
    { "j",                                      0x006A },   //              j        //
    { "k",                                      0x006B },   //              k        //
    { "l",                                      0x006C },   //              l        //
    { "m",                                      0x006D },   //              m        //
    { "n",                                      0x006E },   //              n        //
    { "o",                                      0x006F },   //              o        //
    { "p",                                      0x0070 },   //              p        //
    { "q",                                      0x0071 },   //              q        //
    { "r",                                      0x0072 },   //              r        //
    { "s",                                      0x0073 },   //              s        //
    { "t",                                      0x0074 },   //              t        //
    { "u",                                      0x0075 },   //              u        //
    { "v",                                      0x0076 },   //              v        //
    { "w",                                      0x0077 },   //              w        //
    { "x",                                      0x0078 },   //              x        //
    { "y",                                      0x0079 },   //              y        //
    { "z",                                      0x007A },   //              z        //
    { "braceleft",                              0x007B },   //              {        //
    { "bar",                                    0x007C },   //              |        //
    { "verticalbar",                            0x007C },   //              |        //
    { "braceright",                             0x007D },   //              }        //
    { "asciitilde",                             0x007E },   //              ~        //
    { "controlDEL",                             0x007F },   //                      //
    { "Amacron",                                0x0100 },   //              Ā       //
    { "amacron",                                0x0101 },   //              ā       //
    { "Abreve",                                 0x0102 },   //              Ă       //
    { "abreve",                                 0x0103 },   //              ă       //
    { "Aogonek",                                0x0104 },   //              Ą       //
    { "aogonek",                                0x0105 },   //              ą       //
    { "Cacute",                                 0x0106 },   //              Ć       //
    { "cacute",                                 0x0107 },   //              ć       //
    { "Ccircumflex",                            0x0108 },   //              Ĉ       //
    { "ccircumflex",                            0x0109 },   //              ĉ       //
    { "Cdot",                                   0x010A },   //              Ċ       //
    { "Cdotaccent",                             0x010A },   //              Ċ       //
    { "cdot",                                   0x010B },   //              ċ       //
    { "cdotaccent",                             0x010B },   //              ċ       //
    { "Ccaron",                                 0x010C },   //              Č       //
    { "ccaron",                                 0x010D },   //              č       //
    { "Dcaron",                                 0x010E },   //              Ď       //
    { "dcaron",                                 0x010F },   //              ď       //
    { "Dcroat",                                 0x0110 },   //              Đ       //
    { "Dslash",                                 0x0110 },   //              Đ       //
    { "dcroat",                                 0x0111 },   //              đ       //
    { "dmacron",                                0x0111 },   //              đ       //
    { "Emacron",                                0x0112 },   //              Ē       //
    { "emacron",                                0x0113 },   //              ē       //
    { "Ebreve",                                 0x0114 },   //              Ĕ       //
    { "ebreve",                                 0x0115 },   //              ĕ       //
    { "Edot",                                   0x0116 },   //              Ė       //
    { "Edotaccent",                             0x0116 },   //              Ė       //
    { "edot",                                   0x0117 },   //              ė       //
    { "edotaccent",                             0x0117 },   //              ė       //
    { "Eogonek",                                0x0118 },   //              Ę       //
    { "eogonek",                                0x0119 },   //              ę       //
    { "Ecaron",                                 0x011A },   //              Ě       //
    { "ecaron",                                 0x011B },   //              ě       //
    { "Gcircumflex",                            0x011C },   //              Ĝ       //
    { "gcircumflex",                            0x011D },   //              ĝ       //
    { "Gbreve",                                 0x011E },   //              Ğ       //
    { "gbreve",                                 0x011F },   //              ğ       //
    { "Gdot",                                   0x0120 },   //              Ġ       //
    { "Gdotaccent",                             0x0120 },   //              Ġ       //
    { "gdot",                                   0x0121 },   //              ġ       //
    { "gdotaccent",                             0x0121 },   //              ġ       //
    { "Gcedilla",                               0x0122 },   //              Ģ       //
    { "Gcommaaccent",                           0x0122 },   //              Ģ       //
    { "gcedilla",                               0x0123 },   //              ģ       //
    { "gcommaaccent",                           0x0123 },   //              ģ       //
    { "Hcircumflex",                            0x0124 },   //              Ĥ       //
    { "hcircumflex",                            0x0125 },   //              ĥ       //
    { "Hbar",                                   0x0126 },   //              Ħ       //
    { "hbar",                                   0x0127 },   //              ħ       //
    { "Itilde",                                 0x0128 },   //              Ĩ       //
    { "itilde",                                 0x0129 },   //              ĩ       //
    { "Imacron",                                0x012A },   //              Ī       //
    { "imacron",                                0x012B },   //              ī       //
    { "Ibreve",                                 0x012C },   //              Ĭ       //
    { "ibreve",                                 0x012D },   //              ĭ       //
    { "Iogonek",                                0x012E },   //              Į       //
    { "iogonek",                                0x012F },   //              į       //
    { "Idot",                                   0x0130 },   //              İ       //
    { "Idotaccent",                             0x0130 },   //              İ       //
    { "dotlessi",                               0x0131 },   //              ı       //
    { "IJ",                                     0x0132 },   //              Ĳ       //
    { "ij",                                     0x0133 },   //              ĳ       //
    { "Jcircumflex",                            0x0134 },   //              Ĵ       //
    { "jcircumflex",                            0x0135 },   //              ĵ       //
    { "Kcedilla",                               0x0136 },   //              Ķ       //
    { "Kcommaaccent",                           0x0136 },   //              Ķ       //
    { "kcedilla",                               0x0137 },   //              ķ       //
    { "kcommaaccent",                           0x0137 },   //              ķ       //
    { "kgreenlandic",                           0x0138 },   //              ĸ       //
    { "Lacute",                                 0x0139 },   //              Ĺ       //
    { "lacute",                                 0x013A },   //              ĺ       //
    { "Lcedilla",                               0x013B },   //              Ļ       //
    { "Lcommaaccent",                           0x013B },   //              Ļ       //
    { "lcedilla",                               0x013C },   //              ļ       //
    { "lcommaaccent",                           0x013C },   //              ļ       //
    { "Lcaron",                                 0x013D },   //              Ľ       //
    { "lcaron",                                 0x013E },   //              ľ       //
    { "Ldot",                                   0x013F },   //              Ŀ       //
    { "Ldotaccent",                             0x013F },   //              Ŀ       //
    { "ldot",                                   0x0140 },   //              ŀ       //
    { "ldotaccent",                             0x0140 },   //              ŀ       //
    { "Lslash",                                 0x0141 },   //              Ł       //
    { "lslash",                                 0x0142 },   //              ł       //
    { "Nacute",                                 0x0143 },   //              Ń       //
    { "nacute",                                 0x0144 },   //              ń       //
    { "Ncedilla",                               0x0145 },   //              Ņ       //
    { "Ncommaaccent",                           0x0145 },   //              Ņ       //
    { "ncedilla",                               0x0146 },   //              ņ       //
    { "ncommaaccent",                           0x0146 },   //              ņ       //
    { "Ncaron",                                 0x0147 },   //              Ň       //
    { "ncaron",                                 0x0148 },   //              ň       //
    { "napostrophe",                            0x0149 },   //              ŉ       //
    { "quoterightn",                            0x0149 },   //              ŉ       //
    { "Eng",                                    0x014A },   //              Ŋ       //
    { "eng",                                    0x014B },   //              ŋ       //
    { "Omacron",                                0x014C },   //              Ō       //
    { "omacron",                                0x014D },   //              ō       //
    { "Obreve",                                 0x014E },   //              Ŏ       //
    { "obreve",                                 0x014F },   //              ŏ       //
    { "Odblacute",                              0x0150 },   //              Ő       //
    { "Ohungarumlaut",                          0x0150 },   //              Ő       //
    { "odblacute",                              0x0151 },   //              ő       //
    { "ohungarumlaut",                          0x0151 },   //              ő       //
    { "Racute",                                 0x0154 },   //              Ŕ       //
    { "racute",                                 0x0155 },   //              ŕ       //
    { "Rcedilla",                               0x0156 },   //              Ŗ       //
    { "Rcommaaccent",                           0x0156 },   //              Ŗ       //
    { "rcedilla",                               0x0157 },   //              ŗ       //
    { "rcommaaccent",                           0x0157 },   //              ŗ       //
    { "Rcaron",                                 0x0158 },   //              Ř       //
    { "rcaron",                                 0x0159 },   //              ř       //
    { "Sacute",                                 0x015A },   //              Ś       //
    { "sacute",                                 0x015B },   //              ś       //
    { "Scircumflex",                            0x015C },   //              Ŝ       //
    { "scircumflex",                            0x015D },   //              ŝ       //
    { "Scedilla",                               0x015E },   //              Ş       //
    { "scedilla",                               0x015F },   //              ş       //
    { "Tcedilla",                               0x0162 },   //              Ţ       //
    { "Tcommaaccent",                           0x0162 },   //              Ţ       //
    { "tcedilla",                               0x0163 },   //              ţ       //
    { "tcommaaccent",                           0x0163 },   //              ţ       //
    { "Tcaron",                                 0x0164 },   //              Ť       //
    { "tcaron",                                 0x0165 },   //              ť       //
    { "Tbar",                                   0x0166 },   //              Ŧ       //
    { "tbar",                                   0x0167 },   //              ŧ       //
    { "Utilde",                                 0x0168 },   //              Ũ       //
    { "utilde",                                 0x0169 },   //              ũ       //
    { "Umacron",                                0x016A },   //              Ū       //
    { "umacron",                                0x016B },   //              ū       //
    { "Ubreve",                                 0x016C },   //              Ŭ       //
    { "ubreve",                                 0x016D },   //              ŭ       //
    { "Uring",                                  0x016E },   //              Ů       //
    { "uring",                                  0x016F },   //              ů       //
    { "Udblacute",                              0x0170 },   //              Ű       //
    { "Uhungarumlaut",                          0x0170 },   //              Ű       //
    { "udblacute",                              0x0171 },   //              ű       //
    { "uhungarumlaut",                          0x0171 },   //              ű       //
    { "Uogonek",                                0x0172 },   //              Ų       //
    { "uogonek",                                0x0173 },   //              ų       //
    { "Wcircumflex",                            0x0174 },   //              Ŵ       //
    { "wcircumflex",                            0x0175 },   //              ŵ       //
    { "Ycircumflex",                            0x0176 },   //              Ŷ       //
    { "ycircumflex",                            0x0177 },   //              ŷ       //
    { "Zacute",                                 0x0179 },   //              Ź       //
    { "zacute",                                 0x017A },   //              ź       //
    { "Zdot",                                   0x017B },   //              Ż       //
    { "Zdotaccent",                             0x017B },   //              Ż       //
    { "zdot",                                   0x017C },   //              ż       //
    { "zdotaccent",                             0x017C },   //              ż       //
    { "Zcaron",                                 0x017D },   //              Ž       //
    { "zcaron",                                 0x017E },   //              ž       //
    { "longs",                                  0x017F },   //              ſ       //
    { "slong",                                  0x017F },   //              ſ       //
    { "bstroke",                                0x0180 },   //              ƀ       //
    { "Bhook",                                  0x0181 },   //              Ɓ       //
    { "Btopbar",                                0x0182 },   //              Ƃ       //
    { "btopbar",                                0x0183 },   //              ƃ       //
    { "Tonesix",                                0x0184 },   //              Ƅ       //
    { "tonesix",                                0x0185 },   //              ƅ       //
    { "Oopen",                                  0x0186 },   //              Ɔ       //
    { "Chook",                                  0x0187 },   //              Ƈ       //
    { "chook",                                  0x0188 },   //              ƈ       //
    { "Dafrican",                               0x0189 },   //              Ɖ       //
    { "Dhook",                                  0x018A },   //              Ɗ       //
    { "Dtopbar",                                0x018B },   //              Ƌ       //
    { "dtopbar",                                0x018C },   //              ƌ       //
    { "deltaturned",                            0x018D },   //              ƍ       //
    { "Ereversed",                              0x018E },   //              Ǝ       //
    { "Schwa",                                  0x018F },   //              Ə       //
    { "Eopen",                                  0x0190 },   //              Ɛ       //
    { "Fhook",                                  0x0191 },   //              Ƒ       //
    { "Ghook",                                  0x0193 },   //              Ɠ       //
    { "Gammaafrican",                           0x0194 },   //              Ɣ       //
    { "hv",                                     0x0195 },   //              ƕ       //
    { "Iotaafrican",                            0x0196 },   //              Ɩ       //
    { "Istroke",                                0x0197 },   //              Ɨ       //
    { "Khook",                                  0x0198 },   //              Ƙ       //
    { "khook",                                  0x0199 },   //              ƙ       //
    { "lbar",                                   0x019A },   //              ƚ       //
    { "lambdastroke",                           0x019B },   //              ƛ       //
    { "Mturned",                                0x019C },   //              Ɯ       //
    { "Nhookleft",                              0x019D },   //              Ɲ       //
    { "nlegrightlong",                          0x019E },   //              ƞ       //
    { "Ocenteredtilde",                         0x019F },   //              Ɵ       //
    { "Ohorn",                                  0x01A0 },   //              Ơ       //
    { "ohorn",                                  0x01A1 },   //              ơ       //
    { "Oi",                                     0x01A2 },   //              Ƣ       //
    { "oi",                                     0x01A3 },   //              ƣ       //
    { "Phook",                                  0x01A4 },   //              Ƥ       //
    { "phook",                                  0x01A5 },   //              ƥ       //
    { "yr",                                     0x01A6 },   //              Ʀ       //
    { "Tonetwo",                                0x01A7 },   //              Ƨ       //
    { "tonetwo",                                0x01A8 },   //              ƨ       //
    { "Esh",                                    0x01A9 },   //              Ʃ       //
    { "eshreversedloop",                        0x01AA },   //              ƪ       //
    { "tpalatalhook",                           0x01AB },   //              ƫ       //
    { "Thook",                                  0x01AC },   //              Ƭ       //
    { "thook",                                  0x01AD },   //              ƭ       //
    { "Tretroflexhook",                         0x01AE },   //              Ʈ       //
    { "Uhorn",                                  0x01AF },   //              Ư       //
    { "uhorn",                                  0x01B0 },   //              ư       //
    { "Upsilonafrican",                         0x01B1 },   //              Ʊ       //
    { "Vhook",                                  0x01B2 },   //              Ʋ       //
    { "Yhook",                                  0x01B3 },   //              Ƴ       //
    { "yhook",                                  0x01B4 },   //              ƴ       //
    { "Zstroke",                                0x01B5 },   //              Ƶ       //
    { "zstroke",                                0x01B6 },   //              ƶ       //
    { "Ezh",                                    0x01B7 },   //              Ʒ       //
    { "Ezhreversed",                            0x01B8 },   //              Ƹ       //
    { "ezhreversed",                            0x01B9 },   //              ƹ       //
    { "ezhtail",                                0x01BA },   //              ƺ       //
    { "twostroke",                              0x01BB },   //              ƻ       //
    { "Tonefive",                               0x01BC },   //              Ƽ       //
    { "tonefive",                               0x01BD },   //              ƽ       //
    { "glottalinvertedstroke",                  0x01BE },   //              ƾ       //
    { "wynn",                                   0x01BF },   //              ƿ       //
    { "clickdental",                            0x01C0 },   //              ǀ       //
    { "clicklateral",                           0x01C1 },   //              ǁ       //
    { "clickalveolar",                          0x01C2 },   //              ǂ       //
    { "clickretroflex",                         0x01C3 },   //              ǃ       //
    { "DZcaron",                                0x01C4 },   //              Ǆ       //
    { "Dzcaron",                                0x01C5 },   //              ǅ       //
    { "dzcaron",                                0x01C6 },   //              ǆ       //
    { "LJ",                                     0x01C7 },   //              Ǉ       //
    { "Lj",                                     0x01C8 },   //              ǈ       //
    { "lj",                                     0x01C9 },   //              ǉ       //
    { "NJ",                                     0x01CA },   //              Ǌ       //
    { "Nj",                                     0x01CB },   //              ǋ       //
    { "nj",                                     0x01CC },   //              ǌ       //
    { "Acaron",                                 0x01CD },   //              Ǎ       //
    { "acaron",                                 0x01CE },   //              ǎ       //
    { "Icaron",                                 0x01CF },   //              Ǐ       //
    { "icaron",                                 0x01D0 },   //              ǐ       //
    { "Ocaron",                                 0x01D1 },   //              Ǒ       //
    { "ocaron",                                 0x01D2 },   //              ǒ       //
    { "Ucaron",                                 0x01D3 },   //              Ǔ       //
    { "ucaron",                                 0x01D4 },   //              ǔ       //
    { "Udieresismacron",                        0x01D5 },   //              Ǖ       //
    { "udieresismacron",                        0x01D6 },   //              ǖ       //
    { "Udieresisacute",                         0x01D7 },   //              Ǘ       //
    { "udieresisacute",                         0x01D8 },   //              ǘ       //
    { "Udieresiscaron",                         0x01D9 },   //              Ǚ       //
    { "udieresiscaron",                         0x01DA },   //              ǚ       //
    { "Udieresisgrave",                         0x01DB },   //              Ǜ       //
    { "udieresisgrave",                         0x01DC },   //              ǜ       //
    { "eturned",                                0x01DD },   //              ǝ       //
    { "Adieresismacron",                        0x01DE },   //              Ǟ       //
    { "adieresismacron",                        0x01DF },   //              ǟ       //
    { "Adotmacron",                             0x01E0 },   //              Ǡ       //
    { "adotmacron",                             0x01E1 },   //              ǡ       //
    { "AEmacron",                               0x01E2 },   //              Ǣ       //
    { "aemacron",                               0x01E3 },   //              ǣ       //
    { "Gstroke",                                0x01E4 },   //              Ǥ       //
    { "gstroke",                                0x01E5 },   //              ǥ       //
    { "Gcaron",                                 0x01E6 },   //              Ǧ       //
    { "gcaron",                                 0x01E7 },   //              ǧ       //
    { "Kcaron",                                 0x01E8 },   //              Ǩ       //
    { "kcaron",                                 0x01E9 },   //              ǩ       //
    { "Oogonek",                                0x01EA },   //              Ǫ       //
    { "oogonek",                                0x01EB },   //              ǫ       //
    { "Oogonekmacron",                          0x01EC },   //              Ǭ       //
    { "oogonekmacron",                          0x01ED },   //              ǭ       //
    { "Ezhcaron",                               0x01EE },   //              Ǯ       //
    { "ezhcaron",                               0x01EF },   //              ǯ       //
    { "jcaron",                                 0x01F0 },   //              ǰ       //
    { "DZ",                                     0x01F1 },   //              Ǳ       //
    { "Dz",                                     0x01F2 },   //              ǲ       //
    { "dz",                                     0x01F3 },   //              ǳ       //
    { "Gacute",                                 0x01F4 },   //              Ǵ       //
    { "gacute",                                 0x01F5 },   //              ǵ       //
    { "Aringacute",                             0x01FA },   //              Ǻ       //
    { "aringacute",                             0x01FB },   //              ǻ       //
    { "AEacute",                                0x01FC },   //              Ǽ       //
    { "aeacute",                                0x01FD },   //              ǽ       //
    { "Oslashacute",                            0x01FE },   //              Ǿ       //
    { "Ostrokeacute",                           0x01FE },   //              Ǿ       //
    { "oslashacute",                            0x01FF },   //              ǿ       //
    { "ostrokeacute",                           0x01FF },   //              ǿ       //
    { "Adblgrave",                              0x0200 },   //              Ȁ       //
    { "adblgrave",                              0x0201 },   //              ȁ       //
    { "Ainvertedbreve",                         0x0202 },   //              Ȃ       //
    { "ainvertedbreve",                         0x0203 },   //              ȃ       //
    { "Edblgrave",                              0x0204 },   //              Ȅ       //
    { "edblgrave",                              0x0205 },   //              ȅ       //
    { "Einvertedbreve",                         0x0206 },   //              Ȇ       //
    { "einvertedbreve",                         0x0207 },   //              ȇ       //
    { "Idblgrave",                              0x0208 },   //              Ȉ       //
    { "idblgrave",                              0x0209 },   //              ȉ       //
    { "Iinvertedbreve",                         0x020A },   //              Ȋ       //
    { "iinvertedbreve",                         0x020B },   //              ȋ       //
    { "Odblgrave",                              0x020C },   //              Ȍ       //
    { "odblgrave",                              0x020D },   //              ȍ       //
    { "Oinvertedbreve",                         0x020E },   //              Ȏ       //
    { "oinvertedbreve",                         0x020F },   //              ȏ       //
    { "Rdblgrave",                              0x0210 },   //              Ȑ       //
    { "rdblgrave",                              0x0211 },   //              ȑ       //
    { "Rinvertedbreve",                         0x0212 },   //              Ȓ       //
    { "rinvertedbreve",                         0x0213 },   //              ȓ       //
    { "Udblgrave",                              0x0214 },   //              Ȕ       //
    { "udblgrave",                              0x0215 },   //              ȕ       //
    { "Uinvertedbreve",                         0x0216 },   //              Ȗ       //
    { "uinvertedbreve",                         0x0217 },   //              ȗ       //
    { "Scommaaccent",                           0x0218 },   //              Ș       //
    { "scommaaccent",                           0x0219 },   //              ș       //
    { "aturned",                                0x0250 },   //              ɐ       //
    { "ascript",                                0x0251 },   //              ɑ       //
    { "ascriptturned",                          0x0252 },   //              ɒ       //
    { "bhook",                                  0x0253 },   //              ɓ       //
    { "oopen",                                  0x0254 },   //              ɔ       //
    { "ccurl",                                  0x0255 },   //              ɕ       //
    { "dtail",                                  0x0256 },   //              ɖ       //
    { "dhook",                                  0x0257 },   //              ɗ       //
    { "ereversed",                              0x0258 },   //              ɘ       //
    { "schwa",                                  0x0259 },   //              ə       //
    { "schwahook",                              0x025A },   //              ɚ       //
    { "eopen",                                  0x025B },   //              ɛ       //
    { "eopenreversed",                          0x025C },   //              ɜ       //
    { "eopenreversedhook",                      0x025D },   //              ɝ       //
    { "eopenreversedclosed",                    0x025E },   //              ɞ       //
    { "jdotlessstroke",                         0x025F },   //              ɟ       //
    { "ghook",                                  0x0260 },   //              ɠ       //
    { "gscript",                                0x0261 },   //              ɡ       //
    { "gammalatinsmall",                        0x0263 },   //              ɣ       //
    { "ramshorn",                               0x0264 },   //              ɤ       //
    { "hturned",                                0x0265 },   //              ɥ       //
    { "hhook",                                  0x0266 },   //              ɦ       //
    { "henghook",                               0x0267 },   //              ɧ       //
    { "istroke",                                0x0268 },   //              ɨ       //
    { "iotalatin",                              0x0269 },   //              ɩ       //
    { "lmiddletilde",                           0x026B },   //              ɫ       //
    { "lbelt",                                  0x026C },   //              ɬ       //
    { "lhookretroflex",                         0x026D },   //              ɭ       //
    { "lezh",                                   0x026E },   //              ɮ       //
    { "mturned",                                0x026F },   //              ɯ       //
    { "mlonglegturned",                         0x0270 },   //              ɰ       //
    { "mhook",                                  0x0271 },   //              ɱ       //
    { "nhookleft",                              0x0272 },   //              ɲ       //
    { "nhookretroflex",                         0x0273 },   //              ɳ       //
    { "obarred",                                0x0275 },   //              ɵ       //
    { "omegalatinclosed",                       0x0277 },   //              ɷ       //
    { "philatin",                               0x0278 },   //              ɸ       //
    { "rturned",                                0x0279 },   //              ɹ       //
    { "rlonglegturned",                         0x027A },   //              ɺ       //
    { "rhookturned",                            0x027B },   //              ɻ       //
    { "rlongleg",                               0x027C },   //              ɼ       //
    { "rhook",                                  0x027D },   //              ɽ       //
    { "rfishhook",                              0x027E },   //              ɾ       //
    { "rfishhookreversed",                      0x027F },   //              ɿ       //
    { "Rsmallinverted",                         0x0281 },   //              ʁ       //
    { "shook",                                  0x0282 },   //              ʂ       //
    { "esh",                                    0x0283 },   //              ʃ       //
    { "dotlessjstrokehook",                     0x0284 },   //              ʄ       //
    { "eshsquatreversed",                       0x0285 },   //              ʅ       //
    { "eshcurl",                                0x0286 },   //              ʆ       //
    { "tturned",                                0x0287 },   //              ʇ       //
    { "tretroflexhook",                         0x0288 },   //              ʈ       //
    { "ubar",                                   0x0289 },   //              ʉ       //
    { "upsilonlatin",                           0x028A },   //              ʊ       //
    { "vhook",                                  0x028B },   //              ʋ       //
    { "vturned",                                0x028C },   //              ʌ       //
    { "wturned",                                0x028D },   //              ʍ       //
    { "yturned",                                0x028E },   //              ʎ       //
    { "zretroflexhook",                         0x0290 },   //              ʐ       //
    { "zcurl",                                  0x0291 },   //              ʑ       //
    { "ezh",                                    0x0292 },   //              ʒ       //
    { "ezhcurl",                                0x0293 },   //              ʓ       //
    { "glottalstop",                            0x0294 },   //              ʔ       //
    { "glottalstopreversed",                    0x0295 },   //              ʕ       //
    { "glottalstopinverted",                    0x0296 },   //              ʖ       //
    { "cstretched",                             0x0297 },   //              ʗ       //
    { "bilabialclick",                          0x0298 },   //              ʘ       //
    { "eopenclosed",                            0x029A },   //              ʚ       //
    { "Gsmallhook",                             0x029B },   //              ʛ       //
    { "jcrossedtail",                           0x029D },   //              ʝ       //
    { "kturned",                                0x029E },   //              ʞ       //
    { "qhook",                                  0x02A0 },   //              ʠ       //
    { "glottalstopstroke",                      0x02A1 },   //              ʡ       //
    { "glottalstopstrokereversed",              0x02A2 },   //              ʢ       //
    { "dzaltone",                               0x02A3 },   //              ʣ       //
    { "dezh",                                   0x02A4 },   //              ʤ       //
    { "dzcurl",                                 0x02A5 },   //              ʥ       //
    { "ts",                                     0x02A6 },   //              ʦ       //
    { "tesh",                                   0x02A7 },   //              ʧ       //
    { "tccurl",                                 0x02A8 },   //              ʨ       //
    { "hsuperior",                              0x02B0 },   //              ʰ       //
    { "hhooksuperior",                          0x02B1 },   //              ʱ       //
    { "jsuperior",                              0x02B2 },   //              ʲ       //
    { "rturnedsuperior",                        0x02B4 },   //              ʴ       //
    { "rhookturnedsuperior",                    0x02B5 },   //              ʵ       //
    { "Rsmallinvertedsuperior",                 0x02B6 },   //              ʶ       //
    { "wsuperior",                              0x02B7 },   //              ʷ       //
    { "ysuperior",                              0x02B8 },   //              ʸ       //
    { "primemod",                               0x02B9 },   //              ʹ       //
    { "dblprimemod",                            0x02BA },   //              ʺ       //
    { "commaturnedmod",                         0x02BB },   //              ʻ       //
    { "afii57929",                              0x02BC },   //              ʼ       //
    { "apostrophemod",                          0x02BC },   //              ʼ       //
    { "afii64937",                              0x02BD },   //              ʽ       //
    { "commareversedmod",                       0x02BD },   //              ʽ       //
    { "ringhalfright",                          0x02BE },   //              ʾ       //
    { "ringhalfleft",                           0x02BF },   //              ʿ       //
    { "glottalstopmod",                         0x02C0 },   //              ˀ       //
    { "glottalstopreversedmod",                 0x02C1 },   //              ˁ       //
    { "arrowheadleftmod",                       0x02C2 },   //              ˂       //
    { "arrowheadrightmod",                      0x02C3 },   //              ˃       //
    { "arrowheadupmod",                         0x02C4 },   //              ˄       //
    { "arrowheaddownmod",                       0x02C5 },   //              ˅       //
    { "caron",                                  0x02C7 },   //              ˇ       //
    { "verticallinemod",                        0x02C8 },   //              ˈ       //
    { "firsttonechinese",                       0x02C9 },   //              ˉ       //
    { "secondtonechinese",                      0x02CA },   //              ˊ       //
    { "fourthtonechinese",                      0x02CB },   //              ˋ       //
    { "verticallinelowmod",                     0x02CC },   //              ˌ       //
    { "macronlowmod",                           0x02CD },   //              ˍ       //
    { "gravelowmod",                            0x02CE },   //              ˎ       //
    { "acutelowmod",                            0x02CF },   //              ˏ       //
    { "colontriangularmod",                     0x02D0 },   //              ː       //
    { "colontriangularhalfmod",                 0x02D1 },   //              ˑ       //
    { "ringhalfrightcentered",                  0x02D2 },   //              ˒       //
    { "ringhalfleftcentered",                   0x02D3 },   //              ˓       //
    { "uptackmod",                              0x02D4 },   //              ˔       //
    { "downtackmod",                            0x02D5 },   //              ˕       //
    { "plusmod",                                0x02D6 },   //              ˖       //
    { "minusmod",                               0x02D7 },   //              ˗       //
    { "breve",                                  0x02D8 },   //              ˘       //
    { "dotaccent",                              0x02D9 },   //              ˙       //
    { "ring",                                   0x02DA },   //              ˚       //
    { "ogonek",                                 0x02DB },   //              ˛       //
    { "hungarumlaut",                           0x02DD },   //              ˝       //
    { "rhotichookmod",                          0x02DE },   //              ˞       //
    { "gammasuperior",                          0x02E0 },   //              ˠ       //
    { "xsuperior",                              0x02E3 },   //              ˣ       //
    { "glottalstopreversedsuperior",            0x02E4 },   //              ˤ       //
    { "tonebarextrahighmod",                    0x02E5 },   //              ˥       //
    { "tonebarhighmod",                         0x02E6 },   //              ˦       //
    { "tonebarmidmod",                          0x02E7 },   //              ˧       //
    { "tonebarlowmod",                          0x02E8 },   //              ˨       //
    { "tonebarextralowmod",                     0x02E9 },   //              ˩       //
    { "gravecmb",                               0x0300 },   //              ̀       //
    { "gravecomb",                              0x0300 },   //              ̀       //
    { "acutecmb",                               0x0301 },   //              ́       //
    { "acutecomb",                              0x0301 },   //              ́       //
    { "circumflexcmb",                          0x0302 },   //              ̂       //
    { "tildecmb",                               0x0303 },   //              ̃       //
    { "tildecomb",                              0x0303 },   //              ̃       //
    { "macroncmb",                              0x0304 },   //              ̄       //
    { "overlinecmb",                            0x0305 },   //              ̅       //
    { "brevecmb",                               0x0306 },   //              ̆       //
    { "dotaccentcmb",                           0x0307 },   //              ̇       //
    { "dieresiscmb",                            0x0308 },   //              ̈       //
    { "hookabovecomb",                          0x0309 },   //              ̉       //
    { "hookcmb",                                0x0309 },   //              ̉       //
    { "ringcmb",                                0x030A },   //              ̊       //
    { "hungarumlautcmb",                        0x030B },   //              ̋       //
    { "caroncmb",                               0x030C },   //              ̌       //
    { "verticallineabovecmb",                   0x030D },   //              ̍       //
    { "dblverticallineabovecmb",                0x030E },   //              ̎       //
    { "dblgravecmb",                            0x030F },   //              ̏       //
    { "candrabinducmb",                         0x0310 },   //              ̐       //
    { "breveinvertedcmb",                       0x0311 },   //              ̑       //
    { "commaturnedabovecmb",                    0x0312 },   //              ̒       //
    { "commaabovecmb",                          0x0313 },   //              ̓       //
    { "commareversedabovecmb",                  0x0314 },   //              ̔       //
    { "commaaboverightcmb",                     0x0315 },   //              ̕       //
    { "gravebelowcmb",                          0x0316 },   //              ̖       //
    { "acutebelowcmb",                          0x0317 },   //              ̗       //
    { "lefttackbelowcmb",                       0x0318 },   //              ̘       //
    { "righttackbelowcmb",                      0x0319 },   //              ̙       //
    { "leftangleabovecmb",                      0x031A },   //              ̚       //
    { "horncmb",                                0x031B },   //              ̛       //
    { "ringhalfleftbelowcmb",                   0x031C },   //              ̜       //
    { "uptackbelowcmb",                         0x031D },   //              ̝       //
    { "downtackbelowcmb",                       0x031E },   //              ̞       //
    { "plusbelowcmb",                           0x031F },   //              ̟       //
    { "minusbelowcmb",                          0x0320 },   //              ̠       //
    { "hookpalatalizedbelowcmb",                0x0321 },   //              ̡       //
    { "hookretroflexbelowcmb",                  0x0322 },   //              ̢       //
    { "dotbelowcmb",                            0x0323 },   //              ̣       //
    { "dotbelowcomb",                           0x0323 },   //              ̣       //
    { "dieresisbelowcmb",                       0x0324 },   //              ̤       //
    { "ringbelowcmb",                           0x0325 },   //              ̥       //
    { "cedillacmb",                             0x0327 },   //              ̧       //
    { "ogonekcmb",                              0x0328 },   //              ̨       //
    { "verticallinebelowcmb",                   0x0329 },   //              ̩       //
    { "bridgebelowcmb",                         0x032A },   //              ̪       //
    { "dblarchinvertedbelowcmb",                0x032B },   //              ̫       //
    { "caronbelowcmb",                          0x032C },   //              ̬       //
    { "circumflexbelowcmb",                     0x032D },   //              ̭       //
    { "brevebelowcmb",                          0x032E },   //              ̮       //
    { "breveinvertedbelowcmb",                  0x032F },   //              ̯       //
    { "tildebelowcmb",                          0x0330 },   //              ̰       //
    { "macronbelowcmb",                         0x0331 },   //              ̱       //
    { "lowlinecmb",                             0x0332 },   //              ̲       //
    { "dbllowlinecmb",                          0x0333 },   //              ̳       //
    { "tildeoverlaycmb",                        0x0334 },   //              ̴       //
    { "strokeshortoverlaycmb",                  0x0335 },   //              ̵       //
    { "strokelongoverlaycmb",                   0x0336 },   //              ̶       //
    { "solidusshortoverlaycmb",                 0x0337 },   //              ̷       //
    { "soliduslongoverlaycmb",                  0x0338 },   //              ̸       //
    { "ringhalfrightbelowcmb",                  0x0339 },   //              ̹       //
    { "bridgeinvertedbelowcmb",                 0x033A },   //              ̺       //
    { "squarebelowcmb",                         0x033B },   //              ̻       //
    { "seagullbelowcmb",                        0x033C },   //              ̼       //
    { "xabovecmb",                              0x033D },   //              ̽       //
    { "tildeverticalcmb",                       0x033E },   //              ̾       //
    { "dbloverlinecmb",                         0x033F },   //              ̿       //
    { "gravetonecmb",                           0x0340 },   //              ̀       //
    { "acutetonecmb",                           0x0341 },   //              ́       //
    { "perispomenigreekcmb",                    0x0342 },   //              ͂       //
    { "koroniscmb",                             0x0343 },   //              ̓       //
    { "dialytikatonoscmb",                      0x0344 },   //              ̈́       //
    { "ypogegrammenigreekcmb",                  0x0345 },   //              ͅ       //
    { "tildedoublecmb",                         0x0360 },   //              ͠       //
    { "breveinverteddoublecmb",                 0x0361 },   //              ͡       //
    { "numeralsigngreek",                       0x0374 },   //              ʹ       //
    { "numeralsignlowergreek",                  0x0375 },   //              ͵       //
    { "ypogegrammeni",                          0x037A },   //              ͺ       //
    { "questiongreek",                          0x037E },   //              ;       //
    { "tonos",                                  0x0384 },   //              ΄       //
    { "dialytikatonos",                         0x0385 },   //              ΅       //
    { "dieresistonos",                          0x0385 },   //              ΅       //
    { "Alphatonos",                             0x0386 },   //              Ά       //
    { "anoteleia",                              0x0387 },   //              ·       //
    { "Epsilontonos",                           0x0388 },   //              Έ       //
    { "Etatonos",                               0x0389 },   //              Ή       //
    { "Iotatonos",                              0x038A },   //              Ί       //
    { "Omicrontonos",                           0x038C },   //              Ό       //
    { "Upsilontonos",                           0x038E },   //              Ύ       //
    { "Omegatonos",                             0x038F },   //              Ώ       //
    { "iotadieresistonos",                      0x0390 },   //              ΐ       //
    { "Iotadieresis",                           0x03AA },   //              Ϊ       //
    { "Upsilondieresis",                        0x03AB },   //              Ϋ       //
    { "alphatonos",                             0x03AC },   //              ά       //
    { "epsilontonos",                           0x03AD },   //              έ       //
    { "etatonos",                               0x03AE },   //              ή       //
    { "iotatonos",                              0x03AF },   //              ί       //
    { "upsilondieresistonos",                   0x03B0 },   //              ΰ       //
    { "iotadieresis",                           0x03CA },   //              ϊ       //
    { "upsilondieresis",                        0x03CB },   //              ϋ       //
    { "omicrontonos",                           0x03CC },   //              ό       //
    { "upsilontonos",                           0x03CD },   //              ύ       //
    { "omegatonos",                             0x03CE },   //              ώ       //
    { "betasymbolgreek",                        0x03D0 },   //              ϐ       //
    { "Upsilonacutehooksymbolgreek",            0x03D3 },   //              ϓ       //
    { "Upsilondieresishooksymbolgreek",         0x03D4 },   //              ϔ       //
    { "phi",                                    0x03D5 },   //              ϕ      // phi1 # texglyphlist.txt: TeX encodings such as 'texmital.enc' disagree with Unicode and the Adobe glyph list; in TeX, the "straight" form of phi takes the name "phi", whereas the more-common "loopy" form of phi, \varphi, takes the name "phi1". //
    { "phisymbolgreek",                         0x03D5 },   //              ϕ       //
    { "Stigmagreek",                            0x03DA },   //              Ϛ       //
    { "Digammagreek",                           0x03DC },   //              Ϝ       //
    { "Koppagreek",                             0x03DE },   //              Ϟ       //
    { "Sampigreek",                             0x03E0 },   //              Ϡ       //
    { "Sheicoptic",                             0x03E2 },   //              Ϣ       //
    { "sheicoptic",                             0x03E3 },   //              ϣ       //
    { "Feicoptic",                              0x03E4 },   //              Ϥ       //
    { "feicoptic",                              0x03E5 },   //              ϥ       //
    { "Kheicoptic",                             0x03E6 },   //              Ϧ       //
    { "kheicoptic",                             0x03E7 },   //              ϧ       //
    { "Horicoptic",                             0x03E8 },   //              Ϩ       //
    { "horicoptic",                             0x03E9 },   //              ϩ       //
    { "Gangiacoptic",                           0x03EA },   //              Ϫ       //
    { "gangiacoptic",                           0x03EB },   //              ϫ       //
    { "Shimacoptic",                            0x03EC },   //              Ϭ       //
    { "shimacoptic",                            0x03ED },   //              ϭ       //
    { "Deicoptic",                              0x03EE },   //              Ϯ       //
    { "deicoptic",                              0x03EF },   //              ϯ       //
    { "kappasymbolgreek",                       0x03F0 },   //              ϰ       //
    { "rhosymbolgreek",                         0x03F1 },   //              ϱ       //
    { "sigmalunatesymbolgreek",                 0x03F2 },   //              ϲ       //
    { "yotgreek",                               0x03F3 },   //              ϳ       //
    { "Iocyrillic",                             0x0401 },   //              Ё       //
    { "afii10023",                              0x0401 },   //              Ё       //
    { "Djecyrillic",                            0x0402 },   //              Ђ       //
    { "afii10051",                              0x0402 },   //              Ђ       //
    { "Gjecyrillic",                            0x0403 },   //              Ѓ       //
    { "afii10052",                              0x0403 },   //              Ѓ       //
    { "Ecyrillic",                              0x0404 },   //              Є       //
    { "afii10053",                              0x0404 },   //              Є       //
    { "Dzecyrillic",                            0x0405 },   //              Ѕ       //
    { "afii10054",                              0x0405 },   //              Ѕ       //
    { "Icyrillic",                              0x0406 },   //              І       //
    { "afii10055",                              0x0406 },   //              І       //
    { "Yicyrillic",                             0x0407 },   //              Ї       //
    { "afii10056",                              0x0407 },   //              Ї       //
    { "Jecyrillic",                             0x0408 },   //              Ј       //
    { "afii10057",                              0x0408 },   //              Ј       //
    { "Ljecyrillic",                            0x0409 },   //              Љ       //
    { "afii10058",                              0x0409 },   //              Љ       //
    { "Njecyrillic",                            0x040A },   //              Њ       //
    { "afii10059",                              0x040A },   //              Њ       //
    { "Tshecyrillic",                           0x040B },   //              Ћ       //
    { "afii10060",                              0x040B },   //              Ћ       //
    { "Kjecyrillic",                            0x040C },   //              Ќ       //
    { "afii10061",                              0x040C },   //              Ќ       //
    { "Ushortcyrillic",                         0x040E },   //              Ў       //
    { "afii10062",                              0x040E },   //              Ў       //
    { "Dzhecyrillic",                           0x040F },   //              Џ       //
    { "afii10145",                              0x040F },   //              Џ       //
    { "Acyrillic",                              0x0410 },   //              А       //
    { "afii10017",                              0x0410 },   //              А       //
    { "Becyrillic",                             0x0411 },   //              Б       //
    { "afii10018",                              0x0411 },   //              Б       //
    { "Vecyrillic",                             0x0412 },   //              В       //
    { "afii10019",                              0x0412 },   //              В       //
    { "Gecyrillic",                             0x0413 },   //              Г       //
    { "afii10020",                              0x0413 },   //              Г       //
    { "Decyrillic",                             0x0414 },   //              Д       //
    { "afii10021",                              0x0414 },   //              Д       //
    { "Iecyrillic",                             0x0415 },   //              Е       //
    { "afii10022",                              0x0415 },   //              Е       //
    { "Zhecyrillic",                            0x0416 },   //              Ж       //
    { "afii10024",                              0x0416 },   //              Ж       //
    { "Zecyrillic",                             0x0417 },   //              З       //
    { "afii10025",                              0x0417 },   //              З       //
    { "Iicyrillic",                             0x0418 },   //              И       //
    { "afii10026",                              0x0418 },   //              И       //
    { "Iishortcyrillic",                        0x0419 },   //              Й       //
    { "afii10027",                              0x0419 },   //              Й       //
    { "Kacyrillic",                             0x041A },   //              К       //
    { "afii10028",                              0x041A },   //              К       //
    { "Elcyrillic",                             0x041B },   //              Л       //
    { "afii10029",                              0x041B },   //              Л       //
    { "Emcyrillic",                             0x041C },   //              М       //
    { "afii10030",                              0x041C },   //              М       //
    { "Encyrillic",                             0x041D },   //              Н       //
    { "afii10031",                              0x041D },   //              Н       //
    { "Ocyrillic",                              0x041E },   //              О       //
    { "afii10032",                              0x041E },   //              О       //
    { "Pecyrillic",                             0x041F },   //              П       //
    { "afii10033",                              0x041F },   //              П       //
    { "Ercyrillic",                             0x0420 },   //              Р       //
    { "afii10034",                              0x0420 },   //              Р       //
    { "Escyrillic",                             0x0421 },   //              С       //
    { "afii10035",                              0x0421 },   //              С       //
    { "Tecyrillic",                             0x0422 },   //              Т       //
    { "afii10036",                              0x0422 },   //              Т       //
    { "Ucyrillic",                              0x0423 },   //              У       //
    { "afii10037",                              0x0423 },   //              У       //
    { "Efcyrillic",                             0x0424 },   //              Ф       //
    { "afii10038",                              0x0424 },   //              Ф       //
    { "Khacyrillic",                            0x0425 },   //              Х       //
    { "afii10039",                              0x0425 },   //              Х       //
    { "Tsecyrillic",                            0x0426 },   //              Ц       //
    { "afii10040",                              0x0426 },   //              Ц       //
    { "Checyrillic",                            0x0427 },   //              Ч       //
    { "afii10041",                              0x0427 },   //              Ч       //
    { "Shacyrillic",                            0x0428 },   //              Ш       //
    { "afii10042",                              0x0428 },   //              Ш       //
    { "Shchacyrillic",                          0x0429 },   //              Щ       //
    { "afii10043",                              0x0429 },   //              Щ       //
    { "Hardsigncyrillic",                       0x042A },   //              Ъ       //
    { "afii10044",                              0x042A },   //              Ъ       //
    { "Yericyrillic",                           0x042B },   //              Ы       //
    { "afii10045",                              0x042B },   //              Ы       //
    { "Softsigncyrillic",                       0x042C },   //              Ь       //
    { "afii10046",                              0x042C },   //              Ь       //
    { "Ereversedcyrillic",                      0x042D },   //              Э       //
    { "afii10047",                              0x042D },   //              Э       //
    { "IUcyrillic",                             0x042E },   //              Ю       //
    { "afii10048",                              0x042E },   //              Ю       //
    { "IAcyrillic",                             0x042F },   //              Я       //
    { "afii10049",                              0x042F },   //              Я       //
    { "acyrillic",                              0x0430 },   //              а       //
    { "afii10065",                              0x0430 },   //              а       //
    { "afii10066",                              0x0431 },   //              б       //
    { "becyrillic",                             0x0431 },   //              б       //
    { "afii10067",                              0x0432 },   //              в       //
    { "vecyrillic",                             0x0432 },   //              в       //
    { "afii10068",                              0x0433 },   //              г       //
    { "gecyrillic",                             0x0433 },   //              г       //
    { "afii10069",                              0x0434 },   //              д       //
    { "decyrillic",                             0x0434 },   //              д       //
    { "afii10070",                              0x0435 },   //              е       //
    { "iecyrillic",                             0x0435 },   //              е       //
    { "afii10072",                              0x0436 },   //              ж       //
    { "zhecyrillic",                            0x0436 },   //              ж       //
    { "afii10073",                              0x0437 },   //              з       //
    { "zecyrillic",                             0x0437 },   //              з       //
    { "afii10074",                              0x0438 },   //              и       //
    { "iicyrillic",                             0x0438 },   //              и       //
    { "afii10075",                              0x0439 },   //              й       //
    { "iishortcyrillic",                        0x0439 },   //              й       //
    { "afii10076",                              0x043A },   //              к       //
    { "kacyrillic",                             0x043A },   //              к       //
    { "afii10077",                              0x043B },   //              л       //
    { "elcyrillic",                             0x043B },   //              л       //
    { "afii10078",                              0x043C },   //              м       //
    { "emcyrillic",                             0x043C },   //              м       //
    { "afii10079",                              0x043D },   //              н       //
    { "encyrillic",                             0x043D },   //              н       //
    { "afii10080",                              0x043E },   //              о       //
    { "ocyrillic",                              0x043E },   //              о       //
    { "afii10081",                              0x043F },   //              п       //
    { "pecyrillic",                             0x043F },   //              п       //
    { "afii10082",                              0x0440 },   //              р       //
    { "ercyrillic",                             0x0440 },   //              р       //
    { "afii10083",                              0x0441 },   //              с       //
    { "escyrillic",                             0x0441 },   //              с       //
    { "afii10084",                              0x0442 },   //              т       //
    { "tecyrillic",                             0x0442 },   //              т       //
    { "afii10085",                              0x0443 },   //              у       //
    { "ucyrillic",                              0x0443 },   //              у       //
    { "afii10086",                              0x0444 },   //              ф       //
    { "efcyrillic",                             0x0444 },   //              ф       //
    { "afii10087",                              0x0445 },   //              х       //
    { "khacyrillic",                            0x0445 },   //              х       //
    { "afii10088",                              0x0446 },   //              ц       //
    { "tsecyrillic",                            0x0446 },   //              ц       //
    { "afii10089",                              0x0447 },   //              ч       //
    { "checyrillic",                            0x0447 },   //              ч       //
    { "afii10090",                              0x0448 },   //              ш       //
    { "shacyrillic",                            0x0448 },   //              ш       //
    { "afii10091",                              0x0449 },   //              щ       //
    { "shchacyrillic",                          0x0449 },   //              щ       //
    { "afii10092",                              0x044A },   //              ъ       //
    { "hardsigncyrillic",                       0x044A },   //              ъ       //
    { "afii10093",                              0x044B },   //              ы       //
    { "yericyrillic",                           0x044B },   //              ы       //
    { "afii10094",                              0x044C },   //              ь       //
    { "softsigncyrillic",                       0x044C },   //              ь       //
    { "afii10095",                              0x044D },   //              э       //
    { "ereversedcyrillic",                      0x044D },   //              э       //
    { "afii10096",                              0x044E },   //              ю       //
    { "iucyrillic",                             0x044E },   //              ю       //
    { "afii10097",                              0x044F },   //              я       //
    { "iacyrillic",                             0x044F },   //              я       //
    { "afii10071",                              0x0451 },   //              ё       //
    { "iocyrillic",                             0x0451 },   //              ё       //
    { "afii10099",                              0x0452 },   //              ђ       //
    { "djecyrillic",                            0x0452 },   //              ђ       //
    { "afii10100",                              0x0453 },   //              ѓ       //
    { "gjecyrillic",                            0x0453 },   //              ѓ       //
    { "afii10101",                              0x0454 },   //              є       //
    { "ecyrillic",                              0x0454 },   //              є       //
    { "afii10102",                              0x0455 },   //              ѕ       //
    { "dzecyrillic",                            0x0455 },   //              ѕ       //
    { "afii10103",                              0x0456 },   //              і       //
    { "icyrillic",                              0x0456 },   //              і       //
    { "afii10104",                              0x0457 },   //              ї       //
    { "yicyrillic",                             0x0457 },   //              ї       //
    { "afii10105",                              0x0458 },   //              ј       //
    { "jecyrillic",                             0x0458 },   //              ј       //
    { "afii10106",                              0x0459 },   //              љ       //
    { "ljecyrillic",                            0x0459 },   //              љ       //
    { "afii10107",                              0x045A },   //              њ       //
    { "njecyrillic",                            0x045A },   //              њ       //
    { "afii10108",                              0x045B },   //              ћ       //
    { "tshecyrillic",                           0x045B },   //              ћ       //
    { "afii10109",                              0x045C },   //              ќ       //
    { "kjecyrillic",                            0x045C },   //              ќ       //
    { "afii10110",                              0x045E },   //              ў       //
    { "ushortcyrillic",                         0x045E },   //              ў       //
    { "afii10193",                              0x045F },   //              џ       //
    { "dzhecyrillic",                           0x045F },   //              џ       //
    { "Omegacyrillic",                          0x0460 },   //              Ѡ       //
    { "omegacyrillic",                          0x0461 },   //              ѡ       //
    { "Yatcyrillic",                            0x0462 },   //              Ѣ       //
    { "afii10146",                              0x0462 },   //              Ѣ       //
    { "afii10194",                              0x0463 },   //              ѣ       //
    { "yatcyrillic",                            0x0463 },   //              ѣ       //
    { "Eiotifiedcyrillic",                      0x0464 },   //              Ѥ       //
    { "eiotifiedcyrillic",                      0x0465 },   //              ѥ       //
    { "Yuslittlecyrillic",                      0x0466 },   //              Ѧ       //
    { "yuslittlecyrillic",                      0x0467 },   //              ѧ       //
    { "Yuslittleiotifiedcyrillic",              0x0468 },   //              Ѩ       //
    { "yuslittleiotifiedcyrillic",              0x0469 },   //              ѩ       //
    { "Yusbigcyrillic",                         0x046A },   //              Ѫ       //
    { "yusbigcyrillic",                         0x046B },   //              ѫ       //
    { "Yusbigiotifiedcyrillic",                 0x046C },   //              Ѭ       //
    { "yusbigiotifiedcyrillic",                 0x046D },   //              ѭ       //
    { "Ksicyrillic",                            0x046E },   //              Ѯ       //
    { "ksicyrillic",                            0x046F },   //              ѯ       //
    { "Psicyrillic",                            0x0470 },   //              Ѱ       //
    { "psicyrillic",                            0x0471 },   //              ѱ       //
    { "Fitacyrillic",                           0x0472 },   //              Ѳ       //
    { "afii10147",                              0x0472 },   //              Ѳ       //
    { "afii10195",                              0x0473 },   //              ѳ       //
    { "fitacyrillic",                           0x0473 },   //              ѳ       //
    { "Izhitsacyrillic",                        0x0474 },   //              Ѵ       //
    { "afii10148",                              0x0474 },   //              Ѵ       //
    { "afii10196",                              0x0475 },   //              ѵ       //
    { "izhitsacyrillic",                        0x0475 },   //              ѵ       //
    { "Izhitsadblgravecyrillic",                0x0476 },   //              Ѷ       //
    { "izhitsadblgravecyrillic",                0x0477 },   //              ѷ       //
    { "Ukcyrillic",                             0x0478 },   //              Ѹ       //
    { "ukcyrillic",                             0x0479 },   //              ѹ       //
    { "Omegaroundcyrillic",                     0x047A },   //              Ѻ       //
    { "omegaroundcyrillic",                     0x047B },   //              ѻ       //
    { "Omegatitlocyrillic",                     0x047C },   //              Ѽ       //
    { "omegatitlocyrillic",                     0x047D },   //              ѽ       //
    { "Otcyrillic",                             0x047E },   //              Ѿ       //
    { "otcyrillic",                             0x047F },   //              ѿ       //
    { "Koppacyrillic",                          0x0480 },   //              Ҁ       //
    { "koppacyrillic",                          0x0481 },   //              ҁ       //
    { "thousandcyrillic",                       0x0482 },   //              ҂       //
    { "titlocyrilliccmb",                       0x0483 },   //              ҃       //
    { "palatalizationcyrilliccmb",              0x0484 },   //              ҄       //
    { "dasiapneumatacyrilliccmb",               0x0485 },   //              ҅       //
    { "psilipneumatacyrilliccmb",               0x0486 },   //              ҆       //
    { "Gheupturncyrillic",                      0x0490 },   //              Ґ       //
    { "afii10050",                              0x0490 },   //              Ґ       //
    { "afii10098",                              0x0491 },   //              ґ       //
    { "gheupturncyrillic",                      0x0491 },   //              ґ       //
    { "Ghestrokecyrillic",                      0x0492 },   //              Ғ       //
    { "ghestrokecyrillic",                      0x0493 },   //              ғ       //
    { "Ghemiddlehookcyrillic",                  0x0494 },   //              Ҕ       //
    { "ghemiddlehookcyrillic",                  0x0495 },   //              ҕ       //
    { "Zhedescendercyrillic",                   0x0496 },   //              Җ       //
    { "zhedescendercyrillic",                   0x0497 },   //              җ       //
    { "Zedescendercyrillic",                    0x0498 },   //              Ҙ       //
    { "zedescendercyrillic",                    0x0499 },   //              ҙ       //
    { "Kadescendercyrillic",                    0x049A },   //              Қ       //
    { "kadescendercyrillic",                    0x049B },   //              қ       //
    { "Kaverticalstrokecyrillic",               0x049C },   //              Ҝ       //
    { "kaverticalstrokecyrillic",               0x049D },   //              ҝ       //
    { "Kastrokecyrillic",                       0x049E },   //              Ҟ       //
    { "kastrokecyrillic",                       0x049F },   //              ҟ       //
    { "Kabashkircyrillic",                      0x04A0 },   //              Ҡ       //
    { "kabashkircyrillic",                      0x04A1 },   //              ҡ       //
    { "Endescendercyrillic",                    0x04A2 },   //              Ң       //
    { "endescendercyrillic",                    0x04A3 },   //              ң       //
    { "Enghecyrillic",                          0x04A4 },   //              Ҥ       //
    { "enghecyrillic",                          0x04A5 },   //              ҥ       //
    { "Pemiddlehookcyrillic",                   0x04A6 },   //              Ҧ       //
    { "pemiddlehookcyrillic",                   0x04A7 },   //              ҧ       //
    { "Haabkhasiancyrillic",                    0x04A8 },   //              Ҩ       //
    { "haabkhasiancyrillic",                    0x04A9 },   //              ҩ       //
    { "Esdescendercyrillic",                    0x04AA },   //              Ҫ       //
    { "esdescendercyrillic",                    0x04AB },   //              ҫ       //
    { "Tedescendercyrillic",                    0x04AC },   //              Ҭ       //
    { "tedescendercyrillic",                    0x04AD },   //              ҭ       //
    { "Ustraightcyrillic",                      0x04AE },   //              Ү       //
    { "ustraightcyrillic",                      0x04AF },   //              ү       //
    { "Ustraightstrokecyrillic",                0x04B0 },   //              Ұ       //
    { "ustraightstrokecyrillic",                0x04B1 },   //              ұ       //
    { "Hadescendercyrillic",                    0x04B2 },   //              Ҳ       //
    { "hadescendercyrillic",                    0x04B3 },   //              ҳ       //
    { "Tetsecyrillic",                          0x04B4 },   //              Ҵ       //
    { "tetsecyrillic",                          0x04B5 },   //              ҵ       //
    { "Chedescendercyrillic",                   0x04B6 },   //              Ҷ       //
    { "chedescendercyrillic",                   0x04B7 },   //              ҷ       //
    { "Cheverticalstrokecyrillic",              0x04B8 },   //              Ҹ       //
    { "cheverticalstrokecyrillic",              0x04B9 },   //              ҹ       //
    { "Shhacyrillic",                           0x04BA },   //              Һ       //
    { "shhacyrillic",                           0x04BB },   //              һ       //
    { "Cheabkhasiancyrillic",                   0x04BC },   //              Ҽ       //
    { "cheabkhasiancyrillic",                   0x04BD },   //              ҽ       //
    { "Chedescenderabkhasiancyrillic",          0x04BE },   //              Ҿ       //
    { "chedescenderabkhasiancyrillic",          0x04BF },   //              ҿ       //
    { "palochkacyrillic",                       0x04C0 },   //              Ӏ       //
    { "Zhebrevecyrillic",                       0x04C1 },   //              Ӂ       //
    { "zhebrevecyrillic",                       0x04C2 },   //              ӂ       //
    { "Kahookcyrillic",                         0x04C3 },   //              Ӄ       //
    { "kahookcyrillic",                         0x04C4 },   //              ӄ       //
    { "Enhookcyrillic",                         0x04C7 },   //              Ӈ       //
    { "enhookcyrillic",                         0x04C8 },   //              ӈ       //
    { "Chekhakassiancyrillic",                  0x04CB },   //              Ӌ       //
    { "chekhakassiancyrillic",                  0x04CC },   //              ӌ       //
    { "Abrevecyrillic",                         0x04D0 },   //              Ӑ       //
    { "abrevecyrillic",                         0x04D1 },   //              ӑ       //
    { "Adieresiscyrillic",                      0x04D2 },   //              Ӓ       //
    { "adieresiscyrillic",                      0x04D3 },   //              ӓ       //
    { "Aiecyrillic",                            0x04D4 },   //              Ӕ       //
    { "aiecyrillic",                            0x04D5 },   //              ӕ       //
    { "Iebrevecyrillic",                        0x04D6 },   //              Ӗ       //
    { "iebrevecyrillic",                        0x04D7 },   //              ӗ       //
    { "Schwacyrillic",                          0x04D8 },   //              Ә       //
    { "afii10846",                              0x04D9 },   //              ә       //
    { "schwacyrillic",                          0x04D9 },   //              ә       //
    { "Schwadieresiscyrillic",                  0x04DA },   //              Ӛ       //
    { "schwadieresiscyrillic",                  0x04DB },   //              ӛ       //
    { "Zhedieresiscyrillic",                    0x04DC },   //              Ӝ       //
    { "zhedieresiscyrillic",                    0x04DD },   //              ӝ       //
    { "Zedieresiscyrillic",                     0x04DE },   //              Ӟ       //
    { "zedieresiscyrillic",                     0x04DF },   //              ӟ       //
    { "Dzeabkhasiancyrillic",                   0x04E0 },   //              Ӡ       //
    { "dzeabkhasiancyrillic",                   0x04E1 },   //              ӡ       //
    { "Imacroncyrillic",                        0x04E2 },   //              Ӣ       //
    { "imacroncyrillic",                        0x04E3 },   //              ӣ       //
    { "Idieresiscyrillic",                      0x04E4 },   //              Ӥ       //
    { "idieresiscyrillic",                      0x04E5 },   //              ӥ       //
    { "Odieresiscyrillic",                      0x04E6 },   //              Ӧ       //
    { "odieresiscyrillic",                      0x04E7 },   //              ӧ       //
    { "Obarredcyrillic",                        0x04E8 },   //              Ө       //
    { "obarredcyrillic",                        0x04E9 },   //              ө       //
    { "Obarreddieresiscyrillic",                0x04EA },   //              Ӫ       //
    { "obarreddieresiscyrillic",                0x04EB },   //              ӫ       //
    { "Umacroncyrillic",                        0x04EE },   //              Ӯ       //
    { "umacroncyrillic",                        0x04EF },   //              ӯ       //
    { "Udieresiscyrillic",                      0x04F0 },   //              Ӱ       //
    { "udieresiscyrillic",                      0x04F1 },   //              ӱ       //
    { "Uhungarumlautcyrillic",                  0x04F2 },   //              Ӳ       //
    { "uhungarumlautcyrillic",                  0x04F3 },   //              ӳ       //
    { "Chedieresiscyrillic",                    0x04F4 },   //              Ӵ       //
    { "chedieresiscyrillic",                    0x04F5 },   //              ӵ       //
    { "Yerudieresiscyrillic",                   0x04F8 },   //              Ӹ       //
    { "yerudieresiscyrillic",                   0x04F9 },   //              ӹ       //
    { "Aybarmenian",                            0x0531 },   //              Ա       //
    { "Benarmenian",                            0x0532 },   //              Բ       //
    { "Gimarmenian",                            0x0533 },   //              Գ       //
    { "Daarmenian",                             0x0534 },   //              Դ       //
    { "Echarmenian",                            0x0535 },   //              Ե       //
    { "Zaarmenian",                             0x0536 },   //              Զ       //
    { "Eharmenian",                             0x0537 },   //              Է       //
    { "Etarmenian",                             0x0538 },   //              Ը       //
    { "Toarmenian",                             0x0539 },   //              Թ       //
    { "Zhearmenian",                            0x053A },   //              Ժ       //
    { "Iniarmenian",                            0x053B },   //              Ի       //
    { "Liwnarmenian",                           0x053C },   //              Լ       //
    { "Xeharmenian",                            0x053D },   //              Խ       //
    { "Caarmenian",                             0x053E },   //              Ծ       //
    { "Kenarmenian",                            0x053F },   //              Կ       //
    { "Hoarmenian",                             0x0540 },   //              Հ       //
    { "Jaarmenian",                             0x0541 },   //              Ձ       //
    { "Ghadarmenian",                           0x0542 },   //              Ղ       //
    { "Cheharmenian",                           0x0543 },   //              Ճ       //
    { "Menarmenian",                            0x0544 },   //              Մ       //
    { "Yiarmenian",                             0x0545 },   //              Յ       //
    { "Nowarmenian",                            0x0546 },   //              Ն       //
    { "Shaarmenian",                            0x0547 },   //              Շ       //
    { "Voarmenian",                             0x0548 },   //              Ո       //
    { "Chaarmenian",                            0x0549 },   //              Չ       //
    { "Peharmenian",                            0x054A },   //              Պ       //
    { "Jheharmenian",                           0x054B },   //              Ջ       //
    { "Raarmenian",                             0x054C },   //              Ռ       //
    { "Seharmenian",                            0x054D },   //              Ս       //
    { "Vewarmenian",                            0x054E },   //              Վ       //
    { "Tiwnarmenian",                           0x054F },   //              Տ       //
    { "Reharmenian",                            0x0550 },   //              Ր       //
    { "Coarmenian",                             0x0551 },   //              Ց       //
    { "Yiwnarmenian",                           0x0552 },   //              Ւ       //
    { "Piwrarmenian",                           0x0553 },   //              Փ       //
    { "Keharmenian",                            0x0554 },   //              Ք       //
    { "Oharmenian",                             0x0555 },   //              Օ       //
    { "Feharmenian",                            0x0556 },   //              Ֆ       //
    { "ringhalfleftarmenian",                   0x0559 },   //              ՙ       //
    { "apostrophearmenian",                     0x055A },   //              ՚       //
    { "emphasismarkarmenian",                   0x055B },   //              ՛       //
    { "exclamarmenian",                         0x055C },   //              ՜       //
    { "commaarmenian",                          0x055D },   //              ՝       //
    { "questionarmenian",                       0x055E },   //              ՞       //
    { "abbreviationmarkarmenian",               0x055F },   //              ՟       //
    { "aybarmenian",                            0x0561 },   //              ա       //
    { "benarmenian",                            0x0562 },   //              բ       //
    { "gimarmenian",                            0x0563 },   //              գ       //
    { "daarmenian",                             0x0564 },   //              դ       //
    { "echarmenian",                            0x0565 },   //              ե       //
    { "zaarmenian",                             0x0566 },   //              զ       //
    { "eharmenian",                             0x0567 },   //              է       //
    { "etarmenian",                             0x0568 },   //              ը       //
    { "toarmenian",                             0x0569 },   //              թ       //
    { "zhearmenian",                            0x056A },   //              ժ       //
    { "iniarmenian",                            0x056B },   //              ի       //
    { "liwnarmenian",                           0x056C },   //              լ       //
    { "xeharmenian",                            0x056D },   //              խ       //
    { "caarmenian",                             0x056E },   //              ծ       //
    { "kenarmenian",                            0x056F },   //              կ       //
    { "hoarmenian",                             0x0570 },   //              հ       //
    { "jaarmenian",                             0x0571 },   //              ձ       //
    { "ghadarmenian",                           0x0572 },   //              ղ       //
    { "cheharmenian",                           0x0573 },   //              ճ       //
    { "menarmenian",                            0x0574 },   //              մ       //
    { "yiarmenian",                             0x0575 },   //              յ       //
    { "nowarmenian",                            0x0576 },   //              ն       //
    { "shaarmenian",                            0x0577 },   //              շ       //
    { "voarmenian",                             0x0578 },   //              ո       //
    { "chaarmenian",                            0x0579 },   //              չ       //
    { "peharmenian",                            0x057A },   //              պ       //
    { "jheharmenian",                           0x057B },   //              ջ       //
    { "raarmenian",                             0x057C },   //              ռ       //
    { "seharmenian",                            0x057D },   //              ս       //
    { "vewarmenian",                            0x057E },   //              վ       //
    { "tiwnarmenian",                           0x057F },   //              տ       //
    { "reharmenian",                            0x0580 },   //              ր       //
    { "coarmenian",                             0x0581 },   //              ց       //
    { "yiwnarmenian",                           0x0582 },   //              ւ       //
    { "piwrarmenian",                           0x0583 },   //              փ       //
    { "keharmenian",                            0x0584 },   //              ք       //
    { "oharmenian",                             0x0585 },   //              օ       //
    { "feharmenian",                            0x0586 },   //              ֆ       //
    { "echyiwnarmenian",                        0x0587 },   //              և       //
    { "periodarmenian",                         0x0589 },   //              ։       //
    { "etnahtafoukhhebrew",                     0x0591 },   //              ֑       //
    { "etnahtafoukhlefthebrew",                 0x0591 },   //              ֑       //
    { "etnahtahebrew",                          0x0591 },   //              ֑       //
    { "etnahtalefthebrew",                      0x0591 },   //              ֑       //
    { "segoltahebrew",                          0x0592 },   //              ֒       //
    { "shalshelethebrew",                       0x0593 },   //              ֓       //
    { "zaqefqatanhebrew",                       0x0594 },   //              ֔       //
    { "zaqefgadolhebrew",                       0x0595 },   //              ֕       //
    { "tipehahebrew",                           0x0596 },   //              ֖       //
    { "tipehalefthebrew",                       0x0596 },   //              ֖       //
    { "reviahebrew",                            0x0597 },   //              ֗       //
    { "reviamugrashhebrew",                     0x0597 },   //              ֗       //
    { "zarqahebrew",                            0x0598 },   //              ֘       //
    { "pashtahebrew",                           0x0599 },   //              ֙       //
    { "yetivhebrew",                            0x059A },   //              ֚       //
    { "tevirhebrew",                            0x059B },   //              ֛       //
    { "tevirlefthebrew",                        0x059B },   //              ֛       //
    { "gereshaccenthebrew",                     0x059C },   //              ֜       //
    { "gereshmuqdamhebrew",                     0x059D },   //              ֝       //
    { "gershayimaccenthebrew",                  0x059E },   //              ֞       //
    { "qarneyparahebrew",                       0x059F },   //              ֟       //
    { "telishagedolahebrew",                    0x05A0 },   //              ֠       //
    { "pazerhebrew",                            0x05A1 },   //              ֡       //
    { "munahhebrew",                            0x05A3 },   //              ֣       //
    { "munahlefthebrew",                        0x05A3 },   //              ֣       //
    { "mahapakhhebrew",                         0x05A4 },   //              ֤       //
    { "mahapakhlefthebrew",                     0x05A4 },   //              ֤       //
    { "merkhahebrew",                           0x05A5 },   //              ֥       //
    { "merkhalefthebrew",                       0x05A5 },   //              ֥       //
    { "merkhakefulahebrew",                     0x05A6 },   //              ֦       //
    { "merkhakefulalefthebrew",                 0x05A6 },   //              ֦       //
    { "dargahebrew",                            0x05A7 },   //              ֧       //
    { "dargalefthebrew",                        0x05A7 },   //              ֧       //
    { "qadmahebrew",                            0x05A8 },   //              ֨       //
    { "telishaqetanahebrew",                    0x05A9 },   //              ֩       //
    { "yerahbenyomohebrew",                     0x05AA },   //              ֪       //
    { "yerahbenyomolefthebrew",                 0x05AA },   //              ֪       //
    { "olehebrew",                              0x05AB },   //              ֫       //
    { "iluyhebrew",                             0x05AC },   //              ֬       //
    { "dehihebrew",                             0x05AD },   //              ֭       //
    { "zinorhebrew",                            0x05AE },   //              ֮       //
    { "masoracirclehebrew",                     0x05AF },   //              ֯       //
    { "afii57799",                              0x05B0 },   //              ְ       //
    { "sheva",                                  0x05B0 },   //              ְ       //
    { "sheva115",                               0x05B0 },   //              ְ       //
    { "sheva15",                                0x05B0 },   //              ְ       //
    { "sheva22",                                0x05B0 },   //              ְ       //
    { "sheva2e",                                0x05B0 },   //              ְ       //
    { "shevahebrew",                            0x05B0 },   //              ְ       //
    { "shevanarrowhebrew",                      0x05B0 },   //              ְ       //
    { "shevaquarterhebrew",                     0x05B0 },   //              ְ       //
    { "shevawidehebrew",                        0x05B0 },   //              ְ       //
    { "afii57801",                              0x05B1 },   //              ֱ       //
    { "hatafsegol",                             0x05B1 },   //              ֱ       //
    { "hatafsegol17",                           0x05B1 },   //              ֱ       //
    { "hatafsegol24",                           0x05B1 },   //              ֱ       //
    { "hatafsegol30",                           0x05B1 },   //              ֱ       //
    { "hatafsegolhebrew",                       0x05B1 },   //              ֱ       //
    { "hatafsegolnarrowhebrew",                 0x05B1 },   //              ֱ       //
    { "hatafsegolquarterhebrew",                0x05B1 },   //              ֱ       //
    { "hatafsegolwidehebrew",                   0x05B1 },   //              ֱ       //
    { "afii57800",                              0x05B2 },   //              ֲ       //
    { "hatafpatah",                             0x05B2 },   //              ֲ       //
    { "hatafpatah16",                           0x05B2 },   //              ֲ       //
    { "hatafpatah23",                           0x05B2 },   //              ֲ       //
    { "hatafpatah2f",                           0x05B2 },   //              ֲ       //
    { "hatafpatahhebrew",                       0x05B2 },   //              ֲ       //
    { "hatafpatahnarrowhebrew",                 0x05B2 },   //              ֲ       //
    { "hatafpatahquarterhebrew",                0x05B2 },   //              ֲ       //
    { "hatafpatahwidehebrew",                   0x05B2 },   //              ֲ       //
    { "afii57802",                              0x05B3 },   //              ֳ       //
    { "hatafqamats",                            0x05B3 },   //              ֳ       //
    { "hatafqamats1b",                          0x05B3 },   //              ֳ       //
    { "hatafqamats28",                          0x05B3 },   //              ֳ       //
    { "hatafqamats34",                          0x05B3 },   //              ֳ       //
    { "hatafqamatshebrew",                      0x05B3 },   //              ֳ       //
    { "hatafqamatsnarrowhebrew",                0x05B3 },   //              ֳ       //
    { "hatafqamatsquarterhebrew",               0x05B3 },   //              ֳ       //
    { "hatafqamatswidehebrew",                  0x05B3 },   //              ֳ       //
    { "afii57793",                              0x05B4 },   //              ִ       //
    { "hiriq",                                  0x05B4 },   //              ִ       //
    { "hiriq14",                                0x05B4 },   //              ִ       //
    { "hiriq21",                                0x05B4 },   //              ִ       //
    { "hiriq2d",                                0x05B4 },   //              ִ       //
    { "hiriqhebrew",                            0x05B4 },   //              ִ       //
    { "hiriqnarrowhebrew",                      0x05B4 },   //              ִ       //
    { "hiriqquarterhebrew",                     0x05B4 },   //              ִ       //
    { "hiriqwidehebrew",                        0x05B4 },   //              ִ       //
    { "afii57794",                              0x05B5 },   //              ֵ       //
    { "tsere",                                  0x05B5 },   //              ֵ       //
    { "tsere12",                                0x05B5 },   //              ֵ       //
    { "tsere1e",                                0x05B5 },   //              ֵ       //
    { "tsere2b",                                0x05B5 },   //              ֵ       //
    { "tserehebrew",                            0x05B5 },   //              ֵ       //
    { "tserenarrowhebrew",                      0x05B5 },   //              ֵ       //
    { "tserequarterhebrew",                     0x05B5 },   //              ֵ       //
    { "tserewidehebrew",                        0x05B5 },   //              ֵ       //
    { "afii57795",                              0x05B6 },   //              ֶ       //
    { "segol",                                  0x05B6 },   //              ֶ       //
    { "segol13",                                0x05B6 },   //              ֶ       //
    { "segol1f",                                0x05B6 },   //              ֶ       //
    { "segol2c",                                0x05B6 },   //              ֶ       //
    { "segolhebrew",                            0x05B6 },   //              ֶ       //
    { "segolnarrowhebrew",                      0x05B6 },   //              ֶ       //
    { "segolquarterhebrew",                     0x05B6 },   //              ֶ       //
    { "segolwidehebrew",                        0x05B6 },   //              ֶ       //
    { "afii57798",                              0x05B7 },   //              ַ       //
    { "patah",                                  0x05B7 },   //              ַ       //
    { "patah11",                                0x05B7 },   //              ַ       //
    { "patah1d",                                0x05B7 },   //              ַ       //
    { "patah2a",                                0x05B7 },   //              ַ       //
    { "patahhebrew",                            0x05B7 },   //              ַ       //
    { "patahnarrowhebrew",                      0x05B7 },   //              ַ       //
    { "patahquarterhebrew",                     0x05B7 },   //              ַ       //
    { "patahwidehebrew",                        0x05B7 },   //              ַ       //
    { "afii57797",                              0x05B8 },   //              ָ       //
    { "qamats",                                 0x05B8 },   //              ָ       //
    { "qamats10",                               0x05B8 },   //              ָ       //
    { "qamats1a",                               0x05B8 },   //              ָ       //
    { "qamats1c",                               0x05B8 },   //              ָ       //
    { "qamats27",                               0x05B8 },   //              ָ       //
    { "qamats29",                               0x05B8 },   //              ָ       //
    { "qamats33",                               0x05B8 },   //              ָ       //
    { "qamatsde",                               0x05B8 },   //              ָ       //
    { "qamatshebrew",                           0x05B8 },   //              ָ       //
    { "qamatsnarrowhebrew",                     0x05B8 },   //              ָ       //
    { "qamatsqatanhebrew",                      0x05B8 },   //              ָ       //
    { "qamatsqatannarrowhebrew",                0x05B8 },   //              ָ       //
    { "qamatsqatanquarterhebrew",               0x05B8 },   //              ָ       //
    { "qamatsqatanwidehebrew",                  0x05B8 },   //              ָ       //
    { "qamatsquarterhebrew",                    0x05B8 },   //              ָ       //
    { "qamatswidehebrew",                       0x05B8 },   //              ָ       //
    { "afii57806",                              0x05B9 },   //              ֹ       //
    { "holam",                                  0x05B9 },   //              ֹ       //
    { "holam19",                                0x05B9 },   //              ֹ       //
    { "holam26",                                0x05B9 },   //              ֹ       //
    { "holam32",                                0x05B9 },   //              ֹ       //
    { "holamhebrew",                            0x05B9 },   //              ֹ       //
    { "holamnarrowhebrew",                      0x05B9 },   //              ֹ       //
    { "holamquarterhebrew",                     0x05B9 },   //              ֹ       //
    { "holamwidehebrew",                        0x05B9 },   //              ֹ       //
    { "afii57796",                              0x05BB },   //              ֻ       //
    { "qubuts",                                 0x05BB },   //              ֻ       //
    { "qubuts18",                               0x05BB },   //              ֻ       //
    { "qubuts25",                               0x05BB },   //              ֻ       //
    { "qubuts31",                               0x05BB },   //              ֻ       //
    { "qubutshebrew",                           0x05BB },   //              ֻ       //
    { "qubutsnarrowhebrew",                     0x05BB },   //              ֻ       //
    { "qubutsquarterhebrew",                    0x05BB },   //              ֻ       //
    { "qubutswidehebrew",                       0x05BB },   //              ֻ       //
    { "afii57807",                              0x05BC },   //              ּ       //
    { "dagesh",                                 0x05BC },   //              ּ       //
    { "dageshhebrew",                           0x05BC },   //              ּ       //
    { "afii57839",                              0x05BD },   //              ֽ       //
    { "siluqhebrew",                            0x05BD },   //              ֽ       //
    { "siluqlefthebrew",                        0x05BD },   //              ֽ       //
    { "afii57645",                              0x05BE },   //              ־       //
    { "maqafhebrew",                            0x05BE },   //              ־       //
    { "afii57841",                              0x05BF },   //              ֿ       //
    { "rafe",                                   0x05BF },   //              ֿ       //
    { "rafehebrew",                             0x05BF },   //              ֿ       //
    { "afii57842",                              0x05C0 },   //              ׀       //
    { "paseqhebrew",                            0x05C0 },   //              ׀       //
    { "afii57804",                              0x05C1 },   //              ׁ       //
    { "shindothebrew",                          0x05C1 },   //              ׁ       //
    { "afii57803",                              0x05C2 },   //              ׂ       //
    { "sindothebrew",                           0x05C2 },   //              ׂ       //
    { "afii57658",                              0x05C3 },   //              ׃       //
    { "sofpasuqhebrew",                         0x05C3 },   //              ׃       //
    { "upperdothebrew",                         0x05C4 },   //              ׄ       //
    { "afii57664",                              0x05D0 },   //              א       //
    { "alef",                                   0x05D0 },   //              א       //
    { "alefhebrew",                             0x05D0 },   //              א       //
    { "afii57665",                              0x05D1 },   //              ב       //
    { "bet",                                    0x05D1 },   //              ב       //
    { "bethebrew",                              0x05D1 },   //              ב       //
    { "afii57666",                              0x05D2 },   //              ג       //
    { "gimel",                                  0x05D2 },   //              ג       //
    { "gimelhebrew",                            0x05D2 },   //              ג       //
    { "afii57667",                              0x05D3 },   //              ד       //
    { "dalet",                                  0x05D3 },   //              ד       //
    { "dalethebrew",                            0x05D3 },   //              ד       //
    { "daletsheva",                             0x05D3 },   //              ד       //
    { "daletshevahebrew",                       0x05D3 },   //              ד       //
    { "dalethatafsegol",                        0x05D3 },   //              ד       //
    { "dalethatafsegolhebrew",                  0x05D3 },   //              ד       //
    { "dalethatafpatah",                        0x05D3 },   //              ד       //
    { "dalethatafpatahhebrew",                  0x05D3 },   //              ד       //
    { "dalethiriq",                             0x05D3 },   //              ד       //
    { "dalethiriqhebrew",                       0x05D3 },   //              ד       //
    { "dalettsere",                             0x05D3 },   //              ד       //
    { "dalettserehebrew",                       0x05D3 },   //              ד       //
    { "daletsegol",                             0x05D3 },   //              ד       //
    { "daletsegolhebrew",                       0x05D3 },   //              ד       //
    { "daletpatah",                             0x05D3 },   //              ד       //
    { "daletpatahhebrew",                       0x05D3 },   //              ד       //
    { "daletqamats",                            0x05D3 },   //              ד       //
    { "daletqamatshebrew",                      0x05D3 },   //              ד       //
    { "daletholam",                             0x05D3 },   //              ד       //
    { "daletholamhebrew",                       0x05D3 },   //              ד       //
    { "daletqubuts",                            0x05D3 },   //              ד       //
    { "daletqubutshebrew",                      0x05D3 },   //              ד       //
    { "afii57668",                              0x05D4 },   //              ה       //
    { "he",                                     0x05D4 },   //              ה       //
    { "hehebrew",                               0x05D4 },   //              ה       //
    { "afii57669",                              0x05D5 },   //              ו       //
    { "vav",                                    0x05D5 },   //              ו       //
    { "vavhebrew",                              0x05D5 },   //              ו       //
    { "afii57670",                              0x05D6 },   //              ז       //
    { "zayin",                                  0x05D6 },   //              ז       //
    { "zayinhebrew",                            0x05D6 },   //              ז       //
    { "afii57671",                              0x05D7 },   //              ח       //
    { "het",                                    0x05D7 },   //              ח       //
    { "hethebrew",                              0x05D7 },   //              ח       //
    { "afii57672",                              0x05D8 },   //              ט       //
    { "tet",                                    0x05D8 },   //              ט       //
    { "tethebrew",                              0x05D8 },   //              ט       //
    { "afii57673",                              0x05D9 },   //              י       //
    { "yod",                                    0x05D9 },   //              י       //
    { "yodhebrew",                              0x05D9 },   //              י       //
    { "afii57674",                              0x05DA },   //              ך       //
    { "finalkaf",                               0x05DA },   //              ך       //
    { "finalkafhebrew",                         0x05DA },   //              ך       //
    { "finalkafsheva",                          0x05DA },   //              ך       //
    { "finalkafshevahebrew",                    0x05DA },   //              ך       //
    { "finalkafqamats",                         0x05DA },   //              ך       //
    { "finalkafqamatshebrew",                   0x05DA },   //              ך       //
    { "afii57675",                              0x05DB },   //              כ       //
    { "kaf",                                    0x05DB },   //              כ       //
    { "kafhebrew",                              0x05DB },   //              כ       //
    { "afii57676",                              0x05DC },   //              ל       //
    { "lamed",                                  0x05DC },   //              ל       //
    { "lamedhebrew",                            0x05DC },   //              ל       //
    { "lamedholam",                             0x05DC },   //              ל       //
    { "lamedholamhebrew",                       0x05DC },   //              ל       //
    { "lamedholamdagesh",                       0x05DC },   //              ל       //
    { "lamedholamdageshhebrew",                 0x05DC },   //              ל       //
    { "afii57677",                              0x05DD },   //              ם       //
    { "finalmem",                               0x05DD },   //              ם       //
    { "finalmemhebrew",                         0x05DD },   //              ם       //
    { "afii57678",                              0x05DE },   //              מ       //
    { "mem",                                    0x05DE },   //              מ       //
    { "memhebrew",                              0x05DE },   //              מ       //
    { "afii57679",                              0x05DF },   //              ן       //
    { "finalnun",                               0x05DF },   //              ן       //
    { "finalnunhebrew",                         0x05DF },   //              ן       //
    { "afii57680",                              0x05E0 },   //              נ       //
    { "nun",                                    0x05E0 },   //              נ       //
    { "nunhebrew",                              0x05E0 },   //              נ       //
    { "afii57681",                              0x05E1 },   //              ס       //
    { "samekh",                                 0x05E1 },   //              ס       //
    { "samekhhebrew",                           0x05E1 },   //              ס       //
    { "afii57682",                              0x05E2 },   //              ע       //
    { "ayin",                                   0x05E2 },   //              ע       //
    { "ayinhebrew",                             0x05E2 },   //              ע       //
    { "afii57683",                              0x05E3 },   //              ף       //
    { "finalpe",                                0x05E3 },   //              ף       //
    { "finalpehebrew",                          0x05E3 },   //              ף       //
    { "afii57684",                              0x05E4 },   //              פ       //
    { "pe",                                     0x05E4 },   //              פ       //
    { "pehebrew",                               0x05E4 },   //              פ       //
    { "afii57685",                              0x05E5 },   //              ץ       //
    { "finaltsadi",                             0x05E5 },   //              ץ       //
    { "finaltsadihebrew",                       0x05E5 },   //              ץ       //
    { "afii57686",                              0x05E6 },   //              צ       //
    { "tsadi",                                  0x05E6 },   //              צ       //
    { "tsadihebrew",                            0x05E6 },   //              צ       //
    { "afii57687",                              0x05E7 },   //              ק       //
    { "qof",                                    0x05E7 },   //              ק       //
    { "qofhebrew",                              0x05E7 },   //              ק       //
    { "qofsheva",                               0x05E7 },   //              ק       //
    { "qofshevahebrew",                         0x05E7 },   //              ק       //
    { "qofhatafsegol",                          0x05E7 },   //              ק       //
    { "qofhatafsegolhebrew",                    0x05E7 },   //              ק       //
    { "qofhatafpatah",                          0x05E7 },   //              ק       //
    { "qofhatafpatahhebrew",                    0x05E7 },   //              ק       //
    { "qofhiriq",                               0x05E7 },   //              ק       //
    { "qofhiriqhebrew",                         0x05E7 },   //              ק       //
    { "qoftsere",                               0x05E7 },   //              ק       //
    { "qoftserehebrew",                         0x05E7 },   //              ק       //
    { "qofsegol",                               0x05E7 },   //              ק       //
    { "qofsegolhebrew",                         0x05E7 },   //              ק       //
    { "qofpatah",                               0x05E7 },   //              ק       //
    { "qofpatahhebrew",                         0x05E7 },   //              ק       //
    { "qofqamats",                              0x05E7 },   //              ק       //
    { "qofqamatshebrew",                        0x05E7 },   //              ק       //
    { "qofholam",                               0x05E7 },   //              ק       //
    { "qofholamhebrew",                         0x05E7 },   //              ק       //
    { "qofqubuts",                              0x05E7 },   //              ק       //
    { "qofqubutshebrew",                        0x05E7 },   //              ק       //
    { "afii57688",                              0x05E8 },   //              ר       //
    { "resh",                                   0x05E8 },   //              ר       //
    { "reshhebrew",                             0x05E8 },   //              ר       //
    { "reshsheva",                              0x05E8 },   //              ר       //
    { "reshshevahebrew",                        0x05E8 },   //              ר       //
    { "reshhatafsegol",                         0x05E8 },   //              ר       //
    { "reshhatafsegolhebrew",                   0x05E8 },   //              ר       //
    { "reshhatafpatah",                         0x05E8 },   //              ר       //
    { "reshhatafpatahhebrew",                   0x05E8 },   //              ר       //
    { "reshhiriq",                              0x05E8 },   //              ר       //
    { "reshhiriqhebrew",                        0x05E8 },   //              ר       //
    { "reshtsere",                              0x05E8 },   //              ר       //
    { "reshtserehebrew",                        0x05E8 },   //              ר       //
    { "reshsegol",                              0x05E8 },   //              ר       //
    { "reshsegolhebrew",                        0x05E8 },   //              ר       //
    { "reshpatah",                              0x05E8 },   //              ר       //
    { "reshpatahhebrew",                        0x05E8 },   //              ר       //
    { "reshqamats",                             0x05E8 },   //              ר       //
    { "reshqamatshebrew",                       0x05E8 },   //              ר       //
    { "reshholam",                              0x05E8 },   //              ר       //
    { "reshholamhebrew",                        0x05E8 },   //              ר       //
    { "reshqubuts",                             0x05E8 },   //              ר       //
    { "reshqubutshebrew",                       0x05E8 },   //              ר       //
    { "afii57689",                              0x05E9 },   //              ש       //
    { "shin",                                   0x05E9 },   //              ש       //
    { "shinhebrew",                             0x05E9 },   //              ש       //
    { "afii57690",                              0x05EA },   //              ת       //
    { "tav",                                    0x05EA },   //              ת       //
    { "tavhebrew",                              0x05EA },   //              ת       //
    { "afii57716",                              0x05F0 },   //              װ       //
    { "vavvavhebrew",                           0x05F0 },   //              װ       //
    { "afii57717",                              0x05F1 },   //              ױ       //
    { "vavyodhebrew",                           0x05F1 },   //              ױ       //
    { "afii57718",                              0x05F2 },   //              ײ       //
    { "yodyodhebrew",                           0x05F2 },   //              ײ       //
    { "gereshhebrew",                           0x05F3 },   //              ׳       //
    { "gershayimhebrew",                        0x05F4 },   //              ״       //
    { "afii57388",                              0x060C },   //              ،       //
    { "commaarabic",                            0x060C },   //              ،       //
    { "afii57403",                              0x061B },   //              ؛       //
    { "semicolonarabic",                        0x061B },   //              ؛       //
    { "afii57407",                              0x061F },   //              ؟       //
    { "questionarabic",                         0x061F },   //              ؟       //
    { "afii57409",                              0x0621 },   //              ء       //
    { "hamzaarabic",                            0x0621 },   //              ء       //
    { "hamzalowarabic",                         0x0621 },   //              ء       //
    { "hamzafathatanarabic",                    0x0621 },   //              ء       //
    { "hamzadammatanarabic",                    0x0621 },   //              ء       //
    { "hamzalowkasratanarabic",                 0x0621 },   //              ء       //
    { "hamzafathaarabic",                       0x0621 },   //              ء       //
    { "hamzadammaarabic",                       0x0621 },   //              ء       //
    { "hamzalowkasraarabic",                    0x0621 },   //              ء       //
    { "hamzasukunarabic",                       0x0621 },   //              ء       //
    { "afii57410",                              0x0622 },   //              آ       //
    { "alefmaddaabovearabic",                   0x0622 },   //              آ       //
    { "afii57411",                              0x0623 },   //              أ       //
    { "alefhamzaabovearabic",                   0x0623 },   //              أ       //
    { "afii57412",                              0x0624 },   //              ؤ       //
    { "wawhamzaabovearabic",                    0x0624 },   //              ؤ       //
    { "afii57413",                              0x0625 },   //              إ       //
    { "alefhamzabelowarabic",                   0x0625 },   //              إ       //
    { "afii57414",                              0x0626 },   //              ئ       //
    { "yehhamzaabovearabic",                    0x0626 },   //              ئ       //
    { "afii57415",                              0x0627 },   //              ا       //
    { "alefarabic",                             0x0627 },   //              ا       //
    { "afii57416",                              0x0628 },   //              ب       //
    { "beharabic",                              0x0628 },   //              ب       //
    { "afii57417",                              0x0629 },   //              ة       //
    { "tehmarbutaarabic",                       0x0629 },   //              ة       //
    { "afii57418",                              0x062A },   //              ت       //
    { "teharabic",                              0x062A },   //              ت       //
    { "afii57419",                              0x062B },   //              ث       //
    { "theharabic",                             0x062B },   //              ث       //
    { "afii57420",                              0x062C },   //              ج       //
    { "jeemarabic",                             0x062C },   //              ج       //
    { "afii57421",                              0x062D },   //              ح       //
    { "haharabic",                              0x062D },   //              ح       //
    { "afii57422",                              0x062E },   //              خ       //
    { "khaharabic",                             0x062E },   //              خ       //
    { "afii57423",                              0x062F },   //              د       //
    { "dalarabic",                              0x062F },   //              د       //
    { "afii57424",                              0x0630 },   //              ذ       //
    { "thalarabic",                             0x0630 },   //              ذ       //
    { "afii57425",                              0x0631 },   //              ر       //
    { "reharabic",                              0x0631 },   //              ر       //
    { "rehyehaleflamarabic",                    0x0631 },   //              ر       //
    { "afii57426",                              0x0632 },   //              ز       //
    { "zainarabic",                             0x0632 },   //              ز       //
    { "afii57427",                              0x0633 },   //              س       //
    { "seenarabic",                             0x0633 },   //              س       //
    { "afii57428",                              0x0634 },   //              ش       //
    { "sheenarabic",                            0x0634 },   //              ش       //
    { "afii57429",                              0x0635 },   //              ص       //
    { "sadarabic",                              0x0635 },   //              ص       //
    { "afii57430",                              0x0636 },   //              ض       //
    { "dadarabic",                              0x0636 },   //              ض       //
    { "afii57431",                              0x0637 },   //              ط       //
    { "taharabic",                              0x0637 },   //              ط       //
    { "afii57432",                              0x0638 },   //              ظ       //
    { "zaharabic",                              0x0638 },   //              ظ       //
    { "afii57433",                              0x0639 },   //              ع       //
    { "ainarabic",                              0x0639 },   //              ع       //
    { "afii57434",                              0x063A },   //              غ       //
    { "ghainarabic",                            0x063A },   //              غ       //
    { "afii57440",                              0x0640 },   //              ـ       //
    { "kashidaautoarabic",                      0x0640 },   //              ـ       //
    { "kashidaautonosidebearingarabic",         0x0640 },   //              ـ       //
    { "tatweelarabic",                          0x0640 },   //              ـ       //
    { "afii57441",                              0x0641 },   //              ف       //
    { "feharabic",                              0x0641 },   //              ف       //
    { "afii57442",                              0x0642 },   //              ق       //
    { "qafarabic",                              0x0642 },   //              ق       //
    { "afii57443",                              0x0643 },   //              ك       //
    { "kafarabic",                              0x0643 },   //              ك       //
    { "afii57444",                              0x0644 },   //              ل       //
    { "lamarabic",                              0x0644 },   //              ل       //
    { "afii57445",                              0x0645 },   //              م       //
    { "meemarabic",                             0x0645 },   //              م       //
    { "afii57446",                              0x0646 },   //              ن       //
    { "noonarabic",                             0x0646 },   //              ن       //
    { "afii57470",                              0x0647 },   //              ه       //
    { "heharabic",                              0x0647 },   //              ه       //
    { "afii57448",                              0x0648 },   //              و       //
    { "wawarabic",                              0x0648 },   //              و       //
    { "afii57449",                              0x0649 },   //              ى       //
    { "alefmaksuraarabic",                      0x0649 },   //              ى       //
    { "afii57450",                              0x064A },   //              ي       //
    { "yeharabic",                              0x064A },   //              ي       //
    { "afii57451",                              0x064B },   //              ً       //
    { "fathatanarabic",                         0x064B },   //              ً       //
    { "afii57452",                              0x064C },   //              ٌ       //
    { "dammatanaltonearabic",                   0x064C },   //              ٌ       //
    { "dammatanarabic",                         0x064C },   //              ٌ       //
    { "afii57453",                              0x064D },   //              ٍ       //
    { "kasratanarabic",                         0x064D },   //              ٍ       //
    { "afii57454",                              0x064E },   //              َ       //
    { "fathaarabic",                            0x064E },   //              َ       //
    { "fathalowarabic",                         0x064E },   //              َ       //
    { "afii57455",                              0x064F },   //              ُ       //
    { "dammaarabic",                            0x064F },   //              ُ       //
    { "dammalowarabic",                         0x064F },   //              ُ       //
    { "afii57456",                              0x0650 },   //              ِ       //
    { "kasraarabic",                            0x0650 },   //              ِ       //
    { "afii57457",                              0x0651 },   //              ّ       //
    { "shaddaarabic",                           0x0651 },   //              ّ       //
    { "shaddafathatanarabic",                   0x0651 },   //              ّ       //
    { "afii57458",                              0x0652 },   //              ْ       //
    { "sukunarabic",                            0x0652 },   //              ْ       //
    { "afii57392",                              0x0660 },   //              ٠       //
    { "zeroarabic",                             0x0660 },   //              ٠       //
    { "zerohackarabic",                         0x0660 },   //              ٠       //
    { "afii57393",                              0x0661 },   //              ١       //
    { "onearabic",                              0x0661 },   //              ١       //
    { "onehackarabic",                          0x0661 },   //              ١       //
    { "afii57394",                              0x0662 },   //              ٢       //
    { "twoarabic",                              0x0662 },   //              ٢       //
    { "twohackarabic",                          0x0662 },   //              ٢       //
    { "afii57395",                              0x0663 },   //              ٣       //
    { "threearabic",                            0x0663 },   //              ٣       //
    { "threehackarabic",                        0x0663 },   //              ٣       //
    { "afii57396",                              0x0664 },   //              ٤       //
    { "fourarabic",                             0x0664 },   //              ٤       //
    { "fourhackarabic",                         0x0664 },   //              ٤       //
    { "afii57397",                              0x0665 },   //              ٥       //
    { "fivearabic",                             0x0665 },   //              ٥       //
    { "fivehackarabic",                         0x0665 },   //              ٥       //
    { "afii57398",                              0x0666 },   //              ٦       //
    { "sixarabic",                              0x0666 },   //              ٦       //
    { "sixhackarabic",                          0x0666 },   //              ٦       //
    { "afii57399",                              0x0667 },   //              ٧       //
    { "sevenarabic",                            0x0667 },   //              ٧       //
    { "sevenhackarabic",                        0x0667 },   //              ٧       //
    { "afii57400",                              0x0668 },   //              ٨       //
    { "eightarabic",                            0x0668 },   //              ٨       //
    { "eighthackarabic",                        0x0668 },   //              ٨       //
    { "afii57401",                              0x0669 },   //              ٩       //
    { "ninearabic",                             0x0669 },   //              ٩       //
    { "ninehackarabic",                         0x0669 },   //              ٩       //
    { "afii57381",                              0x066A },   //              ٪       //
    { "percentarabic",                          0x066A },   //              ٪       //
    { "decimalseparatorarabic",                 0x066B },   //              ٫       //
    { "decimalseparatorpersian",                0x066B },   //              ٫       //
    { "thousandsseparatorarabic",               0x066C },   //              ٬       //
    { "thousandsseparatorpersian",              0x066C },   //              ٬       //
    { "afii63167",                              0x066D },   //              ٭       //
    { "asteriskaltonearabic",                   0x066D },   //              ٭       //
    { "asteriskarabic",                         0x066D },   //              ٭       //
    { "afii57511",                              0x0679 },   //              ٹ       //
    { "tteharabic",                             0x0679 },   //              ٹ       //
    { "afii57506",                              0x067E },   //              پ       //
    { "peharabic",                              0x067E },   //              پ       //
    { "afii57507",                              0x0686 },   //              چ       //
    { "tcheharabic",                            0x0686 },   //              چ       //
    { "afii57512",                              0x0688 },   //              ڈ       //
    { "ddalarabic",                             0x0688 },   //              ڈ       //
    { "afii57513",                              0x0691 },   //              ڑ       //
    { "rreharabic",                             0x0691 },   //              ڑ       //
    { "afii57508",                              0x0698 },   //              ژ       //
    { "jeharabic",                              0x0698 },   //              ژ       //
    { "afii57505",                              0x06A4 },   //              ڤ       //
    { "veharabic",                              0x06A4 },   //              ڤ       //
    { "afii57509",                              0x06AF },   //              گ       //
    { "gafarabic",                              0x06AF },   //              گ       //
    { "afii57514",                              0x06BA },   //              ں       //
    { "noonghunnaarabic",                       0x06BA },   //              ں       //
    { "haaltonearabic",                         0x06C1 },   //              ہ       //
    { "hehaltonearabic",                        0x06C1 },   //              ہ       //
    { "yehthreedotsbelowarabic",                0x06D1 },   //              ۑ       //
    { "afii57519",                              0x06D2 },   //              ے       //
    { "yehbarreearabic",                        0x06D2 },   //              ے       //
    { "afii57534",                              0x06D5 },   //              ە       //
    { "zeropersian",                            0x06F0 },   //              ۰       //
    { "onepersian",                             0x06F1 },   //              ۱       //
    { "twopersian",                             0x06F2 },   //              ۲       //
    { "threepersian",                           0x06F3 },   //              ۳       //
    { "fourpersian",                            0x06F4 },   //              ۴       //
    { "fivepersian",                            0x06F5 },   //              ۵       //
    { "sixpersian",                             0x06F6 },   //              ۶       //
    { "sevenpersian",                           0x06F7 },   //              ۷       //
    { "eightpersian",                           0x06F8 },   //              ۸       //
    { "ninepersian",                            0x06F9 },   //              ۹       //
    { "candrabindudeva",                        0x0901 },   //              ँ      //
    { "anusvaradeva",                           0x0902 },   //              ं      //
    { "visargadeva",                            0x0903 },   //              ः      //
    { "adeva",                                  0x0905 },   //              अ      //
    { "aadeva",                                 0x0906 },   //              आ      //
    { "ideva",                                  0x0907 },   //              इ      //
    { "iideva",                                 0x0908 },   //              ई      //
    { "udeva",                                  0x0909 },   //              उ      //
    { "uudeva",                                 0x090A },   //              ऊ      //
    { "rvocalicdeva",                           0x090B },   //              ऋ      //
    { "lvocalicdeva",                           0x090C },   //              ऌ      //
    { "ecandradeva",                            0x090D },   //              ऍ      //
    { "eshortdeva",                             0x090E },   //              ऎ      //
    { "edeva",                                  0x090F },   //              ए      //
    { "aideva",                                 0x0910 },   //              ऐ      //
    { "ocandradeva",                            0x0911 },   //              ऑ      //
    { "oshortdeva",                             0x0912 },   //              ऒ      //
    { "odeva",                                  0x0913 },   //              ओ      //
    { "audeva",                                 0x0914 },   //              औ      //
    { "kadeva",                                 0x0915 },   //              क      //
    { "khadeva",                                0x0916 },   //              ख      //
    { "gadeva",                                 0x0917 },   //              ग      //
    { "ghadeva",                                0x0918 },   //              घ      //
    { "ngadeva",                                0x0919 },   //              ङ      //
    { "cadeva",                                 0x091A },   //              च      //
    { "chadeva",                                0x091B },   //              छ      //
    { "jadeva",                                 0x091C },   //              ज      //
    { "jhadeva",                                0x091D },   //              झ      //
    { "nyadeva",                                0x091E },   //              ञ      //
    { "ttadeva",                                0x091F },   //              ट      //
    { "tthadeva",                               0x0920 },   //              ठ      //
    { "ddadeva",                                0x0921 },   //              ड      //
    { "ddhadeva",                               0x0922 },   //              ढ      //
    { "nnadeva",                                0x0923 },   //              ण      //
    { "tadeva",                                 0x0924 },   //              त      //
    { "thadeva",                                0x0925 },   //              थ      //
    { "dadeva",                                 0x0926 },   //              द      //
    { "dhadeva",                                0x0927 },   //              ध      //
    { "nadeva",                                 0x0928 },   //              न      //
    { "nnnadeva",                               0x0929 },   //              ऩ      //
    { "padeva",                                 0x092A },   //              प      //
    { "phadeva",                                0x092B },   //              फ      //
    { "badeva",                                 0x092C },   //              ब      //
    { "bhadeva",                                0x092D },   //              भ      //
    { "madeva",                                 0x092E },   //              म      //
    { "yadeva",                                 0x092F },   //              य      //
    { "radeva",                                 0x0930 },   //              र      //
    { "rradeva",                                0x0931 },   //              ऱ      //
    { "ladeva",                                 0x0932 },   //              ल      //
    { "lladeva",                                0x0933 },   //              ळ      //
    { "llladeva",                               0x0934 },   //              ऴ      //
    { "vadeva",                                 0x0935 },   //              व      //
    { "shadeva",                                0x0936 },   //              श      //
    { "ssadeva",                                0x0937 },   //              ष      //
    { "sadeva",                                 0x0938 },   //              स      //
    { "hadeva",                                 0x0939 },   //              ह      //
    { "nuktadeva",                              0x093C },   //              ़      //
    { "avagrahadeva",                           0x093D },   //              ऽ      //
    { "aavowelsigndeva",                        0x093E },   //              ा      //
    { "ivowelsigndeva",                         0x093F },   //              ि      //
    { "iivowelsigndeva",                        0x0940 },   //              ी      //
    { "uvowelsigndeva",                         0x0941 },   //              ु      //
    { "uuvowelsigndeva",                        0x0942 },   //              ू      //
    { "rvocalicvowelsigndeva",                  0x0943 },   //              ृ      //
    { "rrvocalicvowelsigndeva",                 0x0944 },   //              ॄ      //
    { "ecandravowelsigndeva",                   0x0945 },   //              ॅ      //
    { "eshortvowelsigndeva",                    0x0946 },   //              ॆ      //
    { "evowelsigndeva",                         0x0947 },   //              े      //
    { "aivowelsigndeva",                        0x0948 },   //              ै      //
    { "ocandravowelsigndeva",                   0x0949 },   //              ॉ      //
    { "oshortvowelsigndeva",                    0x094A },   //              ॊ      //
    { "ovowelsigndeva",                         0x094B },   //              ो      //
    { "auvowelsigndeva",                        0x094C },   //              ौ      //
    { "viramadeva",                             0x094D },   //              ्      //
    { "omdeva",                                 0x0950 },   //              ॐ      //
    { "udattadeva",                             0x0951 },   //              ॑      //
    { "anudattadeva",                           0x0952 },   //              ॒      //
    { "gravedeva",                              0x0953 },   //              ॓      //
    { "acutedeva",                              0x0954 },   //              ॔      //
    { "qadeva",                                 0x0958 },   //              क़      //
    { "khhadeva",                               0x0959 },   //              ख़      //
    { "ghhadeva",                               0x095A },   //              ग़      //
    { "zadeva",                                 0x095B },   //              ज़      //
    { "dddhadeva",                              0x095C },   //              ड़      //
    { "rhadeva",                                0x095D },   //              ढ़      //
    { "fadeva",                                 0x095E },   //              फ़      //
    { "yyadeva",                                0x095F },   //              य़      //
    { "rrvocalicdeva",                          0x0960 },   //              ॠ      //
    { "llvocalicdeva",                          0x0961 },   //              ॡ      //
    { "lvocalicvowelsigndeva",                  0x0962 },   //              ॢ      //
    { "llvocalicvowelsigndeva",                 0x0963 },   //              ॣ      //
    { "danda",                                  0x0964 },   //              ।      //
    { "dbldanda",                               0x0965 },   //              ॥      //
    { "zerodeva",                               0x0966 },   //              ०      //
    { "onedeva",                                0x0967 },   //              १      //
    { "twodeva",                                0x0968 },   //              २      //
    { "threedeva",                              0x0969 },   //              ३      //
    { "fourdeva",                               0x096A },   //              ४      //
    { "fivedeva",                               0x096B },   //              ५      //
    { "sixdeva",                                0x096C },   //              ६      //
    { "sevendeva",                              0x096D },   //              ७      //
    { "eightdeva",                              0x096E },   //              ८      //
    { "ninedeva",                               0x096F },   //              ९      //
    { "abbreviationsigndeva",                   0x0970 },   //              ॰      //
    { "candrabindubengali",                     0x0981 },   //              ঁ      //
    { "anusvarabengali",                        0x0982 },   //              ং      //
    { "visargabengali",                         0x0983 },   //              ঃ      //
    { "abengali",                               0x0985 },   //              অ      //
    { "aabengali",                              0x0986 },   //              আ      //
    { "ibengali",                               0x0987 },   //              ই      //
    { "iibengali",                              0x0988 },   //              ঈ      //
    { "ubengali",                               0x0989 },   //              উ      //
    { "uubengali",                              0x098A },   //              ঊ      //
    { "rvocalicbengali",                        0x098B },   //              ঋ      //
    { "lvocalicbengali",                        0x098C },   //              ঌ      //
    { "ebengali",                               0x098F },   //              এ      //
    { "aibengali",                              0x0990 },   //              ঐ      //
    { "obengali",                               0x0993 },   //              ও      //
    { "aubengali",                              0x0994 },   //              ঔ      //
    { "kabengali",                              0x0995 },   //              ক      //
    { "khabengali",                             0x0996 },   //              খ      //
    { "gabengali",                              0x0997 },   //              গ      //
    { "ghabengali",                             0x0998 },   //              ঘ      //
    { "ngabengali",                             0x0999 },   //              ঙ      //
    { "cabengali",                              0x099A },   //              চ      //
    { "chabengali",                             0x099B },   //              ছ      //
    { "jabengali",                              0x099C },   //              জ      //
    { "jhabengali",                             0x099D },   //              ঝ      //
    { "nyabengali",                             0x099E },   //              ঞ      //
    { "ttabengali",                             0x099F },   //              ট      //
    { "tthabengali",                            0x09A0 },   //              ঠ      //
    { "ddabengali",                             0x09A1 },   //              ড      //
    { "ddhabengali",                            0x09A2 },   //              ঢ      //
    { "nnabengali",                             0x09A3 },   //              ণ      //
    { "tabengali",                              0x09A4 },   //              ত      //
    { "thabengali",                             0x09A5 },   //              থ      //
    { "dabengali",                              0x09A6 },   //              দ      //
    { "dhabengali",                             0x09A7 },   //              ধ      //
    { "nabengali",                              0x09A8 },   //              ন      //
    { "pabengali",                              0x09AA },   //              প      //
    { "phabengali",                             0x09AB },   //              ফ      //
    { "babengali",                              0x09AC },   //              ব      //
    { "bhabengali",                             0x09AD },   //              ভ      //
    { "mabengali",                              0x09AE },   //              ম      //
    { "yabengali",                              0x09AF },   //              য      //
    { "rabengali",                              0x09B0 },   //              র      //
    { "labengali",                              0x09B2 },   //              ল      //
    { "shabengali",                             0x09B6 },   //              শ      //
    { "ssabengali",                             0x09B7 },   //              ষ      //
    { "sabengali",                              0x09B8 },   //              স      //
    { "habengali",                              0x09B9 },   //              হ      //
    { "nuktabengali",                           0x09BC },   //              ়      //
    { "aavowelsignbengali",                     0x09BE },   //              া      //
    { "ivowelsignbengali",                      0x09BF },   //              ি      //
    { "iivowelsignbengali",                     0x09C0 },   //              ী      //
    { "uvowelsignbengali",                      0x09C1 },   //              ু      //
    { "uuvowelsignbengali",                     0x09C2 },   //              ূ      //
    { "rvocalicvowelsignbengali",               0x09C3 },   //              ৃ      //
    { "rrvocalicvowelsignbengali",              0x09C4 },   //              ৄ      //
    { "evowelsignbengali",                      0x09C7 },   //              ে      //
    { "aivowelsignbengali",                     0x09C8 },   //              ৈ      //
    { "ovowelsignbengali",                      0x09CB },   //              ো      //
    { "auvowelsignbengali",                     0x09CC },   //              ৌ      //
    { "viramabengali",                          0x09CD },   //              ্      //
    { "aulengthmarkbengali",                    0x09D7 },   //              ৗ      //
    { "rrabengali",                             0x09DC },   //              ড়      //
    { "rhabengali",                             0x09DD },   //              ঢ়      //
    { "yyabengali",                             0x09DF },   //              য়      //
    { "rrvocalicbengali",                       0x09E0 },   //              ৠ      //
    { "llvocalicbengali",                       0x09E1 },   //              ৡ      //
    { "lvocalicvowelsignbengali",               0x09E2 },   //              ৢ      //
    { "llvocalicvowelsignbengali",              0x09E3 },   //              ৣ      //
    { "zerobengali",                            0x09E6 },   //              ০      //
    { "onebengali",                             0x09E7 },   //              ১      //
    { "twobengali",                             0x09E8 },   //              ২      //
    { "threebengali",                           0x09E9 },   //              ৩      //
    { "fourbengali",                            0x09EA },   //              ৪      //
    { "fivebengali",                            0x09EB },   //              ৫      //
    { "sixbengali",                             0x09EC },   //              ৬      //
    { "sevenbengali",                           0x09ED },   //              ৭      //
    { "eightbengali",                           0x09EE },   //              ৮      //
    { "ninebengali",                            0x09EF },   //              ৯      //
    { "ramiddlediagonalbengali",                0x09F0 },   //              ৰ      //
    { "ralowerdiagonalbengali",                 0x09F1 },   //              ৱ      //
    { "rupeemarkbengali",                       0x09F2 },   //              ৲      //
    { "rupeesignbengali",                       0x09F3 },   //              ৳      //
    { "onenumeratorbengali",                    0x09F4 },   //              ৴      //
    { "twonumeratorbengali",                    0x09F5 },   //              ৵      //
    { "threenumeratorbengali",                  0x09F6 },   //              ৶      //
    { "fournumeratorbengali",                   0x09F7 },   //              ৷      //
    { "denominatorminusonenumeratorbengali",    0x09F8 },   //              ৸      //
    { "sixteencurrencydenominatorbengali",      0x09F9 },   //              ৹      //
    { "issharbengali",                          0x09FA },   //              ৺      //
    { "bindigurmukhi",                          0x0A02 },   //              ਂ      //
    { "agurmukhi",                              0x0A05 },   //              ਅ      //
    { "aagurmukhi",                             0x0A06 },   //              ਆ      //
    { "igurmukhi",                              0x0A07 },   //              ਇ      //
    { "iigurmukhi",                             0x0A08 },   //              ਈ      //
    { "ugurmukhi",                              0x0A09 },   //              ਉ      //
    { "uugurmukhi",                             0x0A0A },   //              ਊ      //
    { "eegurmukhi",                             0x0A0F },   //              ਏ      //
    { "aigurmukhi",                             0x0A10 },   //              ਐ      //
    { "oogurmukhi",                             0x0A13 },   //              ਓ      //
    { "augurmukhi",                             0x0A14 },   //              ਔ      //
    { "kagurmukhi",                             0x0A15 },   //              ਕ      //
    { "khagurmukhi",                            0x0A16 },   //              ਖ      //
    { "gagurmukhi",                             0x0A17 },   //              ਗ      //
    { "ghagurmukhi",                            0x0A18 },   //              ਘ      //
    { "ngagurmukhi",                            0x0A19 },   //              ਙ      //
    { "cagurmukhi",                             0x0A1A },   //              ਚ      //
    { "chagurmukhi",                            0x0A1B },   //              ਛ      //
    { "jagurmukhi",                             0x0A1C },   //              ਜ      //
    { "jhagurmukhi",                            0x0A1D },   //              ਝ      //
    { "nyagurmukhi",                            0x0A1E },   //              ਞ      //
    { "ttagurmukhi",                            0x0A1F },   //              ਟ      //
    { "tthagurmukhi",                           0x0A20 },   //              ਠ      //
    { "ddagurmukhi",                            0x0A21 },   //              ਡ      //
    { "ddhagurmukhi",                           0x0A22 },   //              ਢ      //
    { "nnagurmukhi",                            0x0A23 },   //              ਣ      //
    { "tagurmukhi",                             0x0A24 },   //              ਤ      //
    { "thagurmukhi",                            0x0A25 },   //              ਥ      //
    { "dagurmukhi",                             0x0A26 },   //              ਦ      //
    { "dhagurmukhi",                            0x0A27 },   //              ਧ      //
    { "nagurmukhi",                             0x0A28 },   //              ਨ      //
    { "pagurmukhi",                             0x0A2A },   //              ਪ      //
    { "phagurmukhi",                            0x0A2B },   //              ਫ      //
    { "bagurmukhi",                             0x0A2C },   //              ਬ      //
    { "bhagurmukhi",                            0x0A2D },   //              ਭ      //
    { "magurmukhi",                             0x0A2E },   //              ਮ      //
    { "yagurmukhi",                             0x0A2F },   //              ਯ      //
    { "ragurmukhi",                             0x0A30 },   //              ਰ      //
    { "lagurmukhi",                             0x0A32 },   //              ਲ      //
    { "vagurmukhi",                             0x0A35 },   //              ਵ      //
    { "shagurmukhi",                            0x0A36 },   //              ਸ਼      //
    { "sagurmukhi",                             0x0A38 },   //              ਸ      //
    { "hagurmukhi",                             0x0A39 },   //              ਹ      //
    { "nuktagurmukhi",                          0x0A3C },   //              ਼      //
    { "aamatragurmukhi",                        0x0A3E },   //              ਾ      //
    { "imatragurmukhi",                         0x0A3F },   //              ਿ      //
    { "iimatragurmukhi",                        0x0A40 },   //              ੀ      //
    { "umatragurmukhi",                         0x0A41 },   //              ੁ      //
    { "uumatragurmukhi",                        0x0A42 },   //              ੂ      //
    { "eematragurmukhi",                        0x0A47 },   //              ੇ      //
    { "aimatragurmukhi",                        0x0A48 },   //              ੈ      //
    { "oomatragurmukhi",                        0x0A4B },   //              ੋ      //
    { "aumatragurmukhi",                        0x0A4C },   //              ੌ      //
    { "halantgurmukhi",                         0x0A4D },   //              ੍      //
    { "khhagurmukhi",                           0x0A59 },   //              ਖ਼      //
    { "ghhagurmukhi",                           0x0A5A },   //              ਗ਼      //
    { "zagurmukhi",                             0x0A5B },   //              ਜ਼      //
    { "rragurmukhi",                            0x0A5C },   //              ੜ      //
    { "fagurmukhi",                             0x0A5E },   //              ਫ਼      //
    { "zerogurmukhi",                           0x0A66 },   //              ੦      //
    { "onegurmukhi",                            0x0A67 },   //              ੧      //
    { "twogurmukhi",                            0x0A68 },   //              ੨      //
    { "threegurmukhi",                          0x0A69 },   //              ੩      //
    { "fourgurmukhi",                           0x0A6A },   //              ੪      //
    { "fivegurmukhi",                           0x0A6B },   //              ੫      //
    { "sixgurmukhi",                            0x0A6C },   //              ੬      //
    { "sevengurmukhi",                          0x0A6D },   //              ੭      //
    { "eightgurmukhi",                          0x0A6E },   //              ੮      //
    { "ninegurmukhi",                           0x0A6F },   //              ੯      //
    { "tippigurmukhi",                          0x0A70 },   //              ੰ      //
    { "addakgurmukhi",                          0x0A71 },   //              ੱ      //
    { "irigurmukhi",                            0x0A72 },   //              ੲ      //
    { "uragurmukhi",                            0x0A73 },   //              ੳ      //
    { "ekonkargurmukhi",                        0x0A74 },   //              ੴ      //
    { "candrabindugujarati",                    0x0A81 },   //              ઁ      //
    { "anusvaragujarati",                       0x0A82 },   //              ં      //
    { "visargagujarati",                        0x0A83 },   //              ઃ      //
    { "agujarati",                              0x0A85 },   //              અ      //
    { "aagujarati",                             0x0A86 },   //              આ      //
    { "igujarati",                              0x0A87 },   //              ઇ      //
    { "iigujarati",                             0x0A88 },   //              ઈ      //
    { "ugujarati",                              0x0A89 },   //              ઉ      //
    { "uugujarati",                             0x0A8A },   //              ઊ      //
    { "rvocalicgujarati",                       0x0A8B },   //              ઋ      //
    { "ecandragujarati",                        0x0A8D },   //              ઍ      //
    { "egujarati",                              0x0A8F },   //              એ      //
    { "aigujarati",                             0x0A90 },   //              ઐ      //
    { "ocandragujarati",                        0x0A91 },   //              ઑ      //
    { "ogujarati",                              0x0A93 },   //              ઓ      //
    { "augujarati",                             0x0A94 },   //              ઔ      //
    { "kagujarati",                             0x0A95 },   //              ક      //
    { "khagujarati",                            0x0A96 },   //              ખ      //
    { "gagujarati",                             0x0A97 },   //              ગ      //
    { "ghagujarati",                            0x0A98 },   //              ઘ      //
    { "ngagujarati",                            0x0A99 },   //              ઙ      //
    { "cagujarati",                             0x0A9A },   //              ચ      //
    { "chagujarati",                            0x0A9B },   //              છ      //
    { "jagujarati",                             0x0A9C },   //              જ      //
    { "jhagujarati",                            0x0A9D },   //              ઝ      //
    { "nyagujarati",                            0x0A9E },   //              ઞ      //
    { "ttagujarati",                            0x0A9F },   //              ટ      //
    { "tthagujarati",                           0x0AA0 },   //              ઠ      //
    { "ddagujarati",                            0x0AA1 },   //              ડ      //
    { "ddhagujarati",                           0x0AA2 },   //              ઢ      //
    { "nnagujarati",                            0x0AA3 },   //              ણ      //
    { "tagujarati",                             0x0AA4 },   //              ત      //
    { "thagujarati",                            0x0AA5 },   //              થ      //
    { "dagujarati",                             0x0AA6 },   //              દ      //
    { "dhagujarati",                            0x0AA7 },   //              ધ      //
    { "nagujarati",                             0x0AA8 },   //              ન      //
    { "pagujarati",                             0x0AAA },   //              પ      //
    { "phagujarati",                            0x0AAB },   //              ફ      //
    { "bagujarati",                             0x0AAC },   //              બ      //
    { "bhagujarati",                            0x0AAD },   //              ભ      //
    { "magujarati",                             0x0AAE },   //              મ      //
    { "yagujarati",                             0x0AAF },   //              ય      //
    { "ragujarati",                             0x0AB0 },   //              ર      //
    { "lagujarati",                             0x0AB2 },   //              લ      //
    { "llagujarati",                            0x0AB3 },   //              ળ      //
    { "vagujarati",                             0x0AB5 },   //              વ      //
    { "shagujarati",                            0x0AB6 },   //              શ      //
    { "ssagujarati",                            0x0AB7 },   //              ષ      //
    { "sagujarati",                             0x0AB8 },   //              સ      //
    { "hagujarati",                             0x0AB9 },   //              હ      //
    { "nuktagujarati",                          0x0ABC },   //              ઼      //
    { "aavowelsigngujarati",                    0x0ABE },   //              ા      //
    { "ivowelsigngujarati",                     0x0ABF },   //              િ      //
    { "iivowelsigngujarati",                    0x0AC0 },   //              ી      //
    { "uvowelsigngujarati",                     0x0AC1 },   //              ુ      //
    { "uuvowelsigngujarati",                    0x0AC2 },   //              ૂ      //
    { "rvocalicvowelsigngujarati",              0x0AC3 },   //              ૃ      //
    { "rrvocalicvowelsigngujarati",             0x0AC4 },   //              ૄ      //
    { "ecandravowelsigngujarati",               0x0AC5 },   //              ૅ      //
    { "evowelsigngujarati",                     0x0AC7 },   //              ે      //
    { "aivowelsigngujarati",                    0x0AC8 },   //              ૈ      //
    { "ocandravowelsigngujarati",               0x0AC9 },   //              ૉ      //
    { "ovowelsigngujarati",                     0x0ACB },   //              ો      //
    { "auvowelsigngujarati",                    0x0ACC },   //              ૌ      //
    { "viramagujarati",                         0x0ACD },   //              ્      //
    { "omgujarati",                             0x0AD0 },   //              ૐ      //
    { "rrvocalicgujarati",                      0x0AE0 },   //              ૠ      //
    { "zerogujarati",                           0x0AE6 },   //              ૦      //
    { "onegujarati",                            0x0AE7 },   //              ૧      //
    { "twogujarati",                            0x0AE8 },   //              ૨      //
    { "threegujarati",                          0x0AE9 },   //              ૩      //
    { "fourgujarati",                           0x0AEA },   //              ૪      //
    { "fivegujarati",                           0x0AEB },   //              ૫      //
    { "sixgujarati",                            0x0AEC },   //              ૬      //
    { "sevengujarati",                          0x0AED },   //              ૭      //
    { "eightgujarati",                          0x0AEE },   //              ૮      //
    { "ninegujarati",                           0x0AEF },   //              ૯      //
    { "kokaithai",                              0x0E01 },   //              ก      //
    { "khokhaithai",                            0x0E02 },   //              ข      //
    { "khokhuatthai",                           0x0E03 },   //              ฃ      //
    { "khokhwaithai",                           0x0E04 },   //              ค      //
    { "khokhonthai",                            0x0E05 },   //              ฅ      //
    { "khorakhangthai",                         0x0E06 },   //              ฆ      //
    { "ngonguthai",                             0x0E07 },   //              ง      //
    { "chochanthai",                            0x0E08 },   //              จ      //
    { "chochingthai",                           0x0E09 },   //              ฉ      //
    { "chochangthai",                           0x0E0A },   //              ช      //
    { "sosothai",                               0x0E0B },   //              ซ      //
    { "chochoethai",                            0x0E0C },   //              ฌ      //
    { "yoyingthai",                             0x0E0D },   //              ญ      //
    { "dochadathai",                            0x0E0E },   //              ฎ      //
    { "topatakthai",                            0x0E0F },   //              ฏ      //
    { "thothanthai",                            0x0E10 },   //              ฐ      //
    { "thonangmonthothai",                      0x0E11 },   //              ฑ      //
    { "thophuthaothai",                         0x0E12 },   //              ฒ      //
    { "nonenthai",                              0x0E13 },   //              ณ      //
    { "dodekthai",                              0x0E14 },   //              ด      //
    { "totaothai",                              0x0E15 },   //              ต      //
    { "thothungthai",                           0x0E16 },   //              ถ      //
    { "thothahanthai",                          0x0E17 },   //              ท      //
    { "thothongthai",                           0x0E18 },   //              ธ      //
    { "nonuthai",                               0x0E19 },   //              น      //
    { "bobaimaithai",                           0x0E1A },   //              บ      //
    { "poplathai",                              0x0E1B },   //              ป      //
    { "phophungthai",                           0x0E1C },   //              ผ      //
    { "fofathai",                               0x0E1D },   //              ฝ      //
    { "phophanthai",                            0x0E1E },   //              พ      //
    { "fofanthai",                              0x0E1F },   //              ฟ      //
    { "phosamphaothai",                         0x0E20 },   //              ภ      //
    { "momathai",                               0x0E21 },   //              ม      //
    { "yoyakthai",                              0x0E22 },   //              ย      //
    { "roruathai",                              0x0E23 },   //              ร      //
    { "ruthai",                                 0x0E24 },   //              ฤ      //
    { "lolingthai",                             0x0E25 },   //              ล      //
    { "luthai",                                 0x0E26 },   //              ฦ      //
    { "wowaenthai",                             0x0E27 },   //              ว      //
    { "sosalathai",                             0x0E28 },   //              ศ      //
    { "sorusithai",                             0x0E29 },   //              ษ      //
    { "sosuathai",                              0x0E2A },   //              ส      //
    { "hohipthai",                              0x0E2B },   //              ห      //
    { "lochulathai",                            0x0E2C },   //              ฬ      //
    { "oangthai",                               0x0E2D },   //              อ      //
    { "honokhukthai",                           0x0E2E },   //              ฮ      //
    { "paiyannoithai",                          0x0E2F },   //              ฯ      //
    { "saraathai",                              0x0E30 },   //              ะ      //
    { "maihanakatthai",                         0x0E31 },   //              ั      //
    { "saraaathai",                             0x0E32 },   //              า      //
    { "saraamthai",                             0x0E33 },   //              ำ      //
    { "saraithai",                              0x0E34 },   //              ิ      //
    { "saraiithai",                             0x0E35 },   //              ี      //
    { "sarauethai",                             0x0E36 },   //              ึ      //
    { "saraueethai",                            0x0E37 },   //              ื      //
    { "sarauthai",                              0x0E38 },   //              ุ      //
    { "sarauuthai",                             0x0E39 },   //              ู      //
    { "phinthuthai",                            0x0E3A },   //              ฺ      //
    { "bahtthai",                               0x0E3F },   //              ฿      //
    { "saraethai",                              0x0E40 },   //              เ      //
    { "saraaethai",                             0x0E41 },   //              แ      //
    { "saraothai",                              0x0E42 },   //              โ      //
    { "saraaimaimuanthai",                      0x0E43 },   //              ใ      //
    { "saraaimaimalaithai",                     0x0E44 },   //              ไ      //
    { "lakkhangyaothai",                        0x0E45 },   //              ๅ      //
    { "maiyamokthai",                           0x0E46 },   //              ๆ      //
    { "maitaikhuthai",                          0x0E47 },   //              ็      //
    { "maiekthai",                              0x0E48 },   //              ่      //
    { "maithothai",                             0x0E49 },   //              ้      //
    { "maitrithai",                             0x0E4A },   //              ๊      //
    { "maichattawathai",                        0x0E4B },   //              ๋      //
    { "thanthakhatthai",                        0x0E4C },   //              ์      //
    { "nikhahitthai",                           0x0E4D },   //              ํ      //
    { "yamakkanthai",                           0x0E4E },   //              ๎      //
    { "fongmanthai",                            0x0E4F },   //              ๏      //
    { "zerothai",                               0x0E50 },   //              ๐      //
    { "onethai",                                0x0E51 },   //              ๑      //
    { "twothai",                                0x0E52 },   //              ๒      //
    { "threethai",                              0x0E53 },   //              ๓      //
    { "fourthai",                               0x0E54 },   //              ๔      //
    { "fivethai",                               0x0E55 },   //              ๕      //
    { "sixthai",                                0x0E56 },   //              ๖      //
    { "seventhai",                              0x0E57 },   //              ๗      //
    { "eightthai",                              0x0E58 },   //              ๘      //
    { "ninethai",                               0x0E59 },   //              ๙      //
    { "angkhankhuthai",                         0x0E5A },   //              ๚      //
    { "khomutthai",                             0x0E5B },   //              ๛      //
    { "Aringbelow",                             0x1E00 },   //              Ḁ      //
    { "aringbelow",                             0x1E01 },   //              ḁ      //
    { "Bdotaccent",                             0x1E02 },   //              Ḃ      //
    { "bdotaccent",                             0x1E03 },   //              ḃ      //
    { "Bdotbelow",                              0x1E04 },   //              Ḅ      //
    { "bdotbelow",                              0x1E05 },   //              ḅ      //
    { "Blinebelow",                             0x1E06 },   //              Ḇ      //
    { "blinebelow",                             0x1E07 },   //              ḇ      //
    { "Ccedillaacute",                          0x1E08 },   //              Ḉ      //
    { "ccedillaacute",                          0x1E09 },   //              ḉ      //
    { "Ddotaccent",                             0x1E0A },   //              Ḋ      //
    { "ddotaccent",                             0x1E0B },   //              ḋ      //
    { "Ddotbelow",                              0x1E0C },   //              Ḍ      //
    { "ddotbelow",                              0x1E0D },   //              ḍ      //
    { "Dlinebelow",                             0x1E0E },   //              Ḏ      //
    { "dlinebelow",                             0x1E0F },   //              ḏ      //
    { "Dcedilla",                               0x1E10 },   //              Ḑ      //
    { "dcedilla",                               0x1E11 },   //              ḑ      //
    { "Dcircumflexbelow",                       0x1E12 },   //              Ḓ      //
    { "dcircumflexbelow",                       0x1E13 },   //              ḓ      //
    { "Emacrongrave",                           0x1E14 },   //              Ḕ      //
    { "emacrongrave",                           0x1E15 },   //              ḕ      //
    { "Emacronacute",                           0x1E16 },   //              Ḗ      //
    { "emacronacute",                           0x1E17 },   //              ḗ      //
    { "Ecircumflexbelow",                       0x1E18 },   //              Ḙ      //
    { "ecircumflexbelow",                       0x1E19 },   //              ḙ      //
    { "Etildebelow",                            0x1E1A },   //              Ḛ      //
    { "etildebelow",                            0x1E1B },   //              ḛ      //
    { "Ecedillabreve",                          0x1E1C },   //              Ḝ      //
    { "ecedillabreve",                          0x1E1D },   //              ḝ      //
    { "Fdotaccent",                             0x1E1E },   //              Ḟ      //
    { "fdotaccent",                             0x1E1F },   //              ḟ      //
    { "Gmacron",                                0x1E20 },   //              Ḡ      //
    { "gmacron",                                0x1E21 },   //              ḡ      //
    { "Hdotaccent",                             0x1E22 },   //              Ḣ      //
    { "hdotaccent",                             0x1E23 },   //              ḣ      //
    { "Hdotbelow",                              0x1E24 },   //              Ḥ      //
    { "hdotbelow",                              0x1E25 },   //              ḥ      //
    { "Hdieresis",                              0x1E26 },   //              Ḧ      //
    { "hdieresis",                              0x1E27 },   //              ḧ      //
    { "Hcedilla",                               0x1E28 },   //              Ḩ      //
    { "hcedilla",                               0x1E29 },   //              ḩ      //
    { "Hbrevebelow",                            0x1E2A },   //              Ḫ      //
    { "hbrevebelow",                            0x1E2B },   //              ḫ      //
    { "Itildebelow",                            0x1E2C },   //              Ḭ      //
    { "itildebelow",                            0x1E2D },   //              ḭ      //
    { "Idieresisacute",                         0x1E2E },   //              Ḯ      //
    { "idieresisacute",                         0x1E2F },   //              ḯ      //
    { "Kacute",                                 0x1E30 },   //              Ḱ      //
    { "kacute",                                 0x1E31 },   //              ḱ      //
    { "Kdotbelow",                              0x1E32 },   //              Ḳ      //
    { "kdotbelow",                              0x1E33 },   //              ḳ      //
    { "Klinebelow",                             0x1E34 },   //              Ḵ      //
    { "klinebelow",                             0x1E35 },   //              ḵ      //
    { "Ldotbelow",                              0x1E36 },   //              Ḷ      //
    { "ldotbelow",                              0x1E37 },   //              ḷ      //
    { "Ldotbelowmacron",                        0x1E38 },   //              Ḹ      //
    { "ldotbelowmacron",                        0x1E39 },   //              ḹ      //
    { "Llinebelow",                             0x1E3A },   //              Ḻ      //
    { "llinebelow",                             0x1E3B },   //              ḻ      //
    { "Lcircumflexbelow",                       0x1E3C },   //              Ḽ      //
    { "lcircumflexbelow",                       0x1E3D },   //              ḽ      //
    { "Macute",                                 0x1E3E },   //              Ḿ      //
    { "macute",                                 0x1E3F },   //              ḿ      //
    { "Mdotaccent",                             0x1E40 },   //              Ṁ      //
    { "mdotaccent",                             0x1E41 },   //              ṁ      //
    { "Mdotbelow",                              0x1E42 },   //              Ṃ      //
    { "mdotbelow",                              0x1E43 },   //              ṃ      //
    { "Ndotaccent",                             0x1E44 },   //              Ṅ      //
    { "ndotaccent",                             0x1E45 },   //              ṅ      //
    { "Ndotbelow",                              0x1E46 },   //              Ṇ      //
    { "ndotbelow",                              0x1E47 },   //              ṇ      //
    { "Nlinebelow",                             0x1E48 },   //              Ṉ      //
    { "nlinebelow",                             0x1E49 },   //              ṉ      //
    { "Ncircumflexbelow",                       0x1E4A },   //              Ṋ      //
    { "ncircumflexbelow",                       0x1E4B },   //              ṋ      //
    { "Otildeacute",                            0x1E4C },   //              Ṍ      //
    { "otildeacute",                            0x1E4D },   //              ṍ      //
    { "Otildedieresis",                         0x1E4E },   //              Ṏ      //
    { "otildedieresis",                         0x1E4F },   //              ṏ      //
    { "Omacrongrave",                           0x1E50 },   //              Ṑ      //
    { "omacrongrave",                           0x1E51 },   //              ṑ      //
    { "Omacronacute",                           0x1E52 },   //              Ṓ      //
    { "omacronacute",                           0x1E53 },   //              ṓ      //
    { "Pacute",                                 0x1E54 },   //              Ṕ      //
    { "pacute",                                 0x1E55 },   //              ṕ      //
    { "Pdotaccent",                             0x1E56 },   //              Ṗ      //
    { "pdotaccent",                             0x1E57 },   //              ṗ      //
    { "Rdotaccent",                             0x1E58 },   //              Ṙ      //
    { "rdotaccent",                             0x1E59 },   //              ṙ      //
    { "Rdotbelow",                              0x1E5A },   //              Ṛ      //
    { "rdotbelow",                              0x1E5B },   //              ṛ      //
    { "Rdotbelowmacron",                        0x1E5C },   //              Ṝ      //
    { "rdotbelowmacron",                        0x1E5D },   //              ṝ      //
    { "Rlinebelow",                             0x1E5E },   //              Ṟ      //
    { "rlinebelow",                             0x1E5F },   //              ṟ      //
    { "Sdotaccent",                             0x1E60 },   //              Ṡ      //
    { "sdotaccent",                             0x1E61 },   //              ṡ      //
    { "Sdotbelow",                              0x1E62 },   //              Ṣ      //
    { "sdotbelow",                              0x1E63 },   //              ṣ      //
    { "Sacutedotaccent",                        0x1E64 },   //              Ṥ      //
    { "sacutedotaccent",                        0x1E65 },   //              ṥ      //
    { "Scarondotaccent",                        0x1E66 },   //              Ṧ      //
    { "scarondotaccent",                        0x1E67 },   //              ṧ      //
    { "Sdotbelowdotaccent",                     0x1E68 },   //              Ṩ      //
    { "sdotbelowdotaccent",                     0x1E69 },   //              ṩ      //
    { "Tdotaccent",                             0x1E6A },   //              Ṫ      //
    { "tdotaccent",                             0x1E6B },   //              ṫ      //
    { "Tdotbelow",                              0x1E6C },   //              Ṭ      //
    { "tdotbelow",                              0x1E6D },   //              ṭ      //
    { "Tlinebelow",                             0x1E6E },   //              Ṯ      //
    { "tlinebelow",                             0x1E6F },   //              ṯ      //
    { "Tcircumflexbelow",                       0x1E70 },   //              Ṱ      //
    { "tcircumflexbelow",                       0x1E71 },   //              ṱ      //
    { "Udieresisbelow",                         0x1E72 },   //              Ṳ      //
    { "udieresisbelow",                         0x1E73 },   //              ṳ      //
    { "Utildebelow",                            0x1E74 },   //              Ṵ      //
    { "utildebelow",                            0x1E75 },   //              ṵ      //
    { "Ucircumflexbelow",                       0x1E76 },   //              Ṷ      //
    { "ucircumflexbelow",                       0x1E77 },   //              ṷ      //
    { "Utildeacute",                            0x1E78 },   //              Ṹ      //
    { "utildeacute",                            0x1E79 },   //              ṹ      //
    { "Umacrondieresis",                        0x1E7A },   //              Ṻ      //
    { "umacrondieresis",                        0x1E7B },   //              ṻ      //
    { "Vtilde",                                 0x1E7C },   //              Ṽ      //
    { "vtilde",                                 0x1E7D },   //              ṽ      //
    { "Vdotbelow",                              0x1E7E },   //              Ṿ      //
    { "vdotbelow",                              0x1E7F },   //              ṿ      //
    { "Wgrave",                                 0x1E80 },   //              Ẁ      //
    { "wgrave",                                 0x1E81 },   //              ẁ      //
    { "Wacute",                                 0x1E82 },   //              Ẃ      //
    { "wacute",                                 0x1E83 },   //              ẃ      //
    { "Wdieresis",                              0x1E84 },   //              Ẅ      //
    { "wdieresis",                              0x1E85 },   //              ẅ      //
    { "Wdotaccent",                             0x1E86 },   //              Ẇ      //
    { "wdotaccent",                             0x1E87 },   //              ẇ      //
    { "Wdotbelow",                              0x1E88 },   //              Ẉ      //
    { "wdotbelow",                              0x1E89 },   //              ẉ      //
    { "Xdotaccent",                             0x1E8A },   //              Ẋ      //
    { "xdotaccent",                             0x1E8B },   //              ẋ      //
    { "Xdieresis",                              0x1E8C },   //              Ẍ      //
    { "xdieresis",                              0x1E8D },   //              ẍ      //
    { "Ydotaccent",                             0x1E8E },   //              Ẏ      //
    { "ydotaccent",                             0x1E8F },   //              ẏ      //
    { "Zcircumflex",                            0x1E90 },   //              Ẑ      //
    { "zcircumflex",                            0x1E91 },   //              ẑ      //
    { "Zdotbelow",                              0x1E92 },   //              Ẓ      //
    { "zdotbelow",                              0x1E93 },   //              ẓ      //
    { "Zlinebelow",                             0x1E94 },   //              Ẕ      //
    { "zlinebelow",                             0x1E95 },   //              ẕ      //
    { "hlinebelow",                             0x1E96 },   //              ẖ      //
    { "tdieresis",                              0x1E97 },   //              ẗ      //
    { "wring",                                  0x1E98 },   //              ẘ      //
    { "yring",                                  0x1E99 },   //              ẙ      //
    { "arighthalfring",                         0x1E9A },   //              ẚ      //
    { "slongdotaccent",                         0x1E9B },   //              ẛ      //
    { "Adotbelow",                              0x1EA0 },   //              Ạ      //
    { "adotbelow",                              0x1EA1 },   //              ạ      //
    { "Ahookabove",                             0x1EA2 },   //              Ả      //
    { "ahookabove",                             0x1EA3 },   //              ả      //
    { "Acircumflexacute",                       0x1EA4 },   //              Ấ      //
    { "acircumflexacute",                       0x1EA5 },   //              ấ      //
    { "Acircumflexgrave",                       0x1EA6 },   //              Ầ      //
    { "acircumflexgrave",                       0x1EA7 },   //              ầ      //
    { "Acircumflexhookabove",                   0x1EA8 },   //              Ẩ      //
    { "acircumflexhookabove",                   0x1EA9 },   //              ẩ      //
    { "Acircumflextilde",                       0x1EAA },   //              Ẫ      //
    { "acircumflextilde",                       0x1EAB },   //              ẫ      //
    { "Acircumflexdotbelow",                    0x1EAC },   //              Ậ      //
    { "acircumflexdotbelow",                    0x1EAD },   //              ậ      //
    { "Abreveacute",                            0x1EAE },   //              Ắ      //
    { "abreveacute",                            0x1EAF },   //              ắ      //
    { "Abrevegrave",                            0x1EB0 },   //              Ằ      //
    { "abrevegrave",                            0x1EB1 },   //              ằ      //
    { "Abrevehookabove",                        0x1EB2 },   //              Ẳ      //
    { "abrevehookabove",                        0x1EB3 },   //              ẳ      //
    { "Abrevetilde",                            0x1EB4 },   //              Ẵ      //
    { "abrevetilde",                            0x1EB5 },   //              ẵ      //
    { "Abrevedotbelow",                         0x1EB6 },   //              Ặ      //
    { "abrevedotbelow",                         0x1EB7 },   //              ặ      //
    { "Edotbelow",                              0x1EB8 },   //              Ẹ      //
    { "edotbelow",                              0x1EB9 },   //              ẹ      //
    { "Ehookabove",                             0x1EBA },   //              Ẻ      //
    { "ehookabove",                             0x1EBB },   //              ẻ      //
    { "Etilde",                                 0x1EBC },   //              Ẽ      //
    { "etilde",                                 0x1EBD },   //              ẽ      //
    { "Ecircumflexacute",                       0x1EBE },   //              Ế      //
    { "ecircumflexacute",                       0x1EBF },   //              ế      //
    { "Ecircumflexgrave",                       0x1EC0 },   //              Ề      //
    { "ecircumflexgrave",                       0x1EC1 },   //              ề      //
    { "Ecircumflexhookabove",                   0x1EC2 },   //              Ể      //
    { "ecircumflexhookabove",                   0x1EC3 },   //              ể      //
    { "Ecircumflextilde",                       0x1EC4 },   //              Ễ      //
    { "ecircumflextilde",                       0x1EC5 },   //              ễ      //
    { "Ecircumflexdotbelow",                    0x1EC6 },   //              Ệ      //
    { "ecircumflexdotbelow",                    0x1EC7 },   //              ệ      //
    { "Ihookabove",                             0x1EC8 },   //              Ỉ      //
    { "ihookabove",                             0x1EC9 },   //              ỉ      //
    { "Idotbelow",                              0x1ECA },   //              Ị      //
    { "idotbelow",                              0x1ECB },   //              ị      //
    { "Odotbelow",                              0x1ECC },   //              Ọ      //
    { "odotbelow",                              0x1ECD },   //              ọ      //
    { "Ohookabove",                             0x1ECE },   //              Ỏ      //
    { "ohookabove",                             0x1ECF },   //              ỏ      //
    { "Ocircumflexacute",                       0x1ED0 },   //              Ố      //
    { "ocircumflexacute",                       0x1ED1 },   //              ố      //
    { "Ocircumflexgrave",                       0x1ED2 },   //              Ồ      //
    { "ocircumflexgrave",                       0x1ED3 },   //              ồ      //
    { "Ocircumflexhookabove",                   0x1ED4 },   //              Ổ      //
    { "ocircumflexhookabove",                   0x1ED5 },   //              ổ      //
    { "Ocircumflextilde",                       0x1ED6 },   //              Ỗ      //
    { "ocircumflextilde",                       0x1ED7 },   //              ỗ      //
    { "Ocircumflexdotbelow",                    0x1ED8 },   //              Ộ      //
    { "ocircumflexdotbelow",                    0x1ED9 },   //              ộ      //
    { "Ohornacute",                             0x1EDA },   //              Ớ      //
    { "ohornacute",                             0x1EDB },   //              ớ      //
    { "Ohorngrave",                             0x1EDC },   //              Ờ      //
    { "ohorngrave",                             0x1EDD },   //              ờ      //
    { "Ohornhookabove",                         0x1EDE },   //              Ở      //
    { "ohornhookabove",                         0x1EDF },   //              ở      //
    { "Ohorntilde",                             0x1EE0 },   //              Ỡ      //
    { "ohorntilde",                             0x1EE1 },   //              ỡ      //
    { "Ohorndotbelow",                          0x1EE2 },   //              Ợ      //
    { "ohorndotbelow",                          0x1EE3 },   //              ợ      //
    { "Udotbelow",                              0x1EE4 },   //              Ụ      //
    { "udotbelow",                              0x1EE5 },   //              ụ      //
    { "Uhookabove",                             0x1EE6 },   //              Ủ      //
    { "uhookabove",                             0x1EE7 },   //              ủ      //
    { "Uhornacute",                             0x1EE8 },   //              Ứ      //
    { "uhornacute",                             0x1EE9 },   //              ứ      //
    { "Uhorngrave",                             0x1EEA },   //              Ừ      //
    { "uhorngrave",                             0x1EEB },   //              ừ      //
    { "Uhornhookabove",                         0x1EEC },   //              Ử      //
    { "uhornhookabove",                         0x1EED },   //              ử      //
    { "Uhorntilde",                             0x1EEE },   //              Ữ      //
    { "uhorntilde",                             0x1EEF },   //              ữ      //
    { "Uhorndotbelow",                          0x1EF0 },   //              Ự      //
    { "uhorndotbelow",                          0x1EF1 },   //              ự      //
    { "Ygrave",                                 0x1EF2 },   //              Ỳ      //
    { "ygrave",                                 0x1EF3 },   //              ỳ      //
    { "Ydotbelow",                              0x1EF4 },   //              Ỵ      //
    { "ydotbelow",                              0x1EF5 },   //              ỵ      //
    { "Yhookabove",                             0x1EF6 },   //              Ỷ      //
    { "yhookabove",                             0x1EF7 },   //              ỷ      //
    { "Ytilde",                                 0x1EF8 },   //              Ỹ      //
    { "ytilde",                                 0x1EF9 },   //              ỹ      //
    { "zerowidthspace",                         0x200B },   //              ​      //
    { "hyphentwo",                              0x2010 },   //              ‐      //
    { "figuredash",                             0x2012 },   //              ‒      //
    { "afii00208",                              0x2015 },   //              ―      //
    { "horizontalbar",                          0x2015 },   //              ―      //
    { "dblverticalbar",                         0x2016 },   //              ‖      //
    { "dbllowline",                             0x2017 },   //              ‗      //
    { "underscoredbl",                          0x2017 },   //              ‗      //
    { "quoteleftreversed",                      0x201B },   //              ‛      //
    { "quotereversed",                          0x201B },   //              ‛      //
    { "onedotenleader",                         0x2024 },   //              ․      //
    { "twodotenleader",                         0x2025 },   //              ‥      //
    { "twodotleader",                           0x2025 },   //              ‥      //
    { "afii61573",                              0x202C },   //              ‬      //
    { "afii61574",                              0x202D },   //              ‭      //
    { "afii61575",                              0x202E },   //              ‮      //
    { "primereversed",                          0x2035 },   //              ‵      //
    { "referencemark",                          0x203B },   //              ※      //
    { "exclamdbl",                              0x203C },   //              ‼      //
    { "asterism",                               0x2042 },   //              ⁂      //
    { "zerosuperior",                           0x2070 },   //              ⁰      //
    { "foursuperior",                           0x2074 },   //              ⁴      //
    { "fivesuperior",                           0x2075 },   //              ⁵      //
    { "sixsuperior",                            0x2076 },   //              ⁶      //
    { "sevensuperior",                          0x2077 },   //              ⁷      //
    { "eightsuperior",                          0x2078 },   //              ⁸      //
    { "ninesuperior",                           0x2079 },   //              ⁹      //
    { "plussuperior",                           0x207A },   //              ⁺      //
    { "equalsuperior",                          0x207C },   //              ⁼      //
    { "parenleftsuperior",                      0x207D },   //              ⁽      //
    { "parenrightsuperior",                     0x207E },   //              ⁾      //
    { "nsuperior",                              0x207F },   //              ⁿ      //
    { "zeroinferior",                           0x2080 },   //              ₀      //
    { "perthousandzero",                        0x2080 },   //              ₀      //
    { "oneinferior",                            0x2081 },   //              ₁      //
    { "twoinferior",                            0x2082 },   //              ₂      //
    { "threeinferior",                          0x2083 },   //              ₃      //
    { "fourinferior",                           0x2084 },   //              ₄      //
    { "fiveinferior",                           0x2085 },   //              ₅      //
    { "sixinferior",                            0x2086 },   //              ₆      //
    { "seveninferior",                          0x2087 },   //              ₇      //
    { "eightinferior",                          0x2088 },   //              ₈      //
    { "nineinferior",                           0x2089 },   //              ₉      //
    { "parenleftinferior",                      0x208D },   //              ₍      //
    { "parenrightinferior",                     0x208E },   //              ₎      //
    { "colonmonetary",                          0x20A1 },   //              ₡      //
    { "colonsign",                              0x20A1 },   //              ₡      //
    { "cruzeiro",                               0x20A2 },   //              ₢      //
    { "franc",                                  0x20A3 },   //              ₣      //
    { "afii08941",                              0x20A4 },   //              ₤      //
    { "lira",                                   0x20A4 },   //              ₤      //
    { "peseta",                                 0x20A7 },   //              ₧      //
    { "won",                                    0x20A9 },   //              ₩      //
    { "afii57636",                              0x20AA },   //              ₪      //
    { "newsheqelsign",                          0x20AA },   //              ₪      //
    { "sheqel",                                 0x20AA },   //              ₪      //
    { "sheqelhebrew",                           0x20AA },   //              ₪      //
    { "dong",                                   0x20AB },   //              ₫      //
    { "centigrade",                             0x2103 },   //              ℃      //
    { "afii61248",                              0x2105 },   //              ℅      //
    { "careof",                                 0x2105 },   //              ℅      //
    { "fahrenheit",                             0x2109 },   //              ℉      //
    { "afii61289",                              0x2113 },   //              ℓ      //
    { "lsquare",                                0x2113 },   //              ℓ      //
    { "afii61352",                              0x2116 },   //              №      //
    { "numero",                                 0x2116 },   //              №      //
    { "prescription",                           0x211E },   //              ℞      //
    { "telephone",                              0x2121 },   //              ℡      //
    { "Ohm",                                    0x2126 },   //              Ω      //
    { "Omega",                                  0x2126 },   //              Ω      //
    { "angstrom",                               0x212B },   //              Å      //
    { "estimated",                              0x212E },   //              ℮      //
    { "onethird",                               0x2153 },   //              ⅓      //
    { "twothirds",                              0x2154 },   //              ⅔      //
    { "oneeighth",                              0x215B },   //              ⅛      //
    { "threeeighths",                           0x215C },   //              ⅜      //
    { "fiveeighths",                            0x215D },   //              ⅝      //
    { "seveneighths",                           0x215E },   //              ⅞      //
    { "Oneroman",                               0x2160 },   //              Ⅰ      //
    { "Tworoman",                               0x2161 },   //              Ⅱ      //
    { "Threeroman",                             0x2162 },   //              Ⅲ      //
    { "Fourroman",                              0x2163 },   //              Ⅳ      //
    { "Fiveroman",                              0x2164 },   //              Ⅴ      //
    { "Sixroman",                               0x2165 },   //              Ⅵ      //
    { "Sevenroman",                             0x2166 },   //              Ⅶ      //
    { "Eightroman",                             0x2167 },   //              Ⅷ      //
    { "Nineroman",                              0x2168 },   //              Ⅸ      //
    { "Tenroman",                               0x2169 },   //              Ⅹ      //
    { "Elevenroman",                            0x216A },   //              Ⅺ      //
    { "Twelveroman",                            0x216B },   //              Ⅻ      //
    { "oneroman",                               0x2170 },   //              ⅰ      //
    { "tworoman",                               0x2171 },   //              ⅱ      //
    { "threeroman",                             0x2172 },   //              ⅲ      //
    { "fourroman",                              0x2173 },   //              ⅳ      //
    { "fiveroman",                              0x2174 },   //              ⅴ      //
    { "sixroman",                               0x2175 },   //              ⅵ      //
    { "sevenroman",                             0x2176 },   //              ⅶ      //
    { "eightroman",                             0x2177 },   //              ⅷ      //
    { "nineroman",                              0x2178 },   //              ⅸ      //
    { "tenroman",                               0x2179 },   //              ⅹ      //
    { "elevenroman",                            0x217A },   //              ⅺ      //
    { "twelveroman",                            0x217B },   //              ⅻ      //
    { "arrowupdn",                              0x2195 },   //              ↕      //
    { "arrowupleft",                            0x2196 },   //              ↖      //
    { "arrowupright",                           0x2197 },   //              ↗      //
    { "arrowdownright",                         0x2198 },   //              ↘      //
    { "arrowdownleft",                          0x2199 },   //              ↙      //
    { "arrowupdnbse",                           0x21A8 },   //              ↨      //
    { "arrowupdownbase",                        0x21A8 },   //              ↨      //
    { "harpoonleftbarbup",                      0x21BC },   //              ↼      //
    { "harpoonrightbarbup",                     0x21C0 },   //              ⇀      //
    { "arrowrightoverleft",                     0x21C4 },   //              ⇄      //
    { "arrowupleftofdown",                      0x21C5 },   //              ⇅      //
    { "arrowleftoverright",                     0x21C6 },   //              ⇆      //
    { "arrowleftdblstroke",                     0x21CD },   //              ⇍      //
    { "arrowrightdblstroke",                    0x21CF },   //              ⇏      //
    { "pageup",                                 0x21DE },   //              ⇞      //
    { "pagedown",                               0x21DF },   //              ⇟      //
    { "arrowdashleft",                          0x21E0 },   //              ⇠      //
    { "arrowdashup",                            0x21E1 },   //              ⇡      //
    { "arrowdashright",                         0x21E2 },   //              ⇢      //
    { "arrowdashdown",                          0x21E3 },   //              ⇣      //
    { "arrowtableft",                           0x21E4 },   //              ⇤      //
    { "arrowtabright",                          0x21E5 },   //              ⇥      //
    { "arrowleftwhite",                         0x21E6 },   //              ⇦      //
    { "arrowupwhite",                           0x21E7 },   //              ⇧      //
    { "arrowrightwhite",                        0x21E8 },   //              ⇨      //
    { "arrowdownwhite",                         0x21E9 },   //              ⇩      //
    { "capslock",                               0x21EA },   //              ⇪      //
    { "Delta",                                  0x2206 },   //              ∆      //
    { "increment",                              0x2206 },   //              ∆      //
    { "notcontains",                            0x220C },   //              ∌      //
    { "minusplus",                              0x2213 },   //              ∓      //
    { "divisionslash",                          0x2215 },   //              ∕      //
    { "bulletoperator",                         0x2219 },   //              ∙      //
    { "orthogonal",                             0x221F },   //              ∟      //
    { "rightangle",                             0x221F },   //              ∟      //
    { "divides",                                0x2223 },   //              ∣      //
    { "parallel",                               0x2225 },   //              ∥      //
    { "notparallel",                            0x2226 },   //              ∦      //
    { "dblintegral",                            0x222C },   //              ∬      //
    { "contourintegral",                        0x222E },   //              ∮      //
    { "because",                                0x2235 },   //              ∵      //
    { "ratio",                                  0x2236 },   //              ∶      //
    { "proportion",                             0x2237 },   //              ∷      //
    { "reversedtilde",                          0x223D },   //              ∽      //
    { "asymptoticallyequal",                    0x2243 },   //              ≃      //
    { "allequal",                               0x224C },   //              ≌      //
    { "approaches",                             0x2250 },   //              ≐      //
    { "geometricallyequal",                     0x2251 },   //              ≑      //
    { "approxequalorimage",                     0x2252 },   //              ≒      //
    { "imageorapproximatelyequal",              0x2253 },   //              ≓      //
    { "notidentical",                           0x2262 },   //              ≢      //
    { "lessoverequal",                          0x2266 },   //              ≦      //
    { "greateroverequal",                       0x2267 },   //              ≧      //
    { "muchless",                               0x226A },   //              ≪      //
    { "muchgreater",                            0x226B },   //              ≫      //
    { "notless",                                0x226E },   //              ≮      //
    { "notgreater",                             0x226F },   //              ≯      //
    { "notlessnorequal",                        0x2270 },   //              ≰      //
    { "notgreaternorequal",                     0x2271 },   //              ≱      //
    { "lessorequivalent",                       0x2272 },   //              ≲      //
    { "greaterorequivalent",                    0x2273 },   //              ≳      //
    { "lessorgreater",                          0x2276 },   //              ≶      //
    { "greaterorless",                          0x2277 },   //              ≷      //
    { "notgreaternorless",                      0x2279 },   //              ≹      //
    { "precedes",                               0x227A },   //              ≺      //
    { "succeeds",                               0x227B },   //              ≻      //
    { "notprecedes",                            0x2280 },   //              ⊀      //
    { "notsucceeds",                            0x2281 },   //              ⊁      //
    { "notsuperset",                            0x2285 },   //              ⊅      //
    { "subsetnotequal",                         0x228A },   //              ⊊      //
    { "supersetnotequal",                       0x228B },   //              ⊋      //
    { "minuscircle",                            0x2296 },   //              ⊖      //
    { "circleot",                               0x2299 },   //              ⊙      //
    { "tackleft",                               0x22A3 },   //              ⊣      //
    { "tackdown",                               0x22A4 },   //              ⊤      //
    { "righttriangle",                          0x22BF },   //              ⊿      //
    { "curlyor",                                0x22CE },   //              ⋎      //
    { "curlyand",                               0x22CF },   //              ⋏      //
    { "lessequalorgreater",                     0x22DA },   //              ⋚      //
    { "greaterequalorless",                     0x22DB },   //              ⋛      //
    { "ellipsisvertical",                       0x22EE },   //              ⋮      //
    { "house",                                  0x2302 },   //              ⌂      //
    { "control",                                0x2303 },   //              ⌃      //
    { "projective",                             0x2305 },   //              ⌅      //
    { "logicalnotreversed",                     0x2310 },   //              ⌐      //
    { "revlogicalnot",                          0x2310 },   //              ⌐      //
    { "arc",                                    0x2312 },   //              ⌒      //
    { "propellor",                              0x2318 },   //              ⌘      //
    { "integraltop",                            0x2320 },   //              ⌠      //
    { "integraltp",                             0x2320 },   //              ⌠      //
    { "integralbottom",                         0x2321 },   //              ⌡      //
    { "integralbt",                             0x2321 },   //              ⌡      //
    { "option",                                 0x2325 },   //              ⌥      //
    { "deleteright",                            0x2326 },   //              ⌦      //
    { "clear",                                  0x2327 },   //              ⌧      //
    { "deleteleft",                             0x232B },   //              ⌫      //
    { "blank",                                  0x2423 },   //              ␣      //
    { "onecircle",                              0x2460 },   //              ①      //
    { "twocircle",                              0x2461 },   //              ②      //
    { "threecircle",                            0x2462 },   //              ③      //
    { "fourcircle",                             0x2463 },   //              ④      //
    { "fivecircle",                             0x2464 },   //              ⑤      //
    { "sixcircle",                              0x2465 },   //              ⑥      //
    { "sevencircle",                            0x2466 },   //              ⑦      //
    { "eightcircle",                            0x2467 },   //              ⑧      //
    { "ninecircle",                             0x2468 },   //              ⑨      //
    { "tencircle",                              0x2469 },   //              ⑩      //
    { "elevencircle",                           0x246A },   //              ⑪      //
    { "twelvecircle",                           0x246B },   //              ⑫      //
    { "thirteencircle",                         0x246C },   //              ⑬      //
    { "fourteencircle",                         0x246D },   //              ⑭      //
    { "fifteencircle",                          0x246E },   //              ⑮      //
    { "sixteencircle",                          0x246F },   //              ⑯      //
    { "seventeencircle",                        0x2470 },   //              ⑰      //
    { "eighteencircle",                         0x2471 },   //              ⑱      //
    { "nineteencircle",                         0x2472 },   //              ⑲      //
    { "twentycircle",                           0x2473 },   //              ⑳      //
    { "oneparen",                               0x2474 },   //              ⑴      //
    { "twoparen",                               0x2475 },   //              ⑵      //
    { "threeparen",                             0x2476 },   //              ⑶      //
    { "fourparen",                              0x2477 },   //              ⑷      //
    { "fiveparen",                              0x2478 },   //              ⑸      //
    { "sixparen",                               0x2479 },   //              ⑹      //
    { "sevenparen",                             0x247A },   //              ⑺      //
    { "eightparen",                             0x247B },   //              ⑻      //
    { "nineparen",                              0x247C },   //              ⑼      //
    { "tenparen",                               0x247D },   //              ⑽      //
    { "elevenparen",                            0x247E },   //              ⑾      //
    { "twelveparen",                            0x247F },   //              ⑿      //
    { "thirteenparen",                          0x2480 },   //              ⒀      //
    { "fourteenparen",                          0x2481 },   //              ⒁      //
    { "fifteenparen",                           0x2482 },   //              ⒂      //
    { "sixteenparen",                           0x2483 },   //              ⒃      //
    { "seventeenparen",                         0x2484 },   //              ⒄      //
    { "eighteenparen",                          0x2485 },   //              ⒅      //
    { "nineteenparen",                          0x2486 },   //              ⒆      //
    { "twentyparen",                            0x2487 },   //              ⒇      //
    { "oneperiod",                              0x2488 },   //              ⒈      //
    { "twoperiod",                              0x2489 },   //              ⒉      //
    { "threeperiod",                            0x248A },   //              ⒊      //
    { "fourperiod",                             0x248B },   //              ⒋      //
    { "fiveperiod",                             0x248C },   //              ⒌      //
    { "sixperiod",                              0x248D },   //              ⒍      //
    { "sevenperiod",                            0x248E },   //              ⒎      //
    { "eightperiod",                            0x248F },   //              ⒏      //
    { "nineperiod",                             0x2490 },   //              ⒐      //
    { "tenperiod",                              0x2491 },   //              ⒑      //
    { "elevenperiod",                           0x2492 },   //              ⒒      //
    { "twelveperiod",                           0x2493 },   //              ⒓      //
    { "thirteenperiod",                         0x2494 },   //              ⒔      //
    { "fourteenperiod",                         0x2495 },   //              ⒕      //
    { "fifteenperiod",                          0x2496 },   //              ⒖      //
    { "sixteenperiod",                          0x2497 },   //              ⒗      //
    { "seventeenperiod",                        0x2498 },   //              ⒘      //
    { "eighteenperiod",                         0x2499 },   //              ⒙      //
    { "nineteenperiod",                         0x249A },   //              ⒚      //
    { "twentyperiod",                           0x249B },   //              ⒛      //
    { "aparen",                                 0x249C },   //              ⒜      //
    { "bparen",                                 0x249D },   //              ⒝      //
    { "cparen",                                 0x249E },   //              ⒞      //
    { "dparen",                                 0x249F },   //              ⒟      //
    { "eparen",                                 0x24A0 },   //              ⒠      //
    { "fparen",                                 0x24A1 },   //              ⒡      //
    { "gparen",                                 0x24A2 },   //              ⒢      //
    { "hparen",                                 0x24A3 },   //              ⒣      //
    { "iparen",                                 0x24A4 },   //              ⒤      //
    { "jparen",                                 0x24A5 },   //              ⒥      //
    { "kparen",                                 0x24A6 },   //              ⒦      //
    { "lparen",                                 0x24A7 },   //              ⒧      //
    { "mparen",                                 0x24A8 },   //              ⒨      //
    { "nparen",                                 0x24A9 },   //              ⒩      //
    { "oparen",                                 0x24AA },   //              ⒪      //
    { "pparen",                                 0x24AB },   //              ⒫      //
    { "qparen",                                 0x24AC },   //              ⒬      //
    { "rparen",                                 0x24AD },   //              ⒭      //
    { "sparen",                                 0x24AE },   //              ⒮      //
    { "tparen",                                 0x24AF },   //              ⒯      //
    { "uparen",                                 0x24B0 },   //              ⒰      //
    { "vparen",                                 0x24B1 },   //              ⒱      //
    { "wparen",                                 0x24B2 },   //              ⒲      //
    { "xparen",                                 0x24B3 },   //              ⒳      //
    { "yparen",                                 0x24B4 },   //              ⒴      //
    { "zparen",                                 0x24B5 },   //              ⒵      //
    { "Acircle",                                0x24B6 },   //              Ⓐ      //
    { "Bcircle",                                0x24B7 },   //              Ⓑ      //
    { "Ccircle",                                0x24B8 },   //              Ⓒ      //
    { "Dcircle",                                0x24B9 },   //              Ⓓ      //
    { "Ecircle",                                0x24BA },   //              Ⓔ      //
    { "Fcircle",                                0x24BB },   //              Ⓕ      //
    { "Gcircle",                                0x24BC },   //              Ⓖ      //
    { "Hcircle",                                0x24BD },   //              Ⓗ      //
    { "Icircle",                                0x24BE },   //              Ⓘ      //
    { "Jcircle",                                0x24BF },   //              Ⓙ      //
    { "Kcircle",                                0x24C0 },   //              Ⓚ      //
    { "Lcircle",                                0x24C1 },   //              Ⓛ      //
    { "Mcircle",                                0x24C2 },   //              Ⓜ      //
    { "Ncircle",                                0x24C3 },   //              Ⓝ      //
    { "Ocircle",                                0x24C4 },   //              Ⓞ      //
    { "Pcircle",                                0x24C5 },   //              Ⓟ      //
    { "Qcircle",                                0x24C6 },   //              Ⓠ      //
    { "Rcircle",                                0x24C7 },   //              Ⓡ      //
    { "Scircle",                                0x24C8 },   //              Ⓢ      //
    { "Tcircle",                                0x24C9 },   //              Ⓣ      //
    { "Ucircle",                                0x24CA },   //              Ⓤ      //
    { "Vcircle",                                0x24CB },   //              Ⓥ      //
    { "Wcircle",                                0x24CC },   //              Ⓦ      //
    { "Xcircle",                                0x24CD },   //              Ⓧ      //
    { "Ycircle",                                0x24CE },   //              Ⓨ      //
    { "Zcircle",                                0x24CF },   //              Ⓩ      //
    { "acircle",                                0x24D0 },   //              ⓐ      //
    { "bcircle",                                0x24D1 },   //              ⓑ      //
    { "ccircle",                                0x24D2 },   //              ⓒ      //
    { "dcircle",                                0x24D3 },   //              ⓓ      //
    { "ecircle",                                0x24D4 },   //              ⓔ      //
    { "fcircle",                                0x24D5 },   //              ⓕ      //
    { "gcircle",                                0x24D6 },   //              ⓖ      //
    { "hcircle",                                0x24D7 },   //              ⓗ      //
    { "icircle",                                0x24D8 },   //              ⓘ      //
    { "jcircle",                                0x24D9 },   //              ⓙ      //
    { "kcircle",                                0x24DA },   //              ⓚ      //
    { "lcircle",                                0x24DB },   //              ⓛ      //
    { "mcircle",                                0x24DC },   //              ⓜ      //
    { "ncircle",                                0x24DD },   //              ⓝ      //
    { "ocircle",                                0x24DE },   //              ⓞ      //
    { "pcircle",                                0x24DF },   //              ⓟ      //
    { "qcircle",                                0x24E0 },   //              ⓠ      //
    { "rcircle",                                0x24E1 },   //              ⓡ      //
    { "scircle",                                0x24E2 },   //              ⓢ      //
    { "tcircle",                                0x24E3 },   //              ⓣ      //
    { "ucircle",                                0x24E4 },   //              ⓤ      //
    { "vcircle",                                0x24E5 },   //              ⓥ      //
    { "wcircle",                                0x24E6 },   //              ⓦ      //
    { "xcircle",                                0x24E7 },   //              ⓧ      //
    { "ycircle",                                0x24E8 },   //              ⓨ      //
    { "zcircle",                                0x24E9 },   //              ⓩ      //
    { "SF100000",                               0x2500 },   //              ─      //
    { "SF110000",                               0x2502 },   //              │      //
    { "SF010000",                               0x250C },   //              ┌      //
    { "SF030000",                               0x2510 },   //              ┐      //
    { "SF020000",                               0x2514 },   //              └      //
    { "SF040000",                               0x2518 },   //              ┘      //
    { "SF080000",                               0x251C },   //              ├      //
    { "SF090000",                               0x2524 },   //              ┤      //
    { "SF060000",                               0x252C },   //              ┬      //
    { "SF070000",                               0x2534 },   //              ┴      //
    { "SF050000",                               0x253C },   //              ┼      //
    { "SF430000",                               0x2550 },   //              ═      //
    { "SF240000",                               0x2551 },   //              ║      //
    { "SF510000",                               0x2552 },   //              ╒      //
    { "SF520000",                               0x2553 },   //              ╓      //
    { "SF390000",                               0x2554 },   //              ╔      //
    { "SF220000",                               0x2555 },   //              ╕      //
    { "SF210000",                               0x2556 },   //              ╖      //
    { "SF250000",                               0x2557 },   //              ╗      //
    { "SF500000",                               0x2558 },   //              ╘      //
    { "SF490000",                               0x2559 },   //              ╙      //
    { "SF380000",                               0x255A },   //              ╚      //
    { "SF280000",                               0x255B },   //              ╛      //
    { "SF270000",                               0x255C },   //              ╜      //
    { "SF260000",                               0x255D },   //              ╝      //
    { "SF360000",                               0x255E },   //              ╞      //
    { "SF370000",                               0x255F },   //              ╟      //
    { "SF420000",                               0x2560 },   //              ╠      //
    { "SF190000",                               0x2561 },   //              ╡      //
    { "SF200000",                               0x2562 },   //              ╢      //
    { "SF230000",                               0x2563 },   //              ╣      //
    { "SF470000",                               0x2564 },   //              ╤      //
    { "SF480000",                               0x2565 },   //              ╥      //
    { "SF410000",                               0x2566 },   //              ╦      //
    { "SF450000",                               0x2567 },   //              ╧      //
    { "SF460000",                               0x2568 },   //              ╨      //
    { "SF400000",                               0x2569 },   //              ╩      //
    { "SF540000",                               0x256A },   //              ╪      //
    { "SF530000",                               0x256B },   //              ╫      //
    { "SF440000",                               0x256C },   //              ╬      //
    { "upblock",                                0x2580 },   //              ▀      //
    { "dnblock",                                0x2584 },   //              ▄      //
    { "block",                                  0x2588 },   //              █      //
    { "lfblock",                                0x258C },   //              ▌      //
    { "rtblock",                                0x2590 },   //              ▐      //
    { "ltshade",                                0x2591 },   //              ░      //
    { "shadelight",                             0x2591 },   //              ░      //
    { "shade",                                  0x2592 },   //              ▒      //
    { "shademedium",                            0x2592 },   //              ▒      //
    { "dkshade",                                0x2593 },   //              ▓      //
    { "shadedark",                              0x2593 },   //              ▓      //
    { "blacksquare",                            0x25A0 },   //              ■      //
    { "filledbox",                              0x25A0 },   //              ■      //
    { "H22073",                                 0x25A1 },   //              □      //
    { "whitesquare",                            0x25A1 },   //              □      //
    { "squarewhitewithsmallblack",              0x25A3 },   //              ▣      //
    { "squarehorizontalfill",                   0x25A4 },   //              ▤      //
    { "squareverticalfill",                     0x25A5 },   //              ▥      //
    { "squareorthogonalcrosshatchfill",         0x25A6 },   //              ▦      //
    { "squareupperlefttolowerrightfill",        0x25A7 },   //              ▧      //
    { "squareupperrighttolowerleftfill",        0x25A8 },   //              ▨      //
    { "squarediagonalcrosshatchfill",           0x25A9 },   //              ▩      //
    { "H18543",                                 0x25AA },   //              ▪      //
    { "blacksmallsquare",                       0x25AA },   //              ▪      //
    { "H18551",                                 0x25AB },   //              ▫      //
    { "whitesmallsquare",                       0x25AB },   //              ▫      //
    { "blackrectangle",                         0x25AC },   //              ▬      //
    { "filledrect",                             0x25AC },   //              ▬      //
    { "blackuppointingtriangle",                0x25B2 },   //              ▲      //
    { "triagup",                                0x25B2 },   //              ▲      //
    { "whiteuppointingtriangle",                0x25B3 },   //              △      //
    { "blackuppointingsmalltriangle",           0x25B4 },   //              ▴      //
    { "whiteuppointingsmalltriangle",           0x25B5 },   //              ▵      //
    { "blackrightpointingtriangle",             0x25B6 },   //              ▶      //
    { "whiterightpointingtriangle",             0x25B7 },   //              ▷      //
    { "whiterightpointingsmalltriangle",        0x25B9 },   //              ▹      //
    { "blackrightpointingpointer",              0x25BA },   //              ►      //
    { "triagrt",                                0x25BA },   //              ►      //
    { "blackdownpointingtriangle",              0x25BC },   //              ▼      //
    { "triagdn",                                0x25BC },   //              ▼      //
    { "whitedownpointingtriangle",              0x25BD },   //              ▽      //
    { "whitedownpointingsmalltriangle",         0x25BF },   //              ▿      //
    { "blackleftpointingtriangle",              0x25C0 },   //              ◀      //
    { "whiteleftpointingtriangle",              0x25C1 },   //              ◁      //
    { "whiteleftpointingsmalltriangle",         0x25C3 },   //              ◃      //
    { "blackleftpointingpointer",               0x25C4 },   //              ◄      //
    { "triaglf",                                0x25C4 },   //              ◄      //
    { "blackdiamond",                           0x25C6 },   //              ◆      //
    { "whitediamond",                           0x25C7 },   //              ◇      //
    { "whitediamondcontainingblacksmalldiamond", 0x25C8 },   //              ◈      //
    { "fisheye",                                0x25C9 },   //              ◉      //
    { "circle",                                 0x25CB },   //              ○      //
    { "whitecircle",                            0x25CB },   //              ○      //
    { "dottedcircle",                           0x25CC },   //              ◌      //
    { "bullseye",                               0x25CE },   //              ◎      //
    { "H18533",                                 0x25CF },   //              ●      //
    { "blackcircle",                            0x25CF },   //              ●      //
    { "circlewithlefthalfblack",                0x25D0 },   //              ◐      //
    { "circlewithrighthalfblack",               0x25D1 },   //              ◑      //
    { "bulletinverse",                          0x25D8 },   //              ◘      //
    { "invbullet",                              0x25D8 },   //              ◘      //
    { "invcircle",                              0x25D9 },   //              ◙      //
    { "whitecircleinverse",                     0x25D9 },   //              ◙      //
    { "blacklowerrighttriangle",                0x25E2 },   //              ◢      //
    { "blacklowerlefttriangle",                 0x25E3 },   //              ◣      //
    { "blackupperlefttriangle",                 0x25E4 },   //              ◤      //
    { "blackupperrighttriangle",                0x25E5 },   //              ◥      //
    { "openbullet",                             0x25E6 },   //              ◦      //
    { "whitebullet",                            0x25E6 },   //              ◦      //
    { "largecircle",                            0x25EF },   //              ◯      //
    { "blackstar",                              0x2605 },   //              ★      //
    { "whitestar",                              0x2606 },   //              ☆      //
    { "telephoneblack",                         0x260E },   //              ☎      //
    { "whitetelephone",                         0x260F },   //              ☏      //
    { "pointingindexleftwhite",                 0x261C },   //              ☜      //
    { "pointingindexupwhite",                   0x261D },   //              ☝      //
    { "pointingindexrightwhite",                0x261E },   //              ☞      //
    { "pointingindexdownwhite",                 0x261F },   //              ☟      //
    { "yinyang",                                0x262F },   //              ☯      //
    { "smileface",                              0x263A },   //              ☺      //
    { "whitesmilingface",                       0x263A },   //              ☺      //
    { "blacksmilingface",                       0x263B },   //              ☻      //
    { "invsmileface",                           0x263B },   //              ☻      //
    { "compass",                                0x263C },   //              ☼      //
    { "sun",                                    0x263C },   //              ☼      //
    { "female",                                 0x2640 },   //              ♀      //
    { "venus",                                  0x2640 },   //              ♀      //
    { "earth",                                  0x2641 },   //              ♁      //
    { "male",                                   0x2642 },   //              ♂      //
    { "mars",                                   0x2642 },   //              ♂      //
    { "heartsuitwhite",                         0x2661 },   //              ♡      //
    { "diamondsuitwhite",                       0x2662 },   //              ♢      //
    { "spadesuitwhite",                         0x2664 },   //              ♤      //
    { "clubsuitwhite",                          0x2667 },   //              ♧      //
    { "hotsprings",                             0x2668 },   //              ♨      //
    { "quarternote",                            0x2669 },   //              ♩      //
    { "musicalnote",                            0x266A },   //              ♪      //
    { "eighthnotebeamed",                       0x266B },   //              ♫      //
    { "musicalnotedbl",                         0x266B },   //              ♫      //
    { "beamedsixteenthnotes",                   0x266C },   //              ♬      //
    { "musicflatsign",                          0x266D },   //              ♭      //
    { "musicsharpsign",                         0x266F },   //              ♯      //
    { "checkmark",                              0x2713 },   //              ✓      //
    { "onecircleinversesansserif",              0x278A },   //              ➊      //
    { "twocircleinversesansserif",              0x278B },   //              ➋      //
    { "threecircleinversesansserif",            0x278C },   //              ➌      //
    { "fourcircleinversesansserif",             0x278D },   //              ➍      //
    { "fivecircleinversesansserif",             0x278E },   //              ➎      //
    { "sixcircleinversesansserif",              0x278F },   //              ➏      //
    { "sevencircleinversesansserif",            0x2790 },   //              ➐      //
    { "eightcircleinversesansserif",            0x2791 },   //              ➑      //
    { "ninecircleinversesansserif",             0x2792 },   //              ➒      //
    { "arrowrightheavy",                        0x279E },   //              ➞      //
    { "ideographicspace",                       0x3000 },   //              　      //
    { "ideographiccomma",                       0x3001 },   //              、      //
    { "ideographicperiod",                      0x3002 },   //              。      //
    { "dittomark",                              0x3003 },   //              〃      //
    { "jis",                                    0x3004 },   //              〄      //
    { "ideographiciterationmark",               0x3005 },   //              々      //
    { "ideographicclose",                       0x3006 },   //              〆      //
    { "ideographiczero",                        0x3007 },   //              〇      //
    { "anglebracketleft",                       0x3008 },   //              〈      //
    { "anglebracketright",                      0x3009 },   //              〉      //
    { "dblanglebracketleft",                    0x300A },   //              《      //
    { "dblanglebracketright",                   0x300B },   //              》      //
    { "cornerbracketleft",                      0x300C },   //              「      //
    { "cornerbracketright",                     0x300D },   //              」      //
    { "whitecornerbracketleft",                 0x300E },   //              『      //
    { "whitecornerbracketright",                0x300F },   //              』      //
    { "blacklenticularbracketleft",             0x3010 },   //              【      //
    { "blacklenticularbracketright",            0x3011 },   //              】      //
    { "postalmark",                             0x3012 },   //              〒      //
    { "getamark",                               0x3013 },   //              〓      //
    { "tortoiseshellbracketleft",               0x3014 },   //              〔      //
    { "tortoiseshellbracketright",              0x3015 },   //              〕      //
    { "whitelenticularbracketleft",             0x3016 },   //              〖      //
    { "whitelenticularbracketright",            0x3017 },   //              〗      //
    { "whitetortoiseshellbracketleft",          0x3018 },   //              〘      //
    { "whitetortoiseshellbracketright",         0x3019 },   //              〙      //
    { "wavedash",                               0x301C },   //              〜      //
    { "quotedblprimereversed",                  0x301D },   //              〝      //
    { "quotedblprime",                          0x301E },   //              〞      //
    { "postalmarkface",                         0x3020 },   //              〠      //
    { "onehangzhou",                            0x3021 },   //              〡      //
    { "twohangzhou",                            0x3022 },   //              〢      //
    { "threehangzhou",                          0x3023 },   //              〣      //
    { "fourhangzhou",                           0x3024 },   //              〤      //
    { "fivehangzhou",                           0x3025 },   //              〥      //
    { "sixhangzhou",                            0x3026 },   //              〦      //
    { "sevenhangzhou",                          0x3027 },   //              〧      //
    { "eighthangzhou",                          0x3028 },   //              〨      //
    { "ninehangzhou",                           0x3029 },   //              〩      //
    { "circlepostalmark",                       0x3036 },   //              〶      //
    { "asmallhiragana",                         0x3041 },   //              ぁ      //
    { "ahiragana",                              0x3042 },   //              あ      //
    { "ismallhiragana",                         0x3043 },   //              ぃ      //
    { "ihiragana",                              0x3044 },   //              い      //
    { "usmallhiragana",                         0x3045 },   //              ぅ      //
    { "uhiragana",                              0x3046 },   //              う      //
    { "esmallhiragana",                         0x3047 },   //              ぇ      //
    { "ehiragana",                              0x3048 },   //              え      //
    { "osmallhiragana",                         0x3049 },   //              ぉ      //
    { "ohiragana",                              0x304A },   //              お      //
    { "kahiragana",                             0x304B },   //              か      //
    { "gahiragana",                             0x304C },   //              が      //
    { "kihiragana",                             0x304D },   //              き      //
    { "gihiragana",                             0x304E },   //              ぎ      //
    { "kuhiragana",                             0x304F },   //              く      //
    { "guhiragana",                             0x3050 },   //              ぐ      //
    { "kehiragana",                             0x3051 },   //              け      //
    { "gehiragana",                             0x3052 },   //              げ      //
    { "kohiragana",                             0x3053 },   //              こ      //
    { "gohiragana",                             0x3054 },   //              ご      //
    { "sahiragana",                             0x3055 },   //              さ      //
    { "zahiragana",                             0x3056 },   //              ざ      //
    { "sihiragana",                             0x3057 },   //              し      //
    { "zihiragana",                             0x3058 },   //              じ      //
    { "suhiragana",                             0x3059 },   //              す      //
    { "zuhiragana",                             0x305A },   //              ず      //
    { "sehiragana",                             0x305B },   //              せ      //
    { "zehiragana",                             0x305C },   //              ぜ      //
    { "sohiragana",                             0x305D },   //              そ      //
    { "zohiragana",                             0x305E },   //              ぞ      //
    { "tahiragana",                             0x305F },   //              た      //
    { "dahiragana",                             0x3060 },   //              だ      //
    { "tihiragana",                             0x3061 },   //              ち      //
    { "dihiragana",                             0x3062 },   //              ぢ      //
    { "tusmallhiragana",                        0x3063 },   //              っ      //
    { "tuhiragana",                             0x3064 },   //              つ      //
    { "duhiragana",                             0x3065 },   //              づ      //
    { "tehiragana",                             0x3066 },   //              て      //
    { "dehiragana",                             0x3067 },   //              で      //
    { "tohiragana",                             0x3068 },   //              と      //
    { "dohiragana",                             0x3069 },   //              ど      //
    { "nahiragana",                             0x306A },   //              な      //
    { "nihiragana",                             0x306B },   //              に      //
    { "nuhiragana",                             0x306C },   //              ぬ      //
    { "nehiragana",                             0x306D },   //              ね      //
    { "nohiragana",                             0x306E },   //              の      //
    { "hahiragana",                             0x306F },   //              は      //
    { "bahiragana",                             0x3070 },   //              ば      //
    { "pahiragana",                             0x3071 },   //              ぱ      //
    { "hihiragana",                             0x3072 },   //              ひ      //
    { "bihiragana",                             0x3073 },   //              び      //
    { "pihiragana",                             0x3074 },   //              ぴ      //
    { "huhiragana",                             0x3075 },   //              ふ      //
    { "buhiragana",                             0x3076 },   //              ぶ      //
    { "puhiragana",                             0x3077 },   //              ぷ      //
    { "hehiragana",                             0x3078 },   //              へ      //
    { "behiragana",                             0x3079 },   //              べ      //
    { "pehiragana",                             0x307A },   //              ぺ      //
    { "hohiragana",                             0x307B },   //              ほ      //
    { "bohiragana",                             0x307C },   //              ぼ      //
    { "pohiragana",                             0x307D },   //              ぽ      //
    { "mahiragana",                             0x307E },   //              ま      //
    { "mihiragana",                             0x307F },   //              み      //
    { "muhiragana",                             0x3080 },   //              む      //
    { "mehiragana",                             0x3081 },   //              め      //
    { "mohiragana",                             0x3082 },   //              も      //
    { "yasmallhiragana",                        0x3083 },   //              ゃ      //
    { "yahiragana",                             0x3084 },   //              や      //
    { "yusmallhiragana",                        0x3085 },   //              ゅ      //
    { "yuhiragana",                             0x3086 },   //              ゆ      //
    { "yosmallhiragana",                        0x3087 },   //              ょ      //
    { "yohiragana",                             0x3088 },   //              よ      //
    { "rahiragana",                             0x3089 },   //              ら      //
    { "rihiragana",                             0x308A },   //              り      //
    { "ruhiragana",                             0x308B },   //              る      //
    { "rehiragana",                             0x308C },   //              れ      //
    { "rohiragana",                             0x308D },   //              ろ      //
    { "wasmallhiragana",                        0x308E },   //              ゎ      //
    { "wahiragana",                             0x308F },   //              わ      //
    { "wihiragana",                             0x3090 },   //              ゐ      //
    { "wehiragana",                             0x3091 },   //              ゑ      //
    { "wohiragana",                             0x3092 },   //              を      //
    { "nhiragana",                              0x3093 },   //              ん      //
    { "vuhiragana",                             0x3094 },   //              ゔ      //
    { "voicedmarkkana",                         0x309B },   //              ゛      //
    { "semivoicedmarkkana",                     0x309C },   //              ゜      //
    { "iterationhiragana",                      0x309D },   //              ゝ      //
    { "voicediterationhiragana",                0x309E },   //              ゞ      //
    { "asmallkatakana",                         0x30A1 },   //              ァ      //
    { "akatakana",                              0x30A2 },   //              ア      //
    { "ismallkatakana",                         0x30A3 },   //              ィ      //
    { "ikatakana",                              0x30A4 },   //              イ      //
    { "usmallkatakana",                         0x30A5 },   //              ゥ      //
    { "ukatakana",                              0x30A6 },   //              ウ      //
    { "esmallkatakana",                         0x30A7 },   //              ェ      //
    { "ekatakana",                              0x30A8 },   //              エ      //
    { "osmallkatakana",                         0x30A9 },   //              ォ      //
    { "okatakana",                              0x30AA },   //              オ      //
    { "kakatakana",                             0x30AB },   //              カ      //
    { "gakatakana",                             0x30AC },   //              ガ      //
    { "kikatakana",                             0x30AD },   //              キ      //
    { "gikatakana",                             0x30AE },   //              ギ      //
    { "kukatakana",                             0x30AF },   //              ク      //
    { "gukatakana",                             0x30B0 },   //              グ      //
    { "kekatakana",                             0x30B1 },   //              ケ      //
    { "gekatakana",                             0x30B2 },   //              ゲ      //
    { "kokatakana",                             0x30B3 },   //              コ      //
    { "gokatakana",                             0x30B4 },   //              ゴ      //
    { "sakatakana",                             0x30B5 },   //              サ      //
    { "zakatakana",                             0x30B6 },   //              ザ      //
    { "sikatakana",                             0x30B7 },   //              シ      //
    { "zikatakana",                             0x30B8 },   //              ジ      //
    { "sukatakana",                             0x30B9 },   //              ス      //
    { "zukatakana",                             0x30BA },   //              ズ      //
    { "sekatakana",                             0x30BB },   //              セ      //
    { "zekatakana",                             0x30BC },   //              ゼ      //
    { "sokatakana",                             0x30BD },   //              ソ      //
    { "zokatakana",                             0x30BE },   //              ゾ      //
    { "takatakana",                             0x30BF },   //              タ      //
    { "dakatakana",                             0x30C0 },   //              ダ      //
    { "tikatakana",                             0x30C1 },   //              チ      //
    { "dikatakana",                             0x30C2 },   //              ヂ      //
    { "tusmallkatakana",                        0x30C3 },   //              ッ      //
    { "tukatakana",                             0x30C4 },   //              ツ      //
    { "dukatakana",                             0x30C5 },   //              ヅ      //
    { "tekatakana",                             0x30C6 },   //              テ      //
    { "dekatakana",                             0x30C7 },   //              デ      //
    { "tokatakana",                             0x30C8 },   //              ト      //
    { "dokatakana",                             0x30C9 },   //              ド      //
    { "nakatakana",                             0x30CA },   //              ナ      //
    { "nikatakana",                             0x30CB },   //              ニ      //
    { "nukatakana",                             0x30CC },   //              ヌ      //
    { "nekatakana",                             0x30CD },   //              ネ      //
    { "nokatakana",                             0x30CE },   //              ノ      //
    { "hakatakana",                             0x30CF },   //              ハ      //
    { "bakatakana",                             0x30D0 },   //              バ      //
    { "pakatakana",                             0x30D1 },   //              パ      //
    { "hikatakana",                             0x30D2 },   //              ヒ      //
    { "bikatakana",                             0x30D3 },   //              ビ      //
    { "pikatakana",                             0x30D4 },   //              ピ      //
    { "hukatakana",                             0x30D5 },   //              フ      //
    { "bukatakana",                             0x30D6 },   //              ブ      //
    { "pukatakana",                             0x30D7 },   //              プ      //
    { "hekatakana",                             0x30D8 },   //              ヘ      //
    { "bekatakana",                             0x30D9 },   //              ベ      //
    { "pekatakana",                             0x30DA },   //              ペ      //
    { "hokatakana",                             0x30DB },   //              ホ      //
    { "bokatakana",                             0x30DC },   //              ボ      //
    { "pokatakana",                             0x30DD },   //              ポ      //
    { "makatakana",                             0x30DE },   //              マ      //
    { "mikatakana",                             0x30DF },   //              ミ      //
    { "mukatakana",                             0x30E0 },   //              ム      //
    { "mekatakana",                             0x30E1 },   //              メ      //
    { "mokatakana",                             0x30E2 },   //              モ      //
    { "yasmallkatakana",                        0x30E3 },   //              ャ      //
    { "yakatakana",                             0x30E4 },   //              ヤ      //
    { "yusmallkatakana",                        0x30E5 },   //              ュ      //
    { "yukatakana",                             0x30E6 },   //              ユ      //
    { "yosmallkatakana",                        0x30E7 },   //              ョ      //
    { "yokatakana",                             0x30E8 },   //              ヨ      //
    { "rakatakana",                             0x30E9 },   //              ラ      //
    { "rikatakana",                             0x30EA },   //              リ      //
    { "rukatakana",                             0x30EB },   //              ル      //
    { "rekatakana",                             0x30EC },   //              レ      //
    { "rokatakana",                             0x30ED },   //              ロ      //
    { "wasmallkatakana",                        0x30EE },   //              ヮ      //
    { "wakatakana",                             0x30EF },   //              ワ      //
    { "wikatakana",                             0x30F0 },   //              ヰ      //
    { "wekatakana",                             0x30F1 },   //              ヱ      //
    { "wokatakana",                             0x30F2 },   //              ヲ      //
    { "nkatakana",                              0x30F3 },   //              ン      //
    { "vukatakana",                             0x30F4 },   //              ヴ      //
    { "kasmallkatakana",                        0x30F5 },   //              ヵ      //
    { "kesmallkatakana",                        0x30F6 },   //              ヶ      //
    { "vakatakana",                             0x30F7 },   //              ヷ      //
    { "vikatakana",                             0x30F8 },   //              ヸ      //
    { "vekatakana",                             0x30F9 },   //              ヹ      //
    { "vokatakana",                             0x30FA },   //              ヺ      //
    { "dotkatakana",                            0x30FB },   //              ・      //
    { "prolongedkana",                          0x30FC },   //              ー      //
    { "iterationkatakana",                      0x30FD },   //              ヽ      //
    { "voicediterationkatakana",                0x30FE },   //              ヾ      //
    { "bbopomofo",                              0x3105 },   //              ㄅ      //
    { "pbopomofo",                              0x3106 },   //              ㄆ      //
    { "mbopomofo",                              0x3107 },   //              ㄇ      //
    { "fbopomofo",                              0x3108 },   //              ㄈ      //
    { "dbopomofo",                              0x3109 },   //              ㄉ      //
    { "tbopomofo",                              0x310A },   //              ㄊ      //
    { "nbopomofo",                              0x310B },   //              ㄋ      //
    { "lbopomofo",                              0x310C },   //              ㄌ      //
    { "gbopomofo",                              0x310D },   //              ㄍ      //
    { "kbopomofo",                              0x310E },   //              ㄎ      //
    { "hbopomofo",                              0x310F },   //              ㄏ      //
    { "jbopomofo",                              0x3110 },   //              ㄐ      //
    { "qbopomofo",                              0x3111 },   //              ㄑ      //
    { "xbopomofo",                              0x3112 },   //              ㄒ      //
    { "zhbopomofo",                             0x3113 },   //              ㄓ      //
    { "chbopomofo",                             0x3114 },   //              ㄔ      //
    { "shbopomofo",                             0x3115 },   //              ㄕ      //
    { "rbopomofo",                              0x3116 },   //              ㄖ      //
    { "zbopomofo",                              0x3117 },   //              ㄗ      //
    { "cbopomofo",                              0x3118 },   //              ㄘ      //
    { "sbopomofo",                              0x3119 },   //              ㄙ      //
    { "abopomofo",                              0x311A },   //              ㄚ      //
    { "obopomofo",                              0x311B },   //              ㄛ      //
    { "ebopomofo",                              0x311C },   //              ㄜ      //
    { "ehbopomofo",                             0x311D },   //              ㄝ      //
    { "aibopomofo",                             0x311E },   //              ㄞ      //
    { "eibopomofo",                             0x311F },   //              ㄟ      //
    { "aubopomofo",                             0x3120 },   //              ㄠ      //
    { "oubopomofo",                             0x3121 },   //              ㄡ      //
    { "anbopomofo",                             0x3122 },   //              ㄢ      //
    { "enbopomofo",                             0x3123 },   //              ㄣ      //
    { "angbopomofo",                            0x3124 },   //              ㄤ      //
    { "engbopomofo",                            0x3125 },   //              ㄥ      //
    { "erbopomofo",                             0x3126 },   //              ㄦ      //
    { "ibopomofo",                              0x3127 },   //              ㄧ      //
    { "ubopomofo",                              0x3128 },   //              ㄨ      //
    { "iubopomofo",                             0x3129 },   //              ㄩ      //
    { "kiyeokkorean",                           0x3131 },   //              ㄱ      //
    { "ssangkiyeokkorean",                      0x3132 },   //              ㄲ      //
    { "kiyeoksioskorean",                       0x3133 },   //              ㄳ      //
    { "nieunkorean",                            0x3134 },   //              ㄴ      //
    { "nieuncieuckorean",                       0x3135 },   //              ㄵ      //
    { "nieunhieuhkorean",                       0x3136 },   //              ㄶ      //
    { "tikeutkorean",                           0x3137 },   //              ㄷ      //
    { "ssangtikeutkorean",                      0x3138 },   //              ㄸ      //
    { "rieulkorean",                            0x3139 },   //              ㄹ      //
    { "rieulkiyeokkorean",                      0x313A },   //              ㄺ      //
    { "rieulmieumkorean",                       0x313B },   //              ㄻ      //
    { "rieulpieupkorean",                       0x313C },   //              ㄼ      //
    { "rieulsioskorean",                        0x313D },   //              ㄽ      //
    { "rieulthieuthkorean",                     0x313E },   //              ㄾ      //
    { "rieulphieuphkorean",                     0x313F },   //              ㄿ      //
    { "rieulhieuhkorean",                       0x3140 },   //              ㅀ      //
    { "mieumkorean",                            0x3141 },   //              ㅁ      //
    { "pieupkorean",                            0x3142 },   //              ㅂ      //
    { "ssangpieupkorean",                       0x3143 },   //              ㅃ      //
    { "pieupsioskorean",                        0x3144 },   //              ㅄ      //
    { "sioskorean",                             0x3145 },   //              ㅅ      //
    { "ssangsioskorean",                        0x3146 },   //              ㅆ      //
    { "ieungkorean",                            0x3147 },   //              ㅇ      //
    { "cieuckorean",                            0x3148 },   //              ㅈ      //
    { "ssangcieuckorean",                       0x3149 },   //              ㅉ      //
    { "chieuchkorean",                          0x314A },   //              ㅊ      //
    { "khieukhkorean",                          0x314B },   //              ㅋ      //
    { "thieuthkorean",                          0x314C },   //              ㅌ      //
    { "phieuphkorean",                          0x314D },   //              ㅍ      //
    { "hieuhkorean",                            0x314E },   //              ㅎ      //
    { "akorean",                                0x314F },   //              ㅏ      //
    { "aekorean",                               0x3150 },   //              ㅐ      //
    { "yakorean",                               0x3151 },   //              ㅑ      //
    { "yaekorean",                              0x3152 },   //              ㅒ      //
    { "eokorean",                               0x3153 },   //              ㅓ      //
    { "ekorean",                                0x3154 },   //              ㅔ      //
    { "yeokorean",                              0x3155 },   //              ㅕ      //
    { "yekorean",                               0x3156 },   //              ㅖ      //
    { "okorean",                                0x3157 },   //              ㅗ      //
    { "wakorean",                               0x3158 },   //              ㅘ      //
    { "waekorean",                              0x3159 },   //              ㅙ      //
    { "oekorean",                               0x315A },   //              ㅚ      //
    { "yokorean",                               0x315B },   //              ㅛ      //
    { "ukorean",                                0x315C },   //              ㅜ      //
    { "weokorean",                              0x315D },   //              ㅝ      //
    { "wekorean",                               0x315E },   //              ㅞ      //
    { "wikorean",                               0x315F },   //              ㅟ      //
    { "yukorean",                               0x3160 },   //              ㅠ      //
    { "eukorean",                               0x3161 },   //              ㅡ      //
    { "yikorean",                               0x3162 },   //              ㅢ      //
    { "ikorean",                                0x3163 },   //              ㅣ      //
    { "hangulfiller",                           0x3164 },   //              ㅤ      //
    { "ssangnieunkorean",                       0x3165 },   //              ㅥ      //
    { "nieuntikeutkorean",                      0x3166 },   //              ㅦ      //
    { "nieunsioskorean",                        0x3167 },   //              ㅧ      //
    { "nieunpansioskorean",                     0x3168 },   //              ㅨ      //
    { "rieulkiyeoksioskorean",                  0x3169 },   //              ㅩ      //
    { "rieultikeutkorean",                      0x316A },   //              ㅪ      //
    { "rieulpieupsioskorean",                   0x316B },   //              ㅫ      //
    { "rieulpansioskorean",                     0x316C },   //              ㅬ      //
    { "rieulyeorinhieuhkorean",                 0x316D },   //              ㅭ      //
    { "mieumpieupkorean",                       0x316E },   //              ㅮ      //
    { "mieumsioskorean",                        0x316F },   //              ㅯ      //
    { "mieumpansioskorean",                     0x3170 },   //              ㅰ      //
    { "kapyeounmieumkorean",                    0x3171 },   //              ㅱ      //
    { "pieupkiyeokkorean",                      0x3172 },   //              ㅲ      //
    { "pieuptikeutkorean",                      0x3173 },   //              ㅳ      //
    { "pieupsioskiyeokkorean",                  0x3174 },   //              ㅴ      //
    { "pieupsiostikeutkorean",                  0x3175 },   //              ㅵ      //
    { "pieupcieuckorean",                       0x3176 },   //              ㅶ      //
    { "pieupthieuthkorean",                     0x3177 },   //              ㅷ      //
    { "kapyeounpieupkorean",                    0x3178 },   //              ㅸ      //
    { "kapyeounssangpieupkorean",               0x3179 },   //              ㅹ      //
    { "sioskiyeokkorean",                       0x317A },   //              ㅺ      //
    { "siosnieunkorean",                        0x317B },   //              ㅻ      //
    { "siostikeutkorean",                       0x317C },   //              ㅼ      //
    { "siospieupkorean",                        0x317D },   //              ㅽ      //
    { "sioscieuckorean",                        0x317E },   //              ㅾ      //
    { "pansioskorean",                          0x317F },   //              ㅿ      //
    { "ssangieungkorean",                       0x3180 },   //              ㆀ      //
    { "yesieungkorean",                         0x3181 },   //              ㆁ      //
    { "yesieungsioskorean",                     0x3182 },   //              ㆂ      //
    { "yesieungpansioskorean",                  0x3183 },   //              ㆃ      //
    { "kapyeounphieuphkorean",                  0x3184 },   //              ㆄ      //
    { "ssanghieuhkorean",                       0x3185 },   //              ㆅ      //
    { "yeorinhieuhkorean",                      0x3186 },   //              ㆆ      //
    { "yoyakorean",                             0x3187 },   //              ㆇ      //
    { "yoyaekorean",                            0x3188 },   //              ㆈ      //
    { "yoikorean",                              0x3189 },   //              ㆉ      //
    { "yuyeokorean",                            0x318A },   //              ㆊ      //
    { "yuyekorean",                             0x318B },   //              ㆋ      //
    { "yuikorean",                              0x318C },   //              ㆌ      //
    { "araeakorean",                            0x318D },   //              ㆍ      //
    { "araeaekorean",                           0x318E },   //              ㆎ      //
    { "kiyeokparenkorean",                      0x3200 },   //              ㈀      //
    { "nieunparenkorean",                       0x3201 },   //              ㈁      //
    { "tikeutparenkorean",                      0x3202 },   //              ㈂      //
    { "rieulparenkorean",                       0x3203 },   //              ㈃      //
    { "mieumparenkorean",                       0x3204 },   //              ㈄      //
    { "pieupparenkorean",                       0x3205 },   //              ㈅      //
    { "siosparenkorean",                        0x3206 },   //              ㈆      //
    { "ieungparenkorean",                       0x3207 },   //              ㈇      //
    { "cieucparenkorean",                       0x3208 },   //              ㈈      //
    { "chieuchparenkorean",                     0x3209 },   //              ㈉      //
    { "khieukhparenkorean",                     0x320A },   //              ㈊      //
    { "thieuthparenkorean",                     0x320B },   //              ㈋      //
    { "phieuphparenkorean",                     0x320C },   //              ㈌      //
    { "hieuhparenkorean",                       0x320D },   //              ㈍      //
    { "kiyeokaparenkorean",                     0x320E },   //              ㈎      //
    { "nieunaparenkorean",                      0x320F },   //              ㈏      //
    { "tikeutaparenkorean",                     0x3210 },   //              ㈐      //
    { "rieulaparenkorean",                      0x3211 },   //              ㈑      //
    { "mieumaparenkorean",                      0x3212 },   //              ㈒      //
    { "pieupaparenkorean",                      0x3213 },   //              ㈓      //
    { "siosaparenkorean",                       0x3214 },   //              ㈔      //
    { "ieungaparenkorean",                      0x3215 },   //              ㈕      //
    { "cieucaparenkorean",                      0x3216 },   //              ㈖      //
    { "chieuchaparenkorean",                    0x3217 },   //              ㈗      //
    { "khieukhaparenkorean",                    0x3218 },   //              ㈘      //
    { "thieuthaparenkorean",                    0x3219 },   //              ㈙      //
    { "phieuphaparenkorean",                    0x321A },   //              ㈚      //
    { "hieuhaparenkorean",                      0x321B },   //              ㈛      //
    { "cieucuparenkorean",                      0x321C },   //              ㈜      //
    { "oneideographicparen",                    0x3220 },   //              ㈠      //
    { "twoideographicparen",                    0x3221 },   //              ㈡      //
    { "threeideographicparen",                  0x3222 },   //              ㈢      //
    { "fourideographicparen",                   0x3223 },   //              ㈣      //
    { "fiveideographicparen",                   0x3224 },   //              ㈤      //
    { "sixideographicparen",                    0x3225 },   //              ㈥      //
    { "sevenideographicparen",                  0x3226 },   //              ㈦      //
    { "eightideographicparen",                  0x3227 },   //              ㈧      //
    { "nineideographicparen",                   0x3228 },   //              ㈨      //
    { "tenideographicparen",                    0x3229 },   //              ㈩      //
    { "ideographicmoonparen",                   0x322A },   //              ㈪      //
    { "ideographicfireparen",                   0x322B },   //              ㈫      //
    { "ideographicwaterparen",                  0x322C },   //              ㈬      //
    { "ideographicwoodparen",                   0x322D },   //              ㈭      //
    { "ideographicmetalparen",                  0x322E },   //              ㈮      //
    { "ideographicearthparen",                  0x322F },   //              ㈯      //
    { "ideographicsunparen",                    0x3230 },   //              ㈰      //
    { "ideographicstockparen",                  0x3231 },   //              ㈱      //
    { "ideographichaveparen",                   0x3232 },   //              ㈲      //
    { "ideographicsocietyparen",                0x3233 },   //              ㈳      //
    { "ideographicnameparen",                   0x3234 },   //              ㈴      //
    { "ideographicspecialparen",                0x3235 },   //              ㈵      //
    { "ideographicfinancialparen",              0x3236 },   //              ㈶      //
    { "ideographiccongratulationparen",         0x3237 },   //              ㈷      //
    { "ideographiclaborparen",                  0x3238 },   //              ㈸      //
    { "ideographicrepresentparen",              0x3239 },   //              ㈹      //
    { "ideographiccallparen",                   0x323A },   //              ㈺      //
    { "ideographicstudyparen",                  0x323B },   //              ㈻      //
    { "ideographicsuperviseparen",              0x323C },   //              ㈼      //
    { "ideographicenterpriseparen",             0x323D },   //              ㈽      //
    { "ideographicresourceparen",               0x323E },   //              ㈾      //
    { "ideographicallianceparen",               0x323F },   //              ㈿      //
    { "ideographicfestivalparen",               0x3240 },   //              ㉀      //
    { "ideographicselfparen",                   0x3242 },   //              ㉂      //
    { "ideographicreachparen",                  0x3243 },   //              ㉃      //
    { "kiyeokcirclekorean",                     0x3260 },   //              ㉠      //
    { "nieuncirclekorean",                      0x3261 },   //              ㉡      //
    { "tikeutcirclekorean",                     0x3262 },   //              ㉢      //
    { "rieulcirclekorean",                      0x3263 },   //              ㉣      //
    { "mieumcirclekorean",                      0x3264 },   //              ㉤      //
    { "pieupcirclekorean",                      0x3265 },   //              ㉥      //
    { "sioscirclekorean",                       0x3266 },   //              ㉦      //
    { "ieungcirclekorean",                      0x3267 },   //              ㉧      //
    { "cieuccirclekorean",                      0x3268 },   //              ㉨      //
    { "chieuchcirclekorean",                    0x3269 },   //              ㉩      //
    { "khieukhcirclekorean",                    0x326A },   //              ㉪      //
    { "thieuthcirclekorean",                    0x326B },   //              ㉫      //
    { "phieuphcirclekorean",                    0x326C },   //              ㉬      //
    { "hieuhcirclekorean",                      0x326D },   //              ㉭      //
    { "kiyeokacirclekorean",                    0x326E },   //              ㉮      //
    { "nieunacirclekorean",                     0x326F },   //              ㉯      //
    { "tikeutacirclekorean",                    0x3270 },   //              ㉰      //
    { "rieulacirclekorean",                     0x3271 },   //              ㉱      //
    { "mieumacirclekorean",                     0x3272 },   //              ㉲      //
    { "pieupacirclekorean",                     0x3273 },   //              ㉳      //
    { "siosacirclekorean",                      0x3274 },   //              ㉴      //
    { "ieungacirclekorean",                     0x3275 },   //              ㉵      //
    { "cieucacirclekorean",                     0x3276 },   //              ㉶      //
    { "chieuchacirclekorean",                   0x3277 },   //              ㉷      //
    { "khieukhacirclekorean",                   0x3278 },   //              ㉸      //
    { "thieuthacirclekorean",                   0x3279 },   //              ㉹      //
    { "phieuphacirclekorean",                   0x327A },   //              ㉺      //
    { "hieuhacirclekorean",                     0x327B },   //              ㉻      //
    { "koreanstandardsymbol",                   0x327F },   //              ㉿      //
    { "ideographmooncircle",                    0x328A },   //              ㊊      //
    { "ideographfirecircle",                    0x328B },   //              ㊋      //
    { "ideographwatercircle",                   0x328C },   //              ㊌      //
    { "ideographwoodcircle",                    0x328D },   //              ㊍      //
    { "ideographmetalcircle",                   0x328E },   //              ㊎      //
    { "ideographearthcircle",                   0x328F },   //              ㊏      //
    { "ideographsuncircle",                     0x3290 },   //              ㊐      //
    { "ideographnamecircle",                    0x3294 },   //              ㊔      //
    { "ideographicfinancialcircle",             0x3296 },   //              ㊖      //
    { "ideographiclaborcircle",                 0x3298 },   //              ㊘      //
    { "ideographicsecretcircle",                0x3299 },   //              ㊙      //
    { "ideographicexcellentcircle",             0x329D },   //              ㊝      //
    { "ideographicprintcircle",                 0x329E },   //              ㊞      //
    { "ideographiccorrectcircle",               0x32A3 },   //              ㊣      //
    { "ideographichighcircle",                  0x32A4 },   //              ㊤      //
    { "ideographiccentrecircle",                0x32A5 },   //              ㊥      //
    { "ideographiclowcircle",                   0x32A6 },   //              ㊦      //
    { "ideographicleftcircle",                  0x32A7 },   //              ㊧      //
    { "ideographicrightcircle",                 0x32A8 },   //              ㊨      //
    { "ideographicmedicinecircle",              0x32A9 },   //              ㊩      //
    { "apaatosquare",                           0x3300 },   //              ㌀      //
    { "aarusquare",                             0x3303 },   //              ㌃      //
    { "intisquare",                             0x3305 },   //              ㌅      //
    { "karoriisquare",                          0x330D },   //              ㌍      //
    { "kirosquare",                             0x3314 },   //              ㌔      //
    { "kiroguramusquare",                       0x3315 },   //              ㌕      //
    { "kiromeetorusquare",                      0x3316 },   //              ㌖      //
    { "guramusquare",                           0x3318 },   //              ㌘      //
    { "kooposquare",                            0x331E },   //              ㌞      //
    { "sentisquare",                            0x3322 },   //              ㌢      //
    { "sentosquare",                            0x3323 },   //              ㌣      //
    { "dorusquare",                             0x3326 },   //              ㌦      //
    { "tonsquare",                              0x3327 },   //              ㌧      //
    { "haitusquare",                            0x332A },   //              ㌪      //
    { "paasentosquare",                         0x332B },   //              ㌫      //
    { "birusquare",                             0x3331 },   //              ㌱      //
    { "huiitosquare",                           0x3333 },   //              ㌳      //
    { "hekutaarusquare",                        0x3336 },   //              ㌶      //
    { "herutusquare",                           0x3339 },   //              ㌹      //
    { "peezisquare",                            0x333B },   //              ㌻      //
    { "hoonsquare",                             0x3342 },   //              ㍂      //
    { "mansyonsquare",                          0x3347 },   //              ㍇      //
    { "mirisquare",                             0x3349 },   //              ㍉      //
    { "miribaarusquare",                        0x334A },   //              ㍊      //
    { "meetorusquare",                          0x334D },   //              ㍍      //
    { "yaadosquare",                            0x334E },   //              ㍎      //
    { "rittorusquare",                          0x3351 },   //              ㍑      //
    { "wattosquare",                            0x3357 },   //              ㍗      //
    { "heiseierasquare",                        0x337B },   //              ㍻      //
    { "syouwaerasquare",                        0x337C },   //              ㍼      //
    { "taisyouerasquare",                       0x337D },   //              ㍽      //
    { "meizierasquare",                         0x337E },   //              ㍾      //
    { "corporationsquare",                      0x337F },   //              ㍿      //
    { "paampssquare",                           0x3380 },   //              ㎀      //
    { "nasquare",                               0x3381 },   //              ㎁      //
    { "muasquare",                              0x3382 },   //              ㎂      //
    { "masquare",                               0x3383 },   //              ㎃      //
    { "kasquare",                               0x3384 },   //              ㎄      //
    { "KBsquare",                               0x3385 },   //              ㎅      //
    { "MBsquare",                               0x3386 },   //              ㎆      //
    { "GBsquare",                               0x3387 },   //              ㎇      //
    { "calsquare",                              0x3388 },   //              ㎈      //
    { "kcalsquare",                             0x3389 },   //              ㎉      //
    { "pfsquare",                               0x338A },   //              ㎊      //
    { "nfsquare",                               0x338B },   //              ㎋      //
    { "mufsquare",                              0x338C },   //              ㎌      //
    { "mugsquare",                              0x338D },   //              ㎍      //
    { "squaremg",                               0x338E },   //              ㎎      //
    { "squarekg",                               0x338F },   //              ㎏      //
    { "Hzsquare",                               0x3390 },   //              ㎐      //
    { "khzsquare",                              0x3391 },   //              ㎑      //
    { "mhzsquare",                              0x3392 },   //              ㎒      //
    { "ghzsquare",                              0x3393 },   //              ㎓      //
    { "thzsquare",                              0x3394 },   //              ㎔      //
    { "mulsquare",                              0x3395 },   //              ㎕      //
    { "mlsquare",                               0x3396 },   //              ㎖      //
    { "dlsquare",                               0x3397 },   //              ㎗      //
    { "klsquare",                               0x3398 },   //              ㎘      //
    { "fmsquare",                               0x3399 },   //              ㎙      //
    { "nmsquare",                               0x339A },   //              ㎚      //
    { "mumsquare",                              0x339B },   //              ㎛      //
    { "squaremm",                               0x339C },   //              ㎜      //
    { "squarecm",                               0x339D },   //              ㎝      //
    { "squarekm",                               0x339E },   //              ㎞      //
    { "mmsquaredsquare",                        0x339F },   //              ㎟      //
    { "cmsquaredsquare",                        0x33A0 },   //              ㎠      //
    { "squaremsquared",                         0x33A1 },   //              ㎡      //
    { "kmsquaredsquare",                        0x33A2 },   //              ㎢      //
    { "mmcubedsquare",                          0x33A3 },   //              ㎣      //
    { "cmcubedsquare",                          0x33A4 },   //              ㎤      //
    { "mcubedsquare",                           0x33A5 },   //              ㎥      //
    { "kmcubedsquare",                          0x33A6 },   //              ㎦      //
    { "moverssquare",                           0x33A7 },   //              ㎧      //
    { "moverssquaredsquare",                    0x33A8 },   //              ㎨      //
    { "pasquare",                               0x33A9 },   //              ㎩      //
    { "kpasquare",                              0x33AA },   //              ㎪      //
    { "mpasquare",                              0x33AB },   //              ㎫      //
    { "gpasquare",                              0x33AC },   //              ㎬      //
    { "radsquare",                              0x33AD },   //              ㎭      //
    { "radoverssquare",                         0x33AE },   //              ㎮      //
    { "radoverssquaredsquare",                  0x33AF },   //              ㎯      //
    { "pssquare",                               0x33B0 },   //              ㎰      //
    { "nssquare",                               0x33B1 },   //              ㎱      //
    { "mussquare",                              0x33B2 },   //              ㎲      //
    { "mssquare",                               0x33B3 },   //              ㎳      //
    { "pvsquare",                               0x33B4 },   //              ㎴      //
    { "nvsquare",                               0x33B5 },   //              ㎵      //
    { "muvsquare",                              0x33B6 },   //              ㎶      //
    { "mvsquare",                               0x33B7 },   //              ㎷      //
    { "kvsquare",                               0x33B8 },   //              ㎸      //
    { "mvmegasquare",                           0x33B9 },   //              ㎹      //
    { "pwsquare",                               0x33BA },   //              ㎺      //
    { "nwsquare",                               0x33BB },   //              ㎻      //
    { "muwsquare",                              0x33BC },   //              ㎼      //
    { "mwsquare",                               0x33BD },   //              ㎽      //
    { "kwsquare",                               0x33BE },   //              ㎾      //
    { "mwmegasquare",                           0x33BF },   //              ㎿      //
    { "kohmsquare",                             0x33C0 },   //              ㏀      //
    { "mohmsquare",                             0x33C1 },   //              ㏁      //
    { "amsquare",                               0x33C2 },   //              ㏂      //
    { "bqsquare",                               0x33C3 },   //              ㏃      //
    { "squarecc",                               0x33C4 },   //              ㏄      //
    { "cdsquare",                               0x33C5 },   //              ㏅      //
    { "coverkgsquare",                          0x33C6 },   //              ㏆      //
    { "cosquare",                               0x33C7 },   //              ㏇      //
    { "dbsquare",                               0x33C8 },   //              ㏈      //
    { "gysquare",                               0x33C9 },   //              ㏉      //
    { "hasquare",                               0x33CA },   //              ㏊      //
    { "HPsquare",                               0x33CB },   //              ㏋      //
    { "KKsquare",                               0x33CD },   //              ㏍      //
    { "squarekmcapital",                        0x33CE },   //              ㏎      //
    { "ktsquare",                               0x33CF },   //              ㏏      //
    { "lmsquare",                               0x33D0 },   //              ㏐      //
    { "squareln",                               0x33D1 },   //              ㏑      //
    { "squarelog",                              0x33D2 },   //              ㏒      //
    { "lxsquare",                               0x33D3 },   //              ㏓      //
    { "mbsquare",                               0x33D4 },   //              ㏔      //
    { "squaremil",                              0x33D5 },   //              ㏕      //
    { "molsquare",                              0x33D6 },   //              ㏖      //
    { "pmsquare",                               0x33D8 },   //              ㏘      //
    { "srsquare",                               0x33DB },   //              ㏛      //
    { "svsquare",                               0x33DC },   //              ㏜      //
    { "wbsquare",                               0x33DD },   //              ㏝      //
    { "twentyhangzhou",                         0x5344 },   //              卄      //
    { "dotlessj",                               0xF6BE },   //                    //
    { "LL",                                     0xF6BF },   //                    //
    { "ll",                                     0xF6C0 },   //                    //
    { "commaaccent",                            0xF6C3 },   //                    //
    { "afii10063",                              0xF6C4 },   //                    //
    { "afii10064",                              0xF6C5 },   //                    //
    { "afii10192",                              0xF6C6 },   //                    //
    { "afii10831",                              0xF6C7 },   //                    //
    { "afii10832",                              0xF6C8 },   //                    //
    { "Acute",                                  0xF6C9 },   //                    //
    { "Caron",                                  0xF6CA },   //                    //
    { "Dieresis",                               0xF6CB },   //                    //
    { "DieresisAcute",                          0xF6CC },   //                    //
    { "DieresisGrave",                          0xF6CD },   //                    //
    { "Grave",                                  0xF6CE },   //                    //
    { "Hungarumlaut",                           0xF6CF },   //                    //
    { "Macron",                                 0xF6D0 },   //                    //
    { "cyrBreve",                               0xF6D1 },   //                    //
    { "cyrFlex",                                0xF6D2 },   //                    //
    { "dblGrave",                               0xF6D3 },   //                    //
    { "cyrbreve",                               0xF6D4 },   //                    //
    { "cyrflex",                                0xF6D5 },   //                    //
    { "dblgrave",                               0xF6D6 },   //                    //
    { "dieresisacute",                          0xF6D7 },   //                    //
    { "dieresisgrave",                          0xF6D8 },   //                    //
    { "copyrightserif",                         0xF6D9 },   //                    //
    { "registerserif",                          0xF6DA },   //                    //
    { "trademarkserif",                         0xF6DB },   //                    //
    { "onefitted",                              0xF6DC },   //                    //
    { "rupiah",                                 0xF6DD },   //                    //
    { "threequartersemdash",                    0xF6DE },   //                    //
    { "centinferior",                           0xF6DF },   //                    //
    { "centsuperior",                           0xF6E0 },   //                    //
    { "commainferior",                          0xF6E1 },   //                    //
    { "commasuperior",                          0xF6E2 },   //                    //
    { "dollarinferior",                         0xF6E3 },   //                    //
    { "dollarsuperior",                         0xF6E4 },   //                    //
    { "hypheninferior",                         0xF6E5 },   //                    //
    { "hyphensuperior",                         0xF6E6 },   //                    //
    { "periodinferior",                         0xF6E7 },   //                    //
    { "periodsuperior",                         0xF6E8 },   //                    //
    { "asuperior",                              0xF6E9 },   //                    //
    { "bsuperior",                              0xF6EA },   //                    //
    { "dsuperior",                              0xF6EB },   //                    //
    { "esuperior",                              0xF6EC },   //                    //
    { "isuperior",                              0xF6ED },   //                    //
    { "lsuperior",                              0xF6EE },   //                    //
    { "msuperior",                              0xF6EF },   //                    //
    { "osuperior",                              0xF6F0 },   //                    //
    { "rsuperior",                              0xF6F1 },   //                    //
    { "ssuperior",                              0xF6F2 },   //                    //
    { "tsuperior",                              0xF6F3 },   //                    //
    { "Brevesmall",                             0xF6F4 },   //                    //
    { "Caronsmall",                             0xF6F5 },   //                    //
    { "Circumflexsmall",                        0xF6F6 },   //                    //
    { "Dotaccentsmall",                         0xF6F7 },   //                    //
    { "Hungarumlautsmall",                      0xF6F8 },   //                    //
    { "Lslashsmall",                            0xF6F9 },   //                    //
    { "OEsmall",                                0xF6FA },   //                    //
    { "Ogoneksmall",                            0xF6FB },   //                    //
    { "Ringsmall",                              0xF6FC },   //                    //
    { "Scaronsmall",                            0xF6FD },   //                    //
    { "Tildesmall",                             0xF6FE },   //                    //
    { "Zcaronsmall",                            0xF6FF },   //                    //
    { "exclamsmall",                            0xF721 },   //                    //
    { "dollaroldstyle",                         0xF724 },   //                    //
    { "ampersandsmall",                         0xF726 },   //                    //
    { "zerooldstyle",                           0xF730 },   //                    //
    { "oneoldstyle",                            0xF731 },   //                    //
    { "twooldstyle",                            0xF732 },   //                    //
    { "threeoldstyle",                          0xF733 },   //                    //
    { "fouroldstyle",                           0xF734 },   //                    //
    { "fiveoldstyle",                           0xF735 },   //                    //
    { "sixoldstyle",                            0xF736 },   //                    //
    { "sevenoldstyle",                          0xF737 },   //                    //
    { "eightoldstyle",                          0xF738 },   //                    //
    { "nineoldstyle",                           0xF739 },   //                    //
    { "questionsmall",                          0xF73F },   //                    //
    { "Gravesmall",                             0xF760 },   //                    //
    { "Asmall",                                 0xF761 },   //                    //
    { "Bsmall",                                 0xF762 },   //                    //
    { "Csmall",                                 0xF763 },   //                    //
    { "Dsmall",                                 0xF764 },   //                    //
    { "Esmall",                                 0xF765 },   //                    //
    { "Fsmall",                                 0xF766 },   //                    //
    { "Gsmall",                                 0xF767 },   //                    //
    { "Hsmall",                                 0xF768 },   //                    //
    { "Ismall",                                 0xF769 },   //                    //
    { "Jsmall",                                 0xF76A },   //                    //
    { "Ksmall",                                 0xF76B },   //                    //
    { "Lsmall",                                 0xF76C },   //                    //
    { "Msmall",                                 0xF76D },   //                    //
    { "Nsmall",                                 0xF76E },   //                    //
    { "Osmall",                                 0xF76F },   //                    //
    { "Psmall",                                 0xF770 },   //                    //
    { "Qsmall",                                 0xF771 },   //                    //
    { "Rsmall",                                 0xF772 },   //                    //
    { "Ssmall",                                 0xF773 },   //                    //
    { "Tsmall",                                 0xF774 },   //                    //
    { "Usmall",                                 0xF775 },   //                    //
    { "Vsmall",                                 0xF776 },   //                    //
    { "Wsmall",                                 0xF777 },   //                    //
    { "Xsmall",                                 0xF778 },   //                    //
    { "Ysmall",                                 0xF779 },   //                    //
    { "Zsmall",                                 0xF77A },   //                    //
    { "exclamdownsmall",                        0xF7A1 },   //                    //
    { "centoldstyle",                           0xF7A2 },   //                    //
    { "Dieresissmall",                          0xF7A8 },   //                    //
    { "Macronsmall",                            0xF7AF },   //                    //
    { "Acutesmall",                             0xF7B4 },   //                    //
    { "Cedillasmall",                           0xF7B8 },   //                    //
    { "questiondownsmall",                      0xF7BF },   //                    //
    { "Agravesmall",                            0xF7E0 },   //                    //
    { "Aacutesmall",                            0xF7E1 },   //                    //
    { "Acircumflexsmall",                       0xF7E2 },   //                    //
    { "Atildesmall",                            0xF7E3 },   //                    //
    { "Adieresissmall",                         0xF7E4 },   //                    //
    { "Aringsmall",                             0xF7E5 },   //                    //
    { "AEsmall",                                0xF7E6 },   //                    //
    { "Ccedillasmall",                          0xF7E7 },   //                    //
    { "Egravesmall",                            0xF7E8 },   //                    //
    { "Eacutesmall",                            0xF7E9 },   //                    //
    { "Ecircumflexsmall",                       0xF7EA },   //                    //
    { "Edieresissmall",                         0xF7EB },   //                    //
    { "Igravesmall",                            0xF7EC },   //                    //
    { "Iacutesmall",                            0xF7ED },   //                    //
    { "Icircumflexsmall",                       0xF7EE },   //                    //
    { "Idieresissmall",                         0xF7EF },   //                    //
    { "Ethsmall",                               0xF7F0 },   //                    //
    { "Ntildesmall",                            0xF7F1 },   //                    //
    { "Ogravesmall",                            0xF7F2 },   //                    //
    { "Oacutesmall",                            0xF7F3 },   //                    //
    { "Ocircumflexsmall",                       0xF7F4 },   //                    //
    { "Otildesmall",                            0xF7F5 },   //                    //
    { "Odieresissmall",                         0xF7F6 },   //                    //
    { "Oslashsmall",                            0xF7F8 },   //                    //
    { "Ugravesmall",                            0xF7F9 },   //                    //
    { "Uacutesmall",                            0xF7FA },   //                    //
    { "Ucircumflexsmall",                       0xF7FB },   //                    //
    { "Udieresissmall",                         0xF7FC },   //                    //
    { "Yacutesmall",                            0xF7FD },   //                    //
    { "Thornsmall",                             0xF7FE },   //                    //
    { "Ydieresissmall",                         0xF7FF },   //                    //
    { "maihanakatleftthai",                     0xF884 },   //                    //
    { "saraileftthai",                          0xF885 },   //                    //
    { "saraiileftthai",                         0xF886 },   //                    //
    { "saraueleftthai",                         0xF887 },   //                    //
    { "saraueeleftthai",                        0xF888 },   //                    //
    { "maitaikhuleftthai",                      0xF889 },   //                    //
    { "maiekupperleftthai",                     0xF88A },   //                    //
    { "maieklowrightthai",                      0xF88B },   //                    //
    { "maieklowleftthai",                       0xF88C },   //                    //
    { "maithoupperleftthai",                    0xF88D },   //                    //
    { "maitholowrightthai",                     0xF88E },   //                    //
    { "maitholowleftthai",                      0xF88F },   //                    //
    { "maitriupperleftthai",                    0xF890 },   //                    //
    { "maitrilowrightthai",                     0xF891 },   //                    //
    { "maitrilowleftthai",                      0xF892 },   //                    //
    { "maichattawaupperleftthai",               0xF893 },   //                    //
    { "maichattawalowrightthai",                0xF894 },   //                    //
    { "maichattawalowleftthai",                 0xF895 },   //                    //
    { "thanthakhatupperleftthai",               0xF896 },   //                    //
    { "thanthakhatlowrightthai",                0xF897 },   //                    //
    { "thanthakhatlowleftthai",                 0xF898 },   //                    //
    { "nikhahitleftthai",                       0xF899 },   //                    //
    { "radicalex",                              0xF8E5 },   //                    //
    { "arrowvertex",                            0xF8E6 },   //                    //
    { "arrowhorizex",                           0xF8E7 },   //                    //
    { "registersans",                           0xF8E8 },   //                    //
    { "copyrightsans",                          0xF8E9 },   //                    //
    { "trademarksans",                          0xF8EA },   //                    //
    { "parenlefttp",                            0xF8EB },   //                    //
    { "parenleftex",                            0xF8EC },   //                    //
    { "parenleftbt",                            0xF8ED },   //                    //
    { "bracketlefttp",                          0xF8EE },   //                    //
    { "bracketleftex",                          0xF8EF },   //                    //
    { "bracketleftbt",                          0xF8F0 },   //                    //
    { "bracelefttp",                            0xF8F1 },   //                    //
    { "braceleftmid",                           0xF8F2 },   //                    //
    { "braceleftbt",                            0xF8F3 },   //                    //
    { "braceex",                                0xF8F4 },   //                    //
    { "integralex",                             0xF8F5 },   //                    //
    { "parenrighttp",                           0xF8F6 },   //                    //
    { "parenrightex",                           0xF8F7 },   //                    //
    { "parenrightbt",                           0xF8F8 },   //                    //
    { "bracketrighttp",                         0xF8F9 },   //                    //
    { "bracketrightex",                         0xF8FA },   //                    //
    { "bracketrightbt",                         0xF8FB },   //                    //
    { "bracerighttp",                           0xF8FC },   //                    //
    { "bracerightmid",                          0xF8FD },   //                    //
    { "bracerightbt",                           0xF8FE },   //                    //
    { "apple",                                  0xF8FF },   //                    //
    { "ff",                                     0xFB00 },   //              ﬀ      //
    { "fi",                                     0xFB01 },   //              ﬁ      //
    { "fl",                                     0xFB02 },   //              ﬂ      //
    { "ffi",                                    0xFB03 },   //              ﬃ      //
    { "ffl",                                    0xFB04 },   //              ﬄ      //
    { "afii57705",                              0xFB1F },   //              ײַ      //
    { "doubleyodpatah",                         0xFB1F },   //              ײַ      //
    { "doubleyodpatahhebrew",                   0xFB1F },   //              ײַ      //
    { "yodyodpatahhebrew",                      0xFB1F },   //              ײַ      //
    { "ayinaltonehebrew",                       0xFB20 },   //              ﬠ      //
    { "afii57694",                              0xFB2A },   //              שׁ      //
    { "shinshindot",                            0xFB2A },   //              שׁ      //
    { "shinshindothebrew",                      0xFB2A },   //              שׁ      //
    { "afii57695",                              0xFB2B },   //              שׂ      //
    { "shinsindot",                             0xFB2B },   //              שׂ      //
    { "shinsindothebrew",                       0xFB2B },   //              שׂ      //
    { "shindageshshindot",                      0xFB2C },   //              שּׁ      //
    { "shindageshshindothebrew",                0xFB2C },   //              שּׁ      //
    { "shindageshsindot",                       0xFB2D },   //              שּׂ      //
    { "shindageshsindothebrew",                 0xFB2D },   //              שּׂ      //
    { "alefpatahhebrew",                        0xFB2E },   //              אַ      //
    { "alefqamatshebrew",                       0xFB2F },   //              אָ      //
    { "alefdageshhebrew",                       0xFB30 },   //              אּ      //
    { "betdagesh",                              0xFB31 },   //              בּ      //
    { "betdageshhebrew",                        0xFB31 },   //              בּ      //
    { "gimeldagesh",                            0xFB32 },   //              גּ      //
    { "gimeldageshhebrew",                      0xFB32 },   //              גּ      //
    { "daletdagesh",                            0xFB33 },   //              דּ      //
    { "daletdageshhebrew",                      0xFB33 },   //              דּ      //
    { "hedagesh",                               0xFB34 },   //              הּ      //
    { "hedageshhebrew",                         0xFB34 },   //              הּ      //
    { "afii57723",                              0xFB35 },   //              וּ      //
    { "vavdagesh",                              0xFB35 },   //              וּ      //
    { "vavdagesh65",                            0xFB35 },   //              וּ      //
    { "vavdageshhebrew",                        0xFB35 },   //              וּ      //
    { "zayindagesh",                            0xFB36 },   //              זּ      //
    { "zayindageshhebrew",                      0xFB36 },   //              זּ      //
    { "tetdagesh",                              0xFB38 },   //              טּ      //
    { "tetdageshhebrew",                        0xFB38 },   //              טּ      //
    { "yoddagesh",                              0xFB39 },   //              יּ      //
    { "yoddageshhebrew",                        0xFB39 },   //              יּ      //
    { "finalkafdagesh",                         0xFB3A },   //              ךּ      //
    { "finalkafdageshhebrew",                   0xFB3A },   //              ךּ      //
    { "kafdagesh",                              0xFB3B },   //              כּ      //
    { "kafdageshhebrew",                        0xFB3B },   //              כּ      //
    { "lameddagesh",                            0xFB3C },   //              לּ      //
    { "lameddageshhebrew",                      0xFB3C },   //              לּ      //
    { "memdagesh",                              0xFB3E },   //              מּ      //
    { "memdageshhebrew",                        0xFB3E },   //              מּ      //
    { "nundagesh",                              0xFB40 },   //              נּ      //
    { "nundageshhebrew",                        0xFB40 },   //              נּ      //
    { "samekhdagesh",                           0xFB41 },   //              סּ      //
    { "samekhdageshhebrew",                     0xFB41 },   //              סּ      //
    { "pefinaldageshhebrew",                    0xFB43 },   //              ףּ      //
    { "pedagesh",                               0xFB44 },   //              פּ      //
    { "pedageshhebrew",                         0xFB44 },   //              פּ      //
    { "tsadidagesh",                            0xFB46 },   //              צּ      //
    { "tsadidageshhebrew",                      0xFB46 },   //              צּ      //
    { "qofdagesh",                              0xFB47 },   //              קּ      //
    { "qofdageshhebrew",                        0xFB47 },   //              קּ      //
    { "reshdageshhebrew",                       0xFB48 },   //              רּ      //
    { "shindagesh",                             0xFB49 },   //              שּ      //
    { "shindageshhebrew",                       0xFB49 },   //              שּ      //
    { "tavdages",                               0xFB4A },   //              תּ      //
    { "tavdagesh",                              0xFB4A },   //              תּ      //
    { "tavdageshhebrew",                        0xFB4A },   //              תּ      //
    { "afii57700",                              0xFB4B },   //              וֹ      //
    { "vavholam",                               0xFB4B },   //              וֹ      //
    { "vavholamhebrew",                         0xFB4B },   //              וֹ      //
    { "betrafehebrew",                          0xFB4C },   //              בֿ      //
    { "kafrafehebrew",                          0xFB4D },   //              כֿ      //
    { "perafehebrew",                           0xFB4E },   //              פֿ      //
    { "aleflamedhebrew",                        0xFB4F },   //              ﭏ      //
    { "pehfinalarabic",                         0xFB57 },   //              ﭗ      //
    { "pehinitialarabic",                       0xFB58 },   //              ﭘ      //
    { "pehmedialarabic",                        0xFB59 },   //              ﭙ      //
    { "ttehfinalarabic",                        0xFB67 },   //              ﭧ      //
    { "ttehinitialarabic",                      0xFB68 },   //              ﭨ      //
    { "ttehmedialarabic",                       0xFB69 },   //              ﭩ      //
    { "vehfinalarabic",                         0xFB6B },   //              ﭫ      //
    { "vehinitialarabic",                       0xFB6C },   //              ﭬ      //
    { "vehmedialarabic",                        0xFB6D },   //              ﭭ      //
    { "tchehfinalarabic",                       0xFB7B },   //              ﭻ      //
    { "tchehinitialarabic",                     0xFB7C },   //              ﭼ      //
    { "tchehmeeminitialarabic",                 0xFB7C },   //              ﭼ      //
    { "tchehmedialarabic",                      0xFB7D },   //              ﭽ      //
    { "ddalfinalarabic",                        0xFB89 },   //              ﮉ      //
    { "jehfinalarabic",                         0xFB8B },   //              ﮋ      //
    { "rrehfinalarabic",                        0xFB8D },   //              ﮍ      //
    { "gaffinalarabic",                         0xFB93 },   //              ﮓ      //
    { "gafinitialarabic",                       0xFB94 },   //              ﮔ      //
    { "gafmedialarabic",                        0xFB95 },   //              ﮕ      //
    { "noonghunnafinalarabic",                  0xFB9F },   //              ﮟ      //
    { "hehhamzaaboveisolatedarabic",            0xFBA4 },   //              ﮤ      //
    { "hehhamzaabovefinalarabic",               0xFBA5 },   //              ﮥ      //
    { "hehfinalaltonearabic",                   0xFBA7 },   //              ﮧ      //
    { "hehinitialaltonearabic",                 0xFBA8 },   //              ﮨ      //
    { "hehmedialaltonearabic",                  0xFBA9 },   //              ﮩ      //
    { "yehbarreefinalarabic",                   0xFBAF },   //              ﮯ      //
    { "behmeemisolatedarabic",                  0xFC08 },   //              ﰈ      //
    { "tehjeemisolatedarabic",                  0xFC0B },   //              ﰋ      //
    { "tehhahisolatedarabic",                   0xFC0C },   //              ﰌ      //
    { "tehmeemisolatedarabic",                  0xFC0E },   //              ﰎ      //
    { "meemmeemisolatedarabic",                 0xFC48 },   //              ﱈ      //
    { "noonjeemisolatedarabic",                 0xFC4B },   //              ﱋ      //
    { "noonmeemisolatedarabic",                 0xFC4E },   //              ﱎ      //
    { "yehmeemisolatedarabic",                  0xFC58 },   //              ﱘ      //
    { "shaddadammatanarabic",                   0xFC5E },   //              ﱞ      //
    { "shaddakasratanarabic",                   0xFC5F },   //              ﱟ      //
    { "shaddafathaarabic",                      0xFC60 },   //              ﱠ      //
    { "shaddadammaarabic",                      0xFC61 },   //              ﱡ      //
    { "shaddakasraarabic",                      0xFC62 },   //              ﱢ      //
    { "behnoonfinalarabic",                     0xFC6D },   //              ﱭ      //
    { "tehnoonfinalarabic",                     0xFC73 },   //              ﱳ      //
    { "noonnoonfinalarabic",                    0xFC8D },   //              ﲍ      //
    { "yehnoonfinalarabic",                     0xFC94 },   //              ﲔ      //
    { "behmeeminitialarabic",                   0xFC9F },   //              ﲟ      //
    { "tehjeeminitialarabic",                   0xFCA1 },   //              ﲡ      //
    { "tehhahinitialarabic",                    0xFCA2 },   //              ﲢ      //
    { "tehmeeminitialarabic",                   0xFCA4 },   //              ﲤ      //
    { "lamjeeminitialarabic",                   0xFCC9 },   //              ﳉ      //
    { "lamhahinitialarabic",                    0xFCCA },   //              ﳊ      //
    { "lamkhahinitialarabic",                   0xFCCB },   //              ﳋ      //
    { "lammeeminitialarabic",                   0xFCCC },   //              ﳌ      //
    { "meemmeeminitialarabic",                  0xFCD1 },   //              ﳑ      //
    { "noonjeeminitialarabic",                  0xFCD2 },   //              ﳒ      //
    { "noonmeeminitialarabic",                  0xFCD5 },   //              ﳕ      //
    { "yehmeeminitialarabic",                   0xFCDD },   //              ﳝ      //
    { "parenleftaltonearabic",                  0xFD3E },   //              ﴾      //
    { "parenrightaltonearabic",                 0xFD3F },   //              ﴿      //
    { "lammeemhahinitialarabic",                0xFD88 },   //              ﶈ      //
    { "lamlamhehisolatedarabic",                0xFDF2 },   //              ﷲ      //
    { "sallallahoualayhewasallamarabic",        0xFDFA },   //              ﷺ      //
    { "twodotleadervertical",                   0xFE30 },   //              ︰      //
    { "emdashvertical",                         0xFE31 },   //              ︱      //
    { "endashvertical",                         0xFE32 },   //              ︲      //
    { "underscorevertical",                     0xFE33 },   //              ︳      //
    { "wavyunderscorevertical",                 0xFE34 },   //              ︴      //
    { "parenleftvertical",                      0xFE35 },   //              ︵      //
    { "parenrightvertical",                     0xFE36 },   //              ︶      //
    { "braceleftvertical",                      0xFE37 },   //              ︷      //
    { "bracerightvertical",                     0xFE38 },   //              ︸      //
    { "tortoiseshellbracketleftvertical",       0xFE39 },   //              ︹      //
    { "tortoiseshellbracketrightvertical",      0xFE3A },   //              ︺      //
    { "blacklenticularbracketleftvertical",     0xFE3B },   //              ︻      //
    { "blacklenticularbracketrightvertical",    0xFE3C },   //              ︼      //
    { "dblanglebracketleftvertical",            0xFE3D },   //              ︽      //
    { "dblanglebracketrightvertical",           0xFE3E },   //              ︾      //
    { "anglebracketleftvertical",               0xFE3F },   //              ︿      //
    { "anglebracketrightvertical",              0xFE40 },   //              ﹀      //
    { "cornerbracketleftvertical",              0xFE41 },   //              ﹁      //
    { "cornerbracketrightvertical",             0xFE42 },   //              ﹂      //
    { "whitecornerbracketleftvertical",         0xFE43 },   //              ﹃      //
    { "whitecornerbracketrightvertical",        0xFE44 },   //              ﹄      //
    { "overlinedashed",                         0xFE49 },   //              ﹉      //
    { "overlinecenterline",                     0xFE4A },   //              ﹊      //
    { "overlinewavy",                           0xFE4B },   //              ﹋      //
    { "overlinedblwavy",                        0xFE4C },   //              ﹌      //
    { "lowlinedashed",                          0xFE4D },   //              ﹍      //
    { "lowlinecenterline",                      0xFE4E },   //              ﹎      //
    { "underscorewavy",                         0xFE4F },   //              ﹏      //
    { "commasmall",                             0xFE50 },   //              ﹐      //
    { "periodsmall",                            0xFE52 },   //              ﹒      //
    { "semicolonsmall",                         0xFE54 },   //              ﹔      //
    { "colonsmall",                             0xFE55 },   //              ﹕      //
    { "parenleftsmall",                         0xFE59 },   //              ﹙      //
    { "parenrightsmall",                        0xFE5A },   //              ﹚      //
    { "braceleftsmall",                         0xFE5B },   //              ﹛      //
    { "bracerightsmall",                        0xFE5C },   //              ﹜      //
    { "tortoiseshellbracketleftsmall",          0xFE5D },   //              ﹝      //
    { "tortoiseshellbracketrightsmall",         0xFE5E },   //              ﹞      //
    { "numbersignsmall",                        0xFE5F },   //              ﹟      //
    { "asterisksmall",                          0xFE61 },   //              ﹡      //
    { "plussmall",                              0xFE62 },   //              ﹢      //
    { "hyphensmall",                            0xFE63 },   //              ﹣      //
    { "lesssmall",                              0xFE64 },   //              ﹤      //
    { "greatersmall",                           0xFE65 },   //              ﹥      //
    { "equalsmall",                             0xFE66 },   //              ﹦      //
    { "dollarsmall",                            0xFE69 },   //              ﹩      //
    { "percentsmall",                           0xFE6A },   //              ﹪      //
    { "atsmall",                                0xFE6B },   //              ﹫      //
    { "alefmaddaabovefinalarabic",              0xFE82 },   //              ﺂ      //
    { "alefhamzaabovefinalarabic",              0xFE84 },   //              ﺄ      //
    { "wawhamzaabovefinalarabic",               0xFE86 },   //              ﺆ      //
    { "alefhamzabelowfinalarabic",              0xFE88 },   //              ﺈ      //
    { "yehhamzaabovefinalarabic",               0xFE8A },   //              ﺊ      //
    { "yehhamzaaboveinitialarabic",             0xFE8B },   //              ﺋ      //
    { "yehhamzaabovemedialarabic",              0xFE8C },   //              ﺌ      //
    { "aleffinalarabic",                        0xFE8E },   //              ﺎ      //
    { "behfinalarabic",                         0xFE90 },   //              ﺐ      //
    { "behinitialarabic",                       0xFE91 },   //              ﺑ      //
    { "behmedialarabic",                        0xFE92 },   //              ﺒ      //
    { "tehmarbutafinalarabic",                  0xFE94 },   //              ﺔ      //
    { "tehfinalarabic",                         0xFE96 },   //              ﺖ      //
    { "tehinitialarabic",                       0xFE97 },   //              ﺗ      //
    { "tehmedialarabic",                        0xFE98 },   //              ﺘ      //
    { "thehfinalarabic",                        0xFE9A },   //              ﺚ      //
    { "thehinitialarabic",                      0xFE9B },   //              ﺛ      //
    { "thehmedialarabic",                       0xFE9C },   //              ﺜ      //
    { "jeemfinalarabic",                        0xFE9E },   //              ﺞ      //
    { "jeeminitialarabic",                      0xFE9F },   //              ﺟ      //
    { "jeemmedialarabic",                       0xFEA0 },   //              ﺠ      //
    { "hahfinalarabic",                         0xFEA2 },   //              ﺢ      //
    { "hahinitialarabic",                       0xFEA3 },   //              ﺣ      //
    { "hahmedialarabic",                        0xFEA4 },   //              ﺤ      //
    { "khahfinalarabic",                        0xFEA6 },   //              ﺦ      //
    { "khahinitialarabic",                      0xFEA7 },   //              ﺧ      //
    { "khahmedialarabic",                       0xFEA8 },   //              ﺨ      //
    { "dalfinalarabic",                         0xFEAA },   //              ﺪ      //
    { "thalfinalarabic",                        0xFEAC },   //              ﺬ      //
    { "rehfinalarabic",                         0xFEAE },   //              ﺮ      //
    { "zainfinalarabic",                        0xFEB0 },   //              ﺰ      //
    { "seenfinalarabic",                        0xFEB2 },   //              ﺲ      //
    { "seeninitialarabic",                      0xFEB3 },   //              ﺳ      //
    { "seenmedialarabic",                       0xFEB4 },   //              ﺴ      //
    { "sheenfinalarabic",                       0xFEB6 },   //              ﺶ      //
    { "sheeninitialarabic",                     0xFEB7 },   //              ﺷ      //
    { "sheenmedialarabic",                      0xFEB8 },   //              ﺸ      //
    { "sadfinalarabic",                         0xFEBA },   //              ﺺ      //
    { "sadinitialarabic",                       0xFEBB },   //              ﺻ      //
    { "sadmedialarabic",                        0xFEBC },   //              ﺼ      //
    { "dadfinalarabic",                         0xFEBE },   //              ﺾ      //
    { "dadinitialarabic",                       0xFEBF },   //              ﺿ      //
    { "dadmedialarabic",                        0xFEC0 },   //              ﻀ      //
    { "tahfinalarabic",                         0xFEC2 },   //              ﻂ      //
    { "tahinitialarabic",                       0xFEC3 },   //              ﻃ      //
    { "tahmedialarabic",                        0xFEC4 },   //              ﻄ      //
    { "zahfinalarabic",                         0xFEC6 },   //              ﻆ      //
    { "zahinitialarabic",                       0xFEC7 },   //              ﻇ      //
    { "zahmedialarabic",                        0xFEC8 },   //              ﻈ      //
    { "ainfinalarabic",                         0xFECA },   //              ﻊ      //
    { "aininitialarabic",                       0xFECB },   //              ﻋ      //
    { "ainmedialarabic",                        0xFECC },   //              ﻌ      //
    { "ghainfinalarabic",                       0xFECE },   //              ﻎ      //
    { "ghaininitialarabic",                     0xFECF },   //              ﻏ      //
    { "ghainmedialarabic",                      0xFED0 },   //              ﻐ      //
    { "fehfinalarabic",                         0xFED2 },   //              ﻒ      //
    { "fehinitialarabic",                       0xFED3 },   //              ﻓ      //
    { "fehmedialarabic",                        0xFED4 },   //              ﻔ      //
    { "qaffinalarabic",                         0xFED6 },   //              ﻖ      //
    { "qafinitialarabic",                       0xFED7 },   //              ﻗ      //
    { "qafmedialarabic",                        0xFED8 },   //              ﻘ      //
    { "kaffinalarabic",                         0xFEDA },   //              ﻚ      //
    { "kafinitialarabic",                       0xFEDB },   //              ﻛ      //
    { "kafmedialarabic",                        0xFEDC },   //              ﻜ      //
    { "lamfinalarabic",                         0xFEDE },   //              ﻞ      //
    { "laminitialarabic",                       0xFEDF },   //              ﻟ      //
    { "lammeemjeeminitialarabic",               0xFEDF },   //              ﻟ      //
    { "lammeemkhahinitialarabic",               0xFEDF },   //              ﻟ      //
    { "lammedialarabic",                        0xFEE0 },   //              ﻠ      //
    { "meemfinalarabic",                        0xFEE2 },   //              ﻢ      //
    { "meeminitialarabic",                      0xFEE3 },   //              ﻣ      //
    { "meemmedialarabic",                       0xFEE4 },   //              ﻤ      //
    { "noonfinalarabic",                        0xFEE6 },   //              ﻦ      //
    { "nooninitialarabic",                      0xFEE7 },   //              ﻧ      //
    { "noonhehinitialarabic",                   0xFEE7 },   //              ﻧ      //
    { "noonmedialarabic",                       0xFEE8 },   //              ﻨ      //
    { "hehfinalalttwoarabic",                   0xFEEA },   //              ﻪ      //
    { "hehfinalarabic",                         0xFEEA },   //              ﻪ      //
    { "hehinitialarabic",                       0xFEEB },   //              ﻫ      //
    { "hehmedialarabic",                        0xFEEC },   //              ﻬ      //
    { "wawfinalarabic",                         0xFEEE },   //              ﻮ      //
    { "alefmaksurafinalarabic",                 0xFEF0 },   //              ﻰ      //
    { "yehfinalarabic",                         0xFEF2 },   //              ﻲ      //
    { "alefmaksurainitialarabic",               0xFEF3 },   //              ﻳ      //
    { "yehinitialarabic",                       0xFEF3 },   //              ﻳ      //
    { "alefmaksuramedialarabic",                0xFEF4 },   //              ﻴ      //
    { "yehmedialarabic",                        0xFEF4 },   //              ﻴ      //
    { "lamalefmaddaaboveisolatedarabic",        0xFEF5 },   //              ﻵ      //
    { "lamalefmaddaabovefinalarabic",           0xFEF6 },   //              ﻶ      //
    { "lamalefhamzaaboveisolatedarabic",        0xFEF7 },   //              ﻷ      //
    { "lamalefhamzaabovefinalarabic",           0xFEF8 },   //              ﻸ      //
    { "lamalefhamzabelowisolatedarabic",        0xFEF9 },   //              ﻹ      //
    { "lamalefhamzabelowfinalarabic",           0xFEFA },   //              ﻺ      //
    { "lamalefisolatedarabic",                  0xFEFB },   //              ﻻ      //
    { "lamaleffinalarabic",                     0xFEFC },   //              ﻼ      //
    { "zerowidthjoiner",                        0xFEFF },   //              ﻿      //
    { "exclammonospace",                        0xFF01 },   //              ！      //
    { "quotedblmonospace",                      0xFF02 },   //              ＂      //
    { "numbersignmonospace",                    0xFF03 },   //              ＃      //
    { "dollarmonospace",                        0xFF04 },   //              ＄      //
    { "percentmonospace",                       0xFF05 },   //              ％      //
    { "ampersandmonospace",                     0xFF06 },   //              ＆      //
    { "quotesinglemonospace",                   0xFF07 },   //              ＇      //
    { "parenleftmonospace",                     0xFF08 },   //              （      //
    { "parenrightmonospace",                    0xFF09 },   //              ）      //
    { "asteriskmonospace",                      0xFF0A },   //              ＊      //
    { "plusmonospace",                          0xFF0B },   //              ＋      //
    { "commamonospace",                         0xFF0C },   //              ，      //
    { "hyphenmonospace",                        0xFF0D },   //              －      //
    { "periodmonospace",                        0xFF0E },   //              ．      //
    { "slashmonospace",                         0xFF0F },   //              ／      //
    { "zeromonospace",                          0xFF10 },   //              ０      //
    { "onemonospace",                           0xFF11 },   //              １      //
    { "twomonospace",                           0xFF12 },   //              ２      //
    { "threemonospace",                         0xFF13 },   //              ３      //
    { "fourmonospace",                          0xFF14 },   //              ４      //
    { "fivemonospace",                          0xFF15 },   //              ５      //
    { "sixmonospace",                           0xFF16 },   //              ６      //
    { "sevenmonospace",                         0xFF17 },   //              ７      //
    { "eightmonospace",                         0xFF18 },   //              ８      //
    { "ninemonospace",                          0xFF19 },   //              ９      //
    { "colonmonospace",                         0xFF1A },   //              ：      //
    { "semicolonmonospace",                     0xFF1B },   //              ；      //
    { "lessmonospace",                          0xFF1C },   //              ＜      //
    { "equalmonospace",                         0xFF1D },   //              ＝      //
    { "greatermonospace",                       0xFF1E },   //              ＞      //
    { "questionmonospace",                      0xFF1F },   //              ？      //
    { "atmonospace",                            0xFF20 },   //              ＠      //
    { "Amonospace",                             0xFF21 },   //              Ａ      //
    { "Bmonospace",                             0xFF22 },   //              Ｂ      //
    { "Cmonospace",                             0xFF23 },   //              Ｃ      //
    { "Dmonospace",                             0xFF24 },   //              Ｄ      //
    { "Emonospace",                             0xFF25 },   //              Ｅ      //
    { "Fmonospace",                             0xFF26 },   //              Ｆ      //
    { "Gmonospace",                             0xFF27 },   //              Ｇ      //
    { "Hmonospace",                             0xFF28 },   //              Ｈ      //
    { "Imonospace",                             0xFF29 },   //              Ｉ      //
    { "Jmonospace",                             0xFF2A },   //              Ｊ      //
    { "Kmonospace",                             0xFF2B },   //              Ｋ      //
    { "Lmonospace",                             0xFF2C },   //              Ｌ      //
    { "Mmonospace",                             0xFF2D },   //              Ｍ      //
    { "Nmonospace",                             0xFF2E },   //              Ｎ      //
    { "Omonospace",                             0xFF2F },   //              Ｏ      //
    { "Pmonospace",                             0xFF30 },   //              Ｐ      //
    { "Qmonospace",                             0xFF31 },   //              Ｑ      //
    { "Rmonospace",                             0xFF32 },   //              Ｒ      //
    { "Smonospace",                             0xFF33 },   //              Ｓ      //
    { "Tmonospace",                             0xFF34 },   //              Ｔ      //
    { "Umonospace",                             0xFF35 },   //              Ｕ      //
    { "Vmonospace",                             0xFF36 },   //              Ｖ      //
    { "Wmonospace",                             0xFF37 },   //              Ｗ      //
    { "Xmonospace",                             0xFF38 },   //              Ｘ      //
    { "Ymonospace",                             0xFF39 },   //              Ｙ      //
    { "Zmonospace",                             0xFF3A },   //              Ｚ      //
    { "bracketleftmonospace",                   0xFF3B },   //              ［      //
    { "backslashmonospace",                     0xFF3C },   //              ＼      //
    { "bracketrightmonospace",                  0xFF3D },   //              ］      //
    { "asciicircummonospace",                   0xFF3E },   //              ＾      //
    { "underscoremonospace",                    0xFF3F },   //              ＿      //
    { "gravemonospace",                         0xFF40 },   //              ｀      //
    { "amonospace",                             0xFF41 },   //              ａ      //
    { "bmonospace",                             0xFF42 },   //              ｂ      //
    { "cmonospace",                             0xFF43 },   //              ｃ      //
    { "dmonospace",                             0xFF44 },   //              ｄ      //
    { "emonospace",                             0xFF45 },   //              ｅ      //
    { "fmonospace",                             0xFF46 },   //              ｆ      //
    { "gmonospace",                             0xFF47 },   //              ｇ      //
    { "hmonospace",                             0xFF48 },   //              ｈ      //
    { "imonospace",                             0xFF49 },   //              ｉ      //
    { "jmonospace",                             0xFF4A },   //              ｊ      //
    { "kmonospace",                             0xFF4B },   //              ｋ      //
    { "lmonospace",                             0xFF4C },   //              ｌ      //
    { "mmonospace",                             0xFF4D },   //              ｍ      //
    { "nmonospace",                             0xFF4E },   //              ｎ      //
    { "omonospace",                             0xFF4F },   //              ｏ      //
    { "pmonospace",                             0xFF50 },   //              ｐ      //
    { "qmonospace",                             0xFF51 },   //              ｑ      //
    { "rmonospace",                             0xFF52 },   //              ｒ      //
    { "smonospace",                             0xFF53 },   //              ｓ      //
    { "tmonospace",                             0xFF54 },   //              ｔ      //
    { "umonospace",                             0xFF55 },   //              ｕ      //
    { "vmonospace",                             0xFF56 },   //              ｖ      //
    { "wmonospace",                             0xFF57 },   //              ｗ      //
    { "xmonospace",                             0xFF58 },   //              ｘ      //
    { "ymonospace",                             0xFF59 },   //              ｙ      //
    { "zmonospace",                             0xFF5A },   //              ｚ      //
    { "braceleftmonospace",                     0xFF5B },   //              ｛      //
    { "barmonospace",                           0xFF5C },   //              ｜      //
    { "bracerightmonospace",                    0xFF5D },   //              ｝      //
    { "asciitildemonospace",                    0xFF5E },   //              ～      //
    { "periodhalfwidth",                        0xFF61 },   //              ｡      //
    { "cornerbracketlefthalfwidth",             0xFF62 },   //              ｢      //
    { "cornerbracketrighthalfwidth",            0xFF63 },   //              ｣      //
    { "ideographiccommaleft",                   0xFF64 },   //              ､      //
    { "middledotkatakanahalfwidth",             0xFF65 },   //              ･      //
    { "wokatakanahalfwidth",                    0xFF66 },   //              ｦ      //
    { "asmallkatakanahalfwidth",                0xFF67 },   //              ｧ      //
    { "ismallkatakanahalfwidth",                0xFF68 },   //              ｨ      //
    { "usmallkatakanahalfwidth",                0xFF69 },   //              ｩ      //
    { "esmallkatakanahalfwidth",                0xFF6A },   //              ｪ      //
    { "osmallkatakanahalfwidth",                0xFF6B },   //              ｫ      //
    { "yasmallkatakanahalfwidth",               0xFF6C },   //              ｬ      //
    { "yusmallkatakanahalfwidth",               0xFF6D },   //              ｭ      //
    { "yosmallkatakanahalfwidth",               0xFF6E },   //              ｮ      //
    { "tusmallkatakanahalfwidth",               0xFF6F },   //              ｯ      //
    { "katahiraprolongmarkhalfwidth",           0xFF70 },   //              ｰ      //
    { "akatakanahalfwidth",                     0xFF71 },   //              ｱ      //
    { "ikatakanahalfwidth",                     0xFF72 },   //              ｲ      //
    { "ukatakanahalfwidth",                     0xFF73 },   //              ｳ      //
    { "ekatakanahalfwidth",                     0xFF74 },   //              ｴ      //
    { "okatakanahalfwidth",                     0xFF75 },   //              ｵ      //
    { "kakatakanahalfwidth",                    0xFF76 },   //              ｶ      //
    { "kikatakanahalfwidth",                    0xFF77 },   //              ｷ      //
    { "kukatakanahalfwidth",                    0xFF78 },   //              ｸ      //
    { "kekatakanahalfwidth",                    0xFF79 },   //              ｹ      //
    { "kokatakanahalfwidth",                    0xFF7A },   //              ｺ      //
    { "sakatakanahalfwidth",                    0xFF7B },   //              ｻ      //
    { "sikatakanahalfwidth",                    0xFF7C },   //              ｼ      //
    { "sukatakanahalfwidth",                    0xFF7D },   //              ｽ      //
    { "sekatakanahalfwidth",                    0xFF7E },   //              ｾ      //
    { "sokatakanahalfwidth",                    0xFF7F },   //              ｿ      //
    { "takatakanahalfwidth",                    0xFF80 },   //              ﾀ      //
    { "tikatakanahalfwidth",                    0xFF81 },   //              ﾁ      //
    { "tukatakanahalfwidth",                    0xFF82 },   //              ﾂ      //
    { "tekatakanahalfwidth",                    0xFF83 },   //              ﾃ      //
    { "tokatakanahalfwidth",                    0xFF84 },   //              ﾄ      //
    { "nakatakanahalfwidth",                    0xFF85 },   //              ﾅ      //
    { "nikatakanahalfwidth",                    0xFF86 },   //              ﾆ      //
    { "nukatakanahalfwidth",                    0xFF87 },   //              ﾇ      //
    { "nekatakanahalfwidth",                    0xFF88 },   //              ﾈ      //
    { "nokatakanahalfwidth",                    0xFF89 },   //              ﾉ      //
    { "hakatakanahalfwidth",                    0xFF8A },   //              ﾊ      //
    { "hikatakanahalfwidth",                    0xFF8B },   //              ﾋ      //
    { "hukatakanahalfwidth",                    0xFF8C },   //              ﾌ      //
    { "hekatakanahalfwidth",                    0xFF8D },   //              ﾍ      //
    { "hokatakanahalfwidth",                    0xFF8E },   //              ﾎ      //
    { "makatakanahalfwidth",                    0xFF8F },   //              ﾏ      //
    { "mikatakanahalfwidth",                    0xFF90 },   //              ﾐ      //
    { "mukatakanahalfwidth",                    0xFF91 },   //              ﾑ      //
    { "mekatakanahalfwidth",                    0xFF92 },   //              ﾒ      //
    { "mokatakanahalfwidth",                    0xFF93 },   //              ﾓ      //
    { "yakatakanahalfwidth",                    0xFF94 },   //              ﾔ      //
    { "yukatakanahalfwidth",                    0xFF95 },   //              ﾕ      //
    { "yokatakanahalfwidth",                    0xFF96 },   //              ﾖ      //
    { "rakatakanahalfwidth",                    0xFF97 },   //              ﾗ      //
    { "rikatakanahalfwidth",                    0xFF98 },   //              ﾘ      //
    { "rukatakanahalfwidth",                    0xFF99 },   //              ﾙ      //
    { "rekatakanahalfwidth",                    0xFF9A },   //              ﾚ      //
    { "rokatakanahalfwidth",                    0xFF9B },   //              ﾛ      //
    { "wakatakanahalfwidth",                    0xFF9C },   //              ﾜ      //
    { "nkatakanahalfwidth",                     0xFF9D },   //              ﾝ      //
    { "voicedmarkkanahalfwidth",                0xFF9E },   //              ﾞ      //
    { "semivoicedmarkkanahalfwidth",            0xFF9F },   //              ﾟ      //
    { "centmonospace",                          0xFFE0 },   //              ￠      //
    { "sterlingmonospace",                      0xFFE1 },   //              ￡      //
    { "macronmonospace",                        0xFFE3 },   //              ￣      //
    { "yenmonospace",                           0xFFE5 },   //              ￥      //
    { "wonmonospace",                           0xFFE6 },   //              ￦      //
    { "f_k",                                    0xE803 },   //                    // -------------------- ftp://ftp.u-aizu.ac.jp/pub/tex/CTAN-historic/fonts/tex-gyre/chorus/1.103/qzc-info.pdf //
    { "acute.cap",                              0xEA00 },   //                    //
    { "Acute",                                  0xEA00 },   //                    //
    { "uni0301.cap",                            0xEA01 },   //                    //
    { "Acutecomb",                              0xEA01 },   //                    //
    { "breve.cap",                              0xEA02 },   //                    //
    { "Breve",                                  0xEA02 },   //                    //
    { "space_uni0306_uni0301.cap",              0xEA03 },   //                    //
    { "Breveacute",                             0xEA03 },   //                    //
    { "space_uni0306_uni0301",                  0xEA04 },   //                    //
    { "breveacute",                             0xEA04 },   //                    //
    { "space_uni032E",                          0xEA05 },   //                    //
    { "brevebelow",                             0xEA05 },   //                    //
    { "space_uni032F",                          0xEA06 },   //                    //
    { "brevebelowinverted",                     0xEA06 },   //                    //
    { "uni0306.cap",                            0xEA07 },   //                    //
    { "Brevecomb",                              0xEA07 },   //                    //
    { "space_uni0306_uni0300.cap",              0xEA08 },   //                    //
    { "Brevegrave",                             0xEA08 },   //                    //
    { "space_uni0306_uni0300",                  0xEA09 },   //                    //
    { "brevegrave",                             0xEA09 },   //                    //
    { "space_uni0306_uni0309.cap",              0xEA0A },   //                    //
    { "Brevehookabove",                         0xEA0A },   //                    //
    { "space_uni0306_uni0309",                  0xEA0B },   //                    //
    { "brevehookabove",                         0xEA0B },   //                    //
    { "space_uni0311.cap",                      0xEA0C },   //                    //
    { "Breveinverted",                          0xEA0C },   //                    //
    { "space_uni0311",                          0xEA0D },   //                    //
    { "breveinverted",                          0xEA0D },   //                    //
    { "uni0311.cap",                            0xEA0E },   //                    //
    { "Breveinvertedcomb",                      0xEA0E },   //                    //
    { "space_uni0306_uni0303.cap",              0xEA0F },   //                    //
    { "Brevetilde",                             0xEA0F },   //                    //
    { "space_uni0306_uni0303",                  0xEA10 },   //                    //
    { "brevetilde",                             0xEA10 },   //                    //
    { "caron.cap",                              0xEA11 },   //                    //
    { "Caron",                                  0xEA11 },   //                    //
    { "uni030C.cap",                            0xEA14 },   //                    //
    { "Caroncomb",                              0xEA14 },   //                    //
    { "circumflex.cap",                         0xEA15 },   //                    //
    { "Circumflex",                             0xEA15 },   //                    //
    { "space_uni0302_uni0301.cap",              0xEA16 },   //                    //
    { "Circumflexacute",                        0xEA16 },   //                    //
    { "space_uni0302_uni0301",                  0xEA17 },   //                    //
    { "circumflexacute",                        0xEA17 },   //                    //
    { "uni0302.cap",                            0xEA18 },   //                    //
    { "Circumflexcomb",                         0xEA18 },   //                    //
    { "space_uni0302_uni0300.cap",              0xEA19 },   //                    //
    { "Circumflexgrave",                        0xEA19 },   //                    //
    { "space_uni0302_uni0300",                  0xEA1A },   //                    //
    { "circumflexgrave",                        0xEA1A },   //                    //
    { "space_uni0302_uni0309.cap",              0xEA1B },   //                    //
    { "Circumflexhookabove",                    0xEA1B },   //                    //
    { "space_uni0302_uni0309",                  0xEA1C },   //                    //
    { "circumflexhookabove",                    0xEA1C },   //                    //
    { "space_uni0302_uni0303.cap",              0xEA1D },   //                    //
    { "Circumflextilde",                        0xEA1D },   //                    //
    { "space_uni0302_uni0303",                  0xEA1E },   //                    //
    { "circumflextilde",                        0xEA1E },   //                    //
    { "space_uni0326",                          0xEA1F },   //                    //
    { "commaaccent",                            0xEA1F },   //                    //
    { "breve.cyrcap",                           0xEA21 },   //                    //
    { "cyrBreve",                               0xEA21 },   //                    //
    { "breve.cyr",                              0xEA22 },   //                    //
    { "cyrbreve",                               0xEA22 },   //                    //
    { "circumflex.cyrcap",                      0xEA23 },   //                    //
    { "cyrFlex",                                0xEA23 },   //                    //
    { "circumflex.cyr",                         0xEA24 },   //                    //
    { "cyrflex",                                0xEA24 },   //                    //
    { "space_uni030F.cap",                      0xEA25 },   //                    //
    { "dblGrave",                               0xEA25 },   //                    //
    { "space_uni030F",                          0xEA26 },   //                    //
    { "dblgrave",                               0xEA26 },   //                    //
    { "uni030F.cap",                            0xEA27 },   //                    //
    { "dblGravecomb",                           0xEA27 },   //                    //
    { "dieresis.cap",                           0xEA28 },   //                    //
    { "Dieresis",                               0xEA28 },   //                    //
    { "uni0308.cap",                            0xEA2B },   //                    //
    { "Dieresiscomb",                           0xEA2B },   //                    //
    { "dotaccent.cap",                          0xEA2E },   //                    //
    { "Dotaccent",                              0xEA2E },   //                    //
    { "uni0307.cap",                            0xEA2F },   //                    //
    { "Dotaccentcomb",                          0xEA2F },   //                    //
    { "grave.cap",                              0xEA30 },   //                    //
    { "Grave",                                  0xEA30 },   //                    //
    { "uni0300.cap",                            0xEA31 },   //                    //
    { "Gravecomb",                              0xEA31 },   //                    //
    { "space_uni0309.cap",                      0xEA32 },   //                    //
    { "Hookabove",                              0xEA32 },   //                    //
    { "space_uni0309",                          0xEA33 },   //                    //
    { "hookabove",                              0xEA33 },   //                    //
    { "uni0309.cap",                            0xEA34 },   //                    //
    { "Hookabovecomb",                          0xEA34 },   //                    //
    { "hungarumlaut.cap",                       0xEA36 },   //                    //
    { "Hungarumlaut",                           0xEA36 },   //                    //
    { "uni030B.cap",                            0xEA37 },   //                    //
    { "Hungarumlautcomb",                       0xEA37 },   //                    //
    { "space_uni0332",                          0xEA38 },   //                    //
    { "linebelow",                              0xEA38 },   //                    //
    { "macron.cap",                             0xEA39 },   //                    //
    { "Macron",                                 0xEA39 },   //                    //
    { "macron.cap.alt",                         0xEA3A },   //                    //
    { "Macron.alt",                             0xEA3A },   //                    //
    { "macron.alt",                             0xEA3B },   //                    //
    { "space_uni0331",                          0xEA3C },   //                    //
    { "macronbelow",                            0xEA3C },   //                    //
    { "uni0304.cap",                            0xEA3D },   //                    //
    { "Macroncomb",                             0xEA3D },   //                    //
    { "ring.cap",                               0xEA3E },   //                    //
    { "Ring",                                   0xEA3E },   //                    //
    { "space_uni030A_uni0301.cap",              0xEA3F },   //                    //
    { "Ringacute",                              0xEA3F },   //                    //
    { "space_uni030A_uni0301",                  0xEA40 },   //                    //
    { "ringacute",                              0xEA40 },   //                    //
    { "uni030A.cap",                            0xEA41 },   //                    //
    { "Ringcomb",                               0xEA41 },   //                    //
    { "tilde.cap",                              0xEA42 },   //                    //
    { "Tilde",                                  0xEA42 },   //                    //
    { "space_uni0330",                          0xEA43 },   //                    //
    { "tildebelow",                             0xEA43 },   //                    //
    { "uni0303.cap",                            0xEA44 },   //                    //
    { "Tildecomb",                              0xEA44 },   //                    //
    { "acute.ts1",                              0xEB02 },   //                    //
    { "Aogonekacute",                           0xEB03 },   //                    //
    { "aogonekacute",                           0xEB04 },   //                    //
    { "at.alt",                                 0xEB05 },   //                    //
    { "bigcircle",                              0xEB08 },   //                    //
    { "star.alt",                               0xEB09 },   //                    //
    { "born",                                   0xEB09 },   //                    //
    { "breve.ts1",                              0xEB0A },   //                    //
    { "caron.ts1",                              0xEB0D },   //                    //
    { "copyleft",                               0xEB0F },   //                    //
    { "cwm",                                    0xEB10 },   //                    //
    { "cwmascender",                            0xEB11 },   //                    //
    { "cwmcapital",                             0xEB12 },   //                    //
    { "dblgrave.ts1",                           0xEB15 },   //                    //
    { "died",                                   0xEB16 },   //                    //
    { "dieresis.ts1",                           0xEB17 },   //                    //
    { "space_uni0323",                          0xEB19 },   //                    //
    { "dotbelow",                               0xEB19 },   //                    //
    { "Eogonekacute",                           0xEB1E },   //                    //
    { "eogonekacute",                           0xEB1F },   //                    //
    { "S_S",                                    0xEB28 },   //                    //
    { "Germandbls",                             0xEB28 },   //                    //
    { "gnaborretni",                            0xEB29 },   //                    //
    { "grave.ts1",                              0xEB2A },   //                    //
    { "guarani",                                0xEB2B },   //                    //
    { "hungarumlaut.ts1",                       0xEB2E },   //                    //
    { "hyphen.alt",                             0xEB2F },   //                    //
    { "hyphen.prop",                            0xEB30 },   //                    //
    { "hyphendbl",                              0xEB31 },   //                    //
    { "hyphendbl.alt",                          0xEB32 },   //                    //
    { "Iogonekacute",                           0xEB35 },   //                    //
    { "iogonekacute",                           0xEB36 },   //                    //
    { "Jacute",                                 0xEB3A },   //                    //
    { "jacute",                                 0xEB3B },   //                    //
    { "leaf",                                   0xEB40 },   //                    //
    { "macron.ts1",                             0xEB43 },   //                    //
    { "Oogonekacute",                           0xEB48 },   //                    //
    { "oogonekacute",                           0xEB49 },   //                    //
    { "paragraph.alt",                          0xEB4C },   //                    //
    { "perthousandzero",                        0xEB4D },   //                    //
    { "quotedblbase.ts1",                       0xEB52 },   //                    //
    { "quotesinglbase.ts1",                     0xEB56 },   //                    //
    { "quotesingle.ts1",                        0xEB57 },   //                    //
    { "registered.alt",                         0xEB5A },   //                    //
    { "suppress",                               0xEB61 },   //                    //
    { "tieaccentcapital",                       0xEB63 },   //                    //
    { "tieaccentcapital.new",                   0xEB64 },   //                    //
    { "tieaccentlowercase",                     0xEB65 },   //                    //
    { "tieaccentlowercase.new",                 0xEB66 },   //                    //
    { "asciitilde.low",                         0xEB67 },   //                    //
    { "tildelow",                               0xEB67 },   //                    //
    { "emdash.alt",                             0xEB6B },   //                    //
    { "U_uni032F",                              0xEB6E },   //                    //
    { "Ubrevebelowinverted",                    0xEB6E },   //                    //
    { "u_uni032F",                              0xEB6F },   //                    //
    { "ubrevebelowinverted",                    0xEB6F },   //                    //
    { "H_uni0303",                              0xEC08 },   //                    //
    { "Htilde",                                 0xEC08 },   //                    //
    { "h_uni0303",                              0xEC09 },   //                    //
    { "htilde",                                 0xEC09 },   //                    //
    { "Imacron.alt",                            0xEC07 },   //                    //
    { "imacron.alt",                            0xEC06 },   //                    //
    { "lslash_lslash",                          0xEC0F },   //                    //
    { "L_uni0303",                              0xEC0A },   //                    //
    { "Ltilde",                                 0xEC0A },   //                    //
    { "l_uni0303",                              0xEC0B },   //                    //
    { "ltilde",                                 0xEC0B },   //                    //
    { "T_uni0308",                              0xEC0E },   //                    //
    { "Tdieresis",                              0xEC0E },   //                    //
    { "T_uni0303",                              0xEC0C },   //                    //
    { "Ttilde",                                 0xEC0C },   //                    //
    { "t_uni0303",                              0xEC0D },   //                    //
    { "ttilde",                                 0xEC0D },   //                    //
    { "cent.oldstyle",                          0xF7A2 },   //                    //
    { "dollar.oldstyle",                        0xF724 },   //                    //
    { "dotlessj",                               0xF6BE },   //                    //
    { "eight.prop",                             0xF640 },   //                    //
    { "eight.oldstyle",                         0xF738 },   //                    //
    { "eight.taboldstyle",                      0xF64B },   //                    //
    { "five.prop",                              0xF63D },   //                    //
    { "five.oldstyle",                          0xF735 },   //                    //
    { "five.taboldstyle",                       0xF648 },   //                    //
    { "four.prop",                              0xF63C },   //                    //
    { "four.oldstyle",                          0xF734 },   //                    //
    { "four.taboldstyle",                       0xF647 },   //                    //
    { "nine.prop",                              0xF641 },   //                    //
    { "nine.oldstyle",                          0xF739 },   //                    //
    { "nine.taboldstyle",                       0xF64C },   //                    //
    { "one.prop",                               0xF6DC },   //                    //
    { "one.oldstyle",                           0xF731 },   //                    //
    { "one.taboldstyle",                        0xF644 },   //                    //
    { "seven.prop",                             0xF63F },   //                    //
    { "seven.oldstyle",                         0xF737 },   //                    //
    { "seven.taboldstyle",                      0xF64A },   //                    //
    { "six.prop",                               0xF63E },   //                    //
    { "six.oldstyle",                           0xF736 },   //                    //
    { "six.taboldstyle",                        0xF649 },   //                    //
    { "three.prop",                             0xF63B },   //                    //
    { "three.oldstyle",                         0xF733 },   //                    //
    { "threequartersemdash",                    0xF6DE },   //                    //
    { "three.taboldstyle",                      0xF646 },   //                    //
    { "two.prop",                               0xF63A },   //                    //
    { "two.oldstyle",                           0xF732 },   //                    //
    { "two.taboldstyle",                        0xF645 },   //                    //
    { "zero.prop",                              0xF639 },   //                    //
    { "zero.slash",                             0xF638 },   //                    //
    { "zero.oldstyle",                          0xF730 },   //                    //
    { "zero.taboldstyle",                       0xF643 },   //                    //
    { "blanksymbol",                            0x2422 },   //              ␢      //
    { "mho",                                    0x2127 },   //              ℧      //
    { "ohm",                                    0x2126 },   //              Ω       //
    { "dblbracketleft",                         0x27E6 },   //              ⟦      //
    { "dblbracketright",                        0x27E7 },   //              ⟧      //
    { "married",                                0x26AD },   //              ⚭      //
    { "divorced",                               0x26AE },   //              ⚮      //
    { "naira",                                  0x20A6 },   //              ₦      //
    { "peso",                                   0x20B1 },   //              ₱      //
    { "recipe",                                 0x211E },   //              ℞      //
    { "interrobang",                            0x203D },   //              ‽      //
    { "permyriad",                              0x2031 },   //              ‱      //
    { "baht",                                   0x0E3F },   //              ฿      //
    { "discount",                               0x2052 },   //              ⁒      //
    { "servicemark",                            0x2120 },   //              ℠      //
    { "quillbracketleft",                       0x2045 },   //              ⁅      //
    { "quillbracketright",                      0x2046 },   //              ⁆      //
    { "published",                              0x2117 },   //              ℗      //
    { "two.superior",                           0x00B2 },   //              ²       //
    { "three.superior",                         0x00B3 },   //              ³       //
    { "one.superior",                           0x00B9 },   //              ¹       //
    { "anglearc",                               0x2222 },   //              ∢      //
    { "diameter",                               0x2300 },   //              ⌀      //
    { "Orogate",                                0xEC10 },   //                    // -------------------- http://texdoc.net/texmf-dist/doc/fonts/lm/lm-info.pdf //
    { "orogate",                                0xEC11 },   //                    //
    { "Ifractur",                               0x2111 },   //                       // -------------------- http://math.sut.ac.th/lab/software/texlive/texmf-dist/fonts/map/glyphlist/texglyphlist.txt //
    { "Ng",                                     0x014A },   //                       //
    { "Rfractur",                               0x211C },   //                       //
    { "altselector",                            0xD802 },   //                       # altselector: invalid Unicode //
    { "angbracketleft",                         0x27E8 },   //                       //
    { "angbracketright",                        0x27E9 },   //                       //
    { "arrowbothv",                             0x2195 },   //                       //
    { "arrowdblbothv",                          0x21D5 },   //                       //
    { "arrowleftbothalf",                       0x21BD },   //                       //
    { "arrowlefttophalf",                       0x21BC },   //                       //
    { "arrownortheast",                         0x2197 },   //                       //
    { "arrownorthwest",                         0x2196 },   //                       //
    { "arrowrightbothalf",                      0x21C1 },   //                       //
    { "arrowrighttophalf",                      0x21C0 },   //                       //
    { "arrowsoutheast",                         0x2198 },   //                       //
    { "arrowsouthwest",                         0x2199 },   //                       //
    { "ascendercompwordmark",                   0xD80A },   //                       # ascendercompwordmark: taller cwm, invalid Unicode //
    { "asteriskcentered",                       0x2217 },   //                       //
    { "bardbl",                                 0x2225 },   //                       //
    { "capitalcompwordmark",                    0xD809 },   //                       # capitalcompwordmark: taller cwm, invalid Unicode //
    { "ceilingleft",                            0x2308 },   //                       //
    { "ceilingright",                           0x2309 },   //                       //
    { "circlecopyrt",                           0x20DD },   //                       //
    { "circledivide",                           0x2298 },   //                       //
    { "circledot",                              0x2299 },   //                       //
    { "circleminus",                            0x2296 },   //                       //
    { "coproduct",                              0x2A3F },   //                       //
    { "cwm",                                    0x200C },   //                       # cwm: Unicode for ZWNJ, used for secondary replacement from EC.enc // qzc-info.pdf jau apibrėžtas kodu 0xEB10  //
    { "diamond",                                0x2662 },   //                       // tuščiaviduris diamond //
    { "diamondmath",                            0x22C4 },   //                       //
    { "dotlessj",                               0xF6BE },   //                       # U+0237 is the proposed allocation for dotless j as of Unicode 4.0 # U+1D6A5 is the mathematical italic version approved in Unicode 5.0 //
    { "emptyset",                               0x2205 },   //                       //
    { "emptyslot",                              0xD801 },   //                       # emptyslot: invalid Unicode //
    { "epsilon1",                               0x03F5 },   //                       //
    { "epsiloninv",                             0x03F6 },   //                       //
    { "equivasymptotic",                        0x224D },   //                       //
    { "flat",                                   0x266D },   //                       //
    { "floorleft",                              0x230A },   //                       //
    { "floorright",                             0x230B },   //                       //
    { "follows",                                0x227B },   //                       //
    { "followsequal",                           0x2AB0 },   //                       //
    { "followsorcurly",                         0x227D },   //                       //
    { "greatermuch",                            0x226B },   //                       //
    { "interrobangdown",                        0x2E18 },   //                       //
    { "intersectionsq",                         0x2293 },   //                       //
    { "latticetop",                             0x22A4 },   //                       //
    { "lessmuch",                               0x226A },   //                       //
    { "lscript",                                0x2113 },   //                       //
    { "natural",                                0x266E },   //                       //
    { "negationslash",                          0x0338 },   //                       //
    { "ng",                                     0x014B },   //                       //
    { "owner",                                  0x220B },   //                       //
    { "pertenthousand",                         0x2031 },   //                       //
    { "pi1",                                    0x03D6 },   //                       //
    { "precedesequal",                          0x2AAF },   //                       //
    { "precedesorcurly",                        0x227C },   //                       //
    { "rho1",                                   0x03F1 },   //                       //
    { "ringfitted",                             0xD80D },   //                       # ringfitted: a ring character centered on the x-width of A, invalid Unicode //
    { "sharp",                                  0x266F },   //                       //
    { "similarequal",                           0x2243 },   //                       //
    { "slurabove",                              0x2322 },   //                       //
    { "slurbelow",                              0x2323 },   //                       //
    { "star",                                   0x22C6 },   //                       //
    { "subsetsqequal",                          0x2291 },   //                       //
    { "supersetsqequal",                        0x2292 },   //                       //
    { "triangle",                               0x25B3 },   //                       //
    { "triangleinv",                            0x25BD },   //                       //
    { "triangleleft",                           0x25C1 },   //                       //
    { "triangleright",                          0x25B7 },   //                       //
    { "turnstileleft",                          0x22A2 },   //                       //
    { "turnstileright",                         0x22A3 },   //                       //
    { "twelveudash",                            0xD80C },   //                       # twelveudash: 2/3-em dash //
    { "unionmulti",                             0x228E },   //                       //
    { "unionsq",                                0x2294 },   //                       //
    { "vector",                                 0x20D7 },   //                       //
    { "visualspace",                            0x2423 },   //                       # visualspace: Unicode for OPEN BOX, used for secondary replacement from EC.enc //
    { "wreathproduct",                          0x2240 },   //                       //
    { "Dbar",                                   0x0110 },   //                       # Dbar = Dcroat # -- Marco Kuhlmann reported annoying glyph neologisms in fontinst encodings //
    { "compwordmark",                           0x200C },   //                       # compwordmark = cwm //
    { "dbar",                                   0x0111 },   //                       # dbar = dcroat //
    { "rangedash",                              0x2013 },   //                       # rangedash = endash //
    { "hyphenchar",                             0x002D },   //                       # hyphenchar = hyphen //
    { "punctdash",                              0x2014 },   //                       # punctdash = emdash //
    { "visiblespace",                           0x2423 },   //                       # visiblespace = visualspace //
    { "Yen",                                    0x00A5 },   //                       # -- These character names are used in the MSAM fonts //
    { "anticlockwise",                          0x27F2 },   //                       // 21BA # the MSAM10 glyph is more closed than U+21BA # the MSAM10 glyph's gap is at the top, while U+27F2 is on the left //
    { "arrowaxisleft",                          0xfffd },   //                       // TODO: !!!  //
    { "arrowaxisright",                         0xfffd },   //                       // TODO: !!! //
    { "arrowparrleftright",                     0x21C6 },   //                       //
    { "arrowparrrightleft",                     0x21C4 },   //                       //
    { "arrowtailleft",                          0x21A2 },   //                       //
    { "arrowtailright",                         0x21A3 },   //                       //
    { "arrowtripleleft",                        0x21DA },   //                       //
    { "arrowtripleright",                       0x21DB },   //                       //
    { "axisshort",                              0xfffd },   //                       // TODO: !!! //
    { "between",                                0x226C },   //                       //
    { "check",                                  0x2713 },   //                       # U+2713 is a Zapf dingbat //
    { "circleR",                                0x00AE },   //                       //
    { "circleS",                                0x24C8 },   //                       # the MSAM10 glyph may be smaller than U+24C8 //
    { "circleasterisk",                         0x229B },   //                       //
    { "circleequal",                            0x229C },   //                       //
    { "circlering",                             0x229A },   //                       //
    { "clockwise",                              0x27F3 },   //                       // 21BB # the MSAM10 glyph is more closed than U+21BB # the MSAM10 glyph's gap is at the top, while U+27F3 is on the left //
    { "complement",                             0x2201 },   //                       //
    { "curlyleft",                              0x21AB },   //                       //
    { "curlyright",                             0x21AC },   //                       //
    { "dblarrowdwn",                            0x21CA },   //                       //
    { "dblarrowheadleft",                       0x219E },   //                       //
    { "dblarrowheadright",                      0x21A0 },   //                       //
    { "dblarrowup",                             0x21C8 },   //                       //
    { "defines",                                0x225C },   //                       //
    { "diamondsolid",                           0x2666 },   //                       # U+2666 is BLACK DIAMOND SUIT # U+29EB is BLACK LOZENGE //
    { "difference",                             0x224F },   //                       //
    { "dotplus",                                0x2214 },   //                       //
    { "downfall",                               0x22CE },   //                       //
    { "equaldotleftright",                      0x2252 },   //                       //
    { "equaldotrightleft",                      0x2253 },   //                       //
    { "equalorfollows",                         0x22DF },   //                       //
    { "equalorgreater",                         0x2A96 },   //                       //
    { "equalorless",                            0x2A95 },   //                       //
    { "equalorprecedes",                        0x22DE },   //                       //
    { "equalsdots",                             0x2251 },   //                       //
    { "followsorequal",                         0x227F },   //                       //
    { "forces",                                 0x22A9 },   //                       //
    { "forcesbar",                              0x22AA },   //                       //
    { "fork",                                   0x22D4 },   //                       //
    { "frown",                                  0x2322 },   //                       //
    { "geomequivalent",                         0x224E },   //                       //
    { "greaterdbleqlless",                      0x2A8C },   //                       //
    { "greaterdblequal",                        0x2267 },   //                       //
    { "greaterlessequal",                       0x22DB },   //                       //
    { "greaterorapproxeql",                     0x2A86 },   //                       //
    { "greaterorequalslant",                    0x2A7E },   //                       //
    { "greaterorsimilar",                       0x2273 },   //                       //
    { "harpoondownleft",                        0x21C3 },   //                       //
    { "harpoondownright",                       0x21C2 },   //                       //
    { "harpoonleftright",                       0x21CC },   //                       # MSAM probably misnamed this glyph //
    { "harpoonrightleft",                       0x21CB },   //                       # MSAM probably misnamed this glyph //
    { "harpoonupleft",                          0x21BF },   //                       //
    { "harpoonupright",                         0x21BE },   //                       //
    { "intercal",                               0x22BA },   //                       # U+22BA may be larger than MSAM intercal //
    { "intersectiondbl",                        0x22D2 },   //                       //
    { "lessdbleqlgreater",                      0x2A8B },   //                       //
    { "lessdblequal",                           0x2266 },   //                       //
    { "lessequalgreater",                       0x22DA },   //                       //
    { "lessorapproxeql",                        0x2A85 },   //                       //
    { "lessorequalslant",                       0x2A7D },   //                       //
    { "lessorsimilar",                          0x2272 },   //                       //
    { "maltesecross",                           0x2720 },   //                       //
    { "measuredangle",                          0x2221 },   //                       //
    { "multimap",                               0x22B8 },   //                       //
    { "multiopenleft",                          0x22CB },   //                       //
    { "multiopenright",                         0x22CC },   //                       //
    { "nand",                                   0x22BC },   //                       //
    { "orunderscore",                           0x22BB },   //                       //
    { "perpcorrespond",                         0x2A5E },   //                       # U+2306 PERSPECTIVE is larger than the MSAM glyph //
    { "precedesorequal",                        0x227E },   //                       //
    { "primereverse",                           0x2035 },   //                       //
    { "revasymptequal",                         0x22CD },   //                       //
    { "revsimilar",                             0x223D },   //                       //
    { "rightanglene",                           0x231D },   //                       # U+231D TOP RIGHT CORNER is a quine corner, U+2E23 TOP RIGHT HALF BRACKET is a half bracket. MSAM rightanglene matches the shape of U+231C but the spacing of U+2E23. Similar for other rightangle characters. //
    { "rightanglenw",                           0x231C },   //                       # 2E22 //
    { "rightanglese",                           0x231F },   //                       # 2E25 //
    { "rightanglesw",                           0x231E },   //                       # 2E24 //
    { "ringinequal",                            0x2256 },   //                       //
    { "satisfies",                              0x22A8 },   //                       # U+22A7 MODELS is shorter than U+22A8 TRUE = satisfies. MSAM satisfies is in between. //
    { "shiftleft",                              0x21B0 },   //                       //
    { "shiftright",                             0x21B1 },   //                       //
    { "smile",                                  0x2323 },   //                       //
    { "sphericalangle",                         0x2222 },   //                       //
    { "square",                                 0x25A1 },   //                       # U+25A1 WHITE SQUARE //
    { "squaredot",                              0x22A1 },   //                       //
    { "squareimage",                            0x228F },   //                       //
    { "squareminus",                            0x229F },   //                       //
    { "squaremultiply",                         0x22A0 },   //                       //
    { "squareoriginal",                         0x2290 },   //                       //
    { "squareplus",                             0x229E },   //                       //
    { "squaresmallsolid",                       0x25AA },   //                       # XXX U+25AA BLACK SMALL SQUARE doesn't sit on the baseline //
    { "squaresolid",                            0x25A0 },   //                       //
    { "squiggleleftright",                      0x21AD },   //                       # U+21AD LEFT RIGHT WAVE ARROW is not actually a squiggle arrow //
    { "squiggleright",                          0x21DD },   //                       //
    { "subsetdbl",                              0x22D0 },   //                       //
    { "subsetdblequal",                         0x2AC5 },   //                       //
    { "supersetdbl",                            0x22D1 },   //                       //
    { "supersetdblequal",                       0x2AC6 },   //                       //
    { "triangledownsld",                        0x25BC },   //                       //
    { "triangleleftequal",                      0x22B4 },   //                       // 25C1 0332 # U+22B4 NORMAL SUBGROUP OF OR EQUAL TO is sharper than MSAM //
    { "triangleleftsld",                        0x25C0 },   //                       //
    { "trianglerightequal",                     0x22B5 },   //                       // 25B7 0332# U+22B5 CONTAINS AS NORMAL SUBGROUP OR EQUAL TO is sharper than MSAM //
    { "trianglerightsld",                       0x25B6 },   //                       //
    { "trianglesolid",                          0x25B2 },   //                       //
    { "uniondbl",                               0x22D3 },   //                       //
    { "uprise",                                 0x22CF },   //                       //
    { "Digamma",                                0x03DD },   //                       // 1D7CB # -- These character names are used in the MSBM fonts # U+1D7CB MATHEMATICAL BOLD SMALL DIGAMMA is the closest match to MSBM, although MSBM Digamma's spelling indicates that a capital was intended U+03DD GREEK SMALL LETTER DIGAMMA for fallback //
    { "Finv",                                   0x2132 },   //                       # U+2132 TURNED CAPITAL F is shown as seriffed, MSBM Finv is sans //
    { "Gmir",                                   0x2141 },   //                       # U+2141 TURNED SANS-SERIF CAPITAL G is turned, MSBM Gmir is only reversed //
    { "Omegainv",                               0x2127 },   //                       //
    { "approxorequal",                          0x224A },   //                       //
    { "archleftdown",                           0x21B6 },   //                       //
    { "archrightdown",                          0x21B7 },   //                       //
    { "barshort",                               0xfffd },   //                       // TODO: !!! //
    { "beth",                                   0x2136 },   //                       //
    { "daleth",                                 0x2138 },   //                       //
    { "dividemultiply",                         0x22C7 },   //                       //
    { "downslope",                              0x29F9 },   //                       # U+29F9 BIG REVERSE SOLIDUS seems the right size //
    { "equalorsimilar",                         0x2242 },   //                       //
    { "follownotdbleqv",                        0x2ABA },   //                       //
    { "follownotslnteql",                       0x2AB6 },   //                       //
    { "followornoteqvlnt",                      0x22E9 },   //                       //
    { "greaterdot",                             0x22D7 },   //                       //
    { "greaternotdblequal",                     0x2A8A },   //                       # MSBM misnamed this glyph //
    { "greaternotequal",                        0x2A88 },   //                       //
    { "greaterornotdbleql",                     0x2269 },   //                       //
    { "greaterornotequal",                      0x2269 },   //                       # MSBM greaterornotequal has a vertical negation slash, not U+2269 diagonal //
    { "greaterornotsimilar",                    0xfffd },   //                       // TODO: !!! //
    { "hatwide",                                0xfffd },   //                       // TODO: !!! //
    { "hatwider",                               0xfffd },   //                       // TODO: !!! //
    { "integerdivide",                          0x2216 },   //                       //
    { "lessdot",                                0x22D6 },   //                       //
    { "lessnotdblequal",                        0x2A89 },   //                       # MSBM misnamed this glyph should be lessnotdbleqv //
    { "lessnotdbleqv",                          0x2A89 },   //                       //
    { "lessnotequal",                           0x2A87 },   //                       //
    { "lessornotdbleql",                        0x2268 },   //                       //
    { "lessornotequal",                         0x2268 },   //                       # MSBM lessornotequal has a vertical negation slash, not U+2268 diagonal //
    { "lessornotsimilar",                       0xfffd },   //                       // TODO: !!! //
    { "multicloseleft",                         0x22C9 },   //                       //
    { "multicloseright",                        0x22CA },   //                       //
    { "notapproxequal",                         0x2247 },   //                       //
    { "notarrowboth",                           0x21AE },   //                       //
    { "notarrowleft",                           0x219A },   //                       //
    { "notarrowright",                          0x219B },   //                       //
    { "notbar",                                 0x2224 },   //                       //
    { "notdblarrowboth",                        0x21CE },   //                       //
    { "notdblarrowleft",                        0x21CD },   //                       //
    { "notdblarrowright",                       0x21CF },   //                       //
    { "notexistential",                         0x2204 },   //                       //
    { "notfollows",                             0x2281 },   //                       //
    { "notfollowsoreql",                        0x22E1 },   //                       // 2AB0 0338 # U+22E1 DOES NOT SUCCEED OR EQUAL has a curved equal sign, unlike MSBM //
    { "notforces",                              0x22AE },   //                       //
    { "notforcesextra",                         0x22AF },   //                       //
    { "notgreaterdblequal",                     0xfffd },   //                       // TODO: !!!  2267 0338 # Unicode has no precomposed negation of U+2267 GREATER THAN OVER EQUAL TO //
    { "notgreaterequal",                        0x2271 },   //                       //
    { "notgreaterorslnteql",                    0xfffd },   //                       // TODO: !!!  2A7E 0338 //
    { "notlessdblequal",                        0xfffd },   //                       // TODO: !!!  //
    { "notlessequal",                           0x2270 },   //                       //
    { "notlessorslnteql",                       0xfffd },   //                       // TODO: !!!  2A7D 0338 //
    { "notprecedesoreql",                       0x22E0 },   //                       // 2AAF 0338, # U+22E0 DOES NOT PRECEDE OR EQUAL has a curved equal sign, unlike MSBM //
    { "notsatisfies",                           0x22AD },   //                       //
    { "notshortbar",                            0xfffd },   //                       // TODO: !!! //
    { "notshortparallel",                       0xfffd },   //                       // TODO: !!! //
    { "notsimilar",                             0x2241 },   //                       //
    { "notsubseteql",                           0x2288 },   //                       //
    { "notsubsetordbleql",                      0xfffd },   //                       // TODO: !!!  2AC5 0338 //
    { "notsubsetoreql",                         0x228A },   //                       # U+228A SUBSET OF WITH NOT EQUAL TO negation slash only touches bar below //
    { "notsuperseteql",                         0x2289 },   //                       //
    { "notsupersetordbleql",                    0xfffd },   //                       // TODO: !!!  2AC6 0338 //
    { "notsupersetoreql",                       0x228B },   //                       # U+228A SUPERSET OF WITH NOT EQUAL TO negation slash only touches bar below //
    { "nottriangeqlleft",                       0x22EC },   //                       // 25C1 0332 0338 # U+22EC NOT NORMAL SUBGROUP OF OR EQUAL TO is sharper than MSBM //
    { "nottriangeqlright",                      0x22ED },   //                       // 25B7 0332 0338 # U+22ED DOES NOT CONTAIN AS NORMAL SUBGROUP OR EQUAL is sharper than MSBM //
    { "nottriangleleft",                        0x22EA },   //                       // 25C1 0338 # U+22EA NOT NORMAL SUBGROUP OF is sharper than MSBM //
    { "nottriangleright",                       0x22EB },   //                       // 25B7 0338 # U+22EB DOES NOT CONTAIN AS NORMAL SUBGROUP is sharper than MSBM //
    { "notturnstile",                           0x22AC },   //                       //
    { "parallelshort",                          0xfffd },   //                       // TODO: !!! //
    { "planckover2pi",                          0x210F },   //                       //
    { "planckover2pi1",                         0x210F },   //                       # U+210F PLANCK CONSTANT OVER TWO PI is shown with diagonal slash, which corresponds to MSBM planckover2pi, but this is a font variant //
    { "precedenotdbleqv",                       0x2AB9 },   //                       //
    { "precedenotslnteql",                      0x2AB5 },   //                       //
    { "precedeornoteqvlnt",                     0x22E8 },   //                       //
    { "subsetnoteql",                           0x228A },   //                       //
    { "subsetornotdbleql",                      0x2ACB },   //                       //
    { "subsetornoteql",                         0xfffd },   //                       // TODO: !!! //
    { "supersetnoteql",                         0x228B },   //                       //
    { "supersetornotdbleql",                    0x2ACC },   //                       //
    { "supersetornoteql",                       0xfffd },   //                       // TODO: !!! //
    { "upslope",                                0x29F8 },   //                       # U+29F8 BIG SOLIDUS seems the right size //
    { "angbracketleftBig",                      0xED01 },   //                       // -------------------- glyphtounicode-cmr.tex //
    { "angbracketleftBigg",                     0xED03 },   //                       //
    { "angbracketleftbig",                      0xED02 },   //                       //
    { "angbracketleftbigg",                     0xED04 },   //                       //
    { "angbracketrightBig",                     0xED06 },   //                       //
    { "angbracketrightBigg",                    0xED08 },   //                       //
    { "angbracketrightbig",                     0xED07 },   //                       //
    { "angbracketrightbigg",                    0xED09 },   //                       //
    { "arrowbt",                                0xED0A },   //                       //
    { "arrowdblbt",                             0xED0B },   //                       //
    { "arrowdbltp",                             0xED0E },   //                       //
    { "arrowhookleft",                          0x21A9 },   //                       //
    { "arrowhookright",                         0x21AA },   //                       //
    { "arrowtp",                                0xED11 },   //                       //
    { "arrowvertexdbl",                         0xED12 },   //                       //
    { "backslashBig",                           0xED13 },   //                       //
    { "backslashBigg",                          0xED15 },   //                       //
    { "backslashbig",                           0xED14 },   //                       //
    { "backslashbigg",                          0xED16 },   //                       //
    { "bracehtipdownleft",                      0xED17 },   //                       //
    { "bracehtipdownright",                     0xED18 },   //                       //
    { "bracehtipupleft",                        0xED19 },   //                       //
    { "bracehtipupright",                       0xED1A },   //                       //
    { "braceleftBig",                           0xED1B },   //                       //
    { "braceleftBigg",                          0xED1D },   //                       //
    { "braceleftbig",                           0xED1C },   //                       //
    { "braceleftbigg",                          0xED1E },   //                       //
    { "bracerightBig",                          0xED20 },   //                       //
    { "bracerightBigg",                         0xED22 },   //                       //
    { "bracerightbig",                          0xED21 },   //                       //
    { "bracerightbigg",                         0xED23 },   //                       //
    { "bracketleftBig",                         0xED24 },   //                       //
    { "bracketleftBigg",                        0xED26 },   //                       //
    { "bracketleftbig",                         0xED25 },   //                       //
    { "bracketleftbigg",                        0xED27 },   //                       //
    { "bracketrightBig",                        0xED28 },   //                       //
    { "bracketrightBigg",                       0xED2A },   //                       //
    { "bracketrightbig",                        0xED29 },   //                       //
    { "bracketrightbigg",                       0xED2B },   //                       //
    { "ceilingleftBig",                         0xED2C },   //                       //
    { "ceilingleftBigg",                        0xED2E },   //                       //
    { "ceilingleftbig",                         0xED2D },   //                       //
    { "ceilingleftbigg",                        0xED2F },   //                       //
    { "ceilingrightBig",                        0xED30 },   //                       //
    { "ceilingrightBigg",                       0xED32 },   //                       //
    { "ceilingrightbig",                        0xED31 },   //                       //
    { "ceilingrightbigg",                       0xED33 },   //                       //
    { "circledotdisplay",                       0xED34 },   //                       //
    { "circledottext",                          0xED35 },   //                       //
    { "circlemultiplydisplay",                  0xED36 },   //                       //
    { "circlemultiplytext",                     0xED37 },   //                       //
    { "circleplusdisplay",                      0xED38 },   //                       //
    { "circleplustext",                         0xED39 },   //                       //
    { "contintegraldisplay",                    0xED3B },   //                       //
    { "contintegraltext",                       0xED3C },   //                       //
    { "coproductdisplay",                       0xED3D },   //                       //
    { "coproducttext",                          0xED3E },   //                       //
    { "floorleftBig",                           0xED42 },   //                       //
    { "floorleftBigg",                          0xED44 },   //                       //
    { "floorleftbig",                           0xED43 },   //                       //
    { "floorleftbigg",                          0xED45 },   //                       //
    { "floorrightBig",                          0xED46 },   //                       //
    { "floorrightBigg",                         0xED48 },   //                       //
    { "floorrightbig",                          0xED47 },   //                       //
    { "floorrightbigg",                         0xED49 },   //                       //
    { "hatwide",                                0xED4A },   //                       //
    { "hatwider",                               0xED4B },   //                       //
    { "hatwidest",                              0xED4C },   //                       //
    { "integraldisplay",                        0xED4D },   //                       //
    { "integraltext",                           0xED4E },   //                       //
    { "intersectiondisplay",                    0xED4F },   //                       //
    { "intersectiontext",                       0xED50 },   //                       //
    { "logicalanddisplay",                      0xED51 },   //                       //
    { "logicalandtext",                         0xED52 },   //                       //
    { "logicalordisplay",                       0xED53 },   //                       //
    { "logicalortext",                          0xED54 },   //                       //
    { "mapsto",                                 0x2192 },   //                      // ED55 //
    { "parenleftBig",                           0xED5A },   //                       //
    { "parenleftBigg",                          0xED5C },   //                       //
    { "parenleftbig",                           0xED5B },   //                       //
    { "parenleftbigg",                          0xED5D },   //                       //
    { "parenrightBig",                          0xED5E },   //                       //
    { "parenrightBigg",                         0xED60 },   //                       //
    { "parenrightbig",                          0xED5F },   //                       //
    { "parenrightbigg",                         0xED61 },   //                       //
    { "productdisplay",                         0xED63 },   //                       //
    { "producttext",                            0xED64 },   //                       //
    { "radicalBig",                             0xED65 },   //                       //
    { "radicalBigg",                            0xED67 },   //                       //
    { "radicalbig",                             0xED66 },   //                       //
    { "radicalbigg",                            0xED68 },   //                       //
    { "radicalbt",                              0xED69 },   //                       //
    { "radicaltp",                              0xED6A },   //                       //
    { "radicalvertex",                          0xED6B },   //                       //
    { "slashBig",                               0xED6C },   //                       //
    { "slashBigg",                              0xED6E },   //                       //
    { "slashbig",                               0xED6D },   //                       //
    { "slashbigg",                              0xED6F },   //                       //
    { "summationdisplay",                       0xED70 },   //                       //
    { "summationtext",                          0xED71 },   //                       //
    { "suppress",                               0xEB61 },   //                       //
    { "tie",                                    0x2040 },   //                       //
    { "tildewide",                              0xEB68 },   //                       //
    { "tildewider",                             0xEB69 },   //                       //
    { "tildewidest",                            0xEB6A },   //                       //
    { "uniondisplay",                           0xED72 },   //                       //
    { "unionmultidisplay",                      0xED73 },   //                       //
    { "unionmultitext",                         0xED74 },   //                       //
    { "unionsqdisplay",                         0xED75 },   //                       //
    { "unionsqtext",                            0xED76 },   //                       //
    { "uniontext",                              0xED77 },   //                       //
    { "vextenddouble",                          0xED79 },   //                       //
    { "vextendsingle",                          0xED7A },   //                       //
    { "",                                       C_Nul  }   
};
