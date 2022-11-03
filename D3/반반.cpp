#include <iostream>
#include <string>
#include <unordered_map>
 
using namespace std;
 
int main() {
 
    int T;
    cin >> T;
 
    for (int t = 1; t <= T; t++) {
        string S, answer = "Yes";
        unordered_map<char, int> alphaCount;
        cin >> S;
 
        for (char c : S)
            alphaCount[c]++;
 
        if (alphaCount.size() != 2)
            answer = "No";
        else
            for (pair<char, int> p : alphaCount)
                if (p.second != 2)
                    answer = "No";
 
        cout << '#' << t << ' ' << answer << '\n';
    }
 
    return 0;
}