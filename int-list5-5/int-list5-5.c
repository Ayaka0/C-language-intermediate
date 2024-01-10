//�v���X�����g���[�j���O�i�����̐��l���L�����ĂP���������l�����

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE	10	//�X�e�[�W��
#define LEVEL_MIN	2	//�ŏ����x���i���l�̌��j
#define LEVEL_MAX	6	//�ő僌�x���i���l�̌��j

//x�~���b�o�߂���̂�҂�
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	//�G���[
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int level;	//���x��
	int success = 0;	//�S�X�e�[�W�̐��𐔂̍��v
	int score[MAX_STAGE];	//�e�X�e�[�W�̐���

	srand(time(NULL));	//�����̎��ݒ�

	printf("�v���X�����g���[�j���O�J�n\n");
	printf("2���̐��l���L�����܂��B\n");
	printf("�P���������l����͂��Ă�������\n");

	do {
		printf("���킷�郌�x���i%d�`%d�j�F", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int no[LEVEL_MAX];	//�L�����鐔
		int x[LEVEL_MAX];	//�ǂݍ��񂾒l
		int seikai = 0;		//���̃X�e�[�W�ł̐���

		printf("\n��%d�X�e�[�W�J�n\n", stage + 1);

		for (int i = 0; i < level; i++) {	//level����
			no[i] = rand() % 90 + 10;	//10�`99�̗����𐶐�����
			printf("%d", no[i]);	//�\������
		}
		fflush(stdout);
		sleep(300 * level);	//0.3 x level�b�҂���
		printf("\r%*s\r", 3 * level, "");	//��������
		fflush(stdout);

		for (int i = 0; i < level; i++) {	//�񓚂�ǂݍ���
			printf("%d�Ԗڂ̐��F", i + 1);
			scanf("%d", &x[i]);
		}

		for (int i = 0; i < level; i++) {	//����𔻒�E�\��
			if (x[i] != no[i] + 1)
				printf("X");
			else {
				printf("�Z");
				seikai++;
			}
		}

		putchar('\n');

		for (int i = 0; i < level; i++)	//������\��
			printf("%2d", no[i]);

		printf("�c%d�����ł��B\n", seikai);
		score[stage] = seikai;	//�X�e�[�W�̐��𐔂��L�^
		success += seikai;	//�S�̂̐��𐔂��X�V
	}

	time_t end = time(NULL);

	printf("%d��%d�������܂����B\n", level * MAX_STAGE, success);

	for (int stage = 0; stage < MAX_STAGE; stage++)
		printf("��%2d�X�e�[�W�F%d\n", stage + 1, score[stage]);

	printf("%.1f�b�ł����B\n", difftime(end,start));

	return 0;
}