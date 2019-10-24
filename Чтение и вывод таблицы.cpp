#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main() {
	ifstream input("input.txt");
	string line,N,M;
	getline(input, N, ' ');
	getline(input, M);
	int n = atoi(N.c_str());
	int m = atoi(M.c_str());
	while (n > 0) {
		n--;
		for (int i = m; i > 0; i--) {
			if (i == 1) {
				getline(input, line);
				int tmp = atoi(line.c_str());
				//cout << setfill('.');
				cout << setw(10) << tmp;
			}
			else {
				getline(input, line, ',');
				int tmp = atoi(line.c_str());
				//cout << setfill('.');
				cout << setw(10) << tmp << ' ';
			}
		}
		if (n != 0) {
			cout << endl;
		}
	}
	return 0;
}