#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string answer;

void swapNumber(string number, int change) {

	if (change == 0) {
		answer = max(number, answer);
		return;
	}

	int pos = 0;
	int len = number.length();
	char maxNumber = *max_element(number.begin() + pos, number.end());

	// 가장 큰 숫자가 pos에 위치하면 pos 증가
	while (pos < len - 1 && number[pos] == maxNumber)
		maxNumber = *max_element(number.begin() + ++pos, number.end());

	// 현재 이미 최대 상금인 경우
	if (pos == len - 1) {
		bool unique = true; // 상금의 모든 숫자가 다른지 판단
		for (int i = 0; i < len - 1; i++) {
			if (number[i] == number[i + 1]) {
				unique = false;
				break;
			}
		}
		// 상금의 모든 숫자가 다르면 끝자리 2개를 교환
		if (unique) {
			string n = number;
			swap(n[len - 2], n[len - 1]);
			swapNumber(n, change - 1);
		}
		else
			swapNumber(number, change - 1);
	}
	else {
		// 가장 큰 값들과 모두 swap하여 비교
		for (int i = 0; i < len; i++) {
			if (number[i] == maxNumber) {
				string n = number;
				swap(n[pos], n[i]);
				swapNumber(n, change - 1);
			}
		}
	}

}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string number;
		int change;
		cin >> number >> change;
		
		answer.clear();
		swapNumber(number, change);

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}