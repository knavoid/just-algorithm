#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, answer = 0;
		cin >> N;

		vector<int> num(N);
		for (int i = 0; i < N; i++)
			cin >> num[i];

		for (int i = 1; i < N - 1; i++)
			if ((num[i - 1] < num[i] && num[i] < num[i + 1])
				|| (num[i + 1] < num[i] && num[i] < num[i - 1]))
				answer++;

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}