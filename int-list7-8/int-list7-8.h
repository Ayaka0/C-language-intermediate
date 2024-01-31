#pragma once
/*getch / putch�p�̋��ʃw�b�_"getputch.h"*/
#ifndef __GETPUTCH

#define __GETPTCH
#if defined(_MSC_VER) || (__TURBOC__) || (LSI_C)

/*MS-Windows / MS-DOS(Visual C++, Borland C++, LSI-C 86 etc)*/
#include<conio.h>
static void init_getputch(void) {} /*���C�u�����̏�������*/
static void term_getputch(void) {} /*���C�u�����I������*/

#else

/*���C�u�������񋟂����UNIX / LINUX / macOS*/
#include<curses.h>
#include<stdio.h>
#include<string.h>

#undef getup
#undef putchar
#undef puts
#undef printf
#undef scanf

/*���C�u������������*/
static void init_getputch(void)
{
	initscr();
	refresh();
}

/*���C�u�����I������*/
static void term_getputch(void)
{
	endwin();
}

/*putch : 1�����\��*/
static int putch(int ch)
{
	int result = addch(ch) == OK ? ch : EOF;
	refresh();
	return result;
}

/*putchar : putchar�֐��̑��*/
static int __putchar(int ch)
{
	return putch(ch);
}

/*__printf:printf�֐��̑��*/
static int __printf(const char* format, ...)
{
	int count;
	va_list ap;
	static char __buf[4096];

	va_start(ap, format);
	vsprintf(__buf, format, ap);
	va_end(ap);

	count = printw("%s", __buf) == OK ? strlen(__buf) : EOF;
	refresh();
	return count;
}

/*__puts : puts�֐��̑��*/
static int __puts(const char* s)
{
	/*���s������t�����ďo��*/
	int count = printw("%s\n", s) == OK ? strlen(s) + 1 : EOF;
	refresh();
	return count;
}

/*__getch : getch�֐��̃��b�p*/
static int __getch(void)
{
	int ch;
	cbreak(); noecho();
	ch = getch();
	nocbreak(); echo();
	return ch;
}

#define getch __getch
#define putchar __putchar
#define printf __printf
#define puts __puts
#define scanf scanw

#endif

#endif
