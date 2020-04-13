// bittorala
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string frase = "", fr1 = ""; char b = ' ', c = ' ', e = ' ', x = ' '; int ncas = 0, r = 0; unsigned int k = 0;
	getline(cin, frase);
	while (frase != "XXX")
	{
		for (unsigned int j = 0; j < frase.size(); ++j)
		{
			c = frase.at(j);
			c = tolower(c);
			if (c != ' ') fr1 += c;
		}
		for (unsigned int q = 0; q < fr1.size(); ++q)
		{
			b = fr1.at(q);
			e = fr1.back();
			fr1.pop_back();
			if (b != e) ++r;
		}
		if (r > 0) cout << "NO\n";
		else cout << "SI\n";
		fr1 = "";
		r = 0;
		k = 0;
		getline(cin, frase);
	}
	return 0;
}