#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    string seq = "";
    for (int i : ingredient)
        seq += (i + '0');

    int pos = 3;
    while ((pos = seq.find("1231", max(0, pos - 3))) != string::npos) {
        seq = seq.substr(0, pos) + seq.substr(pos + 4);
        answer++;
    }

    return answer;
}