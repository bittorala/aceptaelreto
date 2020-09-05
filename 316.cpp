#include <stdio.h>

int fastscan()
{
	int n = 0;
	bool negative = false;
	char c;
	for (c = getchar_unlocked(); (c < '0' || c > '9') && c != '-'; c = getchar_unlocked());
	if (c == '-') negative = true, c = getchar_unlocked();
	for (; c >= '0' && c <= '9'; c = getchar_unlocked())
		n = 10 * n + (c - '0');
	if (negative)
		n = -n;
	return n;	
}


int main()
{
	int ncases;
	for (ncases = fastscan(); ncases; --ncases)
	{
		int maxleft, maxright, left, right, days, earnings;
	    	int sum = 0;	
		int maxsum = 0;
		left = right = 0;
		days = fastscan();
		for (right = 0 ; right <  days; ++right)
		{
			earnings = fastscan();
			sum += earnings;
			if (sum <= 0)
			{
				left = right + 1;
				sum = 0;
			}
			else
			{
				if (sum > maxsum)
				{
					maxleft = left;
					maxright = right;
					maxsum = sum;
				}
				else if (sum == maxsum && right-left < maxright - maxleft)
				{
					maxleft = left; maxright = right; 
				}
			}
		}
		printf("%d %d\n", maxleft + 1, maxright + 1);
	}	
	return 0;

}
