// bittorala
#include <stdio.h>
#include <algorithm>
#define MAX 1000
#define MOD 1000000007
using uint = unsigned int;
using ushort = unsigned short;
uint choose[((MAX+1)/2 + 1)*(MAX+1)/2 +((MAX+1)+1)/2];
uint a,b;
constexpr uint index(uint row, uint col)
{
	return (row/2 + 1)*(row/2) + col + (row%2)*(row+1)/2;
}

void compute()
{
	choose[0] = 1;
	for(uint i = 1; i < MAX + 1; ++i)
	{
		choose[index(i,0)] = 1;
		for(uint j = 1; j <= i / 2; ++j)
			choose[index(i,j)] = (choose[index(i-1,std::min(j,i-1-j))] + choose[index(i-1,std::min(j-1, i-j))]) % MOD;
	}
}

inline uint fastscan() 
{
    char c = getchar_unlocked();
    uint num = 0;

    for (;c < '0' || c > '9'; c = getchar_unlocked()) {}

    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) {
        num = 10 * num + c - '0';
    }

    return num;
}


int main()
{
	compute();
	a = fastscan();
	b = fastscan();
	while(a != 0 || b != 0)
	{
		printf("%i\n",(b <= a ? choose[index(a,std::min(b,a-b))] : 0));
		a = fastscan();
		b = fastscan();
	}
	return 0;
}