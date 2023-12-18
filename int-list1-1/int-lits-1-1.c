//数当てゲーム（その１：試作版）

#include<stdio.h>

int main(void)
{
	printf("0～9の整数を当てよう！\n");

	int ans = 7; //当てさせる数
	int no;     //読み込んだ値

	printf("いくつかな：");
	scanf("%d", &no);

	if (no > ans)
		printf("もっと小さいよ。\n");
	else if (no < ans)
		printf("もっと大きいよ。\n");
	else
		printf("正解です。\n");


	return 0;
}