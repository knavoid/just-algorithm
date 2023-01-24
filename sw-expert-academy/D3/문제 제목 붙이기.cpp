#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, cnt = 0;
		cin >> N;

		vector<string> titles(N);
		for (int i = 0; i < N; i++)
			cin >> titles[i];

		sort(titles.begin(), titles.end());

		for (int i = 0; i < N; i++) {
			int alpha = cnt + 'A';
			if (titles[i].front() < alpha)
				continue;
			else if (titles[i].front() > alpha)
				break;
			cnt++;
		}

		cout << '#' << t << ' ' << cnt << '\n';
	}

	return 0;
}