//�J�����_�[�\��

#include<stdio.h>

//�e���̓���
int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//year�Nmonth��day���̗j�������߂�
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

//year�N�͉[�N���H0�c����/1�c�[�N
int is_leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

//year�Nmonth���̓���(28�`31)
int monthdays(int year, int month)
{
	if (month-- != 2)	//month��2���łȂ��Ƃ�
		return mday[month];
	return mday[month] + is_leap(year);	//month��2���ł���Ƃ�
}

//y�Nm���̃J�����_�[��\��
void put_calendar(int y, int m)
{
	int wd = dayofweek(y, m, 1);	//���N1���̗j��
	int mdays = monthdays(y, m);	//���N�����̓���

	printf("�� ���@�΁@���@�؁@���@�y\n");
	printf("--------------------------\n");

	printf("%*s", 3 * wd, "");	//1����荶���̃X�y�[�X��\��

	for (int i = 1; i <= mdays; i++) {
		printf("%4d", i);
		if (++wd % 7 == 0)	//�y�j����\��������
		putchar('\n');
	}

	if (wd % 7 != 0)
		putchar('\n');
}

int main(void)
{
	int y, m;

	printf("�J�����_�[��\��\n");
	printf("�N�F"); scanf("%d", &y);
	printf("���F"); scanf("%d", &m);

	putchar('\n');

	put_calendar(y, m);

	return 0;
}