//���b�N�i���o�[�T�[�`�E�g���[�j���O�i����Łj

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE	10	//�����

int main(void)
{
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];

	srand(time(NULL));	//�����̎��ݒ�

	printf("�����Ă��鐔���������悤\n");
	time_t start = time(NULL);
	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;	//�R�s�[���΂��v�f�̓Y���i0�`8�j

		int i = 0, j = 0;
		while (i < 9) {	//dgt[x]���΂��ăR�s�[
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (int i = 0; i < 8; i++)	//�S�v�f��\��
			printf("%d", a[i]);
		printf("�F");
		int no;	//�ǂݍ��񂾒l
		do {
			scanf("%d", &no);
		} while (no != dgt[x]);	//���������͂����܂ŌJ��Ԃ�
	}
	time_t end = time(NULL);

	double jikan = difftime(end, start);

	printf("%.1f�b������܂���\n", jikan);

	if (jikan > 25.0)
		printf("�݂����܂�\n");
	else if (jikan > 20.0)
		printf("�����݂����܂�\n");
	else if (jikan > 17.0)
		printf("�܂��܂��ł���\n");
	else
		printf("�f�����ł���\n");


	return 0;
}