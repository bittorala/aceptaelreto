// Bittorala
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void walter(int num, int & gs){
	if (num / 10 == 0){
		gs += num;
		cout << num;
	}
	else{
		gs += num % 10;
		walter(num/10, gs);
		cout << " + " << num % 10;
	}
}

int main(){
	int num, gs = 0;
	cin >> num;
	while (num >= 0){
		walter(num,gs);
		cout << " = " << gs << '\n';
		gs = 0;
		cin >> num;
	}
	return 0;
}