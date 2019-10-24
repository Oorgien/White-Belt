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


class Rational {
public:
	Rational() {
		// Реализуйте конструктор по умолчанию
		Num = 0;
		Denom = 1;
	}

	Rational(int numerator, int denominator) {
		// Реализуйте конструктор
		if (denominator == 0) throw invalid_argument("Invalid argument");
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
	return Rational(a, b);
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator()==0) throw domain_error("Division by zero");
	int a = lhs.Numerator() * rhs.Denominator();
	int b = lhs.Denominator() * rhs.Numerator();
	return Rational(a, b);
}


ostream& operator<<(ostream& stream, const Rational& r) {
	stream << r.Numerator() << "/" << r.Denominator();
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
	int a, b, c, d;
	Rational res;
	char oper;
	cin >> a;
	cin.ignore(1);
	cin >> b;
	cin >> oper;
	cin >> c;
	cin.ignore(1);
	cin >> d;
	try {
		Rational(a, b);
		Rational(c, d);
	}
	catch (invalid_argument& ex) {
		cout << ex.what();
		return 0;
	}
	
	if (oper == '/') {
		try {
			res = Rational(a, b) / Rational(c, d);
		}
		catch
			(domain_error& ex) {
			cout << ex.what();
			return 0;
		}
	}
	else if (oper == '+') {
		res = Rational(a, b) + Rational(c, d);
	}
	else if (oper == '-') {
		res = Rational(a, b) - Rational(c, d);
	}
	else if (oper == '*') {
		res = Rational(a, b) * Rational(c, d);
	}
	cout << res;
}