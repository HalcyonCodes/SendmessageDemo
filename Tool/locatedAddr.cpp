#include "pch.h"
#include "locatedAddr.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//STOI无法在hideModule状态下执行
QWORD loacatedAddr(HANDLE processHandle, const char* markArr, QWORD startAddr, QWORD endAddr) {
	int offset;
	int bufferSize = 4096 + (strlen(markArr) + 1) / 2 * sizeof(BYTE);
	BYTE* buffer = (BYTE*)malloc(bufferSize);
	while (startAddr < endAddr)
	{
		bool flag = ReadProcessMemory(processHandle, (PVOID)startAddr, buffer, bufferSize, NULL);
		if (flag && byteArrComp(buffer, markArr, &offset)) {
			//printf("offset:%p", offset);
			return (startAddr + offset);
		}
		startAddr += 4096;
		
	}
	free(buffer);
	return 0;
}

bool byteArrComp(BYTE* sourceBuffer, const char* markArr, int* offset) {
	int sourceBufferLength = 4096 + (strlen(markArr)+ 1)/2;
	BYTE* markArrBytes = (BYTE*)malloc(((strlen(markArr) +1)/ 2) * sizeof(BYTE));
	//printf("len：%d||", strlen(markArr));
	//printf("test:%d|||", ((strlen(markArr) + 1) / 2) * sizeof(BYTE));
	//printf("size:%d|||", sizeof(markArrBytes));

	hexToByte(markArr, markArrBytes);
	//printf("ttt:%p|||", *(QWORD*)(QWORD)(markArrBytes + 8));
	//printf("BYTE:%p",*markArrBytes);
	for (int i = 0; i <= sourceBufferLength - 1; i++) {
		bool isFalse = false;
		if ((sourceBuffer[i] == markArrBytes[0]) || (markArrBytes[0] == 0x3F)) {
			for (int j = 0; j <= (strlen(markArr)+1)/2 - 1; j++) {
				if (sourceBuffer[i + j] == markArrBytes[j] || markArrBytes[j] == 0x3F) {
					
				}
				else {
					isFalse = true;
					break;
				}
				*offset = i;
				
			}
			if (!isFalse) {
				return true;
			}
		}
		else
		{
			continue;
		}
		
	}
	return false;
}


void hexToByte(const char* markArr, BYTE* byte) {
	int byteLength = 0;
	char temp[3];
	int len = strlen(markArr);
	for (int i = 0, j = 0; i <= len - 1; i++) {
		if (markArr[i] == ' ') {
			continue;
		}
	
		temp[j % 2] = markArr[i];
		if((j + 1) % 2 == 0){
			if (markArr[i] == '?') {
				byte[byteLength++] = 0x3F;
			}
			else {
				temp[2] = '\0';
				byte[byteLength++] = (BYTE)stoi(temp, NULL, 16);
			}

			
		}
		j++;
	}
	return;
}
