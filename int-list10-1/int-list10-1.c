//�p�P��w�K�\�t�g�i����ŁF���{��̒P��A�p�P��������_���ɕ\���j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define QNO 12	//�P��̐�

//���{��
char* jword[] = {
	"����","��","��","��","��","�{","�֎q",
	"��","��","��","���a","�G��", };

//�p��
char* eword[] = {
	"animal","car","flower","house","desk","book",
	"chair","father","mother","love","peace","magazine", };

int main(void)
{
	srand(time(NULL));	//�����̎��ݒ�

	int pq = QNO;	//�O��̖��ԍ��i�����l�͑��݂��Ȃ����ԍ��j
	int retry;	//�Ē��킷�邩�H

	do {
		int nq;					//���ԍ�
		do {					//�O��Əd�����Ȃ��悤�ɖ��ԍ�������
			nq = rand() % QNO;
		} while (nq == pq);

		int lang = rand() % 2;		//�P��̌���i0�F���{��@�P�F�p��j

		printf("%s\n", lang ? eword[nq] : jword[nq]);
		pq = nq;

		printf("������x�H�@0�[�������@1�[�͂��F");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}