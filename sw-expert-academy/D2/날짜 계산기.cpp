#include <iostream>

using namespace std;

int main() {

	int T;
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int m1, d1, m2, d2, answer = 0;
		cin >> m1 >> d1 >> m2 >> d2;

		// 월 계산
		for (int i = m1; i < m2; i++) 
			answer += days[i - 1];
		
		// 일 계산
		answer += d2 - d1;
	
		cout << '#' << t << ' ' << answer + 1 << '\n';
	}

	return 0;
}