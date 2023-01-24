#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, Q, L, R;
		cin >> N >> Q;

		vector<int> boxes(N);
		for (int i = 1; i <= Q; i++) {
			cin >> L >> R;
			for (int j = L - 1; j < R; j++)
				boxes[j] = i;
		}

		cout << '#' << t << ' ';
		for (int i = 0; i < N; i++)
			cout << boxes[i] << ' ';
		cout << '\n';
	}

	return 0;
}