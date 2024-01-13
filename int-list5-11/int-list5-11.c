//プラスワントレーニング（その４：最後のMAX_RECORDステージの正解数を表示）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define LEVEL_MIN	2	//最小レベル（数値の個数）
#define LEVEL_MAX	5	//最大レベル（数値の個数）
#define	MAX_RECORD	10	//正解数を記録するステージ数

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
	int level;	//レベル
	int success = 0;	//全ステージの正解数の合計
	int score[MAX_RECORD];	//全ステージの正解数

	srand(time(NULL));	//乱数の種を設定

	printf("プラスワントレーニング開始\n");
	printf("2桁の数値を記憶します。\n");
	printf("1を加えた値を入力してください。\n");

	do {
		printf("挑戦するレベル（%d～%d）：", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	int stage = 0;

	time_t start = time(NULL);
	int retry;

	do {
		int no[LEVEL_MAX];	//記憶する数
		int x[LEVEL_MAX];	//読み込んだ値
		int seikai = 0;	//このステージの成功数

		printf("\n第%dステージ開始\n", stage + 1);

		for (int i = 0; i < level; i++) {	//level個だけ
			no[i] = rand() % 90 + 10;	//10～99の乱数を生成して
			printf("%d", no[i]);	//表示する
		}
		fflush(stdout);
		sleep(300 * level);	//0.3xlevel秒待つ
		printf("\r%*s\r", 3 * level, "");	//問題を消す
		fflush(stdout);

		for (int i = 0; i < level; i++) {	//回答を読み込む
			printf("%d番目の数：", i + 1);
			scanf("%d", &x[i]);
		}

		for (int i = 0; i < level; i++) {	//正誤を判定・表示
			if (x[i] != no[i] + 1)
				printf("x ");
			else {
				printf("〇 ");
				seikai++;
			}
		}

		putchar('\n');

		for (int i = 0; i < level; i++)	//正解を表示
			printf("%2d ", no[i]);

		printf(" … %d個正解です。\n", seikai);

		score[stage++ % MAX_RECORD] = seikai;	//ステージの正解数を記録
		success += seikai;	//全体の正解数を更新

		printf("続けますか？（yes…1 / no…0）：");
		scanf("%d", &retry);
	} while (retry == 1);
	time_t end = time(NULL);

	printf("\n■□ 成績 □■\n");

	int stage2 = stage - MAX_RECORD;
	if (stage2 < 0) stage2 = 0;

	for (int i = level; i >= 1; i--) {
		for (int j = stage2; j < stage; j++)
			if (score[j % MAX_RECORD] >= i)
				printf(" ★ ");
			else
				printf("    ");
		putchar('\n');
	}
	printf("----------------------------------------\n");

	for (int j = stage2; j < stage; j++)
		printf(" %02d", j + 1);
	putchar("\n");

	printf("%d個中%d個正解。\n", level * stage, success);
	printf("%.1f秒でした。\n", difftime(end, start));



	return 0;
}