
#include "windows.h"
#include "head.h"
#include "dbgPrint.h"



//----------机器人功能模块--------------------
extern LRESULT CALLBACK acceptProc(int code, WPARAM wParam, LPARAM lParam) {
	CWPSTRUCT* lpArg = (CWPSTRUCT*)lParam;
	if (code == HC_ACTION) {
		if (lpArg->message == acceptMsgCode) {
			switch (lpArg->wParam) {
				//这里添加各种机器人动作
			case msgTest1: {
				//----------------测试----------------------
				dbgPrint("接收端接收到消息");
				break;
			}
	 
			}
		}
		return CallNextHookEx(NULL, code, wParam, lParam);
		
	}
}
