#include <iostream>
using namespace std;
int main()
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	while (x2 >= x1 && y2 >= y1)
	{
		int sol = 0;
		sol = (x2 - x1) * (y2 - y1);
		cout << sol << '\n';
		cin >> x1 >> y1 >> x2 >> y2;
	}
	return 0;
}