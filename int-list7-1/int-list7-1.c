//配列コピーして表示

#include<stdio.h>

int main(void)
{
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[9] = { 0 };

	for (int i = 0; i < 9; i++)	//全要素をコピー
		a[i] = dgt[i];

	for (int i = 0; i < 9; i++)	//全要素を表示
		printf("%d", a[i]);

	putchar('\n');


	return 0;
}