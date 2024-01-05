//単純記憶トレーニング（4桁の数値を記憶）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE 10

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
	int success = 0;	//正解数

	srand(time(NULL));	//乱数の種を設定

	printf("4桁の数値を記憶しよう。\n");

	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int x;	//読み込んだ値
		int no = rand() % 9000 + 1000;	//記憶すべき数値

		printf("%d", no);
		fflush(stdout);
		sleep(500);	//問題提示は0.5秒だけ

		printf("\r入力せよ：");
		fflush(stdout);
		scanf("%d", &x);

		if (x != no)
			printf("間違いです。\a\n");
		else {
			printf("正解です。\n");
			success++;
		}
	}
	time_t end = time(NULL);

	printf("%d回中%d回成功。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", difftime(end, start));
	return 0;
}