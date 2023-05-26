#include "utf8ToUnicode.h"
#include "pch.h"
#include "windows.h"
#include "dbgPrint.h";
#include <string>

//��Ҫ��delectɾ��
char* utf8ToUnicode(const char* str) {
    //std::string result;
    WCHAR* strSrc;
    LPSTR szRes;

    //�����ʱ�����Ĵ�С
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //�����ʱ�����Ĵ�С
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    //result = szRes;
    delete[]strSrc;
    //delete[]szRes;

    return szRes;
}