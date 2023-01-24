#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct stage {
    int number;
    double failure_rate;
};

bool compare(stage s1, stage s2) {
    if (s1.failure_rate > s2.failure_rate) return true;
    if (s1.failure_rate < s2.failure_rate) return false;
    return s1.number < s2.number;
}

vector<int> solution(int N, vector<int> stages) {

    vector<int> answer;
    vector<stage> stages_info;

    for (int i = 1; i <= N; i++)
    {
        double challenge_count = 0;
        double arrival_count = 0;
        for (int s : stages)
        {
            if (s == i) challenge_count++;
            if (s >= i) arrival_count++;
        }
        
        double failure = challenge_count / arrival_count;
        stages_info.push_back({ i, failure });
    }

    sort(stages_info.begin(), stages_info.end(), compare);

    for (int i = 0; i < N; i++) 
        answer.push_back(stages_info[i].number);    

    return answer;
}
