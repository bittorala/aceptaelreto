// Bittor
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
    int n, prize, right, max, sum, prefixsum, maxprefix;
    for (n = fastscan(); n; n = fastscan())
    {
        right = max = sum = prefixsum = maxprefix = 0;
        while (right < n)
        {
            prize = fastscan();
            sum += prize;
            prefixsum += prize;
            max = sum > max ? sum : max;
            maxprefix = prefixsum > maxprefix ? prefixsum : maxprefix;
            if (sum < 0) sum = 0;
            ++right;
        }
        max = sum + maxprefix > max ? sum + maxprefix : max;
        printf("%d\n", max);
    }
    return 0;
}
