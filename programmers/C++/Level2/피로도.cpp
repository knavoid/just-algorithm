#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int n = dungeons.size();
    sort(dungeons.begin(), dungeons.end());

    do {
        int count = 0;
        int fatigue = k;

        while (count < n && dungeons[count][0] <= fatigue) 
            fatigue -= dungeons[count++][1];

        answer = max(count, answer);
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}

int main() {
    cout << solution(80, { {80, 20}, {50, 40}, {30, 10} });
    return 0;
}