#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> pronounce{ "aya", "ye", "woo", "ma" };

bool canPronounce(string str, string before) {
    if (str.empty())
        return true;

    for (string p : pronounce) 
        if (p != before && str.find(p) == 0) 
            return canPronounce(str.substr(p.length()), p);

    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;

    for (string b : babbling) 
        if (canPronounce(b, ""))
            answer++;

    return answer;
}