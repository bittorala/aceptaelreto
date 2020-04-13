// bittorala
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
const float cd = 2;
int main()
{
	vector<float> puntuaciones(7), medias(3); float puntu = 0, final = 0;
	while (cin >> puntu)
	{
		puntuaciones[0] = puntu; for (int i = 1; i < 7; ++i)	{ cin >> puntu; puntuaciones[i] = puntu; }
		sort(puntuaciones.begin(), puntuaciones.end());
		medias[0] = puntuaciones[2]; medias[1] = puntuaciones[3]; medias[2] = puntuaciones[4];
		final = cd * (medias[0] + medias[1] + medias[2]);
		cout << fixed << setprecision(0) << final << '\n';
	}
		return 0;
}