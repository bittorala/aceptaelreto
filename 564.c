// Bittor
#include <stdio.h>

int fastscan()
{
    int num = 0; char c = getchar_unlocked();
    for (; c < '0' || c > '9'; c = getchar_unlocked());
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return num;
}


int main()
{
    int ncases, k;
    for(ncases = fastscan(); ncases; --ncases)
    {
        k = fastscan();
        printf("%d\n", k / 3); 
    }
    return 0;
}
