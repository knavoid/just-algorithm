#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, P, C;
		cin >> N;

		vector<int> A(N), B(N);
		for (int i = 0; i < N; i++)
			cin >> A[i] >> B[i];

		cin >> P;
		cout << '#' << t << ' ';
		for (int i = 0; i < P; i++) {
			int cnt = 0;
			cin >> C;
			for (int j = 0; j < N; j++)
				if (A[j] <= C && C <= B[j])
					cnt++;
			cout << cnt << ' ';
		}
		cout << '\n';
	}

	return 0;
}