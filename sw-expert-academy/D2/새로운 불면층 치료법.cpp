#include <iostream>
#include <set>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, cnt = 0;
		set<int> numbers;
		cin >> N;

		while (numbers.size() != 10) {
			int number = N * (cnt + 1);
			while (number) {
				numbers.insert(number % 10);
				number /= 10;
			}
			cnt++;
		}

		cout << '#' << t << ' ' << N * cnt << '\n';
	}

	return 0;
}