//�ÎZ�g���[�j���O�i0�`99�̐�����4���Z����̂ɗv���鎞�Ԃ��v���j

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//�����̎��ݒ�

	int a = rand() % 100;	//������l�F0�`99�̗���
	int b = rand() % 100;	//������l�F0�`99�̗���
	int c = rand() % 100;	//������l�F0�`99�̗���
	int d = rand() % 100;	//������l�F0�`99�̗���

	printf("%d + %d + %d + %d�͉��ł����F", a, b, c, d);

	time_t start = time(NULL);	//�J�n����

	while (1) {
		int x;	//�ǂݍ��񂾒l
		scanf("%d", &x);
		if (x == a + b + c + d)
			break;
		printf("�Ⴂ�܂���\n�ē��͂��Ă��������F");

		time_t end = time(NULL);	//�I������

		printf("%.0f�b������܂����B\n", difftime(end, start));
	}


	return 0;
}