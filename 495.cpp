// bittor
#include <stdio.h>
int N, M, row, col;
int heights[1000];
int costs[1000];
int function[1000];

inline int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

inline bool fastscan(int & N)
{
	N = 0; char c;
	for (c = getchar_unlocked(); (c < '0' || c > '9') && c >= 0; c = getchar_unlocked());
	if (c < 0) return false;
	for (; c >= '0' && c <= '9'; c = getchar_unlocked())
		N = 10*N + (c - '0');
	return c < 0 ? false : true;
}

int main()
{
    while (fastscan(N))
    {
        for (int i = 0; i < N; ++i) fastscan(heights[i]);
        for (int i = 0; i < N; ++i) fastscan(costs[i]);
        fastscan(M);
        for (int k = 0; k < N; ++k)
        {
           if (heights[k] <= M) function[k] = 0;
           else function[k] = ~(0x01 << 31); // INT_MAX
           for (int j = k - 1; j >= 0 && heights[k] - heights[j] <= M; --j)
               function[k] = minimum(function[k], function[j] + costs[j]);
        }
        printf("%u\n", function[N-1]);
    }
    return 0;
}