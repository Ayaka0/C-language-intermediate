//������Ƃ��ēǂݍ��񂾐�����ϊ����ĕ\��

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char temp[20];	//�ǂݍ��ݗp�̕�����

	printf("��������͂���F");
	scanf("%s", temp);

	printf("%d�Ɠ��͂��܂����ˁB\n", atoi(temp));


	return 0;
}