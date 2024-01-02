//コンピュータが必ず勝つじゃんけんゲーム

#include<stdio.h>

int main(void)
{
	char* hd[] = { "グー", "チョキ", "パー" };	//手
	printf("じゃんけんゲーム開始\n");

	int retry;	//再度

	do {
		int human;	//人間の手

		do {
			printf("\nじゃんけんポン…");
			int i;
			for (i = 0; i < 3; i++)
				printf("(%d)%s", i, hd[i]);
			printf(":");
			scanf("%d", &human);	//人間の手を読み込む
		} while (human < 0 || human > 2);

		int comp = (human + 2) % 3;	//コンピュータは後出し
		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);
		int judge = (human - comp + 3) % 3;	//勝敗を判定

		switch (judge) {
		case 0: puts("引き分けです"); break;
		case 1: puts("あなたの負けです"); break;
		case 2: puts("あなたの勝ちです"); break;
		}

		printf("もう一度しますか？…0：いいえ　１：はい");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}