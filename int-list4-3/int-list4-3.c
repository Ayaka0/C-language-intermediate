//文字列として読み込んだ整数を変換して表示

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char temp[20];	//読み込み用の文字列

	printf("整数を入力せよ：");
	scanf("%s", temp);

	printf("%dと入力しましたね。\n", atoi(temp));


	return 0;
}