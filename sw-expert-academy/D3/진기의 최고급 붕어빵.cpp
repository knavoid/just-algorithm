#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M, K;
		bool possible = true;
		cin >> N >> M >> K;

		vector<int> time(N);
		for (int i = 0; i < N; i++)
			cin >> time[i];
		// 도착한 시간을 오름차순 정렬
		sort(time.begin(), time.end());

		for (int i = 0; i < N; i++) {
			int t = time[i]; // 도착한 시간
			int b = t / M * K; // 그 시간까지 만든 총 붕어빵의 수
			if (b <= i) { // 붕어빵 수가 충족되지 않은 경우
				possible = false;
				break;
			}
		}

		cout << '#' << tc << ' ';
		possible ? cout << "Possible\n" : cout << "Impossible\n";
	}

	return 0;
}