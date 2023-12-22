#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_STAGE 10 //最大入力回数

int main(void)
{
	srand(time(NULL)); //乱数の種を設定
	int ans;
	int num;
	//int stage = 10;
	int no; //読み込んだ値
	int remain = MAX_STAGE;	//残り回数

	//3の倍数乱数が出るまで繰り返す
	do {
		num = 3 + rand() % 1000; //3以上999以下の乱数生成
	} while (num % 3);
	
	printf("3～999の整数を当てよう。\n");


	do {
		printf("残り%d回,いくつかな：", remain);
		scanf("%d", &ans);
		remain--;

		if (ans % 3 != 0)	//3の倍数出ない場合
		{
			printf("3の倍数ではないので終了\n");
			break;
		}
		else
			if (ans > num)
				printf("もっと小さいよ\n");
			else if (ans < num)
				printf("もっと大きいよ\n");
	} while (ans  != num && remain < MAX_STAGE);

	return 0;
}




//入力された値が3の倍数でない場合、ゲーム終了し、再入力

//入力された値が3の倍数なら、判定結果表示