//���E�����̎���g��P�������˂��ÎZ�g���[�j���O

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//�����̎��ݒ�

	printf("����g��ÎZ�g���[�j���O�J�n�I\n");
	time_t start = time(NULL);	//�J�n����

	for (int stage = 0; stage < 10; stage++) {
		int a = 10 + rand() % 90;	//���Z���鐔�l�F10�`99�̗���
		int b = 10 + rand() % 90;	//		�h
		int c = 10 + rand() % 90;	//		�h
		int n = rand() % 17;		//�]���̕��F0�`16�̗���

		printf("%d%*s + %*s%d%*s + %*s%d�F", a, n, "", n, "", b, n, "", n, "", c);

		do {
			int x;
			scanf("%d", &x);
			if (x == a + b + c)
				break;
			printf("�Ⴂ�܂��B�ē��͂��Ă��������F");
		} while (1);
	}

	time_t end = time(NULL);	//�I������

	printf("%.1f�b������܂����B\n", difftime(end, start));

	return 0;
}