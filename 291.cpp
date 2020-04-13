// bittorala
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct mot{
	string n;
	vector<int> pos;
};

ostream & operator<<(ostream & irt, vector<mot> hitzak){
	for (int i = 0; i < hitzak.size(); ++i){
		irt << hitzak[i].n << " ";
		for (int j = 0; j < hitzak[i].pos.size() - 1; ++j) irt << hitzak[i].pos[j] << " ";
		irt << hitzak[i].pos[hitzak[i].pos.size() - 1] << '\n';
	}
	irt << "----\n";
	return irt;
}

bool lessSt(string w1, string w2, bool & eq){
	int j = 0, msize = min(w1.size(), w2.size());
	while (j < msize){
		if (w1[j] < w2[j]) return true;
		else if (w1[j] > w2[j]) return false;
		++j;
	}
	if (w1 == w2) eq = true;
	else if (w1.substr(0, msize - 1) == w2.substr(0, msize - 1)) return w1.size() == msize;
	return false;
}

void vshift(vector<mot> & words, string const & hi, int ini, int i){
	words.push_back(words[words.size() - 1]);
	for (int j = words.size() - 2; j > ini; --j){
		words[j] = words[j - 1];
	}
	words[ini].n = hi;
	words[ini].pos.resize(1);
	words[ini].pos[0] = i;
}

void introduce(string hi, vector<mot> & words, int i){
	size_t ini = 0, fin = words.size(), half;
	bool found = false, eq;
	while (ini < fin && !found) {
		eq = false;
		half = (ini + fin -1) / 2;
		if(lessSt(hi,words[half].n,eq)) fin = half;
		else if(!eq) ini = half + 1;
		else found = true;
	}
	// Si es igual a otro no nos aseguraremos de que el words[half].pos.size() sea positivo, ya que ha de serlo
	if (found && words[half].pos[words[half].pos.size()-1] != i) words[half].pos.push_back(i);
	else if (!found) vshift(words,hi,ini,i);
}

void solvecase(int nlines){
	vector<mot> words; string hi; char ce = ' '; mot firstword;
	for (int i = 1; i <= nlines; ++i){
		while (ce != '\n'){
			cin >> hi; if (hi.size() > 2) {
				for (int j = 0; j < hi.size(); ++j) hi[j] = tolower(hi[j]);
				if(words.size()) introduce(hi, words, i);
				else{
					firstword.n = hi;
					firstword.pos = { i };
					words.push_back(firstword);
				}
			}
			cin.get(ce);
		}
		ce = ' ';
	}
	cout << words;
}

int main(){
	int nlines;
	cin >> nlines;
	while (nlines != 0) {
		solvecase(nlines); 
		cin >> nlines;
	}
	return 0;
}
