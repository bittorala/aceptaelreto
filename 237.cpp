// bittorala
#include <stdio.h>
#include <cmath>
using ullint = unsigned long long int;

static ullint N;
static unsigned int digits;
static bool polidivisible;
static const char POLIDIV[] = "POLIDIVISIBLE";
static const char NOPOLIDIV[] = "NO POLIDIVISIBLE";
// static powers_ten[19];

// inline void printyes()
// {
// 	for (int i = 0; i < 14; ++i)
// 		putchar_unlocked(POLIDIV[i]);
// }

// inline void printno()
// {
// 	for (int i = 0; i < 17; ++i)
// 		putchar_unlocked(NOPOLIDIV[i]);
// }

// bool div(ullint & a, unsigned int b)
// {
// 	switch (b)
// 	{
// 		case 2:
// 			return !bool(a & 0x01);
// 		case 3:
// 			return !bool(a % 3);
// 		case 4:
// 			return !bool(a & 0x03);
// 		case 5:
// 			return !bool(a % 5);	
// 		case 6:
// 			return !bool(a & 0x01) && !(a % 3);
// 		case 7:
// 			return !bool(a % 7);
// 		case 9:
// 			return !bool(a % 9);
// 		case 10:
// 			return !bool(a & 0x01) && !(a % 5);
// 		case 11:
// 			return !bool(a % 11);
// 		case 12:
// 			return !bool(a & 0x03) && !bool(a % 3);
// 		case 13:
// 			return !bool(a % 13);
// 		case 14:
// 			return !bool(a & 0x01) && !bool(a % 7);
// 		case 15:
// 			return !bool(a % 3) && !bool(a % 5);
// 		case 16:
// 			return !bool(a & 0x0F);
// 		case 17:
// 			return !bool(a % 17);
// 		case 18:
// 			return !bool(a % 18);
// 		case 19:
// 			return false;			
// 	}
// }

inline bool fastscan()
{
	N = 0; char c;
	digits = 0;
	for (c = getchar_unlocked(); (c < '0' || c > '9') && c >= 0; c = getchar_unlocked());
	if (c < 0) return false;
	for (; c >= '0' && c <= '9'; c = getchar_unlocked(), ++digits)
		N = 10*N + ((ullint) c - '0');
	return c < 0 ? false : true;
}

int main()
{
	while (fastscan())
	{
		polidivisible = true;
		for (; digits > 1 && polidivisible; --digits)
		{
			polidivisible = !bool(N % digits);
			N /= 10;
		}
		polidivisible ? puts(POLIDIV) : puts(NOPOLIDIV);
	}
	return 0;
}