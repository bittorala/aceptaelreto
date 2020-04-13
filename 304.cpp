// bittorala
#include <stdio.h>
#include <stdlib.h>
static int a, b, ncases, q, r;

inline int fastscan()
{
	char c;
	int num = 0;
	bool negative;
	for (c = getchar_unlocked(); (c < '0' || c > '9') && c != '-'; c = getchar_unlocked());
	negative = c == '-';
	if (negative) c = getchar_unlocked();
	for (; c >= '0' && c <= '9'; c = getchar_unlocked())
		num = num * 10 + c - '0';
	if (negative) num = 0 - num;
	return num;
}

int main()
{
	ncases = fastscan();
	for(int i = 0; i < ncases; ++i)
	{
		a = fastscan();
		b = fastscan();
		if (b == 0)
		{
			printf("DIV0\n");
			continue;
		}
		q = a / b;
		r = a % b;
		if (r < 0) // When a < 0
		{
			r += abs(b);
			q += b < 0 ? 1 : -1;
		}
		printf("%i %i\n",q,r);
	}
	return 0;
}