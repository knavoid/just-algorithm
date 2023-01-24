#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int angle;
		cin >> angle;

		int hour = angle / 30;
		int minute = angle * 2 % 60;

		cout << '#' << t << ' ' << hour << ' ' << minute << '\n';
	}

	return 0;
}