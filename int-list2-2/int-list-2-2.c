//後退\bの利用例1秒ごとに1文字ずつ消去

#include<stdio.h>
#include<time.h>

//xミリ秒経過するのを待つ
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	//エラー
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	printf("ABCDEFG");

	for (int i = 0; i < 7; i++) {
		sleep(1000);	//1秒ごとに
		printf("\b \b");	//後ろから1文字ずつ消す
		fflush(stdout);	//バッファを掃き出す
	}

	sleep(500);
	printf("消去終了\n");

	return 0;
}
