#include <iostream>
#include <vector>

using namespace std;

int N;
int answer;
vector<int> prime;
vector<bool> isPrime(1000, true);

// 3개의 소수 선택
void selectPrime(int cnt, int sum, int begin) {

	if (sum > N)
		return;
	if (cnt == 3) {
		if (sum == N)
			answer++;
		return;
	}

	for (int i = begin; i < prime.size(); i++) {
		if (sum + prime[i] > N)
			return;
		selectPrime(cnt + 1, sum + prime[i], i);
	}
}

int main() {

	int T;
	cin >> T;
	
	// 999 이하의 소수 구하기
	for (int i = 2; i < 1000; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			for (int j = 2 * i; j < 1000; j += i)
				isPrime[j] = false;
		}
	}

	for (int t = 1; t <= T; t++) {
		cin >> N;
		answer = 0;
		selectPrime(0, 0, 0);

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}