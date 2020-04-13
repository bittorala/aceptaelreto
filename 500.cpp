// bittor
#include <stdio.h>

inline int fastscan()
{
    int num = 0; char c = getchar_unlocked();
    for (; c < '0' || c > '9'; c = getchar_unlocked());
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return num;
}

inline int fastscan(int & digits)
{
    int num = 0; char c = getchar_unlocked();
    digits = 0;
    for (; c < '0' || c > '9'; c = getchar_unlocked());
    for (; c >= '0' && c <= '9'; c = getchar_unlocked(), ++digits)
        num = num * 10 + c - '0';
    return num;
}

inline int reverse(int k, int digits)
{
    int r = 0;
    for (int i = 0; i < digits; ++i)
    {
        r = r * 10 + k % 10;
        k /= 10;
    }
    return r;
}

int main()
{
    int N, Q, M, digits;
    for (N = fastscan(digits), Q = fastscan(); N != 0 || Q != 0; N = fastscan(digits), Q = fastscan())
    {
        M = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (i + reverse(i, digits) >= Q && i + reverse(i, digits) <= N)
            {
                ++M;
            }
        }
        printf("%i %i %i\n", N, Q, M);
    }
    return 0;
}
