#pragma once
#define QWORD unsigned long long


#include <Windows.h>



//ͨ�������붨λ��ַ

//Ϊ0ʱ��ʾ�Ҳ���
QWORD loacatedAddr(HANDLE processHandle, const char* markArr, QWORD startAddr, QWORD endAddr);
bool byteArrComp(BYTE* buffer, const char* markArr, int* offset);
void hexToByte(const char* markArr, BYTE* byte);