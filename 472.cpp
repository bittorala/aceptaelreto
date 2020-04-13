// bittor
#include <stdio.h>

inline bool fastscan(int & num)
{
    num = 0;
    char c;
    for (c = getchar_unlocked(); (c < '0' || c > '9') && c >= 0; c = getchar_unlocked());
    if (c < 0) return false;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return c >= 0;
}

int main()
{
    int D, N, hill, start_of_hill, last_height, height;
    bool feasible;
    while (fastscan(D) && fastscan(N))
    {
        fastscan(start_of_hill); hill = 0;
        last_height = start_of_hill;
        feasible = true;
        for (int i = 1; i < N; ++i)
        {
            fastscan(height);
            if(!feasible) continue;
            if (height > last_height) 
            {
                if (hill) feasible =  height - start_of_hill <= D;
                else
                {
                    feasible = height - last_height <= D;
                    hill = 1;
                    start_of_hill = last_height;
                }
            }
            else hill = 0;
            last_height = height;
        }
        feasible ? puts("APTA") : puts("NO APTA");
    }
    return 0;
}