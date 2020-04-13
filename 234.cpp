// DG 01 - Bittor Alaña
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void resuelvecaso(){
	int npilas, voltaje, contador = 0, ncoches = 0;  bool irse = false;
	cin >> npilas >> voltaje; vector<int> pilas(npilas);
	for (int i = 0; i < npilas; ++i) cin >> pilas[i];
	sort(pilas.begin(), pilas.end());
	for (int i = npilas - 1; i >= contador && !irse && pilas[i] >= voltaje / 2; --i){
		bool acabar = false;
		for (; contador < i && !acabar; ++contador){
			if (pilas[contador] + pilas[i] >= voltaje){
				++ncoches;
				acabar = true;
			}
		}
		if (contador == i) irse = true;
	}
	cout << ncoches << '\n';
}
int main(){
	int ncasos = 0;
	cin >> ncasos;
	for (int i = 0; i < ncasos; ++i) resuelvecaso();
}