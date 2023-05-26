
#include "windows.h"

#include "head.h"

#include "dbgPrint.h"
#include "writeItem.h"
//#include "proc.h"
#include "myStrCpy.h"
#include <stdio.h>

LPTSTR pBuf = 0;
FILE* stream;

typedef struct PMsg {
	char itemName[128] = {};
	WORD itemId;
};


//----------机器人功能模块--------------------
extern LRESULT CALLBACK acceptProc(int code, WPARAM wParam, LPARAM lParam) {
	CWPSTRUCT* lpArg = (CWPSTRUCT*)lParam;
	if (code == HC_ACTION) {
		if (lpArg->message == acceptMsgCode) {
			switch (lpArg->wParam) {
				//这里添加各种机器人动作
			case msgTest1: {
				//----------------测试----------------------
				//::MessageBox(NULL, L"消息来了", L"caption", 0x00000002L);
				/*HANDLE hMapFile = CreateFileMapping(
					INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 256, L"BotMem"
				);
				
				//映射共享内存到进程地址中
				pBuf = (LPTSTR)MapViewOfFile(
					hMapFile,
					FILE_MAP_ALL_ACCESS,
					0,
					0,
					256
				);
				//printf("PBUFF:%p", pBuf);
				if (pBuf == NULL) {
					::MessageBox(NULL, L"pBuff为NULL", L"caption", 0x00000002L);
				}*/
				PMsg* p = (PMsg*)pBuf;
				//printf("accetTest:%s", p->itemName);
				WORD id = p->itemId;
				char* name = p->itemName;
				//printf("tst:%s", p->itemName);
				writeItem(id, name);
				break;
			}

			}
		}
		return CallNextHookEx(NULL, code, wParam, lParam);

	}
}

LRESULT CALLBACK keyboardProc(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	::MessageBox(NULL, L"按键了", L"caption", 0x00000002L);
	return CallNextHookEx(NULL, code, wParam, lParam);//第一个参数一般可以为NULL
}

