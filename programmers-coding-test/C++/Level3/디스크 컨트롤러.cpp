#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare_queue {
    bool operator() (vector<int> v1, vector<int> v2) {
        return v1[1] > v2[1];
    }
};

int solution(vector<vector<int>> jobs) {

    int answer = 0;
    int time = 0; // 현재 시간
    int index = 0; // jobs index
    priority_queue<vector<int>, vector<vector<int>>, compare_queue> waiting;  // 대기중인 작업 (작업 시간이 짧은 것 우선)

    sort(jobs.begin(), jobs.end());  // 작업의 시작시간 순서로 정렬

    while (index < jobs.size() || !waiting.empty()) {

        while (index < jobs.size() && jobs[index][0] <= time) {  // 들어오는 작업의 요청시간이 현재 시간보다 빠른 경우
            waiting.push(jobs[index++]);
        }

        if (!waiting.empty()) {  // 대기중인 작업이 남아있는 경우
            time += waiting.top()[1]; 
            answer += time - waiting.top()[0]; 
            waiting.pop();
        }
        else {  // 대기중인 작업이 없는 경우
            time = jobs[index][0];
        }
    }

    return answer / jobs.size();
}
