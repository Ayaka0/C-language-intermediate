//���O���e���b�v�\���i���̂P�F�������֕����𗬂��j

#include<time.h>
#include<stdio.h>
#include<string.h>

//x�~���b�o�߂���̂�҂�
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	//�G���[
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int cnt = 0;	//�擪�����̓Y��
	char name[] = "BohYoh";	//�\�����镶����
	int name_len = strlen(name);	//������NAME�̕�����

	while (1) {
		putchar('\r');	//�J�[�\�����s�̐擪��

		int i;
		for (i = 0; i < name_len; i++) {
			if (cnt + i < name_len)
				putchar(name[cnt + i]);
			else
				putchar(name[cnt + i - name_len]);
		}

		fflush(stdout);
		sleep(500);

		if (cnt < name_len - 1)
			cnt++;	//�����1�ʔ��̕�������\��
		else
			cnt = 0;	//����͐擪��������\��
	}


	return 0;
}