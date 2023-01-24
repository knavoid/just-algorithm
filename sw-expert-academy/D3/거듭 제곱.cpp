#include <iostream>

using namespace std;

int power(int N, int M) {
	return M == 1 ? N : (M % 2 ? N * power(N * N, M / 2) : power(N * N, M / 2));
}

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		int N, M;
		cin >> tc >> N >> M;
		cout << '#' << tc << ' ' << power(N, M) << '\n';
	}

	return 0;
}