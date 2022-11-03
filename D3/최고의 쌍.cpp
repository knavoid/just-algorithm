#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 주어진 숫자가 연속적으로 증가하는지 판단
bool isCoutinuouslyIncreasing(int n) {

	string str = to_string(n);
	int len = str.length();
	char first = str.front();
	
	for (int i = 1; i < len; i++)
		if (str[i] != i + first)
			return false;

	return true;
}

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, answer = -1;
		cin >> N;

		vector<int> numbers(N);
		for (int i = 0; i < N; i++)
			cin >> numbers[i];

		for (int i = 0; i < N - 1; i++) 
			for (int j = i + 1; j < N; j++) 
				if (isCoutinuouslyIncreasing(numbers[i] * numbers[j]))
					answer = max(answer, numbers[i] * numbers[j]);

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}