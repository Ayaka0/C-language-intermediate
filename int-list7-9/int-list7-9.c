//�ό������󂯎���ăA�N�Z�X����֐�

#include<stdio.h>
#include<stdarg.h>

//��1�����̎w��ɉ����đ�Q�ȍ~�̈����̘a�����߂�
double vsum(int sw, ...)
{
	double sum = 0.0;
	va_list ap;

	va_start(ap.sw);	//�ϕ������A�N�Z�X�J�n

	switch (sw) {
	case 0: sum += va_arg(ap, int);	//vsum(0, int, int)
		sum += va_arg(ap, int);
		break;

	case 1: sum += va_arg(ap, int);	//vsum(1, int, long)
		sum += va_arg(ap, long);
		break;

	case 2: sum += va_arg(ap, int);	//vsum(2, int, long, double)
		sum += va_arg(ap, long);
		sum += va_arg(ap, double);
		break;
	}
	va_end(ap);	//�ϕ������A�N�Z�X�I��

	return sum;
}

int main(void)
{
	printf("10 + 2				= %.2f\n", vsum(0, 10, 2));
	printf("57 + 300000L		= %.2f\n", vsum(1, 57, 300000L));
	printf("98 + 2L	+ 3.14		= %.2f\n", vsum(2, 98, 2L, 3.14));

	return 0;
}