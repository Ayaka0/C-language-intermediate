//������𓮓I�Ɋm��

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	char str[16];

	printf("������str����͂���F");
	scanf("%s", str);

	char* ptr = malloc(strlen(str) + 1);	//�L����𓮓I�Ɋm��

	if (ptr){
		strcpy(ptr, str);
		printf("������str�̕���ptr�����܂����B\n");
		printf("str = %s\n", str);
		printf("ptr = %s\n", ptr);
		free(ptr);	//�L��������
		}


	return 0;
}