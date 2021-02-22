#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    return n == pow(round(sqrt(n)), 2) ? pow(sqrt(n) + 1, 2) : -1;
}