//���݂����v���O����

#include<time.h>
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	srand(time(NULL));	//�����̎�̐ݒ�

	int ans = rand() % 8;	//0�`6�̗�������
	int no;		//�ǂݍ��񂾒l
	int retry;
	
	do {
		printf("1�`7�̐�������͂��Ă��݂��������悤\n");
		scanf("%d", &no);

		switch (no) {
		case 1:
			printf("��g\n");
			break;
		case 2:
			printf("���g\n");
			break;
		case 3:
			printf("���g\n");
			break;
		case 4:
			printf("�g\n");
			break;
		case 5:
			printf("���g\n");
			break;
		case 6:
			printf("��\n");
			break;
		case 7:
			printf("�勥\n");
			break;
		}

		printf("������x�H �͂��F0�@�������F9");
		scanf("%d", &retry);
	} while (retry == 0);

	return 0;
}