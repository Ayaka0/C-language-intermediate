//����������ɂ��L�[�^�C�s���O���K�i���̂P�j

#include<time.h>
#include<stdio.h>
#include<string.h>
#include"int-list7-8.h"

#define QNO 12	//��萔

int main(void) {

	char* str[QNO] = {
		"book","computer", "default", "comfort", "monday", "power", 
		"light", "programming", "music", "dog", "video", "include",
	};

	init_getputch();

	printf("�^�C�s���O���K���n�߂܂�\n");
	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
	while (getch() != ' ')	//�X�y�[�X�L�[������
		;					//�����܂ő҂�

	time_t start = time(NULL);	//�J�n����

	for (int stage = 0; stage < QNO; stage++) {
		int len = strlen(str[stage]);	//������str[stage]�̕�����
		for (int i = 0; i < len; i++) {
			//str[stage][i]�ȍ~��\�����ăJ�[�\����擪�ɖ߂�
			printf("%s \r", &str[stage][i]);

			fflush(stdout);
			while (getch() != str[stage][i])
				;
		}
	}

	time_t end = time(NULL);	//�I������

	printf("\r%.1f�b�ł����B\n", difftime(end, start));
	term_getputch();



	return 0;
}