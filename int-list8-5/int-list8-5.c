//����������ɂ��L�[�^�C�s���O���K�i���̂Q�F�o�菇�������_����@�Q�j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"int-list7-8.h"

#define QNO	12	//��萔

#define swap(type,x,y)	do{type t = y; x = y; y=t;}while(0)

int main(void)
{
	char* str[QNO] = {
		"book", "computer", "default", "comfort", "monday", "power",
		"light", "programming", "music", "dog", "video", "include",
	};

	init_getputch();
	srand(time(NULL));	//�����̎��ݒ�

	for (int i = QNO - 1; i > 0; i--) {	//�z��str���V���b�t��
		int j = rand() % (i + 1);
		if (i != j)
			swap(char*, str[i], str[j]);
	}

	printf("�^�C�s���O���K�J�n\n");
	printf("�X�y�[�X�L�[�ŊJ�n\n");
	while (getch() != ' ')	//�X�y�[�X�L�[������
		;					//�����܂ő҂�

	time_t start = time(NULL);	//�J�n����

	for (int stage = 0; stage < QNO; stage++) {
		int len = strlen(str[stage])	//������str[stage]�̕�����
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