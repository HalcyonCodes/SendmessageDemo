#include "pch.h"
#include "getHWNDByPid.h"






//回调函数
BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lparam)
{
	WindowsArg* pArg = (WindowsArg*)lparam;

	DWORD dwId = 0;
	GetWindowThreadProcessId(hwnd, &dwId);
	if (pArg->processId == dwId)
	{
		pArg->hwnd = hwnd;
		return FALSE;//匹配进程ID成功，结束遍历
	}

	return TRUE; //!< 继续遍历
}

//通过进程ID获取窗口句柄
HWND getHwndByProcessId()
{
	HWND hwndRet = NULL;
	WindowsArg wa;
	wa.processId = getpid();
	wa.hwnd = NULL;
	EnumWindows(enumWindowsProc, (LPARAM)&wa);
	if (wa.hwnd)
		hwndRet = wa.hwnd;
	return hwndRet;
}
