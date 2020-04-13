// bittor
#include <iostream>
#include <string>
using namespace std;

string recurs(int nchoc, int nvan, string pre){
	if (nchoc == 0 && nvan == 0) return " ";
	else if (nchoc != 0 && nvan == 0){
		string aux = pre; for (int i = 0; i < nchoc; ++i) aux += "C";
		return aux + " ";
	}
	else if (nchoc == 0 && nvan != 0){
		string aux = pre; for (int i = 0; i < nvan; ++i) aux += "V";
		return aux + " ";
	}
	else{
		return recurs(nchoc - 1, nvan,pre + "C") + recurs(nchoc,nvan-1,pre + "V");
	}
	return "";
}

void solvecase(){
	int nchoc, nvan; string izzz;
	cin >> nchoc >> nvan;
	izzz = recurs(nchoc, nvan, "");
	cout << izzz.substr(0, izzz.size() - 1) << '\n';
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solvecase();
	return 0;
}