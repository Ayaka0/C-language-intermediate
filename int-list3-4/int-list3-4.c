//��������̃o�C�g�𕶎���16�i����2�i���ŕ\��

#include<ctype.h>
#include<stdio.h>
#include<limits.h>

//��������̃o�C�g�𕶎���16�i����2�i���ŕ\��
void strdump(const char* s)
{
	while (*s) {
		unsigned char x = (unsigned char)*s;	// �|�C���^s���w���ʒu�̕�����unsigned char�^�ɕϊ�

		printf("%c ", isprint(x) ? x : ' ');	// ����������\�ȏꍇ�͂��̂܂ܕ\���A�����łȂ��ꍇ�̓X�y�[�X��\��
		printf("%0*X ", (CHAR_BIT + 3) / 4, x);	// 16�i���\���BCHAR_BIT��1�o�C�g������̃r�b�g���B16�i���̌������v�Z���ĕ\���B
		int i;
		for (i = CHAR_BIT - 1; i >= 0; i--)	// 2�i���\���B�r�b�g��1���E�ɃV�t�g���ĕ\���B
			putchar(((x >> i) & 1U) ? '1' : '0');
		putchar('\n');
		s++;

	}
}

int main(void)
{
	puts("����");		strdump("����");		putchar('\n');
	puts("12���{��AB");		strdump("12���{��AB");		putchar('\n');

	return 0;
}