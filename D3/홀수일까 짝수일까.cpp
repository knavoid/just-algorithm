#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string number;
		cin >> number;

		// 마지막 자릿수 가져오기
		int last = number.back() - '0';
		string answer = last % 2 ? "Odd" : "Even";

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}