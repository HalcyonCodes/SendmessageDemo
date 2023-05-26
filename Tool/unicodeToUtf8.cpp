#include "unicodeToUtf8.h"
#include "pch.h"
#include "windows.h"
#include "dbgPrint.h";
#include <string>

char* unicodeToUtf8(const char* input) {

	std::string temp;
	temp = input;
	//��ת�ɿ��ַ�
	int unicodeLen = MultiByteToWideChar(CP_ACP, 0, temp.c_str(), -1, nullptr, 0);
	// ��ָ�򻺳�����ָ����������ڴ�    
	wchar_t* pUnicode = (wchar_t*)malloc(sizeof(wchar_t) * unicodeLen);
	MultiByteToWideChar(CP_ACP, 0, temp.c_str(), -1, pUnicode, unicodeLen);
	//ת��utf-8
	int len = WideCharToMultiByte(CP_UTF8, 0, pUnicode, -1, NULL, 0, NULL, NULL);
	char* result = (char*)malloc(len + 1);
	memset(result, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, pUnicode, -1, result, len, NULL, NULL);
	free(pUnicode);

	return result;
}