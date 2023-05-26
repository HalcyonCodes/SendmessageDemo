#pragma once

#include "pch.h"
#include <wtypes.h>

//得到基地址相对于游戏模块的偏移
QWORD getBaseAddr(DWORD offset);

//计算对象首地址
//如果参数带有“+”则不进入下一层直接加地址
//必须以""为最后一个参数
QWORD getTargetAddr(QWORD baseAddr, ...);

int hex2dec(char* hex);

int c2i(char ch);