//‚¨‚İ‚­‚¶ƒvƒƒOƒ‰ƒ€

#include<time.h>
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	srand(time(NULL));	//—”‚Ìí‚Ìİ’è

	int ans = rand() % 8;	//0`6‚Ì—”¶¬
	int no;		//“Ç‚İ‚ñ‚¾’l
	int retry;
	
	do {
		printf("1`7‚Ì®”‚ğ“ü—Í‚µ‚Ä‚¨‚İ‚­‚¶‚ğ‚µ‚æ‚¤\n");
		scanf("%d", &no);

		switch (no) {
		case 1:
			printf("‘å‹g\n");
			break;
		case 2:
			printf("’†‹g\n");
			break;
		case 3:
			printf("¬‹g\n");
			break;
		case 4:
			printf("‹g\n");
			break;
		case 5:
			printf("––‹g\n");
			break;
		case 6:
			printf("‹¥\n");
			break;
		case 7:
			printf("‘å‹¥\n");
			break;
		}

		printf("‚à‚¤ˆê“xH ‚Í‚¢F0@‚¢‚¢‚¦F9");
		scanf("%d", &retry);
	} while (retry == 0);

	return 0;
}