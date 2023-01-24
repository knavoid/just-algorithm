#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string numbers;
		unordered_set<int> note;
		cin >> numbers;

		for (char c : numbers) {
			int n = c - '0';
			// n이 적혀있지 않은 경우
			if (note.find(n) == note.end())
				note.insert(n);
			// n이 이미 적혀있는 경우
			else
				note.erase(n);
		}

		cout << '#' << t << ' ' << note.size() << '\n';
	}

	return 0;
}