#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	int T;
	string S;
	unordered_map<string, int> week = {
		{"SUN", 7}, {"MON", 6}, {"TUE", 5}, {"WED", 4}, {"THU", 3}, {"FRI", 2}, {"SAT", 1}
	};

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> S;
		cout << '#' << t << ' ' << week[S] << '\n';
	}

	return 0;
}