#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int score, sum = 0;

		for (int i = 0; i < 5; i++) {
			cin >> score;
			score < 40 ? sum += 40 : sum += score;
		}

		cout << '#' << t << ' ' << sum / 5 << '\n';
	}

	return 0;
}