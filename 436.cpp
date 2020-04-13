// bittor
#include <iostream>
#include <math.h>
#define K 1000000
const double LOG2_E = log(2);
const double LOGK_2 = log2(K);



int main()
{
	int G, H;
	double aux;
	std::ios::sync_with_stdio(false);
	//FILE * fptr = fopen("casos.txt", "r");
	//while (fscanf(fptr,"%i",&G))
	while (std::cin >> G >> H)
	{
		//fscanf(fptr,"%i", &H);
		// log (H*K/G) = log H + log K - log G
		aux = log2(H) + LOGK_2 - log2(G);
		//printf("%i\n", (int) ceil(aux));
		std::cout << (int) ceil(aux) << "\n";
	}
	//fclose(fptr);
	return 0;
}