//���Y�g���[�j���O�i3��3���̐�����������F�v����time_t�^�𗘗p�j
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(NULL));	//�����̎��ݒ�

	int a = 100 + rand() % 900;	//���Z���鐔�l�F100�`999�̗���
	int b = 100 + rand() % 900;
	int c = 100 + rand() % 900;

	printf("%d + %d + %d�͉��ł����F", a, b, c);

	time_t start = time(NULL);	//�v���J�n

	//��������܂ŌJ��Ԃ�
	while (1) {
		int x;	//�ǂݍ��񂾒l
		scanf("%d", &x);
		if (x == a + b + c)
			break;
		printf("�Ⴂ�܂���\n�ē��͂��Ă��������F");
	}

	time_t end = time(NULL);	//�v���I��

	double req_time = difftime(end, start);	//�����ɗv��������

	printf("%.1f�b������܂����B\n", req_time);

	if (req_time > 30.0)
		printf("���Ԃ������肷���ł��B\n");
	else if (req_time > 17.0)
		printf("�܂��܂��ł���\n");
	else
		printf("�f�����ł���\n");

	return 0;
}