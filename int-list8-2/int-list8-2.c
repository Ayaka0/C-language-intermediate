//1�̕�����ɂ��L�[�^�C�s���O���K�i����2�F�����������������Ă����j

#include<time.h>
#include<stdio.h>
#include<string.h>
#include"int-list7-8.h"

int main(void)
{
	char* str = "How do you do?";	//�^�C�v���镶����
	int len = strlen(str);	//������str�̕�����

	init_getputch();
	printf("���̒ʂ�^�C�v���悤�B\n");

	time_t start = time(NULL);	//�J�n����

	for (int i = 0; i < len; i++) {
		//str[i]�ȍ~�Ƌ󔒂�\�����ăJ�[�\����擪�֖߂�
		printf("%s \r", &str[i]);

		fflush(stdout);
		while (getch() != str[i])
			;
	}

	time_t end = time(NULL);	//�I������
	printf("\r%.1f�b�ł����B\n", difftime(end, start));
	term_getputch();

	return 0;
}