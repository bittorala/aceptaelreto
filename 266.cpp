// bittor
#include <iostream>
using namespace std;
typedef char letras[26];
struct tMatriz{
	char mat[500][500];
	int fil, col;
	letras cambio;
};
istream & operator>>(istream & arch, tMatriz & matriz){
	for (int i = 0; i < matriz.fil; ++i)
		for (int j = 0; j < matriz.col; ++j)
			arch >> matriz.mat[i][j];
	return arch;
}
void inicializar(letras & let){
	for (int i = 0; i < 26; ++i){
		let[i] = char('A' + i);
	}
}
void convertir(letras & cambio, char color0, char colorf){
	for (int i = 0; i < 26; ++i){
		if (cambio[i] == color0) cambio[i] = colorf;
	}
}
void copiar(tMatriz & imagen){
	for (int i = 0; i < imagen.fil; ++i)
		for (int j = 0; j < imagen.col; ++j)
			imagen.mat[i][j] = imagen.cambio[imagen.mat[i][j] - 'A'];
}
ostream & operator<<(ostream & arch, tMatriz const & imagen){
	for (int i = 0; i < imagen.fil; ++i){
		for (int j = 0; j < imagen.col; ++j)
			arch << imagen.mat[i][j];
		arch << '\n';
	}
	return arch;
}
void resuelvecaso(int fils, int cols){
	tMatriz imagen; int ncopistas = 0; char color0, colorf;
	inicializar(imagen.cambio);
	imagen.fil = fils; imagen.col = cols;
	cin >> imagen;
	cin >> ncopistas;
	for (int i = 0; i < ncopistas; ++i){
		cin >> color0 >> colorf;
		convertir(imagen.cambio, color0, colorf);
	}
	copiar(imagen);
	cout << imagen;
}
int main(){
	int fils, cols;
	cin >> fils >> cols;
	while (fils != 0 || cols != 0){
		resuelvecaso(fils, cols);
		cin >> fils >> cols;
	}
	return 0;
}