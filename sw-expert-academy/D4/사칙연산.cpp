#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int answer, N, num;
string vertex;
double leftVertex, rightVertex;
vector<string> vertexValue;
vector<pair<double, double>> tree;
 
double postorder(int num) {
    // 연산자인 경우
    if (tree[num].first && tree[num].second) {
        double left = postorder(tree[num].first);
        double right = postorder(tree[num].second);
        string value = vertexValue[num];
        if (value == "+")
            return left + right;
        else if (value == "-")
            return left - right;
        else if (value == "*")
            return left * right;
        else // oper == "/"
            return left / right;
    }
    // 숫자인 경우
    else
        return stod(vertexValue[num]);
}
 
int main() {
 
    for (int tc = 1; tc <= 10; tc++) {
        // initialize
        cin >> N;
        vertexValue.assign(N + 1, "");
        tree.assign(N + 1, {});
 
        // solution
        for (int i = 1; i <= N; i++) {
            cin >> num >> vertex;
            vertexValue[i] = vertex;
            // 연산자인 경우 좌우 정점을 추가로 입력
            if (string("+-*/").find(vertex) != string::npos) {
                cin >> leftVertex >> rightVertex;
                tree[i] = make_pair(leftVertex, rightVertex);
            }
        }
        answer = postorder(1);
 
        // result
        cout << '#' << tc << ' ' << answer << '\n';
    }
 
    return 0;
}