//�L�[�z�u�A�z�^�C�s���O���K�i�^�C�v���镶�����l��������j
//A?DFG�ƕ\�����ꂽ��S���^�C�v
//qwe?t�ƕ\�����ꂽ��r���^�C�v

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"int-list7-8.h"

#define NO	30	//���K��
#define KTYPE	16	//�u���b�N��

int main(void)
{
	char* kstr[] = {
		"12345", "67890-=\\",	//��1�i
		"!@#$%", "^&*()_+",
		"qwert", "yuiop[]",
		"QWERT", "YUIOP{}",
		"asdfg", "hjkl;'\"",
		"ASDFG", "HJKL:",
		"zxcvb", "nm,./",
		"ZXCVB", "NM<>?",
	};

	init_getputch();
	srand(time(NULL));

	printf("�L�[�ʒu�A�z�^�C�s���O\n");
	printf("�H�ŉB���ꂽ�������^�C�v����\n");
	printf("�X�y�[�X�L�[�ŊJ�n\n");
	fflush(stdout);
	while (getch() != ' ');
	;

	time_t start = time(NULL);

	for (int stage = 0; stage < NO; stage++) {
		int k, p, key;
		char temp[10];

		do {
			k = rand() % KTYPE;
			p = rand() % strlen(kstr[k]);
			key = kstr[k][p];
		} while (key == ' ');
		strcpy(temp, kstr[k]);

		temp[p] = '?';

		printf("%s", temp);
		fflush(stdout);

		while (getch() != key)
			;
		putchar('\n');
	}
	time_t end = time(NULL);
	printf("%.1f�b�ł����B\n", difftime(end, start));
	term_getputch();

	return 0;

}