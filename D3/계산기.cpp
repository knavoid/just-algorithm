#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, num, answer;
		cin >> N >> answer;

		for (int i = 0; i < N - 1; i++) {
			cin >> num;
			answer = max(answer + num, answer * num);
		}

		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}