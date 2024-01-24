//ダブルナンバーサーチ・トレーニング（その１）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE	10	//挑戦回数
#define swap(type, x, y) do{ type t = x; x = y; y = t;} while(0)

int main(void) {

	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];

	srand(time(NULL));	//乱数の種を設定

	printf("ダブっている数字を見つけよう\n");
	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;	//ダブってコピーを飛ばす要素の添字（0～8）

		int i = 0, j = 0;
		while (i < 9) {	//dgt[x]を飛ばしてコピー
				a[j++] = dgt[i];
			if (i == x)
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
		printf("：");
		int no;	//読み込んだ値
		do {
			scanf("%d", &no);
		} while (no != dgt[x]);	//正解が入力されるまで繰り返す
	}
	time_t end = time(NULL);

	double jikan = difftime(end, start);

	printf("%.1f秒かかりました\n", jikan);

	if (jikan > 25.0)
		printf("鈍すぎます\n");
	else if (jikan > 20.0)
		printf("少し鈍すぎます\n");
	else if (jikan > 17.0)
		printf("まあまあですね\n");
	else
		printf("素早いですね\n");



	return 0;
}