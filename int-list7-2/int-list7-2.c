//配列をコピーして表示（要素を1個飛ばす）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8] = { 0 };

	srand(time(NULL));	//乱数の種を設定

	int x = rand() % 9;	//濃いーを飛ばす要素の添字(0～8)
	int i = 0, j = 0;
	while (i < 9) {
		if (i != x)	//dgt[x]を飛ばしてコピー
			a[j++] = dgt[i];
		i++;
	}
	for (int i = 0; i < 8; i++)//全要素を表示
		printf("%d", a[i]);

	putchar('\n');

	return 0;
}