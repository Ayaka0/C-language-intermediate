//実数値を指定された桁数で表示

#include<stdio.h>

int main(void)
{
	double x;	//表示する値
	int w, p;	//全体と小数部の桁数

	printf("実　数　値："); scanf("%lf", &x);
	printf("全体の桁数："); scanf("%d", &w);
	printf("小数部の桁数："); scanf("%d", &p);

	printf("%*.*f\n", w, p, x);

	return 0;
}