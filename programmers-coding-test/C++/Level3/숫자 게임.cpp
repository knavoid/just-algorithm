#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {

    int a = 0, b = 0, score = 0;
    int len = A.size();

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    while (a < len) {
        if (A[a] < B[b]) {
            score++;
            b++;
        }
        a++;
    }

    return score;
}
