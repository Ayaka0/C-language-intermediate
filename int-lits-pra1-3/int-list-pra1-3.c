//�����ăQ�[��-999�ȏ�999�ȉ�

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE 10	//�ő���͉�

int main(void)
{
	srand(time(NULL));	//�����̎�̐ݒ�

	int ans = -999 + rand() % 1000; //-999�`999�̗�������
	int remain = MAX_STAGE;	//�c��̓��͉�
	int no;		//�ǂݍ��񂾒l

	printf("-999�`999�̐����𓖂Ă�\n");

	do {
		printf("�c��%d�񐔁B�����B�F", remain);
		scanf("%d", &no);
		remain--;

		if (no > ans)
			printf("�����Ə�����\n");
		else if (no < ans)
			printf("�����Ƒ傫����\n");
	} while (no != ans && remain > 0);

	if (no != ans)
		printf("�c�O�B������%d�ł����B\n", ans);
	else {
		printf("����\n");
		printf("%d��œ�����܂���\n", MAX_STAGE - remain);
	}

	return 0;
}