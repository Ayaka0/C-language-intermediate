//�_�u���i���o�[�T�[�`�E�g���[�j���O�i���̂Q�G���A���^�C���L�[���́j

#include<ctype.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include"getputch.h"

#define MAX_STAGE 10	//�����
#define swap(type, x, y) do{ type t = x; x = y; y = t;} while (0)

int main(void)
{
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[10];

	init_getputch();
	srand(time(NULL));	//�����̎��ݒ�

	printf("�_�u���Ă��鐔����������\n");
	printf("�X�y�[�X�L�[�ŊJ�n����\n");
	fflush(stdout);
	while (getch() != ' ')
		;
	time_t start = time(NULL);
	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;	//�_�u���ăR�s�[����v�f�̓Y����

		int i = 0; j = 0;
		while (i < 9) {	//dgt[x]�����Ԃ点�ăR�s�[
			a[j++] = dgt[i];
			if (i == x)
				a[j++] = dgt[i];
			i++;
		}
		for (int i = 9; i > 0; i--) {	//�z��a���V���b�t��
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}
		for (int i = 0; i < 10; i++)	//�S�v�f��\��
			printf("%d", a[i]);
		printf(":");
		fflush(stdout);

		int no;	//�ǂݍ��񂾒l
		do {
			no = getch();
			if (isprint(no)) {	//�\���\�ł����
				putch(no);	//�����ꂽ�L�[��\��
				if (no != dgt[x] + '0')	//�����łȂ����
					putch('\b');	//�J�[�\����1�߂�
				else
					printf("\n");	//���s
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	time_t end = time(NULL);
	double jikan = difftime(end, start);
	printf("%.1f�b���������B\n", jikan);

	if (jikan > 25.0)
		printf("�݂�����\n");
	else if (jikan > 20.0)
		printf("�����݂�\n");
	else if (jikan > 17.0)
		printf("�܂��܂�\n");
	else
		printf("�f����\n");
	term_getputch();

	return 0;
}