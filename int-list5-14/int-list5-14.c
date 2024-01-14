//int型の配列を動的に確保

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;	//要素数

	printf("要素数：");
	scanf("%d", &n);

	int* x = calloc(n, sizeof(int));	//確保

	if (x == NULL)
		puts("記憶域の確保に失敗しました。");
	else {
		for (int i = 0; i < n; i++)	//値を代入
			x[i] = i;

		for (int i = 0; i < n; i++)	//値を表示
			printf("x[%d] = %d\n", i, x[i]);

		free(x);
	}




	return 0;
}