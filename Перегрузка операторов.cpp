#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

struct Rational {
public:
	Rational() {
		// Реализуйте конструктор по умолчанию
		Num = 0;
		Denom = 1;
	}

	Rational(int numerator, int denominator) {
		// Реализуйте конструктор
		int res;
		Num = numerator;
		Denom = denominator;
		int a = abs(numerator);
		int b = abs(denominator);
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}
		res = a + b;
		Num /= res;
		Denom /= res;
		if (denominator < 0) {
			Num = -Num;
			Denom = -Denom;
		}
	}

	int Numerator() const {
		// Реализуйте этот метод
		return Num;
	}

	int Denominator() const {
		// Реализуйте этот метод
		return Denom;
	}
private:
	int Num;// Добавьте поля
	int Denom;
};

// реализация ==, - , +
Rational operator+ (const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator() * rhs.Denominator();//левый числитель
	int b = rhs.Numerator() * lhs.Denominator(); // правый числитель
	int c = lhs.Denominator() * rhs.Denominator();//общий знаменатель
	return Rational(a + b, c);
}

Rational operator- (const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator() * rhs.Denominator();//левый числитель
	int b = rhs.Numerator() * lhs.Denominator(); // правый числитель
	int c = lhs.Denominator() * rhs.Denominator();//общий знаменатель
	return Rational(a - b, c);
}

bool operator== (const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator() * rhs.Denominator();//левый числитель
	int b = rhs.Numerator() * lhs.Denominator(); // правый числитель
	int c = lhs.Denominator() * rhs.Denominator();//общий знаменатель
	return a == b;
}

Rational operator* (const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator() * rhs.Numerator();
	int b = lhs.Denominator() * rhs.Denominator();
	return Rational(a,b);
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator() * rhs.Denominator();
	int b = lhs.Denominator() * rhs.Numerator();
	return Rational(a, b);
}


ostream& operator<<(ostream& stream,const Rational& r) {
	stream << r.Numerator() <<"/" << r.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& r) {
	int a, b;
	if (stream.tellg() == -1) {
		return stream;
	}
	else {
		stream >> a;
		stream.ignore(1);
		stream >> b;
		r = { a,b };
		return stream;
	}
}

bool operator< (const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator() * rhs.Denominator();//левый числитель
	int b = rhs.Numerator() * lhs.Denominator(); // правый числитель
	int c = lhs.Denominator() * rhs.Denominator();//общий знаменатель
	return a < b;
}

int main() {
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}