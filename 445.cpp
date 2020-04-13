// bittor
#include <stdio.h>
#include <algorithm>
#include <queue>
#define gcu getchar_unlocked
struct activity
{
    unsigned start, end;
};

bool operator<(const activity & a1, const activity & a2)
{
    return a1.end > a2.end || a1.end == a2.end && a1.start > a2.start;
}

bool start_order(const activity & a1, const activity & a2)
{
    return a1.start < a2.start || a1.start == a2.start && a1.end < a2.end;
}

activity activities[200000];

inline bool fastscan(unsigned & n)
{
    n = 0; char c = gcu();
    for (; (c < '0' || c > '9') && c >= 0; c = gcu());
    if (c < 0) return false;
    for (; c >= '0' && c <= '9'; c = gcu())
        n = n * 10 + c - '0';
    return c >= 0;
}

int main()
{
    unsigned N, mates;
    bool covered;
    while (fastscan(N))
    {
        for (unsigned i = 0; i < N; ++i)
        {
            fastscan(activities[i].start);
            fastscan(activities[i].end);
        }
        std::sort(activities, activities + N, start_order);
        std::priority_queue<activity> pq;
        mates = 0;
        pq.push(activities[0]);
        for (unsigned i = 1; i < N; ++i)
        {
            if (pq.top().end <= activities[i].start)
            {
                pq.pop();
            }
            else
            {
                ++mates;
            }
            pq.push(activities[i]);
        }
        printf("%u\n", mates);
    }
    return 0;
}