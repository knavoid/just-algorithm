#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int coke = n; // 가지고 있는 콜라 수
    int empty = 0; // 빈 콜라병 수

    while (coke > 0) {
        empty += coke;
        coke = (empty / a) * b;
        empty %= a;
        answer += coke;
    }

    return answer;
}