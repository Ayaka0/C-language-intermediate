//xƒ~ƒŠ•bŒx‰ú‚·‚é‚Ì‚ğ‘Ò‚Â

int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_1)-1)	//ƒGƒ‰[
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);

	return 1;
}