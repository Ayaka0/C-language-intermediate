//�x��𔭂��鏑���t���o�͊֐�
#include<stdio.h>
#include<stdarg.h>

//�x��𔭂��鏑���t���o�͊֐�
int alert_printf(const char* format, ...)
{
	va_list ap;

	putchar('\a');
	va_start(ap, format);
	int count = vprintf(format, ap);	//�ό����̏�����vsprintf�Ɉ�C
	va_end(ap);
	return count;
}

int main(void)
{
	alert_printf("Hello\n");
	alert_printf("% d % ld % .2f", 2, 3L, 3.14);

	return 0;
}