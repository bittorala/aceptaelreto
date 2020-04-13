// bittorala
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void caso()
{
	vector<int> pesos; int burros = 0, peso = 0, npes = 0, pares = 0;
	cin >> burros >> npes;
	for (int i = 0; i < npes; ++i) { cin >> peso; pesos.push_back(peso); }
	sort(pesos.begin(), pesos.end());
	for (int i = 0; i < pesos.size() - 1; ++i)	if (pesos[i] == pesos[i + 1]) {	++pares; ++i;}
	if (pares < burros) cout << pares << '\n';
	else cout << burros << '\n';
}
int main()
{
	int ncas = 0; cin >> ncas;
	for (int i = 0; i < ncas; ++i) caso();
	return 0;
}