#pragma once

#include "pch.h"
#include <wtypes.h>

//�õ�����ַ�������Ϸģ���ƫ��
QWORD getBaseAddr(DWORD offset);

//��������׵�ַ
//����������С�+���򲻽�����һ��ֱ�Ӽӵ�ַ
//������""Ϊ���һ������
QWORD getTargetAddr(QWORD baseAddr, ...);

int hex2dec(char* hex);

int c2i(char ch);