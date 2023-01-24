#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		long long A, B;
		cin >> A >> B;

		long long answer = (A / B) * (A / B);
		cout << '#' << tc << ' ' << answer << '\n';
	}
	
	return 0;
}