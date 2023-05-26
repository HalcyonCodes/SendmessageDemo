#include "pch.h"
#include "dbgPrint.h"
#include <Windows.h>
#include <stdio.h>
#include <iostream>

void dbgPrint(const char* pFormat, ...)
{
#ifdef _DEBUG
	char bufFormat[0x1000];
	char printFilter[0x1012] = "Game:";
	va_list argList;
	va_start(argList, pFormat);
	vsprintf_s(bufFormat, pFormat, argList);
	strcat_s(printFilter, bufFormat);
	OutputDebugStringA(printFilter);
	va_end(argList);
#endif
}
