//カレンダー表示(表示する年月をコマンドラインで指定)

#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>

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

//y年m月のカレンダーを表示
void put_calendar(int y, int m)
{
	int wd = dayofweek(y, m, 1);	//ｙ年1日の曜日
	int mdays = monthdays(y, m);	//ｙ年ｍ月の日数

	printf("日 月　火　水　木　金　土\n");
	printf("--------------------------\n");

	printf("%*s", 3 * wd, "");	//1日より左側のスペースを表示

	for (int i = 1; i <= mdays; i++) {
		printf("%4d", i);
		if (++wd % 7 == 0)	//土曜日を表示したら
			putchar('\n');
	}

	if (wd % 7 != 0)
		putchar('\n');
}


	//文字列の先頭n文字を比較（大文字・小文字を区別しない）
	int strncmpx(const char* s1, const char* s2, size_t n)
	{
		while (n && toupper(*s1) && toupper(*s2)) {
			if (toupper(*s1) != toupper(*s2))	//等しくない
				return (unsigned char)*s1 - (unsigned char)*s2;
			s1++;
			s2++;
			n--;
		}
		if (!n) return 0;
		if (*s1) return 1;
		return -1;

	}

	//文字列から月の値を得る
	int get_month(char* s)
	{
		char* month[] = { "", "January", "Februrary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

		int m = atoi(s);	//月
		if (m >= 1 && m <= 12)	//数字表記："1", "2", …"12"
			return m;

		for (int i = 1; i <= 12; i++)	//英語表記
			if (strncmpx(month[i], s, 3) == 0)
				return i;

		return -1;	//変換失敗
	}


int main(int argc, char *argv[])
{
	time_t now = time(NULL);
	struct tm* current = localtime(&now);

	int y = current->tm_year + 1900;	//今日の年
	int m = current->tm_mon + 1;	//今日の月

	if (argc >= 2) {
		m = get_month(argv[1]);
		if (m < 0 || m > 12) {
			fprintf(stderr, "月の値が不正です。\n");
			return 1;
		}
	}
	if (argc >= 3) {
		y = atoi(argv[2]);
		if (y < 0) {
			fprintf(stderr, "年の値が不正です。\n");
			return 1;
		}
	}

	printf("%d年%d月\n\n", y, m);
	put_calendar(y, m);	//y年m月のカレンダーを表示


	return 0;
}