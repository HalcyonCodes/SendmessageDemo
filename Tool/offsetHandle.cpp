#include "pch.h"
#include "framework.h"
#include "offsetHandle.h"
#include <string>
#include "dbgPrint.h"
//using namespace std;


QWORD getBaseAddr(DWORD offset) {
	QWORD gameHandle = (QWORD)LoadLibraryA("ffxiv_dx11.exe");
	return (QWORD)(gameHandle + offset);
}

QWORD getTargetAddr(QWORD baseAddr, ...) {
	va_list offsetList;
	QWORD addr = baseAddr;
	char* arg;
	try {
		va_start(offsetList, baseAddr);

		while (true)
		{
			arg = va_arg(offsetList, char*);
			if (strcmp(arg, "") == 0) {
				break;
			}
			//��һ���ַ����ڡ�+������ʾ��ͬһ��
			if (arg[0] == 43) {
				//dbgPrint("f");
				char* offsetMath = &arg[3];
				addr = addr + (QWORD)hex2dec(offsetMath);
				//dbgPrint("f current addr: %x", addr);
				//dbgPrint("4:%p", addr);
			}
			else if (arg[0] == 45) {
				char* offsetMath = &arg[3];
				//dbgPrint("f of %x", stoi(offsetMath, 0, 16));
				addr = addr - (QWORD)hex2dec(offsetMath);
				//dbgPrint("f current addr: %x", addr);
			}
			else {
				//dbgPrint("h");
				char* offsetMath = &arg[2];
				//dbgPrint("test");
				//dbgPrint("h addr:%x", *(QWORD*)addr);
				//dbgPrint("of %x", stoi(offsetMath, 0, 16));
				addr = ((*(QWORD*)addr) + (QWORD)hex2dec(offsetMath));
			}
		}
		va_end(offsetList);
		return addr;
	}
	catch (...) {
		dbgPrint("��ȡƫ��ʧ��");
	}
}


/*
 * ���ַ�ת��Ϊ��ֵ
 * */
int c2i(char ch)
{
	// ��������֣��������ֵ�ASCII���ȥ48, ���ch = '2' ,�� '2' - 48 = 2
	if (isdigit(ch))
		return ch - 48;

	// �������ĸ��������A~F,a~f�򷵻�
	if (ch < 'A' || (ch > 'F' && ch < 'a') || ch > 'z')
		return -1;

	// ����Ǵ�д��ĸ���������ֵ�ASCII���ȥ55, ���ch = 'A' ,�� 'A' - 55 = 10
	// �����Сд��ĸ���������ֵ�ASCII���ȥ87, ���ch = 'a' ,�� 'a' - 87 = 10
	if (isalpha(ch))
		return isupper(ch) ? ch - 55 : ch - 87;

	return -1;
}


/*
 * ���ܣ���ʮ�������ַ���ת��Ϊ����(int)��ֵ
 * */
int hex2dec(char* hex)
{
	int len;
	int num = 0;
	int temp;
	int bits;
	int i;

	// ������ hex = "1de" ����Ϊ3, hex��main�������ݵ�
	len = strlen(hex);

	for (i = 0, temp = 0; i < len; i++, temp = 0)
	{
		// ��һ�Σ�i=0, *(hex + i) = *(hex + 0) = '1', ��temp = 1
		// �ڶ��Σ�i=1, *(hex + i) = *(hex + 1) = 'd', ��temp = 13
		// �����Σ�i=2, *(hex + i) = *(hex + 2) = 'd', ��temp = 14
		temp = c2i(*(hex + i));
		// �ܹ�3λ��һ��16����λ�� 4 bit����
		// ��һ�Σ�'1'Ϊ���λ������temp���� (len - i -1) * 4 = 2 * 4 = 8 λ
		// �ڶ��Σ�'d'Ϊ�θ�λ������temp���� (len - i -1) * 4 = 1 * 4 = 4 λ
		// �����Σ�'e'Ϊ���λ������temp���� (len - i -1) * 4 = 0 * 4 = 0 λ
		bits = (len - i - 1) * 4;
		temp = temp << bits;

		// �˴�Ҳ������ num += temp;�����ۼ�
		num = num | temp;
	}

	// ���ؽ��
	return num;
}

