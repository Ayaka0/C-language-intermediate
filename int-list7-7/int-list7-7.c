//getch�̗��p��

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
		addstr("�L�[�������Ă�������\n");

		int ch = getch();

		printw("�����ꂽ�L�[��%c�Œl��%d�ł��B\n", isprint(ch) ? ch : ' ', ch);

		printw("������x�H Y / N : ");
		retry = getch();
		if (isprint(retry))
			addch(retry);
		addch('\n');
	} while (retry == 'Y' || retry == 'y');

	endwin();

	return 0;
}