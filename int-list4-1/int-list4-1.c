//相異なる4個の数字の並びを生成して配列xに格納

void make4digits(int x[])
{
	for (int i = 0; i < 4; i++) {
		int j, val;
		do {
			val = rand() % 10;	//0〜9の乱数
			for (j = 0; j < i; j++)	//既に得られているか
				if (val == x[j])
					break;
		} while (j < i);	//重複しない値が得られるまで繰り返す
		x[i] = val;
	}
}