#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> complete;
    vector<int> answer;

    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses.at(i);  // 남은 작업의 양
        int taken_days = ceil((double)remain / (double)speeds.at(i));  // 작업 완료까지 걸리는 시간
        complete.push_back(taken_days);
    }

    int start = 0;  // 배포 시작 위치
    int len = complete.size();
    while (start < len)
    {
        int end = start;  // 배포 끝 위치
        while (end < len && complete.at(start) >= complete.at(end)) end++;
        answer.push_back(end - start);
        start = end;
    }

    return answer;
}