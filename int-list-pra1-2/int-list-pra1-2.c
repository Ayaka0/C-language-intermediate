//おみくじプログラム

#include<time.h>
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	srand(time(NULL));	//乱数の種の設定
	int ans;
	int num;		//読み込んだ値

	do {
		printf("おみくじをしよう\n");
	;	num = rand() % 11;	//0〜6の乱数生成

		switch (num) {
		case 0:
		case 1:
			printf("大吉\n");
			break;
		case 2:
		case 3:
			printf("中吉\n");
			break;
		case 4:
		case 5:
			printf("小吉\n");
			break;
		case 6:
			printf("吉\n");
			break;
		case 7:
			printf("末吉\n");
			break;
		case 8:
			printf("凶\n");
			break;
		case 9:
			printf("大凶\n");
			break;
		}

		printf("もう一度？ はい：0　いいえ：9\n");
		scanf("%d", &ans);
	} while (ans == 0);

	return 0;
}