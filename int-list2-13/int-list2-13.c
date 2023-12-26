//数字文字を1桁ずつずらしながら表示（その２）

#include<stdio.h>

int main(void)
{
	int x;	//表示する段数

	printf("段数：");
	scanf("%d", &x);

	int i, j;
	for (i = 1; i <= x; i++) 
		printf("%*d\n",i, i % 10);

	return 0;
}