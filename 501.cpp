// bittor
#include <stdio.h>
#include <algorithm>
#include <vector>
int td, ta, dd, da, no;
std::vector<int> values_d(1000);
std::vector<int> values_a(1000);

inline int min(int a, int b)
{
    return a < b ? a : b;
}

inline bool fastscan(int & num)
{
    char c; num = 0;
    for (c = getchar_unlocked(); (c < '0' || c > '9') && c >= 0 ; c = getchar_unlocked());
    if (c < 0) return false;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return c >= 0;
}

inline bool fastscan2(int & num)
{
    char c; num = 0;
    for (c = getchar_unlocked(); (c < '0' || c > '9') && c >= 0 ; c = getchar_unlocked());
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        num = num * 10 + c - '0';
    return c != '\n' && c != '\r';
}

int main()
{
    int played_d, played_a;
    bool end_of_attack = false;
    while (fastscan(td) && fastscan(ta) && fastscan(dd) && fastscan(da) 
            &&  fastscan(no))
    {
        for (int l = 0; l < no; ++l)
        {
            played_d = min(dd,td);
            played_a = min(da, ta);
            int i;
            for (i = 0; i < played_d; ++i) fastscan(values_d[i]);
            for (i = 0; i < played_a; ++i) end_of_attack = !fastscan2(values_a[i]);
            std::sort(values_d.begin(), values_d.begin() + played_d);
            std::sort(values_a.begin(), values_a.begin() + played_a);
            // quickSort(values_d,0,played_d-1);
            // quickSort(values_a,0,played_a-1);
            for (int k = 0 ; k < min(played_d, played_a); ++k)
            {
                if (values_d[played_d - 1 - k] >= values_a[played_a - 1 - k])
                    --ta;
                else
                    --td;
            }
            if (end_of_attack) break;
        }
        printf("%i %i\n", td, ta);
    }
    return 0;
}