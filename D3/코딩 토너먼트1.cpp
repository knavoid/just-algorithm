#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int K, ability, boredom = 0;
		cin >> K;

		queue<int> abilities;
		for (int i = 0; i < pow(2, K); i++) {
			cin >> ability;
			abilities.push(ability);
		}

		while (abilities.size() > 1) {
			int ab1 = abilities.front();
			abilities.pop();
			int ab2 = abilities.front();
			abilities.pop();

			abilities.push(max(ab1, ab2));
			boredom += abs(ab1 - ab2);
		}

		cout << '#' << t << ' ' << boredom << '\n';
	}

	return 0;
}