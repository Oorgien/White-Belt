#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void ShowV(vector<bool>& x) {
	for (auto s : x) {
		cout << s << " ";
	}
}

int WorryCount(vector<bool>& x) {
	int i;
	int k = 0;
	for (i = 0; i < x.size(); i++) {
		if (x[i] == 1) {
			k++;
		}
	}
	return k;
}

void MakeWorried(vector<bool>& x, int i) {
	x[i] = 1;
}

void MakeQuiet(vector<bool>& x, int i) {
	x[i] = 0;
}

void Add(vector<bool>& x, int i) {
	x.resize(x.size() + i);
}


int main(){
	vector<bool> v(0,0);
	int commands;
	cin >> commands;
	string command;
	int num;
	while (commands != 0) {
		commands--;
		cin >> command;
		if (command == "WORRY_COUNT") {
			cout << WorryCount(v) << endl;
			continue;
		}
		else if (command == "COME") {
			cin >> num;
			if (num > 0) {
				Add(v,num);
				//ShowV(v);
				continue;
			}
			else if (num < 0) {
				Add(v,num);
				//ShowV(v);
				continue;
			}
		}
		else if (command == "WORRY") {
			cin >> num;
			MakeWorried(v,num);
			//ShowV(v);
			continue;
		}
		else if (command == "QUIET") {
			cin >> num;
			MakeQuiet(v,num);
			//ShowV(v);
			continue;
		}
	}
	return 0;
}