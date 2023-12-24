//安産トレーニング（3個の3桁の整数を加える）
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//乱数の種を設定

	int a = 100 + rand() % 900;	//加算する数値：100～999の乱数
	int b = 100 + rand() % 900;
	int c = 100 + rand() % 900;

	printf("%d + %d + %dは何ですか：", a, b, c);

	clock_t start = clock();	//計測開始

	//正解するまで繰り返す
	while (1) {
		int x;	//読み込んだ値
		scanf("%d", &x);
		if (x == a + b + c)
			break;
		printf("違いますよ\n再入力してください：");
	}

	clock_t end = clock();	//計測終了

	double req_time = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", req_time);

	if (req_time > 30.0)
		printf("時間がかかりすぎです。\n");
	else if (req_time > 17.0)
		printf("まあまあですね\n");
	else
		printf("素早いですね\n");

	return 0;
}