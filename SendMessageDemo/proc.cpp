
#include "windows.h"
#include "head.h"
#include "dbgPrint.h"



//----------�����˹���ģ��--------------------
extern LRESULT CALLBACK acceptProc(int code, WPARAM wParam, LPARAM lParam) {
	CWPSTRUCT* lpArg = (CWPSTRUCT*)lParam;
	if (code == HC_ACTION) {
		if (lpArg->message == acceptMsgCode) {
			switch (lpArg->wParam) {
				//������Ӹ��ֻ����˶���
			case msgTest1: {
				//----------------����----------------------
				dbgPrint("���ն˽��յ���Ϣ");
				break;
			}
	 
			}
		}
		return CallNextHookEx(NULL, code, wParam, lParam);
		
	}
}
