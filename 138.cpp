// bittorala
#include <stdio.h>

unsigned num, ncases, zeros;

inline unsigned fastscan(unsigned & N)
{
    N = 0; char c;
    for (c = getchar_unlocked(); c < '0' || c > '9'; c = getchar_unlocked());
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        N = N * 10 + c - '0';
    return N;
}

int main()
{
    for (fastscan(ncases); ncases > 0; --ncases)
    {
        fastscan(num);
        zeros = 0;
        while (num != 0)
        {
        num /= 5;
        zeros += num;
        }
        printf("%i\n", zeros);
    }
    return 0;
}