#include <iostream>
#include <climits>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int numbers[10];
		int maxValue = INT_MIN;
		int minValue = INT_MAX;
			
		for (int i = 0; i < 10; i++)
			cin >> numbers[i];

		for (int number : numbers) {
			int sum = 0;
			while (number) {
				sum += number % 10;
				number /= 10;
			}
			maxValue = max(sum, maxValue);
			minValue = min(sum, minValue);
		}

		cout << '#' << t << ' ' << maxValue << ' ' << minValue << '\n';
	}

	return 0;
}