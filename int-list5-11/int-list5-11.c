//�v���X�����g���[�j���O�i���̂S�F�Ō��MAX_RECORD�X�e�[�W�̐��𐔂�\���j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define LEVEL_MIN	2	//�ŏ����x���i���l�̌��j
#define LEVEL_MAX	5	//�ő僌�x���i���l�̌��j
#define	MAX_RECORD	10	//���𐔂��L�^����X�e�[�W��

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
	int score[MAX_RECORD];	//�S�X�e�[�W�̐���

	srand(time(NULL));	//�����̎��ݒ�

	printf("�v���X�����g���[�j���O�J�n\n");
	printf("2���̐��l���L�����܂��B\n");
	printf("1���������l����͂��Ă��������B\n");

	do {
		printf("���킷�郌�x���i%d�`%d�j�F", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	int stage = 0;

	time_t start = time(NULL);
	int retry;

	do {
		int no[LEVEL_MAX];	//�L�����鐔
		int x[LEVEL_MAX];	//�ǂݍ��񂾒l
		int seikai = 0;	//���̃X�e�[�W�̐�����

		printf("\n��%d�X�e�[�W�J�n\n", stage + 1);

		for (int i = 0; i < level; i++) {	//level����
			no[i] = rand() % 90 + 10;	//10�`99�̗����𐶐�����
			printf("%d", no[i]);	//�\������
		}
		fflush(stdout);
		sleep(300 * level);	//0.3xlevel�b�҂�
		printf("\r%*s\r", 3 * level, "");	//��������
		fflush(stdout);

		for (int i = 0; i < level; i++) {	//�񓚂�ǂݍ���
			printf("%d�Ԗڂ̐��F", i + 1);
			scanf("%d", &x[i]);
		}

		for (int i = 0; i < level; i++) {	//����𔻒�E�\��
			if (x[i] != no[i] + 1)
				printf("x ");
			else {
				printf("�Z ");
				seikai++;
			}
		}

		putchar('\n');

		for (int i = 0; i < level; i++)	//������\��
			printf("%2d ", no[i]);

		printf(" �c %d�����ł��B\n", seikai);

		score[stage++ % MAX_RECORD] = seikai;	//�X�e�[�W�̐��𐔂��L�^
		success += seikai;	//�S�̂̐��𐔂��X�V

		printf("�����܂����H�iyes�c1 / no�c0�j�F");
		scanf("%d", &retry);
	} while (retry == 1);
	time_t end = time(NULL);

	printf("\n���� ���� ����\n");

	int stage2 = stage - MAX_RECORD;
	if (stage2 < 0) stage2 = 0;

	for (int i = level; i >= 1; i--) {
		for (int j = stage2; j < stage; j++)
			if (score[j % MAX_RECORD] >= i)
				printf(" �� ");
			else
				printf("    ");
		putchar('\n');
	}
	printf("----------------------------------------\n");

	for (int j = stage2; j < stage; j++)
		printf(" %02d", j + 1);
	putchar("\n");

	printf("%d��%d�����B\n", level * stage, success);
	printf("%.1f�b�ł����B\n", difftime(end, start));



	return 0;
}