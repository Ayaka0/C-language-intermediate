//����������1�������炵�Ȃ���\���i�E�l�߂���j

#include<stdio.h>

int main(void)
{
	int x;	//�\������i��

	printf("�i���F");
	scanf("%d", &x);

	int i, j;
	for (i = 1; i <= x; i++) {
		for (j = x; j > i; j--)	//i - 1�̋󔒂�\���B2�d���[�v�̓�����for���͂��������l����X�^�[�g
			putchar(' ');
		printf("%d\n", i % 10);
	}

	return 0;
}