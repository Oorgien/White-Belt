#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int current = 0;

void ShowV(vector<vector<string>>& x) {
	for (auto s : x) {
		for (auto c : s) {
			cout << c << " ";
		}
	}
}

void ADD(vector<vector<string>>& x, string s, int i) {
	x[i-1].push_back(s);
	
}

void NEXT(vector<vector<string>>& y) {
	const vector<int> x = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i = current;
	int n = x[i]-1;
	if (current == 11) {
		current = -1;
		y.resize(31);
		//cout << y.size();
	}
	
	else if (x[i] > x[i + 1]) {
		vector<string> tmp;
		while (n > (x[i + 1] - 1)) {
			for (auto k : y[n]) {
				tmp.push_back(k);
			}
			--n;
		}
	y.resize(n+1);
	y[n].insert(end(y[n]), begin(tmp), end(tmp));
	//cout << y.size();
	} else {
		y.resize(x[i+1]);
		//cout << y.size();
	}
	++current;
	
}

void DUMP(vector<vector<string>>& x, int i) {
	/*int k;
	for (k = 0; k < x.size(); k++) {
		if (k != (i - 1)) {
			x[i - 1].insert(end(x[i - 1]), begin(x[k]), end(x[k]));
		}
	}
	cout << endl << x[i-1].size() << " ";
	for (auto item : x[i-1]) {
		cout << item << " ";
	}*/
	cout << x[i - 1].size()<< " ";
	for (auto item : x[i-1]) {
		
		cout << item << " ";
	}
	cout << endl;
}

int main(){
	vector<vector<string>> Dela(31);
	int commands;
	cin >> commands;
	string command;
	while (commands != 0) {
		commands--;
		cin >> command;
		if (command == "ADD") {
			int i;
			string s;
			cin >> i >> s;
			ADD(Dela, s, i);
			//ShowV(Dela);
			continue;
		}
		else if (command == "NEXT") {
			NEXT(Dela);
			//ShowV(Dela);
			continue;
		}
		else if (command == "DUMP") {
			int i;
			cin >> i;
			DUMP(Dela, i);
		}
	}
	return 0;
}
	
