#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n, m, car, income = 0;
		cin >> n >> m;

		vector<int> parkingLot(n); // 주차장 이용

		vector<int> R(n), W(m);
		for (int i = 0; i < n; i++)
			cin >> R[i];
		for (int i = 0; i < m; i++)
			cin >> W[i];

		queue<int> wait;
		for (int i = 0; i < 2 * m; i++) {
			cin >> car;
			if (car > 0) { // 주차장에 들어옴
				bool parking = false;
				for (int j = 0; j < n; j++) {
					if (parkingLot[j] == 0) {
						parkingLot[j] = car;
						parking = true;
						break;
					}
				}
				// 주차하지 못한 경우 대기
				if (!parking)
					wait.push(car);
			} 
			else { // 주차장에서 나감
				int loc = -1;
				for (int j = 0; j < n; j++) {
					if (parkingLot[j] == -car) {
						parkingLot[j] = 0;
						loc = j;
						break;
					}
				}
				// 대기 차량이 있는 경우 주차 
				if (!wait.empty()) {
					parkingLot[loc] = wait.front();
					wait.pop();
				}
				
				// 주차 요금 정산
				income += R[loc] * W[-car - 1];
			}
		}

		cout << '#' << t << ' ' << income << '\n';
	}

	return 0;
}