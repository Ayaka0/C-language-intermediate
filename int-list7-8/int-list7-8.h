#pragma once
/*getch / putch用の共通ヘッダ"getputch.h"*/
#ifndef __GETPUTCH

#define __GETPTCH
#if defined(_MSC_VER) || (__TURBOC__) || (LSI_C)

/*MS-Windows / MS-DOS(Visual C++, Borland C++, LSI-C 86 etc)*/
#include<conio.h>
static void init_getputch(void) {} /*ライブラリの初期処理*/
static void term_getputch(void) {} /*ライブラリ終了処理*/

#else

/*ライブラリが提供されるUNIX / LINUX / macOS*/
#include<curses.h>
#include<stdio.h>
#include<string.h>

#undef getup
#undef putchar
#undef puts
#undef printf
#undef scanf

/*ライブラリ初期処理*/
static void init_getputch(void)
{
	initscr();
	refresh();
}

/*ライブラリ終了処理*/
static void term_getputch(void)
{
	endwin();
}

/*putch : 1文字表示*/
static int putch(int ch)
{
	int result = addch(ch) == OK ? ch : EOF;
	refresh();
	return result;
}

/*putchar : putchar関数の代替*/
static int __putchar(int ch)
{
	return putch(ch);
}

/*__printf:printf関数の代替*/
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

/*__puts : puts関数の代替*/
static int __puts(const char* s)
{
	/*改行文字を付加して出力*/
	int count = printw("%s\n", s) == OK ? strlen(s) + 1 : EOF;
	refresh();
	return count;
}

/*__getch : getch関数のラッパ*/
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
