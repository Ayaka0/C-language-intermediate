//複数文字列によるキータイピング練習（その２：出題順序ランダム手法２）

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

	init_getputch();
	srand(time(NULL));	//乱数の種を設定

	for (int i = QNO - 1; i > 0; i--) {	//配列strをシャッフル
		int j = rand() % (i + 1);
		if (i != j)
			swap(char*, str[i], str[j]);
	}

	printf("タイピング練習開始\n");
	printf("スペースキーで開始\n");
	while (getch() != ' ')	//スペースキーが押下
		;					//されるまで待つ

	time_t start = time(NULL);	//開始時刻

	for (int stage = 0; stage < QNO; stage++) {
		int len = strlen(str[stage])	//文字列str[stage]の文字数
			for (int i = 0; i < len; i++) {
				//str[stage][i]以降を表示してカーソルを先頭に戻す
				printf("%s \r", &str[stage][i]);

				fflush(stdout);
				while (getch() != str[stage][i])
					;
			}
	}

	time_t end = time(NULL);	//終了時刻

	printf("\r%.1f秒でした。\n", difftime(end, start));

	term_getputch();

	return 0;
}