//文字列を動的に確保

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char str[16];

	printf("文字列strを入力せよ：");
	scanf("%s", str);

	char* ptr = malloc(strlen(str) + 1);	//記憶域を動的に確保

	if (ptr){
		strcpy(ptr, str);
		printf("文字列strの複製ptrを作りました。\n");
		printf("str = %s\n", str);
		printf("ptr = %s\n", ptr);
		free(ptr);	//記憶域を解放
		}


	return 0;
}