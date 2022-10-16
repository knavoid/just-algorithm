#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, velocity = 0, distance = 0;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int command, accel;
			cin >> command;
			if (command) {
				cin >> accel;
				if (command == 1)
					velocity += accel;
				else
					velocity = max(0, velocity - accel);
			}
			distance += velocity;
		}

		cout << '#' << t << ' ' << distance << '\n';
	}

	return 0;
}