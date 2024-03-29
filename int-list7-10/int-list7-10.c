//警報を発する書式付き出力関数
#include<stdio.h>
#include<stdarg.h>

//警報を発する書式付き出力関数
int alert_printf(const char* format, ...)
{
	va_list ap;

	putchar('\a');
	va_start(ap, format);
	int count = vprintf(format, ap);	//可変個引数の処理をvsprintfに一任
	va_end(ap);
	return count;
}

int main(void)
{
	alert_printf("Hello\n");
	alert_printf("% d % ld % .2f", 2, 3L, 3.14);

	return 0;
}