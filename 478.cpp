// bittor
#include <stdio.h>
#include <cstdint>
#include <bitset>
#define MAX_N 200000
#define MAX_POWER 500001
uint32_t power[MAX_N];
std::bitset<MAX_POWER> inset;

inline uint32_t fastscan()
{
	unsigned char c;
	uint32_t num = 0;
	for (c = getchar_unlocked(); c < '0' || c > '9'; c = getchar_unlocked()) {}
	for (; c >= '0' && c <= '9'; c = getchar_unlocked()) num = num * 10 + c - '0';
	return num;
}

inline uint64_t fastscan64()
{
	unsigned char c;
	uint64_t num = 0;
	for (c = getchar_unlocked(); c < '0' || c > '9'; c = getchar_unlocked()) {}
	for (; c >= '0' && c <= '9'; c = getchar_unlocked()) num = num * 10 + static_cast<uint64_t>(c - '0');
	return num;
}

void solve(uint32_t n)
{
	uint64_t total_power = 0, harm_done;
	uint64_t aux;
	for (uint32_t i = 0; i < n; ++i) 
	{
		power[i] = fastscan();
		inset.set(power[i]);
		total_power += static_cast<uint64_t>(power[i]);
	}
	//scanf("%llu", &harm_done);
	harm_done = fastscan64();
	total_power -= harm_done;
	uint32_t count = 0;
	while (count < n && power[count] < total_power)
	{
		aux = total_power - static_cast<uint64_t>(power[count]);
		if (aux < static_cast<uint64_t>(MAX_POWER) && inset.test(aux))
		{
			printf("%u %u\n", power[count], aux);
			break;
		}
		++count;
	}
	for (int i = 0; i < n; ++i) inset.reset(power[i]);
}

int main()
{
	inset.reset();
	uint32_t n;
	for (n = fastscan(); n != 0; n = fastscan()) solve(n);
	return 0;
}