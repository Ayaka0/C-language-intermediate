//数当てゲーム（その２：当たるまで繰り返す：do文を利用）

#include<stdio.h>

int main(void)
{
	printf("0～9の整数を当てよう。\n");

	int ans = 7; //当てさせる数
	int no;     //読み込んだ値

	do {
		printf("いくつかな：");
		scanf("%d", &no);

		if (no > ans)
			printf("もっと小さいよ。\n");
		else if (no < ans)
			printf("もっと大きいよ。\n");
	} while (no != ans);					//当たるまで繰り返す

	printf("正解です。\n");

	return 0;
}