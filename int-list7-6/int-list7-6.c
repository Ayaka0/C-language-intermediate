//getch利用
//visual C++などのMS-Windows/MS-DOSで動作

#include<conio.h>
#include<ctype.h>
#include<stdio.h>

int main(void)
{
	int retry;

	do {
		puts("キーを押してください");

		int ch = getch();

		printf("押されたキーは%cで値は%dです。\n", isprint(ch) ? ch : ' ', ch);

		printf("もう一度？（Y / N）: ");

		retry = getch();
		if (isprint(retry))
			putchar(retry);

		putchar('\n');
	} while (retry == 'Y' || retry == 'y');


	return 0;
}