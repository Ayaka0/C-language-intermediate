//���A\r�̗��p��F�\���ς݂̍s�̏�������

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
	printf("My name is Fukuoka.");
	fflush(stdout);

	sleep(2000);
	printf("\rHow do you do?     ");
	fflush(stdout);

	sleep(2000);
	printf("\rThanks.            ");

	printf("\v123\vABCDEFG\vttelevision");


	return 0;
}