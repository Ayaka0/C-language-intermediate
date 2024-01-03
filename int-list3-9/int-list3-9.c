//����񂯂�Q�[���i���̂S�F�֐��ɕ����{�\���̂ɂ��X�R�A���L�^�j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

//�X�R�A�p�\����

typedef struct {
	int draw;	//������������
	int lose;	//��������
	int win;	//��������
}Score;

char* hd[] = { "�O�[", "�`���L", "�p�[" };	//��

//��������
void initialize(Score* s)
{
	s->win = s->lose = s->draw = 0;	//�X�R�A���N���A

	srand(time(NULL));	//�����̎��ݒ�

	printf("����񂯂�Q�[���J�n\n");
}

//����񂯂���s�i�R���s���[�^�̎�̐���/���[�U�[�̎�̓ǂݍ��݁j
void jyanken(int* h_hand, int* c_hand)
{
	*c_hand = rand() % 3;	//�R���s���[�^�̎�i0�`2�j�𗐐��Ő���

	do {
		printf("\n����񂯂�|���c");
		int i;
		for (i = 0; i < 3; i++)
			printf("(%d)%s", i, hd[i]);
		printf(":");
		scanf("%d", h_hand);
	} while (*h_hand < 0 || *h_hand > 2);
}

//�X�R�A�X�V
void update_score(Score* s, int result)
{
	switch (result) {
	case 0: s->draw++; break;	//��������
	case 1: s->lose++; break;	//����
	case 2: s->win++; break;	//����
	}
}

//���茋�ʂ�\��
void disp_result(int result)
{
	switch (result) {
	case 0: puts("��������"); break;	//��������
	case 1: puts("���Ȃ��̕���"); break;	//����
	case 2: puts("���Ȃ��̏���"); break;	//����	
	}
}

//�Ē��킷�邩���m�F
int confirm_retry(void)
{
	int x;

	printf("������x�H�c0�������@1�͂��F");
	scanf("%d", &x);

	return x;
}

int main(void)
{
	Score score;	//�X�R�A
	initialize(&score);	//��������
	int retry;	//�ēx�H

	do {
		int human;	//�l�Ԃ̎�
		int comp;	//�R���s���[�^�̎�

		jyanken(&human, &comp);	//����񂯂���s

		//�R���s���[�^�Ɛl�Ԃ̎��\��
		printf("����%s�ŁA���Ȃ���%s�ł��B\n", hd[comp], hd[human]);

		int judge = (human - comp + 3) % 3;	//���s�𔻒�

		update_score(&score, judge);	//�X�R�A�X�V

		disp_result(judge);	//���茋�ʂ�\��

		retry = confirm_retry();	//�Ē��킷�邩�̊m�F
	} while (retry == 1);

	printf("%d��%d�s%d�����ł����B\n", score.win, score.lose, score.draw);

	return 0;
}