//���݂̓��t�E���������萢�E���ŕ\��(gmtime�֐��Ŏ擾)

#include<time.h>
#include<stdio.h>

//���t�E������\��
void put_date(const struct tm* timer)
{
	char* wday_name[] = { "��", "��", "��", "��", "��", "��", "�y" };

	printf("%4d�N%02d��%02d��(%s)%02d��%02��%02d�b",
		timer->tm_year + 1900,	//�N
		timer->tm_mon + 1,		//��
		timer->tm_mday,			//��
		wday_name[timer->tm_wday],	//�j��
		timer->tm_hour,			//��
		timer->tm_min,			//��
		timer->tm_sec			//�b
	);
}

int main(void)
{
	time_t now = time(NULL);	//�������i���݂̗������j
	struct tm* current = gmtime(&now);	//�v�f�ʂ̎����i���萢�E���j
	struct tm* current_lo = localtime(&now);	//�v�f�ʂ̎����i�n�����j

	printf("���݂̓��t�E������UTC��");
	put_date(current);
	printf("�ł��B\n");

	printf("���݂̓��t�E������");
	put_date(current_lo);
	printf("�ł��B\n");

	return 0;
}