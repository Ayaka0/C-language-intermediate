//����񂯂�Q�[���i���̂P�j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//�����̎��ݒ�

	printf("����񂯂�Q�[���J�n\n");

	int retry;	//�ēx�g���C

	do {
		int comp = rand() % 3;	//�R���s���[�^�̎�F0�`2�̗���
		int human;				//�l�Ԃ̎�

		printf("\n����񂯂�|���c0�F�O�[�@1�F�`���L�@2�F�p�[�F");
		scanf("%d", &human);	//�l�Ԃ̎��ǂݍ���

		printf("����");	//�R���s���[�^�̎��\��
		switch (comp) {
		case 0: printf("�O�["); break;
		case 1: printf("�`���L"); break;
		case 2: printf("�p�["); break;
		}
		printf("�ł��B\n");

		
		/*
		printf("����");
		if(comp == 0)
			printf("�O�[");
		else if (comp == 1)
			printf("�`���L");
		else if (comp == 2)
			printf("�p�[");
		
		printf("�ł��B\n");
		
		int judge = (human - comp + 3) % 3;	//���s����

		if(judge == 0)
			printf("��������");
		else if (comp == 1)
			printf("you are lose");
		else if (comp == 2)
			printf("You are win");

		printf("�ł��B\n");

		*/
		

		
		int judge = (human - comp + 3) % 3;	//���s����

		switch (judge) {
		case 0: printf("���������ł��B"); break;
		case 1: printf("���Ȃ��̕����ł��B"); break;
		case 2: printf("���Ȃ��̏����ł��B"); break;
		}
		
		printf("������x�H�c0�F�������@1�F�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}