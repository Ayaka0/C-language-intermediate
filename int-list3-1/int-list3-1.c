//じゃんけんゲーム（その１）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//乱数の種を設定

	printf("じゃんけんゲーム開始\n");

	int retry;	//再度トライ

	do {
		int comp = rand() % 3;	//コンピュータの手：0～2の乱数
		int human;				//人間の手

		printf("\nじゃんけんポン…0：グー　1：チョキ　2：パー：");
		scanf("%d", &human);	//人間の手を読み込む

		printf("私は");	//コンピュータの手を表示
		switch (comp) {
		case 0: printf("グー"); break;
		case 1: printf("チョキ"); break;
		case 2: printf("パー"); break;
		}
		printf("です。\n");

		
		/*
		printf("私は");
		if(comp == 0)
			printf("グー");
		else if (comp == 1)
			printf("チョキ");
		else if (comp == 2)
			printf("パー");
		
		printf("です。\n");
		
		int judge = (human - comp + 3) % 3;	//勝敗判定

		if(judge == 0)
			printf("引き分け");
		else if (comp == 1)
			printf("you are lose");
		else if (comp == 2)
			printf("You are win");

		printf("です。\n");

		*/
		

		
		int judge = (human - comp + 3) % 3;	//勝敗判定

		switch (judge) {
		case 0: printf("引き分けです。"); break;
		case 1: printf("あなたの負けです。"); break;
		case 2: printf("あなたの勝ちです。"); break;
		}
		
		printf("もう一度？…0：いいえ　1：はい：");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}