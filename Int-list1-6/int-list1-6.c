//�����ăQ�[���i���̂R�F���Ă����鐔��0�`999�̗����j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL)); //�����̎��ݒ�
	int ans = rand() % 1000; //0�`999�̗����𐶐�
	int no; //�ǂݍ��񂾒l

	printf("0�`999�̐����𓖂Ă悤�B\n\n");

	do {
		printf("�������ȁF");
		scanf("%d", &no);

		if (no > ans)
			printf("�����Ə�������B\n");
		else if (no < ans)
			printf("�����Ƒ傫����B\n");
	} while (no != ans);

	printf("�����ł��B\n");


	return 0;
}