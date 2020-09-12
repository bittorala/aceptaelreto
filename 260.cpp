// Bittor
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NCHARS 'z'-'a'+1

int count[NCHARS];
char * buffer;

int main()
{
	int ncases;
	int n;
	char c;
	size_t size;
	for (scanf("%d", &ncases), getchar_unlocked(); ncases; ncases--)
	{
		for (int i = 0; i < NCHARS; ++i) count[i] = 0;
		n = getline(&buffer, &size, stdin);
		for (int i = 0; i < n; ++i)
		{
			c = buffer[i];
			if (!isalpha(c)) continue;
			c = tolower(c);
			if (c-'a' < 0 || c-'a'>= NCHARS) continue;
			++count[c-'a'];	
		}
		n = getline(&buffer,&size,stdin);
		for (int i = 0; i < n; ++i)
		{
			c = buffer[i];
			if (!isalpha(c)) continue;
			c = tolower(c);
			if (c-'a' < 0 || c-'a'>= NCHARS) continue;
			--count[c-'a'];	
		}
		bool anagram = true;
		for (int i = 0; i < NCHARS && anagram; ++i)
			if (count[i]) anagram = false;
		anagram ? puts("SI") : puts("NO");
	}
	return 0;
}




