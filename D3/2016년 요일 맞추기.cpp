#include <iostream>

using namespace std;

int main() {

	int T;
	int days[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int m, d;
		cin >> m >> d;

		int answer = 4; // 금요일로 시작

		// 월 계산
		for (int i = 0; i < m - 1; i++)
			answer += days[i];

		// 일 계산
		answer += d - 1;

		cout << '#' << tc << ' ' << answer % 7 << '\n';
	}

	return 0;
}