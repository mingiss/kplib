/* -----------------------------------------------
 *
 * kpwinsys.cpp
 *
 *		Win32 kernel
 *
 * 2015-03-27  mp  initial creation
 *
 */


#include "envir.h"

#ifdef __WIN32__

#include <vector>
#include <string>
#include <windows.h>

using namespace std;

#include "kpstdlib.h"
#include "kpmsg.h"
#include "kptree.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kperrno.h"
#include "kperr.h"
#include "kpstdio.h"
#include "kpcapp.h"
#include "kpwindow.h"
#include "kpwinsys.h"


// ------------------------------------------
HRESULT StartProcess(const KpStrPtr lpszCmdLine, const KpStrPtr lpszCurDir, HANDLE hStdOut, WORD iWndShowType, HANDLE *phProcess, DWORD *plThreadId)
{
HRESULT retc = S_OK;
static uchar cmd_line[KP_MAX_FNAME_LEN + 1];
STARTUPINFO startup_info;
PROCESS_INFORMATION proc_inf;
int retv = ERROR_SUCCESS;
static unsigned char win_name[KP_MAX_FNAME_LEN + 1];
static uchar dir_buf[KP_MAX_FNAME_LEN + 1]; // sCurDir kopija – parametras CreateProcess()
static uchar cur_dir[KP_MAX_FNAME_LEN + 1]; // paleidimo komandos sCmdLine kelias, į jį nustatinėjam aktyvų katalogą, o lpszCmdLine paliekam tik failo vardą
SECURITY_ATTRIBUTES sec_atr_proc, sec_atr_thread;

	KP_ASSERT(strlen(lpszCmdLine) < KP_MAX_FNAME_LEN, E_INVALIDARG, null);

// ----------------------------------------
	KP_ASSERT(GetFullPathName((const char *)lpszCurDir, KP_MAX_FNAME_LEN, (char *)dir_buf, NULL) != 0, KP_E_FILE_NOT_FOUND, null);

// ----------------------------------------
	if(SUCCEEDED(retc))
	{
		strcpy(cmd_line, lpszCmdLine);
		strlwr(cmd_line); // nes būna "IEXPLORE"
	}

// ---------------------------- lpszCmdLine paliekam tik failo vardą – XFS.exe kitaip neveikia
// ---------------------------- lpszCmdLine kelią perkeliam į cur_dir – į jį nustatysim darbinį katalogą
	if(SUCCEEDED(retc)) strcpy(cur_dir, dir_buf);
	if(SUCCEEDED(retc)) // if(strchr(cmd_line, '\\') != null) if(cmd_line[1] != ':') // if(cmd_line[0] != '\\') // komandoms nuo šakninio katalogo ar su disko vardu – turėtų veikt, bent jau kai diskas sutampa su aktyviu
		if(strstr(cmd_line, "\"") == null) if(strstr(cmd_line, " ") == null) // komandoms su failø vardais su tarpais (d?l to su kabut?m)  TvFnameSplit() neveikia
		if(strchr(cmd_line, '/') == null) if(strstr(cmd_line, ".exe ") == null) if(strstr(cmd_line, ".bin ") == null) // tik komandoms be parametrø
		if(strstr(cmd_line, ".exe\" ") == null) if(strstr(cmd_line, ".bin\" ") == null)
	{
static unsigned char full_cmd[KP_MAX_FNAME_LEN + 1];
static unsigned char cmd_disk[KP_MAX_FNAME_LEN + 1];
static unsigned char cmd_path[KP_MAX_FNAME_LEN + 1];
static unsigned char cmd_name[KP_MAX_FNAME_LEN + 1];
static unsigned char cmd_type[KP_MAX_FTYPE_LEN + 1];

		if(GetFullPathName((const char *)cmd_line, KP_MAX_FNAME_LEN, (char *)full_cmd, NULL) == 0)
		{
			retc = KP_E_FILE_NOT_FOUND;
#ifndef Debug
			if(KpError.m_bOutMsg)
			{
				uchar str_buf[KP_MAX_FILE_LIN_LEN + 1];
				sprintf((char *)str_buf, (char *)KP_MSG_UNABLE_TO_EXECUTE,
						(strstr(cmd_line, "\\tv")==NULL) ? lpszCmdLine : (KpStrPtr)""); // nerodyt laikinų slaptų failų
				KpMsgOut(str_buf, IDI_ERROR, KP_MB_TESTI);
			}
#else
			KP_ERROR(retc, null /* retv */);
#endif
		}


		/* retc = */ FnameSplit(cmd_disk, cmd_path, cmd_name, cmd_type, full_cmd);
//		KP_ASSERT(strlen(dir_buf) + strlen(cmd_path) < KP_MAX_FNAME_LEN, KP_E_BUFFER_OVERFLOW, null, True);
		if(SUCCEEDED(retc))
		{
//			strcat(dir_buf, cmd_path); // permetam lpszCmdLine kelią į lpszCurDir galą – ne, lpszCurDir turi būti tiksliai tas, kurio reikia
			strcpy(cur_dir, cmd_disk);
			strcat(cur_dir, cmd_path);

			if (lpszCurDir)
			{
				strcpy(cmd_line, lpszCmdLine);
			}
			else
			{
				strcpy(cmd_line, cmd_name);
				if(cmd_type[0] != Nul)
				{
					strcat(cmd_line, ".");
					strcat(cmd_line, cmd_type);
				}
			}
		}
	}

// ------------------------ išsaugojam path
char dir_buf_sav[KP_MAX_FNAME_LEN + 1];
	GetCurrentDirectory(KP_MAX_FNAME_LEN, dir_buf_sav);

// ----------------------------
	if(SUCCEEDED(retc))
	{
		ZeroMemory(&startup_info, sizeof(startup_info));

		startup_info.cb = sizeof(startup_info);
		startup_info.lpReserved = NULL;
		startup_info.lpDesktop = NULL;
		startup_info.lpTitle = NULL;
		startup_info.dwX = 0;
		startup_info.dwY = 0;
		startup_info.dwXSize = 300;
		startup_info.dwYSize = 300;
		startup_info.dwXCountChars = 80;
		startup_info.dwYCountChars = 25;
		startup_info.dwFillAttribute = 0;
		startup_info.dwFlags = STARTF_USESHOWWINDOW | (hStdOut ? STARTF_USESTDHANDLES : 0);
		startup_info.wShowWindow = iWndShowType;
		startup_info.cbReserved2 = 0;
		startup_info.lpReserved2 = NULL;
		startup_info.hStdInput = hStdOut ? GetStdHandle(STD_INPUT_HANDLE) : 0;
		startup_info.hStdOutput = hStdOut;
		startup_info.hStdError = hStdOut ? GetStdHandle(STD_ERROR_HANDLE) : 0;

		sec_atr_proc.nLength = sizeof(sec_atr_proc);
		sec_atr_proc.lpSecurityDescriptor = NULL;
		sec_atr_proc.bInheritHandle = True;

		sec_atr_thread.nLength = sizeof(sec_atr_thread);
		sec_atr_thread.lpSecurityDescriptor = NULL;
		sec_atr_thread.bInheritHandle = True;

		ZeroMemory(&proc_inf, sizeof(proc_inf));

// ------------------------ nustatom path – XFS.exe kitaip neveikia; jei paleidimo diskas kitas – neužteks !!!!
		SetCurrentDirectory((const char *)cur_dir);

// char dir_buf_tmp[KP_MAX_FNAME_LEN + 1];
// GetCurrentDirectory(KP_MAX_FNAME_LEN, dir_buf_tmp);
// PutLogMessage_("StartProcess(): [%s] [%s] [%s] %d %d", cmd_line, dir_buf, dir_buf_tmp, iWndShowType, SW_SHOWNORMAL);

		if(!CreateProcess(NULL /* (const char *)m_szAcroReadPath */, (char *)cmd_line,
			&sec_atr_proc /* NULL */, &sec_atr_thread /* NULL */, True /* False */,
			0L /* NORMAL_PRIORITY_CLASS */, NULL, lpszCurDir? (const char *)dir_buf : (const char *)cur_dir, &startup_info, &proc_inf))
		{
			retv = GetLastError();
			retc = KP_E_SYSTEM_ERROR;
			KP_WARNING(retc, retv);
			KP_WARNING(retc, dir_buf);
			KP_WARNING(retc, cmd_line);
			if((retv == ERROR_FILE_NOT_FOUND) || (retv == ERROR_PATH_NOT_FOUND))
			{
				retc = KP_E_FILE_NOT_FOUND;
#ifndef Debug
				if(KpError.m_bOutMsg)
				{
					uchar str_buf[KP_MAX_FILE_LIN_LEN + 1];
					sprintf((char *)str_buf, (char *)KP_MSG_UNABLE_TO_EXECUTE,
						(
							(strstr(cmd_line, "\\tv")==NULL) && // nerodyt laikinu slaptu failu 
							(strstr(cmd_line, "cert")==NULL) && // ir sertifikatų slaptažodžių
							(strstr(cmd_line, "pfx")==NULL)
						) ? cmd_line : (unsigned char *)"");
					KpMsgOut(str_buf, IDI_ERROR, KP_MB_TESTI);
				}
#else
				KP_ERROR(retc, retv);
#endif
			}
			else
#ifndef Debug
				if(KpError.m_bOutMsg)
#endif
					KP_ERROR(retc, retv);
		}
	}

// ------------------------ atstatom buvus? path
	SetCurrentDirectory((const char *)dir_buf_sav);

	if(plThreadId && SUCCEEDED(retc)) *plThreadId = proc_inf.dwThreadId;
	if(phProcess && SUCCEEDED(retc)) *phProcess = proc_inf.hProcess;

return(retc);
}


