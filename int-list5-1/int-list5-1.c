//�P���L���g���[�j���O�i4���̐��l���L���j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE 10

//x�~���b�o�߂���̂�҂�
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	//�G���[
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int success = 0;	//����

	srand(time(NULL));	//�����̎��ݒ�

	printf("4���̐��l���L�����悤�B\n");

	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int x;	//�ǂݍ��񂾒l
		int no = rand() % 9000 + 1000;	//�L�����ׂ����l

		printf("%d", no);
		fflush(stdout);
		sleep(500);	//���񎦂�0.5�b����

		printf("\r���͂���F");
		fflush(stdout);
		scanf("%d", &x);

		if (x != no)
			printf("�ԈႢ�ł��B\a\n");
		else {
			printf("�����ł��B\n");
			success++;
		}
	}
	time_t end = time(NULL);

	printf("%d��%d�񐬌��B\n", MAX_STAGE, success);
	printf("%.1f�b�ł����B\n", difftime(end, start));
	return 0;
}