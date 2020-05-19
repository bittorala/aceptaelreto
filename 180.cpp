// bittor

#include <stdio.h>
#include <algorithm>

int sides[3];

int main()
{
	int ncases;
	int x;
	for (scanf("%i", &ncases); ncases; --ncases)
	{
		scanf("%i",sides);
		scanf("%i",sides+1);
		scanf("%i",sides+2);
		std::sort(sides, sides + 3);
		if (sides[2] >= sides[1] + sides[0])
		{
			puts("IMPOSIBLE");
			continue;
		}
		x = sides[2] * sides[2] - sides[1] * sides[1] - sides[0] *sides[0];
		if (x == 0) puts("RECTANGULO");
		else if (x < 0) puts("ACUTANGULO");
		else puts("OBTUSANGULO");
	}
	return 0;
}