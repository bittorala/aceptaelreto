// bittorala
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void resuelve(int nkings){
	unordered_map<string, int> kings;
	unordered_map<string, int>::iterator it;
	string aux;
	for (int i = 0; i < nkings; ++i){
		cin >> aux;
		it = kings.find(aux);
		if (it == kings.end()) kings.insert({ aux, 1 });
		else ++it->second;
	}
	int nHeirs;
	cin >> nHeirs;
	for (int j = 0; j < nHeirs; ++j){
		cin >> aux;
		it = kings.find(aux);
		if (it == kings.end()) it = kings.insert({ aux, 0 }).first;
		cout << ++it->second << '\n';
	}
	cout << '\n';
}

int main(){
	int nkings;
	cin >> nkings;
	while (nkings != 0){
		resuelve(nkings);
		cin >> nkings;
	}
	return 0;
}