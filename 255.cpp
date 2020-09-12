// Bittor
#include <stdio.h>
#include <stdint.h>

inline int maximum(uint16_t a, uint16_t b)
{
	return a < b ? b : a;
}

void solve(char * str, size_t bytes)
{
	int longest = 1;
	for (int i = 1; i < bytes; ++i)
	{
		int j = i - 1, k = i;
		while (j >= 0 && k < bytes && str[j]==str[k])
		{
			longest = maximum(longest, k - j + 1);
			--j; ++k;
		}
		j = i - 1; k = i + 1;
		while (j >= 0 && k < bytes && str[j] == str[k])
		{
			longest = maximum(longest, k -j + 1);
			--j; ++k;
		}	
	}
	printf("%d\n", longest);
}

int main()
{
	char * str = NULL;
	size_t size, bytes;
	int n;
	while((n = getline(&str, &size, stdin)) > 0)
	{
		if (str[n-1] == '\n') size = n - 1;
		else size = n;
		solve(str, size);
	}
	return 0;
}
