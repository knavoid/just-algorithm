#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;

		vector<int> numbers(N);
		for (int i = 0; i < N; i++)
			cin >> numbers[i];

		// numbers에서의 합의 수
		vector<int> sumCount(K + 1);
		sumCount[0] = 1;
		for (int n : numbers)
			for (int i = K; i >= n; i--)
				sumCount[i] += sumCount[i - n];

		cout << '#' << tc << ' ' << sumCount[K] << '\n';
	}

	return 0;
}