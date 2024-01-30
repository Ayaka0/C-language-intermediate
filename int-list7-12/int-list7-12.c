//トライグラフ連想トレーニング（数字・英字の3文字の並びを完成させる）

#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"getputch.h"

#define MAX_STAGE 20
#define swap(type, x,y) do{type t = x; x = y; y = t;}while(0)

int main(void)
{
	char* qstr[] = { "0123456789",
					"ABCDEFGHIGKLMNOPQRSTUVWXYZ",
					"abcdefghijklmnopqrstuvwxyz" };

	int chmax[] = { 10, 26, 26 };

	init_getputch();
	srand(time(NULL));

	printf("　連続する3つの数字あるいは英字から\n");
	printf("　隠されている文字をタイプする\n");
	printf("　たとえばA ? C :とひょうじされたらBを\n");
	printf("　			4 5 ? :と表示されたら6を\n");
	printf("　タイプする\n");

	printf("★スペースキーで開始\n");
	while (getch() != ' ')
		;

	time_t start = time(NULL);

	for (int stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;	//0：数字/１：英大文字/２：英小文字
		int nhead = rand() % (chmax[qtype] - 2);	//先頭文字の添え字
		int x = rand() % 3;	//3文字のどれ'？'にするか

		putchar('\r');
		for (int i = 0; i < 3; i++) {	//問題を表示
			if (i != x)
				printf(" %c", qstr[qtype][nhead + i]);
			else
				printf(" ?");
		}
		printf(" : ");
		fflush(stdout);

		int key;	//読み込んだキー
		do {
			key = getch();
			if (isprint(key)) {	//表示可能なら
				putch(key);	//押されたキーを表示
				if (key != qstr[qtype][nhead + x])	//正解でなければ
					putch('\b');	//カーソルを1つ戻す
			}
		} while (key != qstr[qtype][nhead + x]);
		printf("\n");
	}

	time_t end = time(NULL);

	double jikan = difftime(end, start);
	printf("\n%.1f秒かかった\n", jikan);

	if (jikan > 50.0)
		printf("鈍すぎる\n");
	else if (jikan > 40.0)
		printf("少し鈍い\n");
	else if (jikan > 34.0)
		printf("まあまあ\n");
	else
		printf("素早い\n");

	term_getputch();


	return (0);
}
