//�j�������߂�i���̂Q�F�c�F���[�̌����𗘗p�j

#include<stdio.h>

//year�Nmonth��day���̗j�������߂�
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

int main(void)
{
	int y, m, d;
	char* ws[] = { "��", "��", "��", "��","��", "��", "�y" };

	printf("�j�������߂�\n");
	printf("�N�F");	scanf("%d", &y);
	printf("���F");	scanf("%d", &m);
	printf("���F");	scanf("%d", &d);

	int w = dayofweek(y, m, d);	//�j�������߂�

	if (w != -1)
		printf("�����%s�j���ł��B\n", ws[w]);
	else
		printf("���߂��܂���ł����B\n");


	return 0;
}