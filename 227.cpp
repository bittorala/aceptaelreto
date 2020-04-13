// bittorala
#include <stdio.h>
#define MAX 5001
#define MOD 1000000007
using uint = unsigned int;
using ullint = unsigned long long;

uint inverses[MAX];

// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

// Function to find modulo inverse of a 
inline uint modInverse(int a, int m) 
{ 
    int x, y; 
    gcdExtended(a, m, &x, &y); 
        // m is added to handle negative x 
    int res = (x%m + m) % m; 
    return (uint) res;
} 

inline void computeInverses()
{
    inverses[1] = 1;
    for (uint i = 2; i < MAX; ++i) inverses[i] = modInverse(i,MOD);
}

inline uint fastscan() 
{
    char c = getchar_unlocked();
    uint num = 0;

    for (;c < '0' || c > '9'; c = getchar_unlocked()) {}

    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) {
        num = 10 * num + c - '0';
    }

    return num;
}

int main()
{
	uint a,b;
    computeInverses();
	for (a = fastscan(), b= fastscan(); a != 0 || b != 0; a = fastscan(), b= fastscan())
	{
		ullint num = 1;
		printf("%llu", num);
		for (uint i = 1; i <= b; ++i) 
		{
			num = num * (a - i + 1) % MOD;
			num = num * inverses[i] % MOD;
			printf(" %llu", num);
		}
		printf("\n");
	}
	return 0;
}