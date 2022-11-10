#include <iostream>

#define MAX 1000000

using namespace std;

// 0: 소수, 1: 합성수
int prime[MAX + 1];

int main() {

	for (int n = 2; n <= MAX; n++) {
		// n이 소수가 아니면 패스
		if (prime[n] == 1)
			continue;
		
		// 소수 출력
		cout << n << ' ';

		// 소수의 배수들을 합성수로 표시
		for (int nn = 2 * n; nn <= MAX; nn += n)
			prime[nn] = 1;
	}
	
	return 0;
}