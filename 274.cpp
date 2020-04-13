// bittorala
#include <iostream>
using namespace std;
void resuelvecaso()
{
	int ndpyear = 0, ndpweek = 0, sday = 0, nweeks = 0;
	cin >> ndpyear >> ndpweek >> sday;
	if (sday == 1) cout << ndpyear / ndpweek << '\n';
	else{
		nweeks = (ndpyear - ndpweek -1 + sday) / ndpweek;
		cout << nweeks << '\n';
	}
}
int main()
{
	int ncas = 0; 
	cin >> ncas;
	for (int i = 0; i < ncas; ++i) resuelvecaso();
	return 0;
}