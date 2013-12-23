/* -----------------------------------------------
 *
 * kpwindow.h
 *
 *    common Win32 things
 *
 * 2013-07-16  mp  initial creation
 *
 */

#ifndef KPWINDOW_INCLUDED
#define KPWINDOW_INCLUDED

#ifdef __WIN32__

// ----------------------------
#define KPW_WND_CAPTION_HGT_INI 26
#define KPW_WND_BORDER_WDT_INI 4
#define KPW_WND_MENU_HGT_INI 20

// ----------------------------
// #define KPW_FIRST_USER_MSG WM_USER
#define KPW_FIRST_USER_MSG 10000

#define KP_TIMEOUT_TIMER            (KPW_FIRST_USER_MSG+124)
#define KP_TIMEOUT_TIMEOUT          30000 // 15000 // 100000 // 5000

#define KP_BLOCKED_SOCK_RELEASED    (KPW_FIRST_USER_MSG + 145)
    // notification from blocking socket thread

#define KPW_FLASH_TIMER             (KPW_FIRST_USER_MSG + 150)
    // kursoriaus mirgėjimo taimerio id
#define KPW_POLL_TIMEOUT 100
    // kas kiek msec tikrinam threadų sinchroniškumą ir pan.
#define KPW_FLASH_TIMEOUT 200
    // kursoriaus mirgėjimo intervalas msec


// ----------------------------
extern void KpDrawLine(HDC p_hDC, int p_iX1, int p_iY1, int p_iX2, int p_iY2,
                                                            COLORREF p_iColor);
extern void KpDrawRect(HDC p_hDC, int p_iX1, int p_iY1, int p_iX2, int p_iY2,
                                                            COLORREF p_lColor);

// ----------------------------
extern HRESULT KpMsgOut(const unsigned char *p_lpszOutStr,
                                LPCTSTR p_lpszIconID, KpMsgTypes p_iMsgType);
#endif // #ifdef __WIN32__

#endif // #ifndef KPWINDOW_INCLUDED
