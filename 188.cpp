// bittorala
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	bool correcto = true; string cadena = "", pal = ""; char aux = ' ';
	while (cin >> pal)
	{
		cadena += pal; cin.get(aux); 
		if (aux == ' ') {
			cadena += aux;
			getline(cin, pal); cadena += pal;
		}
		for (unsigned int i = 0; i < cadena.size() - 2; ++i)
		{
			if (cadena.at(i) == ' ')
			{
				if (cadena.at(i - 2) != cadena.at(i + 1) || cadena.at(i - 1) != cadena.at(i + 2)) correcto = false;
			}
		}
		if (correcto) cout << "SI\n";
		else cout << "NO\n";
		correcto = true; cadena = "";
	}
	return 0;
}