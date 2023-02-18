#include <iostream>

using namespace std;

int T, N;
int now; // 현재까지 본 숫자의 값 (비트)
int target = (1 << 10) - 1; // 모든 숫자를 볼때의 값 (비트)

int main() {

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		// initialize
		cin >> N;
		now = 0;

		// solution
		int count = 0;
		while (now != target) {
			int number = N * ++count;
			while (number) {
				now |= (1 << (number % 10));
				number /= 10;
			}
		}
		
		// result
		cout << '#' << tc << ' ' << N * count << '\n';
	}

	return 0;
}