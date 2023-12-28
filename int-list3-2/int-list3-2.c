//じゃんけんゲーム（その２：両者の手を表示）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//乱数の種を設定

	printf("じゃんけんゲーム開始\n");

	int retry;	//再度

	do {
		int comp = rand() % 3;	//コンピュータの手：0～2の乱数
		int human;	//human's hand

		do {
			printf("\nじゃんけんポン…0：グー　1：チョキ　2：パー：");
			scanf("%d", &human);	//人間の手を読み込み
		} while (human < 0 || human > 2);

		printf("私は");
		switch (comp) {	//コンピュータの手を表示
		case 0: printf("グー"); break;
		case 1: printf("チョキ"); break;
		case 2: printf("パー"); break;
		}

		printf("あなたは");
		switch (human) {	//人間の手を表示
		case 0: printf("グー"); break;
		case 1: printf("チョキ"); break;
		case 2: printf("パー"); break;
		}
		printf("です。\n");

		int judge = (human - comp + 3) % 3;	//勝敗判定

		switch (judge) {	//勝敗判定
		case 0: printf("引き分け"); break;
		case 1: printf("あなたの負け"); break;
		case 2: printf("あなたの勝ち"); break;
		}

		printf("もう一度？…0：いいえ　1：はい");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}