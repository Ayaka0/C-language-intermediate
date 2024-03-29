//曜日を求める（その１：mktime関数を利用）

#include<time.h>
#include<stdio.h>

//year年month月day日の曜日を求める
int dayofweek(int year, int month, int day)
{
	struct tm t;

	t.tm_year = year - 1900;	//年を調整
	t.tm_mon = month - 1;		//月を調整
	t.tm_mday = day;			//日
	t.tm_hour = 0;			//時
	t.tm_min = 0;			//分
	t.tm_sec = 0;			//秒
	t.tm_isdst = -1;		//夏時間

	if (mktime(&t) == (time_t)-1)		//変換に失敗したら
		return -1;	//-1を返却
	return t.tm_wday;	//mktime関数で設定された曜日を返却
}

int main(void)
{
	int y, m, d;
	char* ws[] = { "日", "月", "火", "水","木", "金", "土" };

	printf("曜日を求める\n");
	printf("年：");	scanf("%d", &y);
	printf("月：");	scanf("%d", &m);
	printf("日：");	scanf("%d", &d);

	int w = dayofweek(y,m,d);	//曜日を求める

	if (w != -1)
		printf("それは%s曜日です。\n", ws[w]);
	else
		printf("求められませんでした。\n");


	return 0;
}