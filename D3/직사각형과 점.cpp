#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int X1, Y1, X2, Y2;
		int N, x, y;
		int case1 = 0, case2 = 0, case3 = 0;

		cin >> X1 >> Y1 >> X2 >> Y2 >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			if (X1 < x && x < X2 && Y1 < y && y < Y2)
				case1++;
			else if (x < X1 || X2 < x || y < Y1 || Y2 < y)
				case3++;
			else
				case2++;
		}

		cout << '#' << t << ' ';
		cout << case1 << ' ' << case2 << ' ' << case3 << '\n';
	}

	return 0;
}