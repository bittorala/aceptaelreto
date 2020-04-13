// bittorala
#include <stdio.h>
#define LAST_NONZERO 4
using uint = unsigned int;
using uchar = unsigned char;

short lastdigit[LAST_NONZERO+1];


inline uint fastscan() 
{
    char c = getchar_unlocked();
    uint num = 0;

    for (;c < '0' || c > '9'; c = getchar_unlocked()) {}

    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) {
        num = 10 * num + c - '0';
    }

    return num;
}

int main()
{ 
	lastdigit[0] = 1;
	for (uint i = 1; i <= LAST_NONZERO; ++i) lastdigit[i] = (lastdigit[i-1] * (i % 10)) % 10;
	uint cases = fastscan();
	uint n;
	for (uint i = 0; i < cases; ++i)
	{
		n = fastscan();
		putchar('0' + (n <= LAST_NONZERO ? lastdigit[n] : 0));
		putchar('\n');
	}
	return 0;
}