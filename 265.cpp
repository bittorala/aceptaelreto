// Bittor
#include <stdio.h>
#include <stack>
#define ll long long
int main()
{
	char c;
	ll sum;
	int n;
	int tenthpow;
	char digits[10];
	int ndigits;
	do 
	{
		
		sum = 0; n = 0; tenthpow = 1; ndigits = 0;
		for (c = getchar_unlocked(); c < '0' || c > '9' ; c = getchar_unlocked());
		for (; c >= '0' && c <= '9'; c = getchar_unlocked(), ++ndigits)
			digits[ndigits] = c;
		for (int i = ndigits-1; i >= 0; --i)
		{
			n = (digits[i] - '0') * tenthpow + n;
			sum += n;
			tenthpow *= 10;
		}
		if (n) printf("%lld\n", sum);
	} while (n);
	return 0;
}
