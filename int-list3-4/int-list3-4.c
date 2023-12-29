//文字列内のバイトを文字と16進数と2進数で表示

#include<ctype.h>
#include<stdio.h>
#include<limits.h>

//文字列内のバイトを文字と16進数と2進数で表示
void strdump(const char* s)
{
	while (*s) {
		unsigned char x = (unsigned char)*s;	// ポインタsが指す位置の文字をunsigned char型に変換

		printf("%c ", isprint(x) ? x : ' ');	// 文字が印刷可能な場合はそのまま表示、そうでない場合はスペースを表示
		printf("%0*X ", (CHAR_BIT + 3) / 4, x);	// 16進数表示。CHAR_BITは1バイトあたりのビット数。16進数の桁数を計算して表示。
		int i;
		for (i = CHAR_BIT - 1; i >= 0; i--)	// 2進数表示。ビットを1つずつ右にシフトして表示。
			putchar(((x >> i) & 1U) ? '1' : '0');
		putchar('\n');
		s++;

	}
}

int main(void)
{
	puts("漢字");		strdump("漢字");		putchar('\n');
	puts("12日本語AB");		strdump("12日本語AB");		putchar('\n');

	return 0;
}