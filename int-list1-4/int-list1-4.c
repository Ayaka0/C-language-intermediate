//�����𐶐��i���̂P�j
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("���̏����n�ł�0�`%d�̗����������ł���B\n", RAND_MAX);
	
	int retry; //������x

	do {
		printf("����%d�𐶐����܂����B\n", rand());

		printf("������x�H�c 0�F������ 1�F�͂�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}