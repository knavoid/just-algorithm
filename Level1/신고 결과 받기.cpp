#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int N = id_list.size();

    // 각 이용자의 id를 인덱스에 매핑
    unordered_map<string, int> index;
    for (int i = 0; i < N; i++)
        index[id_list[i]] = i;

    // 각 이용자를 신고한 신고자들 표시
    vector<set<int>> reporters(N, set<int>());
    for (string r : report) {
        int pos = r.find(' ');
        string reporter = r.substr(0, pos);
        string reported = r.substr(pos + 1);
        reporters[index[reported]].insert(index[reporter]);
    }

    // 신고 인원 파악
    vector<int> answer(N);
    for (int i = 0; i < N; i++) 
        if (reporters[i].size() >= k) 
            for (int r : reporters[i])
                answer[r]++;

    return answer;
}