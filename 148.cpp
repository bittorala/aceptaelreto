// bittorala
#include <iostream>
using namespace std;
const int MINSDIA = 1440;
int main(){
	int mins, hors; char aux;
	cin >> hors >> aux >> mins;
	while(hors != 00 || mins != 00){
	cout << MINSDIA - hors * 60 - mins << '\n';
	cin >> hors >> aux >> mins;	
	}
return 0;
}