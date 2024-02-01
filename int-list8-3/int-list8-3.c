//複数文字列によるキータイピング練習（その１）

#include<time.h>
#include<stdio.h>
#include<string.h>
#include"int-list7-8.h"

#define QNO 12	//問題数

int main(void) {

	char* str[QNO] = {
		"book","computer", "default", "comfort", "monday", "power", 
		"light", "programming", "music", "dog", "video", "include",
	};

	init_getputch();

	printf("タイピング練習を始めます\n");
	printf("スペースキーで開始します。\n");
	while (getch() != ' ')	//スペースキーが押下
		;					//されるまで待つ

	time_t start = time(NULL);	//開始時刻

	for (int stage = 0; stage < QNO; stage++) {
		int len = strlen(str[stage]);	//文字列str[stage]の文字数
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