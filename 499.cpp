// bittorala
#include <stdio.h>
#define gcu getchar_unlocked
short data[1000000];
int accum[1000000];

inline void fastscan(int & num)
{
    bool negative = false;
    num = 0;
    char c;
    for (c = gcu(); (c < '0' || c > '9') && c != '-'; c = gcu());
    if (c == '-')
    { 
        negative = true;
        c = gcu();
    }
    for (; c >= '0' && c <= '9'; c = gcu())
        num = num * 10 + c - '0';
    if (negative) num = 0 - num;
}

int main()
{
    int F, C, N, col, start, end, M;
    //int accum;
    for (fastscan(F), fastscan(C), fastscan(N); F != 0 || C != 0 || N != 0; fastscan(F), fastscan(C), fastscan(N))
    {
        for (int i = 0; i < F; ++i)
            for (int j = 0; j < C; ++j)
                data[i * C + j] = 0;
        for (int i = 0; i < N; ++i)
        {
            fastscan(col); fastscan(start); fastscan(end); fastscan(M);
            data[start * C + col] += M;
            if (end + 1 < F)
                data[(end + 1) * C + col] -= M;
        }
        for (int i = 0; i < C; ++i) accum[i] = 0;
        for (int i = 0; i < F; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                accum[j] += data[i * C + j];
                if (j != 0) printf(" ");
                printf("%i", accum[j]);
            }
            printf("\n");
        }
    }
    return 0;
}