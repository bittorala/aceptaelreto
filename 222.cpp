// bittorala
#include <stdio.h>
#include <cstdint>

static const uint64_t MAX = 1000007;
uint32_t inverses[101];
uint32_t x,n;

uint32_t inverse(uint32_t a)
{
    int t, newt, r, newr, quotient, auxt, auxr;
    t = 0; newt = 1; r = 1000007; newr = a;
    while (newr != 0)
    {
        quotient = r / newr;
        auxt = t; auxr = r;
        t = newt; r = newr;
        newt = auxt - quotient * newt;
        newr = auxr - quotient * newr;
    }
    if (r > 1) return 0; // No inverse (gcd(a,1000007) != 1)
    if (t < 0) t = (t + MAX) % MAX;
    return t % MAX;
}

inline bool fastscan(uint32_t & N)
{
	N = 0; char c;
	for (c = getchar_unlocked(); (c < '0' || c > '9') && c >= 0; c = getchar_unlocked());
	if (c < 0) return false;
	for (; c >= '0' && c <= '9'; c = getchar_unlocked())
		N = 10*N + (c - '0');
	return c < 0 ? false : true;
}

inline void compute_inverses()
{
	inverses[1] = 1;
	for(int i = 2; i < 101; ++i)
	{
		inverses[i] = inverse(i);
	}
}

uint64_t slow_way(uint64_t base, uint32_t power)
{
	uint64_t sum = 1, pow = 1;
	for (uint32_t i = 1; i <= power; ++i)
	{
		pow = pow * base % MAX;
		sum = (sum + pow) % MAX;
	}
	return sum;
}

uint64_t pow(uint64_t base, uint32_t power)
{
	if (power == 0) return 1;
	uint64_t aux = 1;
	while (power != 1)
	{
		if (power & 0x01)
		{
			aux = base * aux % MAX; base = base * base % MAX; power /= 2;
		}
		else
		{
			base = base * base % MAX; power /= 2;
		}
	}
	aux = base * aux % MAX;
	return aux;
}

int main()
{
	compute_inverses();
	while (fastscan(x))
	{
		fastscan(n);
		if (x == 1) printf("%llu\n", n + 1);
		else if (x % 29 == 1) printf("%llu\n", slow_way(static_cast<uint64_t>(x),n));
		else 
		printf("%llu\n", ((pow(static_cast<uint64_t>(x), n + 1) - 1) * static_cast<uint64_t>(inverses[x - 1]) % MAX ));
	}
	return 0;
}
