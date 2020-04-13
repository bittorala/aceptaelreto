#include <stdio.h>
#include <string.h>

#define gcu getchar_unlocked
#define TAM_MAX 10005

char line[TAM_MAX];

inline int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int logged_in, max_logged_in;
	int n;
	for(scanf("%i", &n); n; --n)
	{
		max_logged_in = logged_in = 0; // out_wout_in = 0;
		scanf("%s", line);
		char c;
		for (int i = 0; line[i] != '\0'; ++i)
		{
			c = line[i];
			if (c == 'I') ++logged_in;
			else if (c == 'O' && logged_in) --logged_in;
			else if (c == 'O' && !logged_in) ++max_logged_in;
			max_logged_in = max(logged_in, max_logged_in);
		}
		printf("%i\n", max_logged_in);
	}
	return 0;
}