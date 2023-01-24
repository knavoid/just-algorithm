#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0"; 
    int n = food.size();

    for (int i = n - 1; i > 0; i--) {
        string s(food[i] / 2, i + '0');
        answer = s + answer + s;
    }

    return answer;
}