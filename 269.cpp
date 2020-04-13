// bittorala
#include <iostream>
using namespace std;
int main()
{
	int kms = 0, ncas = 0, sol = 0, kmdia = 0;
	cin >> ncas;
	for (int i = 0; i < ncas; ++i){
		cin >> kms;
		while (kms != 0)
		{
			kmdia += 2 * kms;
			sol += kmdia;
			cin >> kms;
		}
		cout << sol << '\n';
		sol = 0;
		kmdia = 0;
	}
	return 0;
}