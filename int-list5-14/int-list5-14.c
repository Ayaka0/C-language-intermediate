//int�^�̔z��𓮓I�Ɋm��

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;	//�v�f��

	printf("�v�f���F");
	scanf("%d", &n);

	int* x = calloc(n, sizeof(int));	//�m��

	if (x == NULL)
		puts("�L����̊m�ۂɎ��s���܂����B");
	else {
		for (int i = 0; i < n; i++)	//�l����
			x[i] = i;

		for (int i = 0; i < n; i++)	//�l��\��
			printf("x[%d] = %d\n", i, x[i]);

		free(x);
	}




	return 0;
}