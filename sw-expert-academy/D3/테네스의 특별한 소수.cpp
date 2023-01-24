#include <iostream>
#include <algorithm>
#include <string>

#define MAX 1000000

using namespace std;

bool prime[MAX + 1];

int main() {

	int T;
	cin >> T;

	fill(prime + 2, prime + MAX + 1, true);

	for (int i = 2; i < MAX / 2; i++)
		if (prime[i])
			for (int j = 2 * i; j <= MAX; j += i)
				prime[j] = false;

	for (int t = 1; t <= T; t++) {
		int D, A, B, answer = 0;
		cin >> D >> A >> B;

		for (int i = A; i <= B; i++)
			if (prime[i] && to_string(i).find(D + '0') != string::npos)
				answer++;

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}