//bcopy…ファイルのコピー

#include<stdio.h>

#define BSIZE 1024	//この大きさに分割してコピー

int main(int argc, char* argv[])
{
	int n;

	if (argc != 3) {
		fprintf(stderr, "パラメータが不正です。\n");
		fprintf(stderr, "bcopyコピー元ファイル名　コピー先ファイル名\n");
	}
	else {
		FILE* src, * dst;
		unsigned char buf[BSIZE];
		if ((src = fopen(**argv, "rb")) == NULL) {
			fprintf(stderr, "ファイル%sがオープンできません。\n", *argv);
			return 1;
		}
		else if((dst = fopen(*++argv, "wb")) == NULL) {
			fprintf(stderr, "ファイル%sがオープンできません。\n", *argv);
			fclose(src);
			return 1;
		}
		else {
			while ((n = fread(buf, 1, BSIZE, src)) > 0)
				fwrite(buf, 1, n, dst);
			fclose(src);
			fclose(dst);
		}
		}
	return 0;
}