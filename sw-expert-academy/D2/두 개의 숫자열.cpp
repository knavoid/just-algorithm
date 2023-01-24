#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMax(vector<int> x, vector<int> y) {  
	int maxValue = INT_MIN;
	int N = x.size(), M = y.size();  // N >= M
	int K = N - M + 1;  // 비교 횟수

	for (int i = 0; i < K; i++) {
		int value = 0;
		for (int j = 0; j < M; j++)
			value += x[i + j] * y[j];

		maxValue = max(value, maxValue);
	}

	return maxValue;
}

int main()
{
	int T, N, M;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		vector<int> A(N), B(M);
		
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];
		
		int answer = N > M ? getMax(A, B) : getMax(B, A);
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}