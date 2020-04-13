// bittor
#include <stdio.h>
#define SIZE 1000
#define gcu getchar_unlocked
int sums[SIZE];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline int fastscan()
{
    int n = 0; char c = gcu();
    for (; c < '0' || c > '9'; c = gcu());
    for (; c >= '0' && c <= '9'; c = gcu())
        n = n * 10 + c - '0';
    return n;
}

int main()
{
    int N;
    for (N = fastscan(); N != 0; N = fastscan())
    {
        int a, b, last_num;
        a = fastscan();
        for (int i = 0; i < N - 1; ++i)
        {
            b = fastscan();
            sums[i] = b - a;
            a = b;
            if (i == N - 2) last_num = b;
        }
        int right = 1, longest_seq = 0;
        // while (right < N - 1)
        // {
        //     if (sums[right] == sums[0])
        //     {
        //         int k = 1;
        //         while (right + k < N - 1 && sums[k % right] == sums[right + k]) ++k;
        //         if (k >= right) longest_seq = max(longest_seq, right);
        //     }
        //     ++right;   
        // }
        while (right <= (N - 1) / 2)
        {
            if (sums[right] == sums[0])
            {
                int k = 1;
                for (; k < right && sums[right + k] == sums[k]; ++k);
                if (k == right) longest_seq = right;
            }
            ++right;
        }
        printf("%i\n", last_num + sums[(N-1) % longest_seq]);
    }
    return 0;
}