#include <iostream>
#include <string>

using namespace std;

// f 함수
long long f(long long n) {

	long long sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		long long n;
		cin >> n;

		while (n >= 10)
			n = f(n);

		cout << '#' << tc << ' ' << n << '\n';
	}
	
	return 0;
}