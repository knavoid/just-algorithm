#include <iostream>

using namespace std;

int main() {
	
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		int arr[7][7];
		int arr90[7][7], arr180[7][7], arr270[7][7];
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];

		// 90도 회전
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				arr90[i][j] = arr[N - j - 1][i];

		// 180도 회전 
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				arr180[i][j] = arr[N - i - 1][N - j - 1];

		// 270도 회전
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				arr270[i][j] = arr[j][N - i - 1];


		// 결과 출력
		cout << '#' << t << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cout << arr90[i][j];
			cout << ' ';
			for (int j = 0; j < N; j++)
				cout << arr180[i][j];
			cout << ' ';
			for (int j = 0; j < N; j++)
				cout << arr270[i][j];
			cout << '\n';
		}
	}

	return 0;
}