//���I�Ɋm�ۂ���int�^�I�u�W�F�N�g�ɒl�������ĕ\��

//���I�Ɋm�ۂ���int�^�I�u�W�F�N�g�ɒl�������ĕ\��

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int* x = calloc(1, sizeof(int));	//�m��

	if (x == NULL)
		puts("�L����̊m�ۂɎ��s�����B");
	else {
		printf("*x�Ɋi�[����l�F");
		scanf("%d", x);
		printf("*x = %d\n", *x);
		free(x);
	}


	return 0;
}