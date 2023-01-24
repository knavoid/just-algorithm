#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> result;

void recur(int level, string now, vector<string>* list, vector<int>* used, vector<vector<string>> tickets) {
    if (level == tickets.size())
    {
        if (result.size() == 0) result = *list;
        return;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] != now) continue;
        if ((*used)[i] == 1) continue;
        string go = tickets[i][1];
        (*used)[i] = 1;
        (*list).push_back(go);
        recur(level + 1, go, list, used, tickets);
        (*list).pop_back();
        (*used)[i] = 0;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<string> answer = { "ICN" };
   
    vector<int> used;
    for (int i = 0; i < tickets.size(); i++) used.push_back(0);

    recur(0, "ICN", &answer, &used, tickets);

    return result;
}