#include <string>
#include <vector>

using namespace std;

int numDivisor(int n) {

    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) cnt++;
    }

    return cnt;
}

int solution(int left, int right) {

    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (numDivisor(i) % 2 == 0) {  // 약수의 개수가 짝수인 경우
            answer += i;
        }
        else {  // 약수의 개수가 홀수인 경우
            answer -= i;
        }
    }

    return answer;
}
