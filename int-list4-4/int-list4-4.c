//入力された文字列ｓの妥当性をチェック

int check(const char s[])
{
	if (strlen(s) != 4)	//文字列の長さが４でない
		return 1;
	for (int i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;	//数字以外の文字が含まれている
		for (int j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;	//同一の数字が含まれている
	}

	return 0;	//文字列は妥当
}