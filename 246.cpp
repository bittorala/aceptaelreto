// bittor
#include <iostream>
using namespace std;

void recurs(long long int numero, int size,int const digmax){
	if (size < digmax){
		// Si el numero es menor que la cota, multiplicado por diez entrara en el rango
		numero *= 10; int cont = 0;
		// Probamos poniendo en ese nuevo digito numeros del 0 al 9, y si alguno es divisible por el digito que toca (size + 1),
		// buscamos mas polidivisibles que empiecen por ese prefijo
		while (cont < 10){
			if (numero % (size + 1) == 0){
				cout << numero << '\n';
				recurs(numero,size + 1,digmax);
			}
			++numero; ++cont;
		}
	}
}

int digitosdelNum(long long int numero){
	int k = 1;
	// Calculamos la primera potencia de diez que excede al numero
	while (numero > 9){
		++k;
		numero = numero / 10;
	}
	return k;
}

bool resolver(){
	long long int numero,digmax,size;
	// Leemos el numero y la cantidad maxima de digitos que queremos
	cin >> numero >> digmax;
	if (!cin) return false;
	size = digitosdelNum(numero); // Calculamos los digitos que tiene el numero polidivisible que nos han dado
	cout << numero << '\n'; // Sacamos el primer numero polidivisible, que es el que nos han dado
	recurs(numero,size,digmax);
	cout << "---\n";
	return true;
}

int main(){
	while (resolver());
	return 0;
}