//���݂̓��t�E������\���iasctime�֐��𗘗p�j
#include<time.h>
#include<stdio.h>

int main(void)
{
	time_t now = time(NULL);	//���݂̎������擾
	printf("���݂̓��t�E�����F%s", asctime(localtime(&now)));

	return 0;
}