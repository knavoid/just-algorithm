#include <iostream>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int answer = 0;
		int N, table[100][100];
		cin >> N;
		for (int i = 0; i < 100; i++) 
			for (int j = 0; j < 100; j++)
				cin >> table[i][j];

		// 1은 N극 (아래로 이동), 2는 S극 (위로 이동)
		for (int j = 0; j < 100; j++) {
			int flag = 0; // 1: N, 0: S;
			for (int i = 0; i < 100; i++) {
				// flag가 0인 상태에서 N극을 만난 경우
				if (table[i][j] == 1 && !flag) 
					flag = 1;
				// flag가 1인 상태에서 S극을 만난 경우
				else if (table[i][j] == 2 && flag) {
					flag = 0;
					answer++; // 교착 상태로 판단
				}
			}
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}