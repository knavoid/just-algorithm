#include <iostream>
#include <string>
 
using namespace std;
 
int N, answer;
string str;
 
int main() {
 
    for (int tc = 1; tc <= 10; tc++) {
        // input
        cin >> N >> str;
 
        // solution
        answer = 0;
        for (int i = 0; i < N; i += 2)
            answer += (str[i] - '0');
 
        // output
        cout << '#' << tc << ' ' << answer << '\n';
    }
 
    return 0;
}