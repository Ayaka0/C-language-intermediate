#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE 10 //�ő���͉�

int main(void)
{
	srand(time(NULL)); //�����̎��ݒ�
	int ans;
	int num;
	//int stage = 10;
	int no; //�ǂݍ��񂾒l
	int remain = MAX_STAGE;	//�c���

	//3�̔{���������o��܂ŌJ��Ԃ�
	do {
		num = 3 + rand() % 1000; //3�ȏ�999�ȉ��̗�������
	} while (num % 3);
	
	printf("3�`999�̐����𓖂Ă悤�B\n");


	do {
		printf("�c��%d��,�������ȁF", remain);
		scanf("%d", &ans);
		remain--;

		if (ans % 3 != 0)	//3�̔{���o�Ȃ��ꍇ
		{
			printf("3�̔{���ł͂Ȃ��̂ŏI��\n");
			break;
		}
		else
			if (ans > num)
				printf("�����Ə�������\n");
			else if (ans < num)
				printf("�����Ƒ傫����\n");
	} while (ans  != num && remain < MAX_STAGE);

	return 0;
}




//���͂��ꂽ�l��3�̔{���łȂ��ꍇ�A�Q�[���I�����A�ē���

//���͂��ꂽ�l��3�̔{���Ȃ�A���茋�ʕ\��