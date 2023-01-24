#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n = discount.size();
    unordered_map<string, int> sale;

    // 첫날부터 열흘간의 할인 목록 세팅
    for (int day = 0; day < 10; day++)
        sale[discount[day]]++;

    // 하루씩 진행하며 할인 목록 확인
    for (int day = 10; day <= n; day++) {
        // 회원가입 여부 파악
        bool signup = true;
        for (int i = 0; i < want.size(); i++) {
            if (sale[want[i]] < number[i]) {
                signup = false;
                break;
            }
        }
        if (signup)
            answer++;

        // 하루 진행
        if (day < n) {
            sale[discount[day]]++;
            sale[discount[day - 10]]--;
        }
    }

    return answer;
}