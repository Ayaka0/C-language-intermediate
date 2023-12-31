//おみくじプログラム

#include<time.h>
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	srand(time(NULL));	//乱数の種の設定

	int ans = rand() % 8;	//0〜6の乱数生成
	int no;		//読み込んだ値
	int retry;
	
	do {
		printf("1〜7の整数を入力しておみくじをしよう\n");
		scanf("%d", &no);

		switch (no) {
		case 1:
			printf("大吉\n");
			break;
		case 2:
			printf("中吉\n");
			break;
		case 3:
			printf("小吉\n");
			break;
		case 4:
			printf("吉\n");
			break;
		case 5:
			printf("末吉\n");
			break;
		case 6:
			printf("凶\n");
			break;
		case 7:
			printf("大凶\n");
			break;
		}

		printf("もう一度？ はい：0　いいえ：9");
		scanf("%d", &retry);
	} while (retry == 0);

	return 0;
}