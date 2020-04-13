// bittor
#include <stdio.h>
#include <bitset>
#define gcu getchar_unlocked
#define to_llint(x) static_cast<long long>(x)
using llint = long long;

int N; int cycle_size; int aux;
llint result;
std::bitset<101> in_a_cycle;
int permutation[101];

inline llint gcd(llint a, llint b)
{
    while (a != 0 && b != 0)
    {
        if (a < b) b %= a;
        else a %= b;
    }
    return a == 0 ? b : a;
}

inline void fastscan(int & num)
{
    num = 0; char c;
    for (c = gcu(); c < '0' || c > '9'; c = gcu());
    for (; c >= '0' && c <= '9'; c = gcu())
        num = num * 10 + c - '0';
}

int main()
{
    for (fastscan(N); N != 0; fastscan(N))
    {
        result = 1;
        in_a_cycle.reset();
        for (int i = 1; i <= N; ++i) fastscan(permutation[i]);
        for (int i = 1; i <= N; ++i)
        {
            if (in_a_cycle.test(i)) continue;
            // Start a new cycle
            in_a_cycle.set(i);
            cycle_size = 1;
            for (aux = i; !in_a_cycle.test(permutation[aux]); aux = permutation[aux], in_a_cycle.set(aux), ++cycle_size);
            result = result * to_llint(cycle_size) / gcd(result, to_llint(cycle_size));
        }
        printf("%lli\n", result);
    }
    return 0;
}