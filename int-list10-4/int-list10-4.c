//������̔z��𓮓I�Ɋm�ہi2�����z��j

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num;	//������̌�

	printf("������͉��F");
	scanf("%d", &num);

	char(*p)[15] = (char(*)[15])malloc(num * 15);

	if (p == NULL)
		puts("�L����̊m�ۂɎ��s���܂����B");
	else {
		for (int i = 0; i < num; i++) {	//�������ǂݍ���
			printf("p[%d] :", i);
			scanf("%s", p[i]);
		}
		for (int i = 0; i < num; i++)	//�������\��
			printf("p[%d] = %s\n", i, p[i]);
		free(p);	//�L��������
	}
	return 0;
}