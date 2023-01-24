#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {

    string answer = "";
    int day_diff = 0;

    vector<string> week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    vector<int> day = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 0; i < a - 1; i++) day_diff += day[i];  // 월 차이 계산
    day_diff += b - 1;  // 일 차이 계산

    answer = week[(day_diff + 5) % 7];

    return answer;
}