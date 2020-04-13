// bittorala
#include <iostream>
using namespace std;

int main()
{
	int ndata = 0, dato = 0, dato1 = 0, sol = 0;
	cin >> ndata;
	while (ndata != 0)
	{
		sol = 0;
		cin >> dato;
		if (ndata == 1)
			cout << "NO\n";
		else
		{
			for (int i = 0; i < ndata - 1; ++i)
			{
				cin >> dato1;
				if (dato >= dato1)
					++sol;
				dato = dato1;
			}
			if (sol == 0)
				cout << "SI\n";
			else
				cout << "NO\n";
		}
		cin >> ndata;
	}
	return 0;
}