//---------------------------
HRESULT WaitForProcessEnd(HANDLE hProcess, HANDLE hThread)
{
HRESULT retc=S_OK;
DWORD exit_code;

	if(hProcess)
	{
		do
		{
			if(!GetExitCodeProcess(hProcess, &exit_code))
				KP_ERROR(KP_E_SYSTEM_ERROR, GetLastError());

			KpSleep(500, HWND_DESKTOP);

		} while((exit_code==STILL_ACTIVE) && SUCCEEDED(retc));
	}
	else if(hThread)
	{
		do
		{
			if(!GetExitCodeThread(hThread, &exit_code))
				KP_ERROR(KP_E_SYSTEM_ERROR, GetLastError());

			KpSleep(500, HWND_DESKTOP);

		} while((exit_code==STILL_ACTIVE) && SUCCEEDED(retc));
	}

return(retc);
}

HRESULT RunProcess(const KpStrPtr lpszCmdLine, const KpStrPtr lpszCurDir, const KpStrPtr lpszStdOutFName, bool bStdOutAppend, WORD iWndShowType)
{
HANDLE hProcess;
HRESULT retc = S_OK;

	HANDLE hstdout = NULL;
	if (lpszStdOutFName)
	{
		SECURITY_ATTRIBUTES sa;
		ZeroMemory(&sa, sizeof(sa));
		sa.nLength = sizeof(sa);
		sa.bInheritHandle=TRUE;

		hstdout = CreateFile((const char *)lpszStdOutFName, GENERIC_READ|GENERIC_WRITE, 0, &sa,
						bStdOutAppend ? OPEN_ALWAYS : CREATE_ALWAYS,
						FILE_ATTRIBUTE_NORMAL, NULL);
		KP_ASSERT(hstdout, KP_E_DIR_ERROR, GetLastError());

		if (SUCCEEDED(retc))
		{
			KP_ASSERT(SetFilePointer(hstdout, 0, NULL, FILE_END) != INVALID_SET_FILE_POINTER, KP_E_FERROR, GetLastError());
		}
	}

	if (SUCCEEDED(retc)) retc = StartProcess(lpszCmdLine, lpszCurDir, hstdout, iWndShowType, &hProcess);
	if (SUCCEEDED(retc)) retc = WaitForProcessEnd(hProcess);

	if (hstdout)
	{
		KP_ASSERT(CloseHandle(hstdout), KP_E_FERROR, GetLastError());
	}

return (retc);
}

