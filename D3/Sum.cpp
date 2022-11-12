#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		cin >> tc;

		int numbers[100][100];
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> numbers[i][j];

		int sum, answer = 0;

		// 가로 행의 합
		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++)
				sum += numbers[i][j];
			answer = max(sum, answer);
		}

		// 세로 행의 합
		for (int j = 0; j < 100; j++) {
			sum = 0; 
			for (int i = 0; i < 100; i++)
				sum += numbers[i][j];
			answer = max(sum, answer);
		}

		// 대각선 합
		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += numbers[i][i];
		answer = max(sum, answer);

		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += numbers[i][99 - i];
		answer = max(sum, answer);

		cout << '#' << tc << ' ' << answer << '\n';
	} 

	return 0;
}