#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {

    int answer = 0;
    vector<int> vect;

    // 3진법으로 변환 & 앞뒤 반전
    while (n)
    {
        vect.push_back(n % 3);
        n /= 3;
    }

    // 10진법으로 표현
    for (int i = 0; i < vect.size(); i++)
        answer += vect[i] * pow(3, vect.size() - i - 1);

    return answer;
}