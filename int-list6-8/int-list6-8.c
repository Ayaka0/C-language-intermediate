//x秒経過するのを待つ
int ssleep(double x)
{
	time_t t1 = time(NULL), t2;

	do {
		if ((t2 = time(NULL)) == (time_t)-1)	//エラー
			return 0;
	} while (difftime(t2, t1) < x);

	return 1;
}