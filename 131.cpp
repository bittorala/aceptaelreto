#include <stdio.h>
#include <climits>
using uint = unsigned;
static uint n, a, b;
static uint me_trips, neighbour_trips;

inline uint fastscan(uint & num) 
{
    char c = getchar_unlocked();
    num = 0;

    for (;c < '0' || c > '9'; c = getchar_unlocked()) {}

    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) {
        num = 10 * num + c - '0';
    }

    return num;
}

inline uint compute_trips()
{
    if (n <= a) return 1;
    if (a <= b) return UINT_MAX;
    return (n-a)/(a-b) + int((n - a) % (a - b) != 0)+ 1;
}

int main()
{
    fastscan(n); fastscan(a); fastscan(b);
    while (n != 0)
    {
        me_trips = compute_trips();
        fastscan(n); fastscan(a); fastscan(b);
        if (n == 0) break;
        neighbour_trips = compute_trips();
        if (me_trips < neighbour_trips) printf("YO %u\n", me_trips);
        else if (me_trips > neighbour_trips) printf("VECINO %u\n", neighbour_trips);
        else printf("EMPATE %u\n", me_trips);
        fastscan(n); fastscan(a); fastscan(b);
    }
    return 0;
}