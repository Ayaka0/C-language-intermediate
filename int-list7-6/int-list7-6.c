//getch���p
//visual C++�Ȃǂ�MS-Windows/MS-DOS�œ���

#include<conio.h>
#include<ctype.h>
#include<stdio.h>

int main(void)
{
	int retry;

	do {
		puts("�L�[�������Ă�������");

		int ch = getch();

		printf("�����ꂽ�L�[��%c�Œl��%d�ł��B\n", isprint(ch) ? ch : ' ', ch);

		printf("������x�H�iY / N�j: ");

		retry = getch();
		if (isprint(retry))
			putchar(retry);

		putchar('\n');
	} while (retry == 'Y' || retry == 'y');


	return 0;
}