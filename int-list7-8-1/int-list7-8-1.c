//1�̕�����ɂ��L�[�^�C�s���O
#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include"int-list7-8.h"

int main(void)
{
	char* str = "How do you do?";	//�^�C�v���镶����
	int len = strlen(str);	//������str�̕�����

	init_getputch();

	printf("���̒ʂ�^�C�v���悤�B\n");
	printf("%s\n", str);	//�^�C�v���镶�����\��
	fflush(stdout);

	time_t start = time(NULL);	//�J�n����
	for (int i = 0; i < len; i++) {
		int ch;
		do {
			ch = getch();	//�L�[�ǂݍ���
			if (isprint(ch)) {
				putch(ch);	//�����ꂽ�L�[��\��
				if (ch != str[i])	//�Ⴄ�L�[�������ꂽ��
					putch('/b');	//�J�[�\����1�߂�
			}
		} while (ch != str[i]);
	}

	time_t end = time(NULL);	//�I������

	printf("\n%.1f�b�ł����B\n", difftime(end, start));

	term_getputch();

	return 0;
}