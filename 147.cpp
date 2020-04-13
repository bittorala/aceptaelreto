// bittorala
#include <stdio.h>
int N, K;

inline bool fastscan(int & num)
{
    num = 0;
    char c = getchar_unlocked();
    for (; (c < '0' || c > '9') && c >= 0; c = getchar_unlocked());
    if (c < 0) return false;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return c >= 0;
}

int main()
{
    while(fastscan(N))
    {
        fastscan(K);
        if ((N - 1) % (K + 1) == 0) puts("PIERDO");
        else
        { 
            if ((N-1) % (K+1) < 10)
            {
                putchar_unlocked('0' + (N-1) % (K+1));
                putchar_unlocked('\n');
            }
            else puts("10");            
//            printf("%i\n", (N-1) % (K+1));
        }
    }
    return 0;
}