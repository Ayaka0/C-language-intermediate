//�z����R�s�[���ĕ\���i�v�f��1��΂��j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8] = { 0 };

	srand(time(NULL));	//�����̎��ݒ�

	int x = rand() % 9;	//�Z���[���΂��v�f�̓Y��(0�`8)
	int i = 0, j = 0;
	while (i < 9) {
		if (i != x)	//dgt[x]���΂��ăR�s�[
			a[j++] = dgt[i];
		i++;
	}
	for (int i = 0; i < 8; i++)//�S�v�f��\��
		printf("%d", a[i]);

	putchar('\n');

	return 0;
}