#pragma once
#define QWORD unsigned long long


#include <Windows.h>



//通过特征码定位地址

//为0时表示找不到
QWORD loacatedAddr(HANDLE processHandle, const char* markArr, QWORD startAddr, QWORD endAddr);
bool byteArrComp(BYTE* buffer, const char* markArr, int* offset);
void hexToByte(const char* markArr, BYTE* byte);