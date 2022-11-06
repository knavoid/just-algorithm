#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<int> numbers(N);
		for (int i = 0; i < N; i++)
			cin >> numbers[i];

		vector<int> dp(N);
		for (int i = 0; i < N; i++) {
			int value = numbers[i], maxValue = 0;
			for (int j = 0; j < i; j++) 
				if (numbers[j] < value)
					maxValue = max(dp[j], maxValue);
			dp[i] = maxValue + 1;
		}

		int answer = *max_element(dp.begin(), dp.end());
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}