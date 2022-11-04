#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMonotonousIncrease(int n) {

	string str = to_string(n);
	int len = str.length();
	for (int i = 0; i < len - 1; i++)
		if (str[i] > str[i + 1])
			return false;

	return true;
}

int main() {

	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		int N, answer = -1;
		cin >> N;

		vector<int> numbers(N);
		for (int i = 0; i < N; i++)
			cin >> numbers[i];

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				int value = numbers[i] * numbers[j];
				if (isMonotonousIncrease(value))
					answer = max(answer, value);
			}
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}