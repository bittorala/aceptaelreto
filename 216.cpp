#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int ncas = 0;
	cin >> ncas;
	for (int i = 0; i < ncas; ++i)
	{
		int hor = 0, min = 0, seg = 0;
		cin >> seg;
			min = seg / 60;
			seg = seg % 60;
			hor = min / 60;
			min = min % 60;
			cout << setw(2) << setfill('0') << hor << ':';
			cout << setw(2) << setfill('0') << min << ':';
			cout << setw(2) << setfill('0') << seg << '\n';
	}
	return 0;
}