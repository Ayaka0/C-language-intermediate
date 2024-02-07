//���b�N�i���o�[�T�[�`�E�g���[�j���O
#include<time.h>
#include<float.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include"int-list7-8.h"

#define MAX_STAGE	10
#define swap(type, x,y) do{type t = x; x = y; y = t;}while(0)

char dtfile[] = "LACKNUM.DAT";	//�t�@�C����

//�O��̃g���[�j���O�����擾�E�\�����čō����_��Ԃ�
double get_data(void)
{
	FILE* fp;
	double best;	//�ō����_

	if ((fp = fopen(dtfile, "r")) == NULL) {
		printf("�{�v���O���������s����̂͏��߂āB\n\n");
		best = DBL_MAX;
	}
	else {
		int year, month, day, h, m, s;
		fscanf_s(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
		fscanf_s(fp, "%lf", &best);
		printf("�O��̏I����%d�N%d��%d��%d��%��%d�b�ł����B\n", year, month, day, h, m, s);

		printf("����܂ł̍ō����_�i�ŒZ���v���ԁj��%.1f�b�ł��B\n\n", best);
		fclose(fp);
	}
	return best;
}

//����̃g���[�j���O������������
void put_data(double best) {
	FILE* fp;

	if ((fp = fopen(dtfile, "w")) == NULL)
		printf("�G���[����");
	else {
		time_t t = time(NULL);
		struct tm* local = localtime(&t);
		fprintf(fp, "%d %d %d %d %d %d\n",
			local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
			local->tm_hour, local->tm_min, local->tm_sec);
		fprintf(fp, "%f\n", best);
		fclose(fp);
	}
}

//�g���[�j���O�����s���ē��_�i���v���ԁj��Ԃ�
double go(void)
{
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[8];

	printf("�����Ă��鐔���������悤\n");
	printf("�X�y�[�X�L�[�ŊJ�n���܂��B\n");
 	while (getch() != ' ');
	;

	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;	//�R�s�[���΂��v�f�̓Y����

		int i = 0, j = 0;
		while (i < 9) {	//dtg[x]���΂��ăR�s�[
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (int i = 7; i > 0; i--) {	//�z��a���V���b�t��
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (int i = 0; i < 8; i++)	//�S�v�f��\��
			printf("%d", a[i]);
			printf(":");
		fflush(stdout);
		int no;	//�ǂݍ��񂾒l
		do {
			no = getch();
			if (isprint(no)) {	//�\���\�Ȃ�
				putch(no);		//�����ꂽ�L�[��\��
				if (no != dgt[x] + '0')	//�����łȂ����
					putch('\b');	//�J�[�\����1�߂�
				else
					printf("\n");	//���s
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	time_t end = time(NULL);
	double jikan = difftime(end, start);
	printf("%.1f�b������܂����B\n", jikan);

	if (jikan > 25.0)
		printf("�݂�����\n");
	else if (jikan > 20.0)
		printf("�����݂�\n");
	else if (jikan > 17.0)
		printf("�܂��܂�\n");
	else
		printf("�f����\n");

	return jikan;
}

int main(void)
{
	init_getputch();
	srand(time(NULL));	//�����̎��ݒ�
	double best_score = get_data();//����܂ł̍ō����_�i���v���ԁj�𓾂�
	int retry;	//������x

	do {
		double score = go();	//�g���[�j���O���s
		if (score < best_score) {
			printf("�ō����_�i���v���ԁj���X�V\n");
			best_score = score;	//�ō����_�X�V
		}
		printf("������x�H�c0�������@�P�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	put_data(best_score);	//�����̓��t�E�����A���_����������
	term_getputch();

	return 0;
}