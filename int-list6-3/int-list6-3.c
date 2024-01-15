//現在の日付・時刻を表示（asctime関数を利用）
#include<time.h>
#include<stdio.h>

int main(void)
{
	time_t now = time(NULL);	//現在の時刻を取得
	printf("現在の日付・時刻：%s", asctime(localtime(&now)));

	return 0;
}