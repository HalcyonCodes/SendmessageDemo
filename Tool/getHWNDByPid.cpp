#include "pch.h"
#include "getHWNDByPid.h"






//�ص�����
BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lparam)
{
	WindowsArg* pArg = (WindowsArg*)lparam;

	DWORD dwId = 0;
	GetWindowThreadProcessId(hwnd, &dwId);
	if (pArg->processId == dwId)
	{
		pArg->hwnd = hwnd;
		return FALSE;//ƥ�����ID�ɹ�����������
	}

	return TRUE; //!< ��������
}

//ͨ������ID��ȡ���ھ��
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
