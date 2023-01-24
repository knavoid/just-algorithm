#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
string answer;
int N, num;
char alpha;
int leftVertex, rightVertex;
vector<char> treetree;
 
void inorder(int num) {
    // 왼쪽 탐색
    if (num * 2 <= N)
        inorder(num * 2);
 
    // 현재 정점 탐색
    answer += treetree[num];
 
    // 오른쪽 탐색
    if (num * 2 + 1 <= N)
        inorder(num * 2 + 1);
}
 
int main() {
 
    for (int tc = 1; tc <= 10; tc++) {
        // initialize
        answer = "";
        cin >> N;
        treetree.assign(N + 1, 0);
        for (int i = 0; i < N; i++) {
            cin >> num >> alpha;
            if (num * 2 <= N)
                cin >> leftVertex;
            if (num * 2 + 1 <= N)
                cin >> rightVertex;
            treetree[num] = alpha;
        }
 
        // solution
        inorder(1);
 
        // result
        cout << '#' << tc << ' ' << answer << '\n';
    }
 
    return 0;
}