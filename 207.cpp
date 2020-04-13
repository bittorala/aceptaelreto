#include <iostream>
using namespace std;
struct tParcela{
	bool arbol = false;
	bool sombra = false;
};
struct tMatriz{
	tParcela parcela[50][50];
	int fil, col;
};
const int masfila[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int mascolumna[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void sombrear(tMatriz & camp, int x, int y, int & cont){
	for (int i = 0; i < 8; ++i){
		if (x + masfila[i] >= 0 && x + masfila[i] < camp.fil && y + mascolumna[i] >= 0 && y + mascolumna[i] < camp.col)
			if (!camp.parcela[x + masfila[i]][y + mascolumna[i]].arbol)
				if (!camp.parcela[x + masfila[i]][y + mascolumna[i]].sombra){
					camp.parcela[x + masfila[i]][y + mascolumna[i]].sombra = true; ++cont;
				}
	}
}
void resuelvecaso(int fil, int col, int narb){
	tMatriz camp; int x , y, cont = 0;
	camp.fil = fil; camp.col = col;
	for (int i = 0; i < narb; ++i){
		cin >> x >> y; --x; --y;
		camp.parcela[x][y].arbol = true;
		if (camp.parcela[x][y].sombra){
			camp.parcela[x][y].sombra = false; --cont;
		}
		sombrear(camp, x, y, cont);
	}
	cout << cont << '\n';
}
int main(){
	int fil, col, narb;
	cin >> fil >> col >> narb;
	while (fil != 0 || col != 0 || narb != 0){
		resuelvecaso(fil, col, narb);
		cin >> fil >> col >> narb;
	}
	return 0;
}