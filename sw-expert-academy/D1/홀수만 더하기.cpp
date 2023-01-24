#include <iostream>

using namespace std;

int main() {
	int N, number, sum;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			cin >> number;
			if (number % 2)
				sum += number;
		}
		cout << '#' << i << ' ' << sum << '\n';
	}

	return 0;
}