//単純記憶トレーニング（英字記憶・その１大文字のみ）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STAGE 10	//ステージ数
#define LEVEL_MIN	3	//最小レベル（文字数）
#define LEVEL_MAX	20	//最大レベル（文字数）

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
	int level;	//レベル（文字数）
	int success = 0;	//正解数
	const char ltr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	//英大文字

	srand(time(NULL));	//乱数の種を設定

	printf("英字記憶トレーニング\n");

	do {
		printf("挑戦するレベル（%d～%d）：", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level> LEVEL_MAX);

	printf("%d個の英字を記憶する\n", level);

	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		char mstr[LEVEL_MAX + 1];	//記憶すべき英字の並び
		char x[LEVEL_MAX * 2];	//読み込んだ英字の並び

		for (int i = 0; i < level; i++)	//問題の文字列を作成
			mstr[i] = ltr[rand() % strlen(ltr)];
		mstr[level] = '\0';

		printf("%s", mstr);
		fflush(stdout);
		sleep(125 * level);	//問題提示は125ｘlevelミリ秒

		printf("\r%*s\r入力せよ：", level, "");
		fflush(stdout);
		scanf("%s", x);

		if (strcmp(x, mstr) != 0)
			printf("間違いです。\n");
		else {
			printf("正解です\n");
			success++;
		}
	}
	time_t end = time(NULL);

	printf("%d回中%d回成功した。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", difftime(end, start));


	return 0;
}