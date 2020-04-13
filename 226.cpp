// bittorala

#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>

std::vector<int> PRIMOS;
std::vector<int> PRIMOS_SQ;

const int PRIMOS_HASTA = 46400;

const int SQRT = sqrt(PRIMOS_HASTA) + 1;


void hallarPrimos() 
{
    bool primos[PRIMOS_HASTA + 1];
    memset(primos, true, sizeof(primos));
    primos[0] = primos[1] = false;
    for (int p = 2; p <= PRIMOS_HASTA; ++p)
    {
        if (primos[p])
        {
            for (unsigned int m = p*p; m <= PRIMOS_HASTA; m += p)
                primos[m] = false;
            PRIMOS.push_back(p);
            PRIMOS_SQ.push_back(p*p-1);
        }
    }
}

void resuelve(int k)
{
	int tam = PRIMOS.size();
	int p;
	long long suma = 1;
	int multiplicidades;
	for (int i = 0; i < tam && k != 1 && PRIMOS_SQ[i] <= k; ++i)
	{
		p = PRIMOS[i];
		multiplicidades = 0;
		if (k % p) continue;
		while (!(k % p))
		{
			k /= p;
			++multiplicidades;
		}
		suma *= 2*multiplicidades + 1;
	}
	if (k != 1) // Cuando k tenía algún primo más grande que 2^16
		suma *= 3;
	std::cout << ((suma >> 1) + 1) << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
	hallarPrimos();
	int k;
	while (std::cin >> k) resuelve(k);
	return 0;
}