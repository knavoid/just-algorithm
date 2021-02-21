#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    string answer = "";
    unordered_map<string, int> hmap;

    for (string name : completion)
    {
        hmap[name]++;  // 마라톤 완주자들을 등록
    }

    for (string name : participant)
    {
        if (hmap[name])  // 완주자 명단에 있는 경우
        {
            hmap[name]--;
        }
        else  // 완주자 명단에 없는 경우
        {
            answer = name;
            break;
        }
    }

    return answer;
}