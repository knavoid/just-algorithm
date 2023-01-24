#include <iostream>

using namespace std;

int main() {
	
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, K, answer;
		cin >> N >> K;

		if (N == K)
			answer = 0;
		else if (N < K) 
			answer = 1;
		else 
			answer = N % K == 0 ? 0 : 1;
		
		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}