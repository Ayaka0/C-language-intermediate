//����������ɂ��L�[�^�C�s���O���K�i���̂Q�F�o�菇�������_���j

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
	int qno[QNO];	//�o�菇��

	init_getputch();
	srand(time(NULL));	//�����̎��ݒ�

	for (int i = 0; i < QNO; i++)
		qno[i] = i;
	for (int i = QNO - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		if (i != j)
			swap(int, qno[i], qno[j]);
	}

	printf("�^�C�s���O���K�J�n\n");
	printf("�X�y�[�X�L�[�ŊJ�n\n");
	while (getch() != ' ')	//�X�y�[�X�L�[������
		;					//�����܂ő҂�
	time_t start = time(NULL);	//�J�n����
	for (int stage = 0; stage < QNO; stage++) {
		int len = strlen(str[qno[stage]]);	//������str[qno[stage]]�̕�����
		for (int i = 0; i < len; i++) {
			//str[qno[stage]][i]�ȍ~��\�����ăJ�[�\����擪�֖߂�
			printf("%s \r", &str[qno[stage]][i]);

			fflush(stdout);
			while (getch() != str[qno[stage]])
				;
		}
	}

	time_t end = time(NULL);	//�I������
	printf("\r%.1f�b�ł����B\n", difftime(end, start));

	term_getputch();

	return 0;
}

