//1つの文字列によるキータイピング
#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include"int-list7-8.h"

int main(void)
{
	char* str = "How do you do?";	//タイプする文字列
	int len = strlen(str);	//文字列strの文字数

	init_getputch();

	printf("この通りタイプしよう。\n");
	printf("%s\n", str);	//タイプする文字列を表示
	fflush(stdout);

	time_t start = time(NULL);	//開始時刻
	for (int i = 0; i < len; i++) {
		int ch;
		do {
			ch = getch();	//キー読み込み
			if (isprint(ch)) {
				putch(ch);	//押されたキーを表示
				if (ch != str[i])	//違うキーが押されたら
					putch('/b');	//カーソルを1つ戻す
			}
		} while (ch != str[i]);
	}

	time_t end = time(NULL);	//終了時刻

	printf("\n%.1f秒でした。\n", difftime(end, start));

	term_getputch();

	return 0;
}