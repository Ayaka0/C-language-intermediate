//英単語学習ソフト（試作版：日本語の単語、英単語をランダムに表示）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define QNO 12	//単語の数

//日本語
char* jword[] = {
	"動物","車","花","家","机","本","椅子",
	"父","母","愛","平和","雑誌", };

//英語
char* eword[] = {
	"animal","car","flower","house","desk","book",
	"chair","father","mother","love","peace","magazine", };

int main(void)
{
	srand(time(NULL));	//乱数の種を設定

	int pq = QNO;	//前回の問題番号（初期値は存在しない問題番号）
	int retry;	//再挑戦するか？

	do {
		int nq;					//問題番号
		do {					//前回と重複しないように問題番号を決定
			nq = rand() % QNO;
		} while (nq == pq);

		int lang = rand() % 2;		//単語の言語（0：日本語　１：英語）

		printf("%s\n", lang ? eword[nq] : jword[nq]);
		pq = nq;

		printf("もう一度？　0ーいいえ　1ーはい：");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}