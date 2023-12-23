//カウントダウン後にプログラム実行時間を表示

#include<time.h>
#include<stdio.h>

//xミリ秒経過するのを待つ
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	//エラー
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int i;
	for (i = 10; i > 0; i--) {	//カウントダウン
		printf("\r%2d", i);
		fflush(stdout);	//ストリームにたまっているデータを即座に吐き出す関数 stdoutは標準出力
		sleep(1000);
	}

	printf("\rFIRE!!\a\n");
	clock_t c = clock();	//クロック関数を構造体clock_t型の構造体変数cに格納
	printf("プログラム開始から%.1f秒経過しました。\n", (double)c / CLOCKS_PER_SEC);

	return 0;
}