//�����l���w�肳�ꂽ�����ŕ\��

#include<stdio.h>

int main(void)
{
	double x;	//�\������l
	int w, p;	//�S�̂Ə������̌���

	printf("���@���@�l�F"); scanf("%lf", &x);
	printf("�S�̂̌����F"); scanf("%d", &w);
	printf("�������̌����F"); scanf("%d", &p);

	printf("%*.*f\n", w, p, x);

	return 0;
}