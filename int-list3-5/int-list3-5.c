//文字列の配列（2次元配列）

#include<stdio.h>

int main(void)
{
	char a[][6] = { "Super", "X", "TRY" };

	int i;
	for (i = 0; i < 3; i++)
		printf("%s\n", a[i]);

	return 0;
}