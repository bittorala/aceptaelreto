// bittorala
#include <cstdio>
#define MAX_SIZE 1000001

int power[MAX_SIZE];

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

void solve(int n)
{
	for (int i = 1; i < n + 1; ++i) fastscan(power[i]);	//scanf("%i", &power[i]);
	for (int i = 1; i < n + 1; ++i) power[i] += power[i-1];
	int a,b,queries;
	fastscan(queries);
	//scanf("%i", &queries);
	for(int i = 0; i < queries; ++i)
	{
		fastscan(a);
		fastscan(b);
		//scanf("%i",&b);
		printf("%i\n", power[b] - power[a-1]);
	}
}

int main()
{
	int n;
	power[0] = 0;
	//scanf("%i",&n);
	fastscan(n);
	while (n != 0)
	{
		solve(n);
		fastscan(n);
		//scanf("%i", &n);
	}
	return 0;
}