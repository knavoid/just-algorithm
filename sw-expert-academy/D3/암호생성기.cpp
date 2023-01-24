#include <iostream>
#include <queue>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		cin >> tc;

		int number;
		queue<int> pw;
		for (int i = 0; i < 8; i++) {
			cin >> number;
			pw.push(number);
		}

		int n = 1;
		while (pw.back() != 0) {
			pw.push(max(0, pw.front() - n));
			pw.pop();
			n = (n % 5) + 1;
		}

		cout << '#' << tc << ' ';
		while (!pw.empty()) {
			cout << pw.front() << ' ';
			pw.pop();
		}
		cout << '\n';
	}

	return 0;
}