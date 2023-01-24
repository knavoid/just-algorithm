#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {

    long long answer = 0;
    vector<int> vect;

    while (n != 0)
    {
        vect.push_back(n % 10);
        n /= 10;
    }

    sort(vect.begin(), vect.end(), greater<int>());

    for (int i = 0; i < vect.size(); i++)
    {
        answer *= 10;
        answer += vect[i];
    }

    return answer;
}