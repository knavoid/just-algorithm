#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {

    int answer = 0;
    int n = people.size();

    sort(people.begin(), people.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
        // 가장 무거운 사람과 가장 가벼운 사람이 함계 탑승 가능한 경우.
        if (people.at(i) + people.at(n - 1) <= limit) n--;
        answer++;
    }


    return answer;
}
