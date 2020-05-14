// Bittorala
#include <stdio.h>

#define llu long long unsigned

llu gcd(llu a, llu b)
{
	while (a != b)
	{
		if (a < b) b %= a;
		else a %= b;
	}
	return a ? a : b;
}

int main()
{
	llu first;
	llu m, aux;
	llu n = 0;
	llu prev;
	llu sol;
	for (scanf("%llu",&first); first != 0; scanf("%llu",&first))
	{
		m = first;
		prev = first;
		sol = 1;
		for (scanf("%llu",&aux); aux != 0; scanf("%llu",&aux))
		{
			m = gcd(prev,aux);
			sol = sol * (prev / m) + aux / m;
			prev = m;
		}
		printf("%llu\n", sol);
	}
	return 0;
}
