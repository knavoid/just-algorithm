#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<string> cards(N);
		for (int i = 0; i < N; i++)
			cin >> cards[i];

		cout << '#' << t << ' ';
		int len = (N + 1) / 2;
		for (int i = 0; i < len; i++) {
			cout << cards[i] << ' ';
			if (i + len < N)
				cout << cards[i + len] << ' ';
		}
		cout << '\n';
	}

	return 0;
}