//数当てゲーム-999以上999以下

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE 10	//最大入力回数

int main(void)
{
	srand(time(NULL));	//乱数の種の設定

	int ans = -999 + rand() % 1000; //-999～999の乱数生成
	int remain = MAX_STAGE;	//残りの入力回数
	int no;		//読み込んだ値

	printf("-999～999の整数を当てる\n");

	do {
		printf("残り%d回数。いくつ。：", remain);
		scanf("%d", &no);
		remain--;

		if (no > ans)
			printf("もっと小さい\n");
		else if (no < ans)
			printf("もっと大きいよ\n");
	} while (no != ans && remain > 0);

	if (no != ans)
		printf("残念。正解は%dでした。\n", ans);
	else {
		printf("正解\n");
		printf("%d回で当たりました\n", MAX_STAGE - remain);
	}

	return 0;
}