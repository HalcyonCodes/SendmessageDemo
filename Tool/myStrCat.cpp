#include "pch.h"
#include "myStrCat.h"
#include <Windows.h>
#include <cassert>


char* myStrCat(char* str1, char* str2) {
	assert(str1 && str2);//Ö¸Õë²»Îª¿Õ
	//char* ret = str1;
	QWORD str1Base = (QWORD)str1;
	QWORD str2Base = (QWORD)str2;
	int str1Size = 0;
	while (*(BYTE*)str1Base != 0x00) {
		str1Base++;
	}

	while (*(BYTE*)str2Base != 0x00) {
		*(BYTE*)str1Base = *(BYTE*)str2Base;
		str2Base++;
		str1Base++;
	}

	return str1;
}