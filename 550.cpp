#include <stdio.h>

#define uint unsigned 
#define NMAX 1000001
int solutions[NMAX];

int main()
{
    uint N;
    solutions[0] = 0; solutions[1] = 1; solutions[2] = 1;
    solutions[3] = 2; solutions[4] = 2;
    for (int i = 5; i < NMAX; ++i)
    {
        if (i & 1) solutions[i] = 2*solutions[(i >> 1)+1] -1;
        else solutions[i] = solutions[i>>1]+solutions[(i>>1)+1]-1;
    }
    for(scanf("%u", &N); N; scanf("%u", &N))
    {
        printf("%u\n", solutions[N]);
    }
    return 0;
}
