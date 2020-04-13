// Bittor
#include <iostream>
using namespace std;
const int despf[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, despc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
struct tCasilla{
	bool cubierto = true, bomba = false, expandido = false;
	int ady = 0;
};
struct tMatriz{
	tCasilla mat[50][50];
	int fil, col;
};
struct vPos{
	int pos[2500][2];
	unsigned int cont = 0, procesados = 0;
};
void leer(tMatriz & tablero){
	char ce = ' ';
	for (int i = 0; i < tablero.fil; ++i)
		for (int j = 0; j < tablero.col; ++j){
			cin >> ce;
			if (ce == '*') tablero.mat[i][j].bomba = true;
		}
}
void adyacencia(int x, int y, tMatriz & tablero){
	// Comprueba las ocho celdas alrededor de la elegida, y si alguna de ellas tiene bomba añade uno al contador ady
	int fils = tablero.fil, cols = tablero.col;
			for (int k = 0; k < 8; ++k){
				if (x + despf[k] >= 0 && x + despf[k] < fils && y + despc[k] >= 0 && y + despc[k] < cols)
				if (tablero.mat[x + despf[k]][y + despc[k]].bomba) ++tablero.mat[x][y].ady;
			}
}
void expandir(tMatriz & tablero, int x, int y){
	vPos posic;
	++posic.cont; posic.pos[0][0] = x; posic.pos[0][1] = y;
	// Posic va a guardar las posiciones pendientes de expandir, ya que al expandir una casilla con ady = 0 (e.d. descubrir las casillas de su alrededor)
	// se consiguen otras casillas con ady = 0, con lo que estas también se tendrán que expandir, y se añadirán a la cola en el vector
	// posic. Cuando se hayan procesado tantas casillas con ady = 0 como las que se han encontrado, se habrá acabado de expandir
	while (posic.cont > posic.procesados){
		int fila = posic.pos[posic.procesados][0], columna = posic.pos[posic.procesados][1];
		for (int i = 0; i < 8; ++i){
			if (fila + despf[i] >= 0 && fila + despf[i] < tablero.fil && columna + despc[i] >= 0 && columna + despc[i] < tablero.col){
				if (tablero.mat[fila + despf[i]][columna + despc[i]].cubierto) {
					adyacencia(fila + despf[i], columna + despc[i], tablero);
					tablero.mat[fila + despf[i]][columna + despc[i]].cubierto = false;
					if (tablero.mat[fila + despf[i]][columna + despc[i]].ady == 0 && !tablero.mat[fila + despf[i]][columna + despc[i]].expandido){
						posic.pos[posic.cont][0] = fila + despf[i];
						posic.pos[posic.cont][1] = columna + despc[i];
						++posic.cont;
					}
				}
			}
		}
		++posic.procesados;
		tablero.mat[fila][columna].expandido = true;
	}
}
ostream & operator<<(ostream & flujo, tMatriz const & tablero){
	for (int i = 0; i < tablero.fil; ++i){
		for (int j = 0; j < tablero.col; ++j)
		{
			if (!tablero.mat[i][j].cubierto){
				if (tablero.mat[i][j].ady == 0) flujo << '-';
				else flujo << tablero.mat[i][j].ady;
			}
			else flujo << 'X';
		}
		cout << '\n';
	}
	return flujo;
}
bool resolvercaso(){
	tMatriz tablero;
	cin >> tablero.fil >> tablero.col;
	if (!cin) return false;
	int x, y, nclicks; bool okay = true;
	leer(tablero);
	cin >> nclicks;
	for (int i = 0; i < nclicks && okay; ++i){
		cin >> x >> y; --x; --y;
		if (tablero.mat[x][y].cubierto) {
			if (!tablero.mat[x][y].bomba) {
				adyacencia(x, y, tablero);
				tablero.mat[x][y].cubierto = false;
				if (tablero.mat[x][y].ady == 0) expandir(tablero, x, y);
			}
			else okay = false;
		}
	}
	if(okay) cout << tablero;
	else cout << "GAME OVER\n";
	return true;
}
int main(){
	while (resolvercaso());
	return 0;
}