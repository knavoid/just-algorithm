#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int N, answer = 0;
		cin >> N;

		vector<int> bd(N);
		for (int i = 0; i < N; i++)
			cin >> bd[i];

		for (int i = 2; i < N - 2; i++)
			answer += max(0, bd[i] - max(max(bd[i - 2], bd[i - 1]), max(bd[i + 1], bd[i + 2])));

		cout << '#' << tc << ' ' << answer << '\n';
	} 

	return 0;
}