#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		vector<int> numbers(N);
		for (int i = 0; i < N; i++) {
			cin >> numbers[i];
			if (i > 0)
				numbers[i] += max(0, numbers[i - 1]);
		}
		
		int answer = *max_element(numbers.begin(), numbers.end());
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}