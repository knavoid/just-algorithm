#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T, number;
	double sum;

	cin >> T;

	for (int i = 1; i <= T; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			cin >> number;
			sum += number;
		}
		cout << '#' << i << ' ' << round(sum / 10) << '\n';
	}

	return 0;
}