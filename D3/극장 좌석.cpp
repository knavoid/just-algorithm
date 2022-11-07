#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, answer;
		cin >> N;

		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];

		// 오름차순 정렬 (인접한 수의 차이를 최소화 하기 위함)
		sort(A.begin(), A.end());

		// 인원 수 + A의 전체합 + 맨 마지막 값
		answer = accumulate(A.begin(), A.end(), N + A.back());

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}