// Bittor
#include <stdio.h>

inline int fastscan()
{
	int n = 0;
	bool negative = false;
	char c;
	for (c = getchar_unlocked(); (c < '0' || c > '9') && c != '-'; c = getchar_unlocked());
	if (c == '-') negative = true, c = getchar_unlocked();
	for (; c >= '0' && c <= '9'; c = getchar_unlocked())
		n = 10 * n + (c - '0');
	if (negative)
		n = -n;
	return n;	
}

int main()
{
    int n, N;
    for (n = fastscan(); n; --n)
    {
        N = fastscan();
        int left = 0; int right = -1; int maxlength = 0;
        int x, maxleft, maxright;
        for (int i = 0; i < N; ++i)
        {
            x = fastscan(); 
            if (x == 0) left = i + 1;
            else { right = i; if (right - left + 1 > maxlength) {maxlength = right -left + 1; maxleft = left; maxright = right;}}
        } 

        if (maxlength) { printf("%d -> [%d,%d]\n", maxlength, maxleft, maxright); }
        else puts("SIGUE BUSCANDO");
    }
    return 0;
}
