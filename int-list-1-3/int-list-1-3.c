//�����ăQ�[���i���̂Q�F������܂ŌJ��Ԃ��Fwhile���𗘗p�j

#include<stdio.h>

int main(void)
{
	printf("0�`9�̐����𓖂Ă悤\n");

	int ans = 7;   //���Ă����鐔
	int no;       //�ǂݍ��񂾒l

	while (1) {
		printf("�������ȁF");
		scanf("%d", &no);

		if (no > ans)
			printf("�����Ə�������B\n");
		else if (no < ans)
			printf("�����Ƒ傫����B\n");
		else
			break;
	}

	printf("�����ł��B\n");

	return 0;
}