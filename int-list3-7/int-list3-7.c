//����񂯂�Q�[���i���̂R�F���\��������𓱓��j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char* hd[] = { "�O�[", "�`���L", "�p�[" };	//��
	srand(time(NULL));	//�����̎��ݒ�

	printf("����񂯂�Q�[���J�n�I\n");

	int retry;	//�ēx

	do {
		int comp = rand() % 3;	//�R���s���[�^�̎�F0�`2�̗���
		int human;	//�l�Ԃ̎�

		do {
			printf("\n����񂯂�|���c");
			for (int i = 0; i < 3; i++)
				printf("(%d)%s", i, hd[i]);
			printf(":");
			scanf("%d", &human);	//�l�Ԃ̎��ǂݍ���
		} while (human < 0 || human > 2);

		printf("����%s�ŁA���Ȃ���%s�ł��B\n", hd[comp], hd[human]);

		int judge = (human - comp + 3) % 3;	//���s�𔻒�

		switch (judge) {
		case 0: puts("���������ł��B"); break;
		case 1: puts("���Ȃ��̕����ł�"); break;
		case 2: puts("���Ȃ��̏����ł��B"); break;
		}

		printf("������x���܂����c0�������@1�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}