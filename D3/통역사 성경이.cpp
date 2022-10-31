#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
bool isName(string word) {
 
    if (!isupper(word.front()))
        return false;
 
    int len = word.length();
    for (int i = 1; i < len; i++)
        if (!islower(word[i]))
            return false;
 
    return true;
}
 
int main() {
 
    int T;
    cin >> T;
 
    for (int t = 1; t <= T; t++) {
        int N;
        int sentenceCount = 0, nameCount = 0;
        string word;
        vector<int> answer;
 
        cin >> N;
 
        while (sentenceCount != N) {
            bool lastWord = false;
            cin >> word;
 
            // 단어의 마지막이 구두점으로 끝나는 경우
            if (word.find_first_of(".!?") == word.length() - 1) {
                word.pop_back();
                lastWord = true;
            }
 
            if (isName(word))
                nameCount++;
 
            if (lastWord) {
                answer.push_back(nameCount);
                nameCount = 0;
                sentenceCount++;
            }
        }
 
        // 결과 출력
        cout << '#' << t << ' ';
        for (int n : answer)
            cout << n << ' ';
        cout << '\n';
    }
 
    return 0;
}