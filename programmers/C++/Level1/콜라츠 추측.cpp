#include <string>
#include <vector>

using namespace std;

int collatz(long n, int count) {
    if (count == 500) return -1;
    if (n == 1) return count;
    return n % 2 ? collatz(n * 3 + 1, count + 1) : collatz(n / 2, count + 1);
}

int solution(int num) {
    return collatz(num, 0);
}
