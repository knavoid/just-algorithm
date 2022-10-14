#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T, N;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		vector<int> numbers(N);
		for (int i = 0; i < N; i++)
			cin >> numbers[i];

		sort(numbers.begin(), numbers.end());

		cout << '#' << t << ' ';
		for (int number : numbers)
			cout << number << ' ';
		cout << '\n';
	}

	return 0;
}