//‚¨‚İ‚­‚¶ƒvƒƒOƒ‰ƒ€

#include<time.h>
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	srand(time(NULL));	//—”‚Ìí‚Ìİ’è
	int ans;
	int num;		//“Ç‚İ‚ñ‚¾’l

	do {
		printf("‚¨‚İ‚­‚¶‚ğ‚µ‚æ‚¤\n");
	;	num = rand() % 11;	//0`6‚Ì—”¶¬

		switch (num) {
		case 0:
		case 1:
			printf("‘å‹g\n");
			break;
		case 2:
		case 3:
			printf("’†‹g\n");
			break;
		case 4:
		case 5:
			printf("¬‹g\n");
			break;
		case 6:
			printf("‹g\n");
			break;
		case 7:
			printf("––‹g\n");
			break;
		case 8:
			printf("‹¥\n");
			break;
		case 9:
			printf("‘å‹¥\n");
			break;
		}

		printf("‚à‚¤ˆê“xH ‚Í‚¢F0@‚¢‚¢‚¦F9\n");
		scanf("%d", &ans);
	} while (ans == 0);

	return 0;
}