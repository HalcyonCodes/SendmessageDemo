#include "pch.h"
#include "reHideModule.h"
#include <wtypes.h>
#include "dbgPrint.h"
#define QWORD unsigned long long


//64位修复重定位表
QWORD reHideModule(HMODULE hModule) {
    
	PIMAGE_DOS_HEADER pDos = (PIMAGE_DOS_HEADER)hModule; //获得dos头地址
	PIMAGE_NT_HEADERS64 pNt = (PIMAGE_NT_HEADERS64)((QWORD)hModule + pDos->e_lfanew);//通过模块地址+dos头e_lfanew存放的偏移跳过dos_stub块获得pe地址
	PBYTE mem = (PBYTE)VirtualAlloc(NULL, pNt->OptionalHeader.SizeOfImage, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (mem == NULL) {
        dbgPrint("分配内存失败");
		return NULL;
	}
	memcpy(mem, (void*)hModule, pNt->OptionalHeader.SizeOfImage);
	PIMAGE_BASE_RELOCATION rBase = (PIMAGE_BASE_RELOCATION)((QWORD)mem + pNt->OptionalHeader.DataDirectory[5].VirtualAddress);
	QWORD n = 0;
	QWORD Base = (QWORD)mem;
    //dbgPrint("5 men: %p", mem);
	QWORD offset = (QWORD)mem - (QWORD)hModule;
    //dbgPrint("offset:%d", offset);
    if (offset == 0) {
        (QWORD)mem;
    }
    typedef struct RELOCATIONITEM
    {
        WORD value : 12;
        WORD attr : 4;

    } *PRELOCATIONITEM;
    PRELOCATIONITEM   rItem;
    QWORD* item;
    while (true)
    {
        if (rBase->SizeOfBlock == 0)
            break;
        rItem = (PRELOCATIONITEM)((PBYTE)rBase + 8);
        n = (rBase->SizeOfBlock - 8) / 2;
        for (int i = 0; i < n; ++i)
        {
            if (10 == rItem[i].attr)
            {
                //dbgPrint("10101010");
                item = (QWORD*)(Base + rBase->VirtualAddress + rItem[i].value);
                *item = (*item + offset);
            }
        }

        rBase = (PIMAGE_BASE_RELOCATION)((PBYTE)rBase + rBase->SizeOfBlock);//指向下一个结构
    }
    return (QWORD)mem;

}