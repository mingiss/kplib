/* -----------------------------------------------
 *
 * kpwindow.h
 *
 *    common Win32 things
 *
 * 2013-07-16  mp  initial creation
 *
 */

#ifndef kpwindows_included
#define kpwindows_included

#ifdef __WIN32__

// ----------------------------
#define KPW_WND_CAPTION_HGT_INI 26
#define KPW_WND_BORDER_WDT_INI 4
#define KPW_WND_MENU_HGT_INI 20

#define KPW_POLL_TIMEOUT 100 // kas kiek msec tikrinam threadų sinchroniškumą ir pan.

// ----------------------------
extern void KpDrawLine(HDC hDC, int iX1, int iY1, int iX2, int iY2, COLORREF iColor);
extern void KpDrawRect(HDC hDC, int iX1, int iY1, int iX2, int iY2, COLORREF lColor);
 
#endif // #ifdef __WIN32__

#endif // #ifndef kpwindows_included
