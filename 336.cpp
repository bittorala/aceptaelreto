// bittor
#include <stdio.h>

#define gcu getchar_unlocked
#define uint unsigned

uint alumnos[300000];

bool FastScan(uint & n)
{
	n = 0;
	char c;
	for (c = gcu(); (c < '0' || c > '9') && c >= 0; c = gcu());
	if (c < 0) return false;
	for (; c >= '0' && c <= '9'; c = gcu())
	{
		n = n * 10 + (c - '0');
	}
	return c >= 0;
}

int main()
{
	uint n, sum, left_w, split;
	while(FastScan(n))
	{
		sum = 0;
		left_w = 0;
		for (uint i = 0; i < n; ++i) 
		{
			FastScan(alumnos[i]);
			sum += alumnos[i];
		}
		left_w = alumnos[0];
		for (split = 1; 2 * left_w < sum; ++split)
		{
			left_w += alumnos[split];
		}
		--split;
		left_w -= alumnos[split];
		if (2 * left_w + alumnos[split] == sum) puts("NO JUEGAN");
		//else if (2 * left_w + 2 * alumnos[split] - sum < sum - 2*left_w + alumnos[split])
		else if (4 * left_w + 2*alumnos[split] < 2*sum) printf("%u %u %u\n", split+1, left_w + alumnos[split], sum - left_w - alumnos[split]);
		else printf("%u %u %u\n", split, left_w, sum - left_w);
	}
	return 0;
}