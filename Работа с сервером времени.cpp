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
	/* ƒл€ тестировани€ повставл€йте сюда код, реализующий различное поведение этой функии:
	   * нормальный возврат строкового значени€
	   * выброс исключени€ system_error
	   * выброс другого исключени€ с сообщением.
	*/

}

class TimeServer {
public:
	string GetCurrentTime() {
		/* –еализуйте этот метод:
			* если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
			* если AskTimeServer() бросила исключение system_error, верните текущее значение
			пол€ last_fetched_time
			* если AskTimeServer() бросила другое исключение, пробросьте его дальше.
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
	// ћен€€ реализацию функции AskTimeServer, убедитесь, что это код работает корректно
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	return 0;
}