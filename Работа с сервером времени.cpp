#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;


string AskTimeServer() {
	/* ��� ������������ ������������ ���� ���, ����������� ��������� ��������� ���� ������:
	   * ���������� ������� ���������� ��������
	   * ������ ���������� system_error
	   * ������ ������� ���������� � ����������.
	*/

}

class TimeServer {
public:
	string GetCurrentTime() {
		/* ���������� ���� �����:
			* ���� AskTimeServer() ������� ��������, �������� ��� � last_fetched_time � �������
			* ���� AskTimeServer() ������� ���������� system_error, ������� ������� ��������
			���� last_fetched_time
			* ���� AskTimeServer() ������� ������ ����������, ���������� ��� ������.
		*/
		try
		{
			last_fetched_time = AskTimeServer();
			return last_fetched_time;
		}
		catch (const system_error&)
		{
			return last_fetched_time;
		}
		catch (...) {
			throw;
		}
	}

private:
	string last_fetched_time = "00:00:00";
};

int main() {
	// ����� ���������� ������� AskTimeServer, ���������, ��� ��� ��� �������� ���������
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	return 0;
}