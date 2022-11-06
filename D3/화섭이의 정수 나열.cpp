#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    int T;
    cin >> T;
 
    for (int t = 1; t <= T; t++) {
        int N, d, answer = 0;
        cin >> N;
 
        string str;
        for (int i = 0; i < N; i++) {
            cin >> d;
            str.append(to_string(d));
        }
 
        while (str.find(to_string(answer)) != string::npos)
            answer++;
 
        cout << '#' << t << ' ' << answer << '\n';
    }
 
    return 0;
}