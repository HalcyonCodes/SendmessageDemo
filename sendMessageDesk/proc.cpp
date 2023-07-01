
#include "windows.h"

#include "head.h"

#include "dbgPrint.h"
#include "writeItem.h"
#include "writeCoordinates.h"
//#include "proc.h"
#include "myStrCpy.h"
#include <stdio.h>

LPTSTR pBuf = 0;
LPTSTR pCBuf = 0;

FILE* stream;

typedef struct PMsg {
	char itemName[128] = {};
	WORD itemId;
};

typedef struct CMsg {
	float pointX;
	float pointY;
	float pointZ;
};

//----------�����˹���ģ��--------------------
extern LRESULT CALLBACK acceptProc(int code, WPARAM wParam, LPARAM lParam) {
	CWPSTRUCT* lpArg = (CWPSTRUCT*)lParam;
	if (code == HC_ACTION) {
		if (lpArg->message == acceptMsgCode) {
			switch (lpArg->wParam) {
				//������Ӹ��ֻ����˶���
			case msgChannelWriteItemId: {
				//----------------����----------------------
				//::MessageBox(NULL, L"��Ϣ����", L"caption", 0x00000002L);
				/*HANDLE hMapFile = CreateFileMapping(
					INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 256, L"BotMem"
				);
				
				//ӳ�乲���ڴ浽���̵�ַ��
				pBuf = (LPTSTR)MapViewOfFile(
					hMapFile,
					FILE_MAP_ALL_ACCESS,
					0,
					0,
					256
				);
				//printf("PBUFF:%p", pBuf);
				if (pBuf == NULL) {
					::MessageBox(NULL, L"pBuffΪNULL", L"caption", 0x00000002L);
				}*/
				PMsg* p = (PMsg*)pBuf;
				//printf("accetTest:%s", p->itemName);
				WORD id = p->itemId;
				char* name = p->itemName;
				//printf("tst:%s", p->itemName);
				writeItem(id, name);
				break;
			}
			//ͨ����Ϸ�����������겢д�������
			case msgChannelWriteCoordinate: {
				CMsg* p = (CMsg*)pCBuf;
				float x = p->pointX;
				float y = p->pointY;
				float z = p->pointZ;
				writeCoordinates((char*)"1132", x, y, z);
			}

			}
		}
		return CallNextHookEx(NULL, code, wParam, lParam);

	}
}



