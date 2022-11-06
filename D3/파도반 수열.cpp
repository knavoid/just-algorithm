#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<long> P{ 0, 1, 1, 1, 2 };
		for (int i = 5; i <= N; i++)
			P.push_back(P[i - 1] + P[i - 5]);

		cout << '#' << t << ' ' << P[N] << '\n';
	}

	return 0;
}