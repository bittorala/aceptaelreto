// Bittor

#include <iostream>


int numbers[5];

bool backtrack(int i, int acc, int goal)
{
	if (i == 5) return acc == goal;
	if (backtrack(i+1, acc + numbers[i], goal)) return true;
	if (backtrack(i+1, acc - numbers[i], goal)) return true;
	if (backtrack(i+1, acc * numbers[i], goal)) return true;
	if (numbers[i] != 0 && (acc % numbers[i] == 0) && backtrack(i+1, acc / numbers[i], goal)) return true;
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	while (std::cin >> n)
	{
		for (int i = 0; i < 5; ++i) std::cin >> numbers[i];
		if (backtrack(1, numbers[0], n)) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
	return 0;
}