// bittor
#include <iostream>
using namespace std;

unsigned int costs(int pagfinal){
	unsigned int n = 1000000, coste = 0; int cont = 7;
	while (pagfinal < n){
		n = n / 10; --cont;
	}
	coste += (pagfinal - n + 1) * cont;
	for (int i = 1; i < cont; ++i){
		int hamarrak = 1, bederatziak = 0;
		for (int j = 1; j <= i; ++j){
			bederatziak += 9 * hamarrak;
			hamarrak = hamarrak * 10;
		}
		coste += (bederatziak - hamarrak / 10 + 1) * i;
	}
	return coste;
}

bool nextcambia(int ini, int fin, int mitad, int p1, int p2){
	int next = mitad + 1;
	unsigned int digits1, digits2;
	digits1 = costs(next) - costs(p1 - 1); digits2 = costs(p2) - costs(next);
	return digits1 > digits2;
}

void resuelveCaso(int p1, int p2){
	bool found = false; int ini = p1, fin = p2, mitad;
	unsigned int digits1, digits2;
	while (ini < fin && !found){
		mitad = (ini + fin - 1) / 2;
		digits1 = costs(mitad) - costs(p1 - 1); digits2 = costs(p2) - costs(mitad);
		if (digits1 < digits2){
			ini = mitad + 1;
			if (nextcambia(ini, fin,mitad, p1, p2)) found = true;
		}
		else if (digits2 < digits1){
			fin = mitad;
		}
		else found = true;
	}
	cout << mitad << '\n';
}

int main(){
	int p1, p2;
	cin >> p1 >> p2;
	while (p1 != 0 || p2 != 0){
		resuelveCaso(p1,p2);
		cin >> p1 >> p2;
	}
	return 0;
}