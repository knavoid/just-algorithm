#include <string>
#include <vector>

using namespace std;

int solution(int n) {

	vector<int> fib(n + 1);
	fib[1] = 1;

	for (int i = 2; i <= n; i++) fib[i] = (fib[i - 2] + fib[i - 1]) % 1234567;

	return fib[n] % 1234567;
}
