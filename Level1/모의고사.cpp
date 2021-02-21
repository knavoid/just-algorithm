#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {

    vector<int> answer;

    vector<int> correct_count(3);
    vector<int> patt1 = { 1, 2, 3, 4, 5 };
    vector<int> patt2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> patt3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    for (int i = 0; i < answers.size(); i++)
    {
        // 1번 수포자가 정답을 맞춘경우
        if (answers[i] == patt1[i % patt1.size()]) correct_count[0]++;

        // 2번 수포자가 정답을 맞춘경우
        if (answers[i] == patt2[i % patt2.size()]) correct_count[1]++;

        // 3번 수포자가 정답을 맞춘경우
        if (answers[i] == patt3[i % patt3.size()]) correct_count[2]++;
    }

    int max_count = *max_element(correct_count.begin(), correct_count.end());
    for (int i = 0; i < 3; i++)
    {
        if (correct_count[i] == max_count) answer.push_back(i + 1);
    }


    return answer;
}