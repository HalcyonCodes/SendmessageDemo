#include "windows.h"
#include <cstdio>
#define QWORD long long

//记录物品id并写入文件
void writeItem(WORD itemId, char* itemName) {

   
	//char txt[512] = {};

	/*strcat_s(txt, sizeof("//id:"), "//id:");
	strcat_s(txt, sizeof((char*)itemId), (char*)itemId);
	strcat_s(txt, sizeof(" name:"), " name:");
	strcat_s(txt, sizeof(itemName), itemName);
	strcat_s(txt, sizeof("\n"), "\n");
	//strcat(txt, "if( strcmp(itemName, \"%s\") == 0){");
	strcat_s(txt, sizeof("if(strcmp(itemName, \""), "if(strcmp(itemName, \"");//; \"%s\", \"%s\") == 0){
	strcat_s(txt, sizeof(itemName), itemName);
	strcat_s(txt, sizeof("\") == 0){"), "\") == 0){");
	strcat_s(txt, sizeof("\n"), "\n");
	strcat_s(txt, sizeof("return "), "return ");
	strcat_s(txt, sizeof((char*)itemId), (char*)itemId);
	strcat_s(txt, sizeof(";"), ";");
	strcat_s(txt, sizeof("\n"), "\n");
	strcat_s(txt, sizeof("}"), "}");
	strcat_s(txt, sizeof("\n"), "\n");
	*/
	
	printf("//id:");
	printf("%04X    ", itemId);
	printf("itemName:%s", itemName);
	printf("\n");
	printf("if(strcmp(itemName, \"%s\") == 0){", itemName);
	printf("\n");
	printf("    return 0x%04X;", itemId);
	printf("\n");
	printf("}");
	printf("\n");



	//fclose(stream);
	
}