// bittor
#include <stdio.h>
#include <cstdint>
static uint64_t a, b, n;

inline void fastscan(uint64_t & num) 
{
    char c = getchar_unlocked();
    num = 0;
    for (;c < '0' || c > '9'; c = getchar_unlocked());
    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) 
        num = 10 * num + c - '0';
}

uint64_t gcd(uint64_t aa, uint64_t bb)
{
    while (aa != 0 && bb != 0)
    {
        if (aa > bb) aa %= bb;
        else bb %= aa;
    }
    return aa == 0 ? bb : aa;
}

int main()
{
    fastscan(a);
    fastscan(b);
    fastscan(n);
    while (a != 0 || b != 0 || n != 0)
    {
        if (a == 0 || b == 0)
        {
            printf("0\n");
            fastscan(a);
            fastscan(b);
            fastscan(n);
            continue;
        }
//        uint64_t mcm = a * b / gcd(a,b);
        printf("%u\n", n /(a * b / gcd(a,b)));
        fastscan(a);
        fastscan(b);
        fastscan(n);
    }
    return 0;
}