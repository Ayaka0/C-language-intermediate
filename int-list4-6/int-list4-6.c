//�}�X�^�[�}�C���h
#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���قȂ�4�̐����̕��т𐶐����Ĕz��x�Ɋi�[

void make4digits(int x[])
{
	for (int i = 0; i < 4; i++) {
		int j, val;
		do {
			val = rand() % 10;	//0�`9�̗���
			for (j = 0; j < i; j++)	//���ɓ����Ă��邩
				if (val == x[j])
					break;
		} while (j < i);	//�d�����Ȃ��l��������܂ŌJ��Ԃ�
		x[i] = val;
	}
}

//���͂��ꂽ�����񂓂̑Ó������`�F�b�N

int check(const char s[])
{
	if (strlen(s) != 4)	//������̒������S�łȂ�
		return 1;
	for (int i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;	//�����ȊO�̕������܂܂�Ă���
		for (int j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;	//����̐������܂܂�Ă���
	}

	return 0;	//������͑Ó�
}

//�q�b�g���u���[�̔���

void judge(const char s[], const int no[], int* hit, int* blow)
{
	*hit = *blow = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j]) {	//��������v
				if (i == j)
					(*hit)++;		//�q�b�g�i�ʒu����v�j
				else
					(*blow)++;		//�u���[�i�ʒu���s��v�j
			}
		}
	}
}

//���茋�ʂ�\��
void print_result(int snum, int spos)
{
	if (spos == 4)
		printf("�����ł��I�I");
	else if (snum == 0)
		printf("	�����̐����͑S���܂܂�܂���B\n");
	else {
		printf("	�����̐�����%d�̐������܂܂�܂��B\n",snum);

		if (spos == 0)
			printf("	�������ʒu�������Ă��鐔���͂���܂���B\n");
		else
			printf("	���̒���%d�͈ʒu�������Ă��܂��B\n", spos);
	}
	putchar('\n');
}

int main(void)
{
	srand(time(NULL));

	puts("�E�}�X�^�[�}�C���h�����悤�B");
	puts("���Ă�̂́A4�̐����̕��тł��B");
	puts("���������������܂܂�邱�Ƃ͂���܂���B");
	puts("4307�̂悤�ɘA�����ē��͂��Ă��������B");
	puts("�X�y�[�X�����Ȃǂ���͂��Ă͂����܂���B\n");

	int no[4];	//���Ă鐔���̕���
	make4digits(no);	//���قȂ�S�̐����̕��т𐶐�

	int hit;	//�ʒu���������������Ă����
	int blow;	//�������������Ĉʒu���������Ă����
	int try_no = 0;	//���͉�

	time_t start = time(NULL);	//�J�n����

	do {
		int chk;	//���͂��ꂽ������̃`�F�b�N����
		char buff[10];	//�ǂݍ��ސ����̕��т��i�[���镶����
		do {
			printf("���͂��Ă��������F");
			scanf("%s", buff);	//������Ƃ��ēǂݍ���

			chk = check(buff);	//�ǂݍ��񂾕�������`�F�b�N

			switch (chk) {
			case 1: puts("�������4�����œ��͂��Ă��������B\n"); break;
			case 2: puts("�����ȊO�̕�������͂��Ȃ��ł�������\n"); break;
			case 3: puts("����̐����𕡐����͂��Ȃ��ł�������\n"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);	//����
		print_result(hit + blow, hit);	//���茋�ʂ�\��
	} while (hit < 4);

	time_t end = time(NULL);	//�I������

	printf("%d�񂩂���܂����B\n���v���Ԃ�%.1f�b�ł����B\n", try_no, difftime(end,start));

	return 0;
}