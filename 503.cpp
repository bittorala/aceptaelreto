// Bittor
#include <stdio.h>

inline bool fastscan(int & num)
{
    char c; num = 0;
    for (c = getchar_unlocked(); (c < '0' || c > '9') && c >= 0 ; c = getchar_unlocked());
    if (c < 0) return false;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return c >= 0;
}

int main()
{
	int ncases, a, b;
	fastscan(ncases);
	while (ncases--)
	{
		fastscan(a); fastscan(b);
		if (b < a)
		{  // Swap
			a = a + b;
			b = a - b;
			a = a - b;
		}
		for (a = a + 1; a < b + 1; ++a) printf("%d ", a);
		printf("%d\n", b+1);
	}
	return 0;
}
