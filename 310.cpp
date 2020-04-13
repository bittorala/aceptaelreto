// bittor
#include <iostream>
using namespace std;

void recurs(int semal, int & max, int h){
	int aux;
	if (semal != 0){
		++h;
		if (h > max) max = h;
		for (int i = 0; i < semal; ++i){
			cin >> aux;
			recurs(aux, max, h);
		}
	}
}

void ebatzi(){
	int semal, max = 1, h = 1;
	cin >> semal;
	recurs(semal,max,h);
	cout << max << '\n';
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) ebatzi();
	return 0;
}