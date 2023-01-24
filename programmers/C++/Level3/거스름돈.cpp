#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money)
{
    vector<long long> result(n + 1);
    result[0] = 1;

    for (int i : money)
        for (int j = i; j <= n; j++)
            result[j] = (result[j] + result[j - i]) % 1000000007;

    return result[n];
}
