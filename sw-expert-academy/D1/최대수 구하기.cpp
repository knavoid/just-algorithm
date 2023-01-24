#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<int> numbers(10);
		for (int i = 0; i < 10; i++)
			cin >> numbers[i];

		cout << '#' << t << ' ' << *max_element(numbers.begin(), numbers.end()) << '\n';
	}

	return 0;
}