// Bittor
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>

#define uint unsigned

uint digit_counts[10];

bool backtracking(uint target, uint level, uint digits, uint tenthpow, std::vector<uint> & sorted,uint a, uint b, bool & found)
{
	if (level == digits)
       	{
		if (target == a * b && (a % 10 || b % 10))
		{found = true; return true;}
		else return false;
	}
	for (uint i = 0; i < sorted.size() && !found; ++i)
	{
		if (!digit_counts[sorted[i]]) continue;
		--digit_counts[sorted[i]];
		for (uint j = 0; j < sorted.size() && !found; ++j)
		{
			if (!digit_counts[sorted[j]]) continue;
			--digit_counts[sorted[j]];
			if ((a + sorted[i] * tenthpow)*(b + sorted[j] * tenthpow) % (10*tenthpow) == target % (10*tenthpow))
				backtracking(target, level + 1, digits, tenthpow*10, sorted, a + sorted[i] * tenthpow,b + sorted[j] * tenthpow, found);
			++digit_counts[sorted[j]];
		}
		++digit_counts[sorted[i]];
	}
	return found;
}

bool isvampire(uint n, uint digits)
{
	if (digits & 0x01) return false;
	std::vector<uint> sorted;
	for (uint i = 0; i < 10; ++i)
		for (uint j = 0; j < digit_counts[i]; ++j)
			sorted.emplace_back(i);
	bool found = false;
	return backtracking(n, 0, digits >> 1, 1, sorted, 0,0,found);
}

uint fastscan(uint & n)
{
	memset(digit_counts, 0, sizeof(uint) * 10);
	n = 0;
	int digits = 0;
	char c = getchar_unlocked();
	for (; c < '0' || c > '9'; c = getchar_unlocked());
	for (; c >= '0' && c <= '9'; c = getchar_unlocked(), ++digits)
		n = n * 10 + c - '0', ++digit_counts[c-'0'];
	return digits;
}

int main()
{
	uint ncases;
	uint num, digits;
	for (fastscan(ncases); ncases; ncases--)
	{
		digits = fastscan(num);
		isvampire(num, digits) ? puts("SI") : puts("NO");
	}
	return 0;
}
