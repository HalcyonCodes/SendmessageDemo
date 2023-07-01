
#include "windows.h"
#include <cstdio>


void writeCoordinates(char* map, float x, float y, float z) {

	//MessageBox(NULL, L"接收到消息！", L"接受到消息", MB_ICONERROR);

	FILE* stream;
	freopen_s(&stream, "coordination.txt", "a", stdout);
	printf("{");
	printf("\"x\": \"%f\", ", x);
	printf("\"y\": \"%f\", ", y);
	printf("\"z\": \"%f\" ", z);
	printf("}");
	printf("\n");
	fclose(stdin);
	
}