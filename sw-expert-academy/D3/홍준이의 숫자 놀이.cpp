#include <iostream>

using namespace std;

pair<int, int> egcd(int A, int B) {

	int q, r, m, n;
	int x = 0, y = 1, u = 1, v = 0;
	while (A) {
		q = B / A;
		r = B % A;
		m = x - u * q;
		n = y - v * q;

		B = A, A = r;
		x = u, y = v;
		u = m, v = n;
	}
	
	return make_pair(x, y);
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int A, B, x, y;
		cin >> A >> B;

		pair<int, int> p = egcd(A, B);
		x = p.first, y = p.second;

		cout << '#' << tc << ' ';
		cout << x << ' ' << y << '\n';
	}

	return 0;
}