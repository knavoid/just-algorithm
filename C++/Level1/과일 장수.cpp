#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int n = score.size();

    sort(score.begin(), score.end(), greater<int>());

    for (int i = m - 1; i < n; i += m)
        answer += score[i] * m;

    return answer;
}