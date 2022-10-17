#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<int> numbers(10);
		for (int i = 0; i < 10; i++)
			cin >> numbers[i];

		sort(numbers.begin(), numbers.end());

		int sum = accumulate(numbers.begin() + 1, numbers.end() - 1, 0);
		int answer = round(sum / 8.0);

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}