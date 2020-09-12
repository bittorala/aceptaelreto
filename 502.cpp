// Bittor
#include <stdio.h>

int mussels[500000];

inline bool fastscan(int & num)
{
    char c; num = 0;
    for (c = getchar_unlocked(); (c < '0' || c > '9') && c >= 0 ; c = getchar_unlocked());
    if (c < 0) return false;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return c >= 0;
}

int binarysearch(int left, int right, int k) // Binary search that finds the first element larger than k
{
	if (left == right) return left;
	int d = (left + right) >> 1;
	if (mussels[d] <= k) return binarysearch(d+1,right,k);
	else return binarysearch(left,d,k);
}

int main()
{
	int n, size;
	int nheaps;
	while (fastscan(n))
	{
		nheaps = 1;
		fastscan(size);
		mussels[0] = size;
		for (int i = 1; i < n; ++i)
		{
			fastscan(size);
			int pos = binarysearch(0,nheaps-1,size);
			if (mussels[pos] <= size)
				mussels[nheaps++] = size;
			else mussels[pos] = size;
		}
		printf("%d\n", nheaps);
	}
	return 0;
}
