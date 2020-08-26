// bittor

#include <iostream>
#include <algorithm>
#include <vector>

struct tpair{
	int spent, received;
	bool operator<(const tpair & other) const
	{
		return spent < other.spent ||
			spent == other.spent && received < other.received;
	}
};

void solve(int n)
{
	std::vector<tpair> pairs;
	int spent, received;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> spent;
		std::cin >> received;
		pairs.push_back({spent,received});
	}
	sort(pairs.begin(), pairs.end());
	bool fair = true;
	int j = 1;
	int i = 0;
	while (j < n && fair)
	{
		while (j < n && pairs[j].spent == pairs[i].spent)
			++j;
		if (j == n)
			break;
		i = j - 1;
		if (pairs[i].received >= pairs[j].received)
			fair = false;
		++j;
		++i;
	}
	std::cout << (fair ? "SI\n" : "NO\n");
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	for (std::cin >> n; n != 0; std::cin >> n)
		solve(n);
	return 0;
}