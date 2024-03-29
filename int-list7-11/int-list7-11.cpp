//ダブルナンバーサーチ・トレーニング（その２；リアルタイムキー入力）

#include<ctype.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include"getputch.h"

#define MAX_STAGE 10	//挑戦回数
#define swap(type, x, y) do{ type t = x; x = y; y = t;} while (0)

int main(void)
{
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[10];

	init_getputch();
	srand(time(NULL));	//乱数の種を設定

	printf("ダブっている数字を見つける\n");
	printf("スペースキーで開始する\n");
	fflush(stdout);
	while (getch() != ' ')
		;
	time_t start = time(NULL);
	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;	//ダブってコピーする要素の添え字

		int i = 0; j = 0;
		while (i < 9) {	//dgt[x]をだぶらせてコピー
			a[j++] = dgt[i];
			if (i == x)
				a[j++] = dgt[i];
			i++;
		}
		for (int i = 9; i > 0; i--) {	//配列aをシャッフル
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}
		for (int i = 0; i < 10; i++)	//全要素を表示
			printf("%d", a[i]);
		printf(":");
		fflush(stdout);

		int no;	//読み込んだ値
		do {
			no = getch();
			if (isprint(no)) {	//表示可能であれば
				putch(no);	//押されたキーを表示
				if (no != dgt[x] + '0')	//正解でなければ
					putch('\b');	//カーソルを1つ戻す
				else
					printf("\n");	//改行
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	time_t end = time(NULL);
	double jikan = difftime(end, start);
	printf("%.1f秒かかった。\n", jikan);

	if (jikan > 25.0)
		printf("鈍すぎる\n");
	else if (jikan > 20.0)
		printf("少し鈍い\n");
	else if (jikan > 17.0)
		printf("まあまあ\n");
	else
		printf("素早い\n");
	term_getputch();

	return 0;
}