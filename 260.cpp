// bittorala
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
void caso()
{
	string frase = "", frase1 = "", nfrase = "", nfrase1 = "";
	getline(cin, frase); getline(cin, frase1);
	for (int i = 0; i < frase.size(); ++i) if (frase[i] != ' ') nfrase += tolower(frase[i]);
	for (int i = 0; i < frase1.size(); ++i) if (frase1[i] != ' ') nfrase1 += tolower(frase1[i]);
	sort(nfrase.begin(), nfrase.end()); sort(nfrase1.begin(), nfrase1.end());
	if (nfrase == nfrase1) cout << "SI\n"; else cout << "NO\n";
}
int main()
{
	int ncas = 0; char aux = ' '; cin >> ncas; cin.get(aux);
	for (int i = 0; i < ncas; ++i) caso();
	return 0;
}