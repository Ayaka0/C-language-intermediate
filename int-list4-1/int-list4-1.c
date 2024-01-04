//‘ŠˆÙ‚È‚é4ŒÂ‚Ì”š‚Ì•À‚Ñ‚ğ¶¬‚µ‚Ä”z—ñx‚ÉŠi”[

void make4digits(int x[])
{
	for (int i = 0; i < 4; i++) {
		int j, val;
		do {
			val = rand() % 10;	//0`9‚Ì—”
			for (j = 0; j < i; j++)	//Šù‚É“¾‚ç‚ê‚Ä‚¢‚é‚©
				if (val == x[j])
					break;
		} while (j < i);	//d•¡‚µ‚È‚¢’l‚ª“¾‚ç‚ê‚é‚Ü‚ÅŒJ‚è•Ô‚·
		x[i] = val;
	}
}