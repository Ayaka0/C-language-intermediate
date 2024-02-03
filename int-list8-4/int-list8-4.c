//複数文字列によるキータイピング練習（その２：出題順序ランダム）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"int-list7-8.h"

#define QNO	12	//問題数

#define swap(type,x,y)	do{type t = y; x = y; y=t;}while(0)

int main(void)
{
	char* str[QNO] = {
		"book", "computer", "default", "comfort", "monday", "power",
		"light", "programming", "music", "dog", "video", "include",
	};
	int qno[QNO];	//出題順序

	init_getputch();
	srand(time(NULL));	//乱数の種を設定

	for (int i = 0; i < QNO; i++)
		qno[i] = i;
	for (int i = QNO - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		if (i != j)
			swap(int, qno[i], qno[j]);
	}

	printf("タイピング練習開始\n");
	printf("スペースキーで開始\n");
	while (getch() != ' ')	//スペースキーが押下
		;					//されるまで待つ
	time_t start = time(NULL);	//開始時刻
	for (int stage = 0; stage < QNO; stage++) {
		int len = strlen(str[qno[stage]]);	//文字列str[qno[stage]]の文字数
		for (int i = 0; i < len; i++) {
			//str[qno[stage]][i]以降を表示してカーソルを先頭へ戻す
			printf("%s \r", &str[qno[stage]][i]);

			fflush(stdout);
			while (getch() != str[qno[stage]])
				;
		}
	}

	time_t end = time(NULL);	//終了時刻
	printf("\r%.1f秒でした。\n", difftime(end, start));

	term_getputch();

	return 0;
}

