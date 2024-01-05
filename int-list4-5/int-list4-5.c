//ヒット＆ブローの判定

void judge(const char s[], const int no[], int* hit, int* blow)
{
	*hit = *blow = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j]) {	//数字が一致
				if (i == j)
					(*hit)++;		//ヒット（位置も一致）
				else
					(*blow)++;		//ブロー（位置が不一致）
			}
		}
	}
}