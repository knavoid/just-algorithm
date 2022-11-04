#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		long long N, answer = -1;
		cin >> N;

		long long begin = floor(pow(N, 0.3333));
		long long end = ceil(pow(N, 0.3334));
		for (long long n = begin; n <= end; n++) {
			if (pow(n, 3) == N) {
				answer = n;
				break;
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}