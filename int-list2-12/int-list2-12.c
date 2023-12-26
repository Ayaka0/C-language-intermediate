//数字文字を1桁ずつずらしながら表示（その１）

#include<stdio.h>

int main(void)
{
	int x;	//表示する段数

	printf("段数：");
	scanf("%d", &x);

	int i, j;
	for (i = 1; i <= x; i++) {
		for (j = 1; j < i; j++)	//i - 1の空白を表示。2重ループの内側のfor文はいつも初期値からスタート
			putchar(' ');
		printf("%d\n", i % 10);
	}

	return 0;
}