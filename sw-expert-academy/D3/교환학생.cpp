#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n, answer = 0;
		int classInfo[7];
		cin >> n;
		for (int i = 0; i < 7; i++)
			cin >> classInfo[i];
		
		// 시작하는 요일에 상관없이 소요되는 일수 계산
		int classCount = count(classInfo, classInfo + 7, 1);
		answer += (n - 1) / classCount * 7;
		n = (n - 1) % classCount + 1;

		// 시작하는 요일에 따라 소요되는 일수 계산
		int days[7] = { 0 };
		for (int i = 0; i < 7; i++) {
			int w = i, cnt = 0, day = 0;
			while (cnt < n) {
				if (classInfo[w] == 1) 
					cnt++;
				w = (w + 1) % 7;
				day++;
			}
			days[i] = day;
		}
		answer += *min_element(days, days + 7);

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}