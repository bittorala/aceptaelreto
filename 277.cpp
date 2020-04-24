// bittor
#include <algorithm>
#include <iostream>
#include <utility>

std::pair<int,int> films[1000];
int maximums[1001];

// Order must be kept (film i starts before j)
inline bool noconflict(int i, int j)
{
	return films[i].first + films[i].second + 10 <= films[j].first;
}

inline int max(int a, int b)
{
	return a < b ? b : a;
}

bool order(const std::pair<int,int> &a, const std::pair<int,int> &b)
{
	return a.first + a.second < b.first + b.second;
}

void solvecase(int nfilms)
{
	char aux; int hh,mm, dur;
	for (int i = 0; i < nfilms; ++i)
	{
		std::cin >> hh >> aux >> mm >> dur;
		films[i].first = hh*60+mm;
		films[i].second = dur;
	}
	sort(films, films + nfilms,order);
	maximums[0] = 0;
	maximums[1] = films[0].second;
	for (int j = 1; j < nfilms; ++j)
	{
		int fc;
		for (fc = j-1; fc >= 0 && !noconflict(fc,j); --fc);
		maximums[j+1] = maximums[fc + int(noconflict(fc,j))] + films[j].second;
		for (int k = fc; k < j; ++k)
			maximums[j+1] = max(maximums[j+1], maximums[k+1]);
	}
	std::cout << maximums[nfilms] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
	int nfilms;
	for (std::cin >> nfilms; nfilms != 0; std::cin >> nfilms)
	{
		solvecase(nfilms);
	}
	return 0;
}