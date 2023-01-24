#include <iostream>
#include <vector>

using namespace std;

void printPascal(int N) {
	
	vector<vector<int>> triangle(N, { 1 });

	// 삼각형 채우기
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			if (i == j)
				triangle[i].push_back(1);
			else
				triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
		}
	}

	// 삼각형 출력
	for (auto v : triangle) {
		for (int n : v)
			cout << n << ' ';
		cout << '\n';
	}
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		cout << '#' << t << '\n';
		printPascal(N);
	}

	return 0;
}