//暗算トレーニング（0～99の整数を4つ加算するのに要する時間を計測）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//乱数の種を設定

	int a = rand() % 100;	//加える値：0～99の乱数
	int b = rand() % 100;	//加える値：0～99の乱数
	int c = rand() % 100;	//加える値：0～99の乱数
	int d = rand() % 100;	//加える値：0～99の乱数

	printf("%d + %d + %d + %dは何ですか：", a, b, c, d);

	time_t start = time(NULL);	//開始時刻

	while (1) {
		int x;	//読み込んだ値
		scanf("%d", &x);
		if (x == a + b + c + d)
			break;
		printf("違いますよ\n再入力してください：");

		time_t end = time(NULL);	//終了時刻

		printf("%.0f秒かかりました。\n", difftime(end, start));
	}


	return 0;
}