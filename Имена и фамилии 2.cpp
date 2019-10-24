#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

void Reverse(vector<string>& v) {
	int n = v.size();  // ��� �������� �������� ������ ������� � ���������� n
	for (int i = 0; i < n / 2; ++i) {
		// ������� � �������� i ����������� �������� � �������� n - 1 - i
		// �������� �� ������� � ������� ��������� ���������� tmp
		string tmp = v[i];
		v[i] = v[n - 1 - i];
		v[n - 1 - i] = tmp;
	}
}

struct FullName { //�������� ��������� �� ����� � �������
	string Name;
	string Soname;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		if (YearNameSoname.count(year) == 0) YearNameSoname[year].Soname = ""; //���� ������ ���� ��� ���, �� ������� ������ ������� � ���� ���
		YearNameSoname[year].Name = first_name; //������� ��������� ���
	}
	void ChangeLastName(int year, const string& last_name) {
		if (YearNameSoname.count(year) == 0) YearNameSoname[year].Name = ""; //���� ������ ���� ��� ���, �� ������� ������ ��� � ���� ���
		YearNameSoname[year].Soname = last_name; //� ������� ��������� �������
	}
	string GetFullName(int year) {
		if (YearNameSoname.size() == 0) { //���� ������ = 0
			return "Incognito"; //������� ���������
		}
		else { //�� ��� ���
			for (const auto& i : YearNameSoname) {
				if (year < i.first) return "Incognito"; //���� ������� ��� ������ ������� ���� ���������, ������� ���������
				break; //����� ������� �� �����
			}
		}
		//�����
		string nm = "";
		string sn = "";
		for (const auto& i : YearNameSoname) { //��������� ���� ���������, (�� ���� �������� ������� ������)
			//� ����� ����������� ���������� sn �������� �������, ���� ��� �� ������ � ���� ������� ��� ������ ��������(� ���������)
			if (i.first <= year && i.second.Soname != "") sn = i.second.Soname;
			//���� ����� � ������
			if (i.first <= year && i.second.Name != "") nm = i.second.Name;
		}
		if (nm == "") return sn + " with unknown first name"; //�������, ���� ��� ������(����� ������� � ������)
		else if (sn == "") return nm + " with unknown last name"; //�������, ���� ������� ����� (����� ����� � ������)
		else return nm + " " + sn; //����� ����� � �������
	}
	string GetFullNameWithHistory(int year) {
		// �������� ��� ����� � ������� �� ��������� �� ����� ���� year
		if (YearNameSoname.size() == 0) { //���� ������ = 0
			return "Incognito"; //������� ���������
		}
		else { //�� ��� ���
			for (const auto& i : YearNameSoname) {
				if (year < i.first) return "Incognito"; //���� ������� ��� ������ ������� ���� ���������, ������� ���������
				break; //����� ������� �� �����
			}
		}
		string nm = "";
		string sn = "";
		string resN;
		string resS;
		vector<string> Names, Surnames;
		for (const auto& i : YearNameSoname) {
			if (i.first <= year && nm != i.second.Name && i.second.Name != "") {
				nm = i.second.Name;
				Names.push_back(nm);//������ ���� ����, ��� ��������

			}
			if (i.first <= year && sn != i.second.Soname && i.second.Soname != "") {
				sn = i.second.Soname;
				Surnames.push_back(sn);//������ ���� �������, ��� �������

			}
		}
		if (Names.size() > 0) Names.pop_back();
		if (Surnames.size() > 0) Surnames.pop_back();
		if (Names.size() > 1) {
			for (int i = 0; i < Names.size() - 1; i++) {

				if (Names[i] == Names[i + 1]) {
					Names.erase(Names.begin() + i);//������� ��� � �������, ���� ��� ����������� ������� �� ������ ���

				}
			}
		}
		if (Surnames.size() > 1) {
			for (int i = 0; i < Surnames.size() - 1; i++) {

				if (Surnames[i] == Surnames[i + 1]) {
					Surnames.erase(Surnames.begin() + i);
				}
			
			}
		}
		Reverse(Names);
		Reverse(Surnames);//������������� ������� � ��������������� �������

		for (int i = 0; i < Names.size(); i++) {//������� ������ �� ��������
			if (Names.size() != 0) {
				if (i != Names.size()-1) resN += (Names[i] + ", ");
				else resN += Names[i];
			}
		}
		for (int i = 0; i < Surnames.size(); i++) {
			if (Surnames.size() != 0) {
				if (i != Surnames.size()-1) resS += (Surnames[i] + ", ");
				else resS += Surnames[i];
			}
		}

		if (Names.size() == 0) {
			if (Surnames.size() == 0) {
				if (nm == "") return sn + " with unknown first name";
				else if (sn == "") return nm + " with unknown last name";
				else return nm + " " + sn;
			}
			else if (Surnames.size() != 0) {
				if (nm == "") return sn + " (" + resS + ")" + " with unknown first name";
				else return nm + " " + sn + " (" + resS + ")";
			}
		}
		else if (Names.size() != 0) {
			if (Surnames.size() == 0) {
				if (sn == "") return nm + " (" + resN + ") " + " with unknown last name";
				else return nm + " (" + resN + ") " + sn;
			}
			else if (Surnames.size() != 0) {
				return nm + " (" + resN + ") " + sn + " (" + resS + ")";
			}
		}
	}
private: //������� � ��������� ������
	map<int, FullName> YearNameSoname; //��������� � ����� � ������ ������
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	
	cout << person.GetFullNameWithHistory(1900) << endl;
	cout << person.GetFullNameWithHistory(1965) << endl;
	cout << person.GetFullNameWithHistory(1990) << endl;
	
	person.ChangeFirstName(1970, "Appolinaria");
	cout << person.GetFullNameWithHistory(1969) << endl;
	cout << person.GetFullNameWithHistory(1970) << endl;

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {cout << person.GetFullNameWithHistory(year) << endl;}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {cout << person.GetFullNameWithHistory(year) << endl;}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
