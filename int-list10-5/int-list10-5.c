//文字列の配列を動的に確保（ポインタの配列）

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int num;	//文字列の個数
	printf("文字列は何個：");
	scanf("%d", &num);

	char** p = (char**)calloc(num, sizeof(char*));

	if (p == NULL)
		puts("記憶域の確保に失敗しました。");
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
				puts("記憶域の確保に失敗しました。");
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