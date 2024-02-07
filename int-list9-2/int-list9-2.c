//ラックナンバーサーチ・トレーニング
#include<time.h>
#include<float.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include"int-list7-8.h"

#define MAX_STAGE	10
#define swap(type, x,y) do{type t = x; x = y; y = t;}while(0)

char dtfile[] = "LACKNUM.DAT";	//ファイル名

//前回のトレーニング情報を取得・表示して最高得点を返す
double get_data(void)
{
	FILE* fp;
	double best;	//最高得点

	if ((fp = fopen(dtfile, "r")) == NULL) {
		printf("本プログラムを実行するのは初めて。\n\n");
		best = DBL_MAX;
	}
	else {
		int year, month, day, h, m, s;
		fscanf_s(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
		fscanf_s(fp, "%lf", &best);
		printf("前回の終了は%d年%d月%d日%d時%分%d秒でした。\n", year, month, day, h, m, s);

		printf("これまでの最高得点（最短所要時間）は%.1f秒です。\n\n", best);
		fclose(fp);
	}
	return best;
}

//今回のトレーニング情報を書き込む
void put_data(double best) {
	FILE* fp;

	if ((fp = fopen(dtfile, "w")) == NULL)
		printf("エラー発生");
	else {
		time_t t = time(NULL);
		struct tm* local = localtime(&t);
		fprintf(fp, "%d %d %d %d %d %d\n",
			local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
			local->tm_hour, local->tm_min, local->tm_sec);
		fprintf(fp, "%f\n", best);
		fclose(fp);
	}
}

//トレーニングを実行して得点（所要時間）を返す
double go(void)
{
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[8];

	printf("欠けている数字を見つけよう\n");
	printf("スペースキーで開始します。\n");
 	while (getch() != ' ');
	;

	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;	//コピーを飛ばす要素の添え字

		int i = 0, j = 0;
		while (i < 9) {	//dtg[x]を飛ばしてコピー
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (int i = 7; i > 0; i--) {	//配列aをシャッフル
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (int i = 0; i < 8; i++)	//全要素を表示
			printf("%d", a[i]);
			printf(":");
		fflush(stdout);
		int no;	//読み込んだ値
		do {
			no = getch();
			if (isprint(no)) {	//表示可能なら
				putch(no);		//押されたキーを表示
				if (no != dgt[x] + '0')	//正解でなければ
					putch('\b');	//カーソルを1つ戻す
				else
					printf("\n");	//改行
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	time_t end = time(NULL);
	double jikan = difftime(end, start);
	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0)
		printf("鈍すぎる\n");
	else if (jikan > 20.0)
		printf("少し鈍い\n");
	else if (jikan > 17.0)
		printf("まあまあ\n");
	else
		printf("素早い\n");

	return jikan;
}

int main(void)
{
	init_getputch();
	srand(time(NULL));	//乱数の種を設定
	double best_score = get_data();//これまでの最高得点（所要時間）を得る
	int retry;	//もう一度

	do {
		double score = go();	//トレーニング実行
		if (score < best_score) {
			printf("最高得点（所要時間）を更新\n");
			best_score = score;	//最高得点更新
		}
		printf("もう一度？…0いいえ　１はい：");
		scanf("%d", &retry);
	} while (retry == 1);

	put_data(best_score);	//今日の日付・時刻、得点を書き込む
	term_getputch();

	return 0;
}