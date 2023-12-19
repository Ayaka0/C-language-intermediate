//数当てゲーム（その４：入力回数に制限を設ける）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL)); //乱数の種を設定

	const int max_stage = 10; //最大入力回数
	int remain = max_stage; //残りの入力回数

	int ans = rand() % 1000; //0～999の乱数生成
	int no; //読み込んだ値

	printf("0～999の整数を当てよう。\n");

	do {
		printf("残り%d回。いくつかな：", remain);
		scanf("%d", &no);
		remain--; //残り回数のデクリメント

		if (no > ans)
			printf("もっと小さいよ。\n");
		else if (no < ans)
			printf("もっと大きいよ\n");
	} while (no != ans && remain > 0);

	if (no != ans)
		printf("残念。正解は%dでした。\n", ans);
	else {
		printf("正解です。\n");
		printf("%d回で当たりましたね。\n", max_stage - remain);
	}



	return 0;
}