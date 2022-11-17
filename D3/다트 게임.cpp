#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, x, y;
		int answer = 0;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			long double r = sqrt(x * x + y * y);
			if (r == 0)
				answer += 10;
			else if (r <= 200)
				answer += 11 - (r / 20);
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}