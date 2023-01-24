#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    int answer = 0;
    vector<int> fib = { 1, 1 };

    for (int i = 2; i <= n; i++)
        fib.push_back((fib[i - 2] + fib[i - 1]) % 1000000007);

    return fib[n];
}
