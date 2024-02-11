//英単語学習ソフト（試作版：日本語の単語、英単語をランダムに表示）

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define QNO 12	//単語の数
#define CNO	4	//選択肢の数

#define swap(type,x,y)	do{type t = x; x = y; y = t;} while(0)

//日本語
char* jword[] = {
	"動物","車","花","家","机","本","椅子",
	"父","母","愛","平和","雑誌", };

//英語
char* eword[] = {
	"animal","car","flower","house","desk","book",
	"chair","father","mother","love","peace","magazine", };

//選択しを生成して正解の添え字を返す
int make_cand(int c[], int answer)
{
	c[0] = answer;	//先頭要素に正解を入れる

	for (int i = 1; i < CNO; i++) {
		int j, x;
		do {
			x = rand() % QNO;	//重複しないように選択肢を生成
			for (j = 0; j < i; j++)
				if (c[j] == x)	//生成済みの番号を
					break;		//スキップ
		} while (i != j);
		c[i] = x;
	}

	int idx = rand() % CNO;	//正解の格納先の添え字
	if (idx != 0)
		swap(int, c[0], c[idx]);//正解を移動

	return idx;
}

//選択肢を表示
void print_cand(const int c[], int lang)
{
	for (int i = 0; i < CNO; i++)
		printf("(%d) %s ", i, lang ? jword[c[i]] : eword[c[i]]);
	printf(" : ");
}

int main(void)
{
	srand(time(NULL));	//乱数の種を設定

	int pq = QNO;	//前回の問題番号（初期値は存在しない問題番号）
	int retry;	//再挑戦するか？

	do {
		int nq;					//問題番号
		int cand[CNO];			//選択肢の番号

		do {					//前回と重複しないように問題番号を決定
			nq = rand() % QNO;
		} while (nq == pq);

		int lang = rand() % 2;		//単語の言語（0：日本語　１：英語）

		printf("%sはどれですか？\n", lang ? eword[nq] : jword[nq]);

		int na = make_cand(cand, nq);	//選択肢を生成
		int no;							//読み込む回答番号

		do {
			print_cand(cand, lang);		//選択肢を表示
			scanf("%d", &no);
			if (no != na)
				puts("\a違います。");
		} while (no != na);
		puts("正解です。");

		pq = nq;

		printf("もう一度？　0ーいいえ　1ーはい：");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}