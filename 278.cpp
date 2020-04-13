// bittor
#include <iostream>
using namespace std;
int main()
{
	int ncas = 0, dl = 0, hl = 0, ml = 0, sl = 0, th = 0, tm = 0, ts = 0; char x = ' ';
	cin >> ncas;
	for (int i = 0; i < ncas; ++i)
	{
		int stot = 0, stasks = 0;
		cin >> dl >> x >> hl >> x >> ml >> x >> sl;
		stot = 86400 * dl + 3600 * hl + 60 * ml + sl;
		cin >> th >> x >> tm >> x >> ts;
		while (th != 00 || tm != 00 || ts != 00)
		{
			stasks += (3600 * th + 60 * tm + ts);
			cin >> th >> x >> tm >> x >> ts;
		}
		if (stasks >= stot) cout << "NO\n";
		else cout << "SI\n";
	}
	return 0;
}