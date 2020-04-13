// bittorala
#include <stdio.h>

int main()
{
    int n, k;
    for (scanf("%i",&n), scanf("%i",&k); n != 0 || k != 0; scanf("%i",&n), scanf("%i",&k))
    {
        printf("%i\n", n * (n - 1) / 2 * (n + 1) + n*k);
    }
    return 0;
}