// bittor
#include <stdio.h>

inline int fastscan() 
{
    char c = getchar_unlocked();
    int num = 0;

    for (;c < '0' || c > '9'; c = getchar_unlocked()) {}

    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) {
        num = 10 * num + c - '0';
    }

    return num;
}

inline int gcd(int a, int b)
{
	while (a && b)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return a ? a : b;
}

int main()
{
	int n, k;
	int lcm;
	while ((n = fastscan()))
	{
		lcm = fastscan();
		for (int i = 0; i < n - 1; ++i)
		{
			k = fastscan();
			lcm = k * lcm / gcd(k,lcm);
		}
		printf("%i\n", lcm);
	}
	return 0;
}