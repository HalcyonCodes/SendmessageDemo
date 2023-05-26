#include "pch.h"
#include "myStrCpy.h"
#include "dbgPrint.h"
#include <Windows.h>
//#include <cassert>

char* myStrCpy(char* str1, char* str2)
{
	QWORD str1Base = (QWORD)str1;
	QWORD str2Base = (QWORD)str2;
	int index = 0;
	//dbgPrint("q1:%p|q2:%p", str1Base, str2Base);
	while (*(BYTE*)str2 != 0x00)//用指针进行循环判断就可以做到不限数组长度了
	{
		//dbgPrint("qwprd:%p", str1);
		*str1 = *str2;
		str1 = (char*)(str1Base + index);
		str2 = (char*)(str2Base + index);
		index++;
		
	}
	*(BYTE*)(str1Base + index) = 0x00;
	return str1;
}