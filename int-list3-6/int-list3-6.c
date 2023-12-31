//文字列の配列（ポインタの配列）

#include<stdio.h>

int main(void)
{
	char* p[] = { "Super", "X", "TRY" };

	int i;
	for (i = 0; i < 3; i++)
		printf("%s\n", p[i]);


	return 0;
}