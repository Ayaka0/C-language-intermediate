//�p�P��w�K�\�t�g�i����ŁF���{��̒P��A�p�P��������_���ɕ\���j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define QNO 12	//�P��̐�
#define CNO	4	//�I�����̐�

#define swap(type,x,y)	do{type t = x; x = y; y = t;} while(0)

//���{��
char* jword[] = {
	"����","��","��","��","��","�{","�֎q",
	"��","��","��","���a","�G��", };

//�p��
char* eword[] = {
	"animal","car","flower","house","desk","book",
	"chair","father","mother","love","peace","magazine", };

//�I�����𐶐����Đ����̓Y������Ԃ�
int make_cand(int c[], int answer)
{
	c[0] = answer;	//�擪�v�f�ɐ���������

	for (int i = 1; i < CNO; i++) {
		int j, x;
		do {
			x = rand() % QNO;	//�d�����Ȃ��悤�ɑI�����𐶐�
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

int main(void)
{
	srand(time(NULL));	//�����̎��ݒ�

	int pq = QNO;	//�O��̖��ԍ��i�����l�͑��݂��Ȃ����ԍ��j
	int retry;	//�Ē��킷�邩�H

	do {
		int nq;					//���ԍ�
		int cand[CNO];			//�I�����̔ԍ�

		do {					//�O��Əd�����Ȃ��悤�ɖ��ԍ�������
			nq = rand() % QNO;
		} while (nq == pq);

		int lang = rand() % 2;		//�P��̌���i0�F���{��@�P�F�p��j

		printf("%s�͂ǂ�ł����H\n", lang ? eword[nq] : jword[nq]);

		int na = make_cand(cand, nq);	//�I�����𐶐�
		int no;							//�ǂݍ��މ񓚔ԍ�

		do {
			print_cand(cand, lang);		//�I������\��
			scanf("%d", &no);
			if (no != na)
				puts("\a�Ⴂ�܂��B");
		} while (no != na);
		puts("�����ł��B");

		pq = nq;

		printf("������x�H�@0�[�������@1�[�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}