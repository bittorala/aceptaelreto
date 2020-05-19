// bittor

#include <stdio.h>
#include <string.h>

char day_names[] = "LMXJVSD";
int pills_for_day[7];

char getPillChar()
{
	char c;
	for (c = getchar(); c != '*' && c != '-'; c = getchar());
	return c;
}

int main()
{
	int ncases; char c; int min, minpos;
	for (scanf("%i", &ncases); ncases; --ncases)
	{
		int rows; scanf("%i", &rows);
		memset(pills_for_day, 0, 7 * sizeof(int));
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				c = getPillChar();
				if (c == '*') ++pills_for_day[j];
			}
		}

		minpos = 0; min = pills_for_day[minpos];
		for (int k = 1; k < 7; ++k)
			if (pills_for_day[k] < min)
			{
				minpos = k;
				min = pills_for_day[minpos];
			}
		printf("%c %i\n", day_names[minpos], min + 1);
	}
	return 0;
}