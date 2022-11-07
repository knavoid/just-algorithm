#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int num; // 분자
		int den = 1; // 분모
		string str, dir;
		cin >> str;

		// 초기 각도 설정
		int pos1 = str.rfind("north");
		int pos2 = str.rfind("west");
		dir = str.substr(max(pos1, pos2));
		str = str.substr(0, str.length() - dir.length());
		num = (dir == "north") ? 0 : 90;

		int n = 1; // 현재까지 등장한 "north" "west" 수의 합
		while (!str.empty()) {
			pos1 = str.rfind("north");
			pos2 = str.rfind("west");
			dir = str.substr(max(pos1, pos2));
			str = str.substr(0, str.length() - dir.length());

			if (dir == "north")
				num = num * pow(2, n) / den - 90;
			else // dir == "west"
				num = num * pow(2, n) / den + 90;
			den = pow(2, n++);

			// 분자와 분모 약분
			while (num % 2 == 0 && den % 2 == 0) {
				num /= 2;
				den /= 2;
			}
		}

		cout << '#' << tc << ' ';
		den == 1 ? cout << num : cout << num << '/' << den;
		cout << '\n';
	}

	return 0;
}