//�R���s���[�^���K��������񂯂�Q�[��

#include<stdio.h>

int main(void)
{
	char* hd[] = { "�O�[", "�`���L", "�p�[" };	//��
	printf("����񂯂�Q�[���J�n\n");

	int retry;	//�ēx

	do {
		int human;	//�l�Ԃ̎�

		do {
			printf("\n����񂯂�|���c");
			int i;
			for (i = 0; i < 3; i++)
				printf("(%d)%s", i, hd[i]);
			printf(":");
			scanf("%d", &human);	//�l�Ԃ̎��ǂݍ���
		} while (human < 0 || human > 2);

		int comp = (human + 2) % 3;	//�R���s���[�^�͌�o��
		printf("����%s�ŁA���Ȃ���%s�ł��B\n", hd[comp], hd[human]);
		int judge = (human - comp + 3) % 3;	//���s�𔻒�

		switch (judge) {
		case 0: puts("���������ł�"); break;
		case 1: puts("���Ȃ��̕����ł�"); break;
		case 2: puts("���Ȃ��̏����ł�"); break;
		}

		printf("������x���܂����H�c0�F�������@�P�F�͂�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}