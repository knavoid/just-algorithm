#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int count = 0;

    unordered_map<int, int> sizeCount;
    for (int t : tangerine)
        sizeCount[t]++;

    vector<int> sizes;
    for (pair<int, int> p : sizeCount)
        sizes.push_back(p.second);
    sort(sizes.begin(), sizes.end());

    while (count < k) {
        count += sizes.back();
        sizes.pop_back();
        answer++;
    }
    
    return answer;
}