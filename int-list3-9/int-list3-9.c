//じゃんけんゲーム（その４：関数に分割＋構造体によるスコアを記録）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

//スコア用構造体

typedef struct {
	int draw;	//引き分けた回数
	int lose;	//負けた回数
	int win;	//勝った回数
}Score;

char* hd[] = { "グー", "チョキ", "パー" };	//手

//初期処理
void initialize(Score* s)
{
	s->win = s->lose = s->draw = 0;	//スコアをクリア

	srand(time(NULL));	//乱数の種を設定

	printf("じゃんけんゲーム開始\n");
}

//じゃんけん実行（コンピュータの手の生成/ユーザーの手の読み込み）
void jyanken(int* h_hand, int* c_hand)
{
	*c_hand = rand() % 3;	//コンピュータの手（0～2）を乱数で生成

	do {
		printf("\nじゃんけんポン…");
		int i;
		for (i = 0; i < 3; i++)
			printf("(%d)%s", i, hd[i]);
		printf(":");
		scanf("%d", h_hand);
	} while (*h_hand < 0 || *h_hand > 2);
}

//スコア更新
void update_score(Score* s, int result)
{
	switch (result) {
	case 0: s->draw++; break;	//引き分け
	case 1: s->lose++; break;	//負け
	case 2: s->win++; break;	//勝ち
	}
}

//判定結果を表示
void disp_result(int result)
{
	switch (result) {
	case 0: puts("引き分け"); break;	//引き分け
	case 1: puts("あなたの負け"); break;	//負け
	case 2: puts("あなたの勝ち"); break;	//勝ち	
	}
}

//再挑戦するかを確認
int confirm_retry(void)
{
	int x;

	printf("もう一度？…0いいえ　1はい：");
	scanf("%d", &x);

	return x;
}

int main(void)
{
	Score score;	//スコア
	initialize(&score);	//初期処理
	int retry;	//再度？

	do {
		int human;	//人間の手
		int comp;	//コンピュータの手

		jyanken(&human, &comp);	//じゃんけん実行

		//コンピュータと人間の手を表示
		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		int judge = (human - comp + 3) % 3;	//勝敗を判定

		update_score(&score, judge);	//スコア更新

		disp_result(judge);	//判定結果を表示

		retry = confirm_retry();	//再挑戦するかの確認
	} while (retry == 1);

	printf("%d勝%d敗%d分けでした。\n", score.win, score.lose, score.draw);

	return 0;
}