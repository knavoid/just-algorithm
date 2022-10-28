#include <iostream>
#include <list>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, day, answer = 0;
		cin >> N;

		list<int> happy;
		for (int i = 0; i < N; i++) {
			cin >> day;
			happy.push_back(day);
		}

		happy.pop_front();
		while (!happy.empty()) {
			int gap = *happy.begin() - 1;
			happy.remove_if([&](int x) { return x % gap == 1; });
			answer++;
		}

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}