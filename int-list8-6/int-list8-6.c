//キー配置連想タイピング練習（タイプする文字を考えさせる）
//A?DFGと表示されたらSをタイプ
//qwe?tと表示されたらrをタイプ

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"int-list7-8.h"

#define NO	30	//練習回数
#define KTYPE	16	//ブロック数

int main(void)
{
	char* kstr[] = {
		"12345", "67890-=\\",	//第1段
		"!@#$%", "^&*()_+",
		"qwert", "yuiop[]",
		"QWERT", "YUIOP{}",
		"asdfg", "hjkl;'\"",
		"ASDFG", "HJKL:",
		"zxcvb", "nm,./",
		"ZXCVB", "NM<>?",
	};

	init_getputch();
	srand(time(NULL));

	printf("キー位置連想タイピング\n");
	printf("？で隠された文字をタイプする\n");
	printf("スペースキーで開始\n");
	fflush(stdout);
	while (getch() != ' ');
	;

	time_t start = time(NULL);

	for (int stage = 0; stage < NO; stage++) {
		int k, p, key;
		char temp[10];

		do {
			k = rand() % KTYPE;
			p = rand() % strlen(kstr[k]);
			key = kstr[k][p];
		} while (key == ' ');
		strcpy(temp, kstr[k]);

		temp[p] = '?';

		printf("%s", temp);
		fflush(stdout);

		while (getch() != key)
			;
		putchar('\n');
	}
	time_t end = time(NULL);
	printf("%.1f秒でした。\n", difftime(end, start));
	term_getputch();

	return 0;

}