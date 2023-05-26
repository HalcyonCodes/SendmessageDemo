#pragma once
#include "windows.h"

//extern LRESULT CALLBACK acceptProc(int code, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK keyboardProc(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);


extern LRESULT CALLBACK acceptProc(int code, WPARAM wParam, LPARAM lParam);

typedef struct PMsg {
	char itemName[128];
	WORD itemId;
};

//¹²ÏíÄÚ´æµØÖ·
extern LPTSTR pBuf;
extern FILE* stream;