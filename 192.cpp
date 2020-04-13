// bittorala
#include <stdio.h>
#include <bitset>
#define MAX 20001
using uint = unsigned int;

static uint num;
static std::bitset<MAX> doable;

inline void fastscan() 
{
    char c = getchar_unlocked();
    num = 0;
    for (;c < '0' || c > '9'; c = getchar_unlocked()) {}
    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) {
        num = 10 * num + c - '0';
    }
}

int main()
{
	doable.set(1);
	doable.reset(2);
	doable.set(3);
	doable.reset(4);
	doable.reset(5);
	for (uint i = 6; i < MAX; ++i)
	{
		if (!(i % 3) && doable.test(i / 3) || doable.test(i - 5)) doable.set(i);
		else doable.reset(i);
	}
	fastscan();
	while(num != 0)
	{
		if (doable.test(num))
		{
			putchar_unlocked('S'); putchar_unlocked('I'); putchar_unlocked('\n');
		}
		else
		{
			putchar_unlocked('N'); putchar_unlocked('O'); putchar_unlocked('\n');
		}
		fastscan();
	}
	return 0;
}