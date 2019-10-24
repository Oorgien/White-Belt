#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString (const string& new_string) {
		s = new_string;
	}
	void Reverse(){
		int n = s.size();
		for (int i = 0; i < n / 2; i++) {
			char tmp = s[i];
			s[i] = s[n - i - 1];
			s[n - i - 1] = tmp;
		}
	}
	string ToString() const{
		return s;
	}
private:
	string s;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}