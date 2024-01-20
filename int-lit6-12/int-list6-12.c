//最大3か月分を横に並べたカレンダー表示

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//各月の日数
int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//year年month月day日の曜日を求める
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

//year年は閏年か？0…平成/1…閏年
int is_leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

//year年month月の日数(28～31)
int monthdays(int year, int month)
{
	if (month-- != 2)	//monthが2月でないとき
		return mday[month];
	return mday[month] + is_leap(year);	//monthが2月であるとき
}

//y年m月のカレンダーを2次元配列sに格納
void make_calendar(int y, int m, char s[7][22])
{
	int wd = dayofweek(y, m, 1);	//ｙ年1日の曜日
	int mdays = monthdays(y, m);	//ｙ年ｍ月の日数
	char tmp[4];

	sprintf(s[0], "%10d / %02d      ", y, m);	//タイトル（年/月）

	int k;
	for (k = 1; k < 7; k++)	//タイトル以外のバッファをクリア
		s[k][0] = '\0';

	k = 1;
	sprintf(s[k], "%*s", 3 * wd, "");	//1日の左側を空白文字で埋める
	for (int i = 1; i <= mdays; i++) {
		sprintf(tmp, "%3d", i);
		strcat(s[k], tmp);	//i日の日付を追加
		if (++wd % 7 == 0)	//土曜日を格納したら
			k++;	//次の行へ進む
	}

	if (wd % 7 == 0)
		k--;
	else {
		for (wd %= 7; wd < 7; wd++)	//最終日の右側に空白文字を追加
			strcat(s[k], "  ");	//再守備の右側に空白文字を追加
	}
	while (k++ < 7)	//未使用行を空白文字で埋め尽くす
		sprintf(s[k], "%21s", "");
}

//3次元配列sbufに格納されたカレンダーを横にn個並べて表示
void print(char sbuf[3][7][22],int n)
{
	for (int i = 0; i < n; i++)	//タイトル（年/月）を表示
		printf("%s  ", sbuf[i][0]);
	putchar('\n');

	for (int i = 0; i < n; i++)
		printf("　日　月　火　水　木　金　土　　　");
	putchar('\n');

	for (int i = 0; i < n; i++)
		printf("----------------------------      ");
	putchar('\n');

	for (int i = 1; i < 7; i++) {	//カレンダー本体部
		for (int j = 0; j < n; j++)		//横にn個並べて
			printf("%s  ", sbuf[j][i]);	//表示
		putchar('\n');
	}
	putchar('\n');
}

//y1年m1月からy2年m2月までのカレンダーを表示
void put_calendar(int y1, int m1, int y2, int m2)
{
	int y = y1;
	int m = m1;
	int n = 0;	//バッファに蓄える月数
	char sbuf[3][7][22];	//カレンダー文字列のバッファ

	while (y <= y2) {
		if (y == y2 && m > m2) break;
		make_calendar(y, m, sbuf[n++]);
		if (n == 3) {	//3か月分たまったら表示
			printf(sbuf, n);
			n = 0;
		}
		m++;	//次の月へ
		if (m == 13 && y < y2) {	//年を繰り越す
			y++;
			m = 1;
		}
	}
	if (n)	//未表示月があれば
		print(sbuf, n);
}

int main(void)
{
	int y1, m1, y2, m2;

	printf("カレンダーを表示\n");

	printf("開始年："); scanf("%d", &y1);
	printf("　　月："); scanf("%d", &m1);
	printf("終了年："); scanf("%d", &y2);
	printf("　　月："); scanf("%d", &m2);

	putchar('\n');

	put_calendar(y1, m1, y2, m2);

	return 0;
}