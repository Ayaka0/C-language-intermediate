//���\b�̗��p��1�b���Ƃ�1����������

#include<stdio.h>
#include<time.h>

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
	printf("ABCDEFG");

	for (int i = 0; i < 7; i++) {
		sleep(1000);	//1�b���Ƃ�
		printf("\b \b");	//��납��1����������
		fflush(stdout);	//�o�b�t�@��|���o��
	}

	sleep(500);
	printf("�����I��\n");

	return 0;
}
