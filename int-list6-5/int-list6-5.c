//現在の日付・時刻を表示（ctime関数を利用）

#include<time.h>
#include<stdio.h>

int main(void)
{
	time_t current = time(NULL);	//現在の時刻を取得

	printf("現在の日付・時刻：%s", ctime(&current));


	return 0;
}