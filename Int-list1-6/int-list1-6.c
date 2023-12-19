//数当てゲーム（その３：当てさせる数は0～999の乱数）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL)); //乱数の種を設定
	int ans = rand() % 1000; //0～999の乱数を生成
	int no; //読み込んだ値

	printf("0～999の整数を当てよう。\n\n");

	do {
		printf("いくつかな：");
		scanf("%d", &no);

		if (no > ans)
			printf("もっと小さいよ。\n");
		else if (no < ans)
			printf("もっと大きいよ。\n");
	} while (no != ans);

	printf("正解です。\n");


	return 0;
}
