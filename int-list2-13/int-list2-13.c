//����������1�������炵�Ȃ���\���i���̂Q�j

#include<stdio.h>

int main(void)
{
	int x;	//�\������i��

	printf("�i���F");
	scanf("%d", &x);

	int i, j;
	for (i = 1; i <= x; i++) 
		printf("%*d\n",i, i % 10);

	return 0;
}