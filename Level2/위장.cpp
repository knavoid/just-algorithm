#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {

    int answer = 1;
    unordered_map<string, int> hmap;

    for (vector<string> vect : clothes)
        hmap[vect.at(1)]++;

    vector<int> count(hmap.size());

    for (auto iter : hmap)
        answer += answer * iter.second;

    return answer - 1;
}
