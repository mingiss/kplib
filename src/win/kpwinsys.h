/* -----------------------------------------------
 *
 * kpwinsys.h
 *
 *    Win32 kernel
 *
 * 2015-03-27  mp  initial creation
 *
 */

#ifndef KPWINSYS_INCLUDED
#define KPWINSYS_INCLUDED

#ifdef __WIN32__

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
extern HRESULT StartProcess(const KpStrPtr lpszCmdLine,
					const KpStrPtr lpszCurDir, // jeigu NULL, einamąjį aplanką išsitraukia iš lpszCmdLine
					HANDLE hStdOut, // gali būti NULL
					WORD iWndShowType, // gali būti SW_SHOWNORMAL arba ne (visi kiti suveikia kaip SW_SHOWMINNOACTIVE)
					HANDLE *phProcess, DWORD *plThreadId = NULL);

extern HRESULT WaitForProcessEnd(HANDLE hProcess, HANDLE hThread = NULL);

extern HRESULT RunProcess( // StartProcess() ir WaitForProcessEnd()
					const KpStrPtr lpszCmdLine, const KpStrPtr lpszCurDir,
					const KpStrPtr lpszStdOutFName = null, bool bStdOutAppend = false,
					WORD iWndShowType = SW_SHOWNORMAL);
extern HRESULT RunProcess(const KpStrPtr lpszCmdLine, const char *lpszCurDir,
					const KpStrPtr lpszStdOutFName = null, bool bStdOutAppend = false,
					WORD iWndShowType = SW_SHOWNORMAL);

extern HRESULT KpSleep(int nMiliSecs, HWND hWind = HWND_DESKTOP);

#endif // #ifdef __WIN32__

#endif // #ifndef KPWINSYS_INCLUDED
