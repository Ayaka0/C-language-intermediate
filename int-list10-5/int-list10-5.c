//������̔z��𓮓I�Ɋm�ہi�|�C���^�̔z��j

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int num;	//������̌�
	printf("������͉��F");
	scanf("%d", &num);

	char** p = (char**)calloc(num, sizeof(char*));

	if (p == NULL)
		puts("�L����̊m�ۂɎ��s���܂����B");
	else {
		for (int i = 0; i < num; i++)
			p[i] = NULL;

		for (int i = 0; i < num; i++) {
			char temp[128];

			printf("p[%d] :", i);
			scanf("%s", temp);

			p[i] = (char*)malloc(strlen(temp) + 1);
			if (p[i] != NULL)
				strcpy(p[i], temp);
			else {
				puts("�L����̊m�ۂɎ��s���܂����B");
				goto Free;
			}
		}
		for (int i = 0; i < num; i++)
			printf("p[%d] = %s\n", i, p[i]);

	Free:
		for (int i = 0; i < num; i++)
			free(p[i]);
		free(p);
	}


	return 0;
}