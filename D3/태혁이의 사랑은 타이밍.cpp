#include <iostream>
 
using namespace std;
 
int main() {
 
    int T;
    cin >> T;
 
    for (int t = 1; t <= T; t++) {
        int D, H, M, answer = 0;
        cin >> D >> H >> M;
 
        answer += (D - 11) * 24 * 60;
        answer += (H - 11) * 60;
        answer += (M - 11);
 
        cout << '#' << t << ' ';
        answer >= 0 ? cout << answer : cout << -1;
        cout << '\n';
    }
 
    return 0;
}