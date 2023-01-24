#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int K, number;
		vector<int> book;
		cin >> K;

		for (int i = 0; i < K; i++) {
			cin >> number;
			if (number != 0)
				book.push_back(number);
			else
				book.pop_back();
		}

		cout << '#' << t << ' ' << accumulate(book.begin(), book.end(), 0) << '\n';
	}

	return 0;
}