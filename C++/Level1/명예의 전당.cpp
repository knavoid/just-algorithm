#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> honor; // 명예의 전당
    for (int s : score) {
        honor.push(s);
        if (k < honor.size()) 
            honor.pop();
        answer.push_back(honor.top());
    }

    return answer;
}