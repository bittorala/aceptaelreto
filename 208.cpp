// Bittor
#include <stdio.h>

void fastscan(unsigned & n)
{
	n = 0;
	char c;
	for (c = getchar_unlocked(); c < '0' || c > '9'; c = getchar_unlocked());
	for (; c >= '0' && c <='9'; c = getchar_unlocked())
		n =  n *10 + c - '0';
}

int main()
{
	unsigned f, b;
	for (fastscan(f), fastscan(b); f; fastscan(f), fastscan(b))
	{
		b = f - b + 1;
		if (b & 0x01) b = ((b+1) >> 1) * b;
		else b = (b >> 1) * (b+1);
		if (f & 0x01) f = ((f+1) >> 1) * f;
		else f = (f >> 1) * (f+1);
		printf("%d\n", f-b);
	}
	return 0;
}


