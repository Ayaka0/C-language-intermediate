//左右方向の視野拡大訓練を兼ねた暗算トレーニング

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//乱数の種を設定

	printf("視野拡大暗算トレーニング開始！\n");
	time_t start = time(NULL);	//開始時刻

	for (int stage = 0; stage < 10; stage++) {
		int a = 10 + rand() % 90;	//加算する数値：10～99の乱数
		int b = 10 + rand() % 90;	//		”
		int c = 10 + rand() % 90;	//		”
		int n = rand() % 17;		//余白の幅：0～16の乱数

		printf("%d%*s + %*s%d%*s + %*s%d：", a, n, "", n, "", b, n, "", n, "", c);

		do {
			int x;
			scanf("%d", &x);
			if (x == a + b + c)
				break;
			printf("違います。再入力してください：");
		} while (1);
	}

	time_t end = time(NULL);	//終了時刻

	printf("%.1f秒かかりました。\n", difftime(end, start));

	return 0;
}