//���݂����v���O����

#include<time.h>
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	srand(time(NULL));	//�����̎�̐ݒ�
	int ans;
	int num;		//�ǂݍ��񂾒l

	do {
		printf("���݂��������悤\n");
	;	num = rand() % 11;	//0�`6�̗�������

		switch (num) {
		case 0:
		case 1:
			printf("��g\n");
			break;
		case 2:
		case 3:
			printf("���g\n");
			break;
		case 4:
		case 5:
			printf("���g\n");
			break;
		case 6:
			printf("�g\n");
			break;
		case 7:
			printf("���g\n");
			break;
		case 8:
			printf("��\n");
			break;
		case 9:
			printf("�勥\n");
			break;
		}

		printf("������x�H �͂��F0�@�������F9\n");
		scanf("%d", &ans);
	} while (ans == 0);

	return 0;
}