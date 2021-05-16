#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

int direct(int a, int b) {
    int d = 1;
    while (d == a || d == b) d++;
    return d;
}

void hanoi(int n, int from, int to) {
    
    if (n == 1) answer.push_back({ from, to });
    else {
        hanoi(n - 1, from, direct(from, to));
        answer.push_back({ from, to });
        hanoi(n - 1, direct(from, to), to);
    }
}

vector<vector<int>> solution(int n) {

    hanoi(n, 1, 3);

    return answer;
}
