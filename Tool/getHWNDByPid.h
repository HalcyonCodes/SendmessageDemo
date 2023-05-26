#pragma once

#include <Windows.h>
#include <process.h>

HWND getHwndByProcessId();

typedef struct
{
	HWND	hwnd;
	DWORD	processId;
}WindowsArg;