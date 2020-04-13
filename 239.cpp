// bittorala
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int nrad = 0, ndias = 0;
	cin >> ndias >> nrad;
	while (ndias != 0 || nrad != 0)
	{
		int segs = 0, mins = 0, hors = 0, dias = 0;
		segs = 24 * 6 * ndias * nrad;
		if (segs >= 60)
		{
			mins = segs / 60;
			segs = segs % 60;
		}
		if (mins >= 60)
		{
			hors = mins / 60;
			mins = mins % 60;
		}
		if (hors >= 24)
		{
			dias = hors / 24;
			hors = hors % 24;
		}
		cout << dias << ':';
		cout << setw(2) << setfill('0') << hors << ':';
		cout << setw(2) << setfill('0') << mins << ':';
		cout << setw(2) << setfill('0') << segs << '\n';
		cin >> ndias >> nrad;
	}
	return 0;
}