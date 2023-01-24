#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		vector<int> hay(N);
		for (int i = 0; i < N; i++)
			cin >> hay[i];

		int gapSum = 0;
		int avg = accumulate(hay.begin(), hay.end(), 0) / N;
		for (int h : hay)
			gapSum += abs(h - avg);

		int answer = gapSum / 2;
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}