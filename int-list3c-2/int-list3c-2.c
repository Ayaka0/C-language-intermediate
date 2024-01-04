//Ž¯•ÊŽq‚Ì—LŒø”ÍˆÍ

#include<stdio.h>

int x = 77;

void print_x(void)
{
	printf("x = %d\n", x);
}

int main(void)
{
	int x = 88;
	print_x();

	printf("x = %d\n", x);

	for (int i = 0; i < 5; i++) {
		int x = i * 11;
		printf("x = %d\n", x);
	}

	printf("x = %d\n", x);

}