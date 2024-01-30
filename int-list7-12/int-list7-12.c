//�g���C�O���t�A�z�g���[�j���O�i�����E�p����3�����̕��т�����������j

#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"getputch.h"

#define MAX_STAGE 20
#define swap(type, x,y) do{type t = x; x = y; y = t;}while(0)

int main(void)
{
	char* qstr[] = { "0123456789",
					"ABCDEFGHIGKLMNOPQRSTUVWXYZ",
					"abcdefghijklmnopqrstuvwxyz" };

	int chmax[] = { 10, 26, 26 };

	init_getputch();
	srand(time(NULL));

	printf("�@�A������3�̐������邢�͉p������\n");
	printf("�@�B����Ă��镶�����^�C�v����\n");
	printf("�@���Ƃ���A ? C :�ƂЂ傤�����ꂽ��B��\n");
	printf("�@			4 5 ? :�ƕ\�����ꂽ��6��\n");
	printf("�@�^�C�v����\n");

	printf("���X�y�[�X�L�[�ŊJ�n\n");
	while (getch() != ' ')
		;

	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;	//0�F����/�P�F�p�啶��/�Q�F�p������
		int nhead = rand() % (chmax[qtype] - 2);	//�擪�����̓Y����
		int x = rand() % 3;	//3�����̂ǂ�'�H'�ɂ��邩

		putchar('\r');
		for (int i = 0; i < 3; i++) {	//����\��
			if (i != x)
				printf(" %c", qstr[qtype][nhead + i]);
			else
				printf(" ?");
		}
		printf(" : ");
		fflush(stdout);

		int key;	//�ǂݍ��񂾃L�[
		do {
			key = getch();
			if (isprint(key)) {	//�\���\�Ȃ�
				putch(key);	//�����ꂽ�L�[��\��
				if (key != qstr[qtype][nhead + x])	//�����łȂ����
					putch('\b');	//�J�[�\����1�߂�
			}
		} while (key != qstr[qtype][nhead + x]);
		printf("\n");
	}

	time_t end = time(NULL);

	double jikan = difftime(end, start);
	printf("\n%.1f�b��������\n", jikan);

	if (jikan > 50.0)
		printf("�݂�����\n");
	else if (jikan > 40.0)
		printf("�����݂�\n");
	else if (jikan > 34.0)
		printf("�܂��܂�\n");
	else
		printf("�f����\n");

	term_getputch();


	return (0);
}
