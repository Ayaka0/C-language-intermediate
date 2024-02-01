//1つの文字列によるキータイピング練習（その2：売った文字が消えていく）

#include<time.h>
#include<stdio.h>
#include<string.h>
#include"int-list7-8.h"

int main(void)
{
	char* str = "How do you do?";	//タイプする文字列
	int len = strlen(str);	//文字列strの文字数

	init_getputch();
	printf("この通りタイプしよう。\n");

	time_t start = time(NULL);	//開始時刻

	for (int i = 0; i < len; i++) {
		//str[i]以降と空白を表示してカーソルを先頭へ戻す
		printf("%s \r", &str[i]);

		fflush(stdout);
		while (getch() != str[i])
			;
	}

	time_t end = time(NULL);	//終了時刻
	printf("\r%.1f秒でした。\n", difftime(end, start));
	term_getputch();

	return 0;
}