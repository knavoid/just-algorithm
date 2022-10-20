#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		long long answer = 0;
		cin >> N;

		vector<int> prices(N);
		for (int i = 0; i < N; i++)
			cin >> prices[i];

		int maxPrice = prices.back();
		for (int i = N - 2; i >= 0; i--) {
			int price = prices[i];
			if (price < maxPrice)
				answer += maxPrice - price;
			else if (price > maxPrice)
				maxPrice = price;
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}