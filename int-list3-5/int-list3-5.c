//������̔z��i2�����z��j

#include<stdio.h>

int main(void)
{
	char a[][6] = { "Super", "X", "TRY" };

	int i;
	for (i = 0; i < 3; i++)
		printf("%s\n", a[i]);

	return 0;
}