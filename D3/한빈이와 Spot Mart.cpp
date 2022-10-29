#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M, answer = -1;
		cin >> N >> M;

		vector<int> a(N);
		for (int i = 0; i < N; i++)
			cin >> a[i];

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				int w = a[i] + a[j];
				if (answer < w && w <= M)
					answer = w;
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}