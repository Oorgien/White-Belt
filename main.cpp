#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> b = v;
	reverse(b.begin(), b.end());
	return b;
}