HRESULT RunProcess(const KpStrPtr lpszCmdLine, const char *lpszCurDir,
					const KpStrPtr lpszStdOutFName, bool bStdOutAppend,
					WORD iWndShowType)
{
return RunProcess(lpszCmdLine, (const KpStrPtr)lpszCurDir, lpszStdOutFName, bStdOutAppend, iWndShowType);
}


HRESULT KpSleep(int nMiliSecs, HWND)
{
	Sleep(nMiliSecs);
return S_OK;
}


// -------------------------------------------
HRESULT KpSetClipboardData(HWND hWndNewOwner, UINT uFormat, const KpStrPtr lpClipData, int iBufSize, bool bClearBeforeSetting)
{
HRESULT retc = S_OK;

	KP_ASSERT(OpenClipboard(hWndNewOwner), KP_E_SYSTEM_ERROR, GetLastError());

	if (bClearBeforeSetting)
	{
		KP_ASSERT(EmptyClipboard(), KP_E_SYSTEM_ERROR, GetLastError());
	}

	HGLOBAL h_mem = NULL;
	h_mem = GlobalAlloc(GMEM_SHARE | GMEM_MOVEABLE, iBufSize);
	KP_ASSERT(h_mem, KP_E_SYSTEM_ERROR, GetLastError());

	KpStrPtr pntd = (KpStrPtr)GlobalLock(h_mem);
	KP_ASSERT(pntd, KP_E_SYSTEM_ERROR, GetLastError());

	memcpy(pntd, lpClipData, iBufSize);

	GlobalUnlock(h_mem);

	KP_ASSERT(SetClipboardData(uFormat, h_mem), KP_E_SYSTEM_ERROR, GetLastError());

	CloseClipboard();

return retc;
}

#endif // #ifdef __WIN32__
