#include <iostream>
#include <string>

using namespace std;

int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 유효성 판단
bool validate(int year, int month, int day) {	

	if (!(1 <= month && month <= 12))
		return false;

	if (!(1 <= day && day <= days[month - 1]))
		return false;

	return true;
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string date;
		cin >> date;

		string year = date.substr(0, 4);
		string month = date.substr(4, 2);
		string day = date.substr(6, 2);

		cout << '#' << t << ' ';
		validate(stoi(year), stoi(month), stoi(day)) ?
			cout << year << '/' << month << '/' << day << '\n' :
			cout << - 1 << '\n';
	}

	return 0;
}