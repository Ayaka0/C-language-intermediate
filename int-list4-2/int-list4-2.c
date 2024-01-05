//整数値の読み込みと表示

#include<stdio.h>

int main(void)
{
	int x;
	printf("整数を入力せよ：");
	scanf("%d", &x);

	printf("%dと入力しましたね。\n", x);


	return 0;
}