#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end());

    for (int h = 0; h <= citations.size(); h++)
        if (citations.at(h) >= citations.size() - h) return h;

    return -1;
}
