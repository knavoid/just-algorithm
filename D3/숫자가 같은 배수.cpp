#include <iostream>
#include <set>
#include <string>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		bool possible = false;
		cin >> N;

		multiset<int> setN;
		for (char c : to_string(N))
			setN.insert(c - '0');

		int len = to_string(N).length();
		int limit = pow(10, len);

		for (int M = 2 * N; M < limit; M += N) {
			multiset<int> setM;
			for (char c : to_string(M))
				setM.insert(c - '0');

			if (setN == setM) {
				possible = true;
				break;
			}
		}

		cout << '#' << t << ' ';
		possible ? cout << "possible" : cout << "impossible";
		cout << '\n';
	}

	return 0;
}