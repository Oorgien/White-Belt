#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
/*
void PrintMap(map<int,vector<string>> m) {
	for (auto item : m) {
		cout << item.first << ": ";
		for (auto item1 : item.second) {
			cout << item1 << " ";
		}
		cout << endl;
	}
}

void PrintVector(vector<string> v) {
	for (auto item : v) {
		cout << item << " ";
	}
	cout << endl;
}
*/
struct Names {
	string Name;
	string Surname;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
		if (Years.count(year) == 0) Years[year].Surname = "";
		Years[year].Name = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
		if (Years.count(year) == 0) Years[year].Name = "";
		Years[year].Surname = last_name;
	}
	string GetFullName(int year) {
		if (Years.size() == 0) { //если размер = 0
			return "Incognito"; //выводим Инкогнито
		}
		else { //ну или так
			for (const auto& i : Years) {
				if (year < i.first) return "Incognito"; //если искомый год меньше первого года изменения, выводим Инкогнито
				break; //сразу выходим из цикла
			}
		}
		//иначе
		string nm = "";
		string sn = "";
		for (const auto& i : Years) { //полистаем нашу структуру, (не стал отдельно функцию делать)
			//и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в структуре)
			if (i.first <= year && i.second.Surname != "") sn = i.second.Surname;
			//тоже самое с именем
			if (i.first <= year && i.second.Name != "") nm = i.second.Name;
		}
		if (nm == "") return sn + " with unknown first name"; //условие, если имя пустое(вывод фамилии и текста)
		else if (sn == "") return nm + " with unknown last name"; //условие, если фамилия пуста (вывод имени и текста)
		else return nm + " " + sn; //вывод имени и фамилии
		// получить имя и фамилию по состоянию на конец года year
	}
private:
	// приватные поля
	map<int, Names> Years;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}

