#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;
		
		int s = 1; // 실력
		vector<int> answer(K);
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0)
				for (int j = 0; j < K; j++)
					answer[j] += s++;
			else
				for (int j = K - 1; j >= 0; j--)
					answer[j] += s++;
		}

		cout << '#' << tc << ' ';
		for (int n : answer)
			cout << n << ' ';
		cout << '\n';
	}

	return 0;
}