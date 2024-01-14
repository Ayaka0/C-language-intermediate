//動的に確保したint型オブジェクトに値を代入して表示

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int* x = calloc(1, sizeof(int));	//確保

	if (x == NULL)
		puts("記憶域の確保に失敗した。");
	else {
		*x = 67;
		printf("*x = %d\n", *x);
		free(x);
	}


	return 0;
}