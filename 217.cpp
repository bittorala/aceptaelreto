#include <iostream>
using namespace std;
int main()
{
	int num = 0;
	cin >> num;
	while (num != 0)
	{
		if (num % 2 == 0) cout << "DERECHA\n";
		else cout << "IZQUIERDA\n";
		cin >> num;
	}
	return 0;
}