#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		int d, answer;
		cin >> d;

		if (0 <= d && d < 100)
			answer = 0;
		else if (100 <= d && d < 1000)
			answer = 1;
		else if (1000 <= d && d < 10000)
			answer = 2;
		else if (10000 <= d && d < 100000)
			answer = 3;
		else if (100000 <= d && d < 1000000)
			answer = 4;
		else
			answer = 5;

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}