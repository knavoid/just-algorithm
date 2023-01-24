#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int N = survey.size();
    unordered_map<char, int> score;

    for (int i = 0; i < N; i++) {
        int c = choices[i];
        if (c < 4)
            score[survey[i][0]] += (4 - c);
        else
            score[survey[i][1]] += (c - 4);
    }

    string types[4] = { "RT", "CF", "JM", "AN" };
    for (string t : types) {
        char t1 = t[0], t2 = t[1];
        answer += (score[t1] >= score[t2]) ? t1 : t2;
    }

    return answer;
}