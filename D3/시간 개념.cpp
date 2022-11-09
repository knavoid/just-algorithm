#include <iostream>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string time1, time2;
		cin >> time1 >> time2;

		// time1의 시, 분, 초
		int h1 = stoi(time1.substr(0, 2));
		int m1 = stoi(time1.substr(3, 2));
		int s1 = stoi(time1.substr(6, 2));

		// time2의 시, 분, 초
		int h2 = stoi(time2.substr(0, 2));
		int m2 = stoi(time2.substr(3, 2));
		int s2 = stoi(time2.substr(6, 2));

		// 남은 시간 계산
		int s = s2 - s1;
		if (s < 0) {
			s += 60;
			m2--;
		}
		int m = m2 - m1;
		if (m < 0) {
			m += 60;
			h2--;
		}
		int h = h2 - h1;
		if (h < 0)
			h += 24;

		// 결과 출력
		string answer = (h < 10 ? '0' + to_string(h) : to_string(h))
			+ ":" + (m < 10 ? '0' + to_string(m) : to_string(m))
			+ ":" + (s < 10 ? '0' + to_string(s) : to_string(s));
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}