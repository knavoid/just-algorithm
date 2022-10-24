#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int test, score, count[101] = { 0 };
		cin >> test;

		for (int j = 0; j < 1000; j++) {
			cin >> score;
			count[score]++;
		}

		int maxCount = *max_element(count, count + 101);
		for (int j = 101; j >= 0; j--) {
			if (count[j] == maxCount) {
				cout << '#' << test << ' ' << j << '\n';
				break;
			}
		}


	}

	return 0;
}