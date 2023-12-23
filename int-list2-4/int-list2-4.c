//拡張表記'\と"\の利用例

#include<stdio.h>

int main(void)
{
	printf("文字列リテラルと文字定数について。\n");

	printf("二重引用符");
	putchar('"');	//\"でも可
	printf("で囲まれた\"ABC\"は文字列リテラルです。\n");	//"は不可

	printf("単一引用符");
	putchar('\'');
	printf("でかこまれた'A'は文字定数です。\n");




	return 0;
}