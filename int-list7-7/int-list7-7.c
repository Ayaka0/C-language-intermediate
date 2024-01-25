//getchの利用例

#include<curses.h>
#include<ctype.h>
#include<stdio.h>

int main(void)
{
	initscr();
	cbreak();
	noecho();
	refresh();

	int retry;

	do {
		addstr("キーを押してください\n");

		int ch = getch();

		printw("押されたキーは%cで値は%dです。\n", isprint(ch) ? ch : ' ', ch);

		printw("もう一度？ Y / N : ");
		retry = getch();
		if (isprint(retry))
			addch(retry);
		addch('\n');
	} while (retry == 'Y' || retry == 'y');

	endwin();

	return 0;
}