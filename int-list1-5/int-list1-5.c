//�����𐶐��i���̂Q�F���݂̎����Ɋ�Â��ė����̎��ݒ�j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL)); //���݂̎����Ɋ�Â��ė����̎��ݒ�

	printf("���̏����n�ł�0�`%d�̗����������ł���B\n", RAND_MAX);

	int retry; //������x�H

	do {
		printf("����%d�𐶐������B\n", rand());

		printf("������x�H�c�@0�F�������A1�F�͂�");
		scanf("%d", &retry);
	} while (retry == 1);



	return 0;
}