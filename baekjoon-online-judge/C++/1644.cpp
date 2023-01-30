#include <iostream>
#include <cstring>
using namespace std;

int N;
bool isPrime[4000001];

void eratos() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;
	for (int i = 2; i * i <= 4000000; i++) {
		if (!isPrime[i]) continue;
		for (int j = i + i; j <= 4000000; j += i) {
			isPrime[j] = false;
		}
	}
}

int main()
{

	eratos();

	cin >> N;

	int lo = 2;
	int hi = 2;
	int sum = 2;
	int res = 0;

	while (lo <= hi && hi <= N) {
		if (sum < N) {
			hi++;
			while (!isPrime[hi])
				hi++;
			sum += hi;
		}
		else if (sum == N) {
			res++;
			sum -= lo;
			lo++;
			while (!isPrime[lo])
				lo++;
		}
		else if (sum > N) {
			sum -= lo;
			lo++;
			while (!isPrime[lo])
				lo++;
		}
	}

	cout << res;
}