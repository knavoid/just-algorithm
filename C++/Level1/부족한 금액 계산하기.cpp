#include <algorithm>

using namespace std;

long long solution(int price, int money, int count) {
    return max(0LL, 1LL * price * count * (count + 1) / 2 - money);
}