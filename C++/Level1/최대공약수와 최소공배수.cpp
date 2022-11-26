#include <string>
#include <vector>

using namespace std;

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

vector<int> solution(int n, int m) {

    vector<int> answer;

    int GCD = n > m ? gcd(n, m) : gcd(m, n);
    int LCM = GCD * (n / GCD) * (m / GCD);

    answer.push_back(GCD);
    answer.push_back(LCM);

    return answer;
}
