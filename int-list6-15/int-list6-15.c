//�v���O�������E�v���O�����������̕\���i���̂R�F�����P�ʂő����j

#include<stdio.h>

int main(int argc, char** argv)
{
	int i = 0;

	while (argc-- > 0) {
		char c;
		printf("argv[%d] = \"", i++);
		while (c = *(argv)++)
			putchar(c);
		argv++;
		printf("\"\n");
	}

	return 0;
}