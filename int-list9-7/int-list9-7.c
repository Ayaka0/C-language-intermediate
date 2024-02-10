//bcopy�c�t�@�C���̃R�s�[

#include<stdio.h>

#define BSIZE 1024	//���̑傫���ɕ������ăR�s�[

int main(int argc, char* argv[])
{
	int n;

	if (argc != 3) {
		fprintf(stderr, "�p�����[�^���s���ł��B\n");
		fprintf(stderr, "bcopy�R�s�[���t�@�C�����@�R�s�[��t�@�C����\n");
	}
	else {
		FILE* src, * dst;
		unsigned char buf[BSIZE];
		if ((src = fopen(**argv, "rb")) == NULL) {
			fprintf(stderr, "�t�@�C��%s���I�[�v���ł��܂���B\n", *argv);
			return 1;
		}
		else if((dst = fopen(*++argv, "wb")) == NULL) {
			fprintf(stderr, "�t�@�C��%s���I�[�v���ł��܂���B\n", *argv);
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