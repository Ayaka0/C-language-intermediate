//����񂯂�Q�[���i���̂Q�F���҂̎��\���j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//�����̎��ݒ�

	printf("����񂯂�Q�[���J�n\n");

	int retry;	//�ēx

	do {
		int comp = rand() % 3;	//�R���s���[�^�̎�F0�`2�̗���
		int human;	//human's hand

		do {
			printf("\n����񂯂�|���c0�F�O�[�@1�F�`���L�@2�F�p�[�F");
			scanf("%d", &human);	//�l�Ԃ̎��ǂݍ���
		} while (human < 0 || human > 2);

		printf("����");
		switch (comp) {	//�R���s���[�^�̎��\��
		case 0: printf("�O�["); break;
		case 1: printf("�`���L"); break;
		case 2: printf("�p�["); break;
		}

		printf("���Ȃ���");
		switch (human) {	//�l�Ԃ̎��\��
		case 0: printf("�O�["); break;
		case 1: printf("�`���L"); break;
		case 2: printf("�p�["); break;
		}
		printf("�ł��B\n");

		int judge = (human - comp + 3) % 3;	//���s����

		switch (judge) {	//���s����
		case 0: printf("��������"); break;
		case 1: printf("���Ȃ��̕���"); break;
		case 2: printf("���Ȃ��̏���"); break;
		}

		printf("������x�H�c0�F�������@1�F�͂�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}