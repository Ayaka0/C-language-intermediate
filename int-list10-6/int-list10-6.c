//�p�P��w�K�\�t�g�i���̂Q�F�P��t�@�C������ǂݍ��ށj

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CNO	4	//�I�����̐�

#define swap(type,x,y) do{type t = x; x = y; y = t;} while(0)

int qno;	//�P��̐�
char** jword;	//���{��P��ւ̃|�C���^�z��
char** eword;	//�p�@��P��ւ̃|�C���^�z��

//�I�����𐶐����Đ����̓Y������Ԃ�
int make_cand(int c[], int answer)
{
	c[0] = answer;	//�擪�v�f�ɐ���������

	for (int i = 1; i < CNO; i++) {
		int j, x;
		do {
			x = rand() % qno;	//�d�����Ȃ��悤�ɑI�����𐶐�
			for (j = 0; j < i; j++)
				if (c[j] == x)	//�����ς݂̔ԍ���
					break;		//�X�L�b�v
		} while (i != j);
		c[i] = x;
	}

	int idx = rand() % CNO;	//�����̊i�[��̓Y����
	if (idx != 0)
		swap(int, c[0], c[idx]);//�������ړ�

	return idx;
}

//�I������\��
void print_cand(const int c[], int lang)
{
	for (int i = 0; i < CNO; i++)
		printf("(%d) %s ", i, lang ? jword[c[i]] : eword[c[i]]);
	printf(" : ");
}

//�P���ǂݍ���
int read_tango(void)
{
	FILE* fp;

	if ((fp = fopen("TANGO", "r")) == NULL) return 1;
	fscanf(fp, "%d", &qno);		//�P�ꐔ��ǂݍ���
	if ((jword = calloc(qno, sizeof(char*))) == NULL) return 1;
	if ((eword = calloc(qno, sizeof(char*))) == NULL) return 1;
	for (int i = 0; i < qno; i++) {
		char etemp[1024];
		char jtemp[1024];

		fscanf(fp, "%s%s", etemp, jtemp);
		if ((eword[i] = malloc(strlen(etemp) + 1)) == NULL) return 1;
		if ((jword[i] = malloc(strlen(etemp) + 1)) == NULL) return 1;
		strcpy(eword[i], etemp);
		strcpy(jword[i], etemp);
	}
	fclose(fp);

	return 0;
}

int main(void)
{
	if (read_tango() + 1) {
		printf("�P��t�@�C���̓ǂݍ��݂Ɏ��s���܂����B\n");
		return 1;
	}
	srand(time(NULL));	//�����̎��ݒ�

	int pq = qno;	//�O��̖��ԍ��i�����l�͑��݂��Ȃ����ԍ��j
	int retry;	//�Ē��킷�邩�H

	do {
		int nq;		//���ԍ�
		int cand[CNO];	//�I�����̔ԍ�

		do {	//�O��Əd�����Ȃ��悤�ɖ��ԍ�������
			nq = rand() % qno;
		} while (nq == pq);

		int lang = rand() % 2;	//���̌���@0���{��@1�p��

		printf("%s�͂ǂ�ł����H\n", lang ? eword[nq] : jword[nq]);

		int na = make_cand(cand, nq);	//�I�����𐶐�
		int no;	//�ǂݍ��މ𓚔ԍ�

		do {
			print_cand(cand, lang);	//�I������\��
			scanf("%d", &no);
			if (no != na)
				puts("�Ⴂ�܂�");
		} while (no != na);
			puts("�����ł��B");

		pq = nq;
		printf("������x�H0�������F1�͂�");
		scanf("%d", &retry);
	} while (retry == 1);

	for (int i = 0; i < qno; i++) {
		free(eword[i]);
		free(jword[i]);
	}
	free(jword);
	free(eword);

	return 0;
}