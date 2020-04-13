// bittor
#include <stdio.h>

#define ullint unsigned long long int
#define gcu getchar_unlocked

inline void fastscan(ullint & n)
{
    n = 0; char c = gcu();
    for (; c < '0' || c > '9'; c = gcu());
    for (; c >= '0' && c <= '9'; c = gcu())
        n = n * 10 + ((ullint) c - '0');
}

int main()
{
    ullint a,b,c;
    for (fastscan(a), fastscan(b), fastscan(c); a != 0 || b != 0 || c != 0; fastscan(a), fastscan(b), fastscan(c))
    {
        ullint result = 0;
        for (int i = 0; i < c; ++i) 
        {
            result += a;
            a *= b;
        }
        printf("%llu\n", result);
    }
    return 0;
}