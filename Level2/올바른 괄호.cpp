#include<string>

using namespace std;

bool solution(string s) {
    
    int stack = 0;
    for (char c : s)
    {
        if (c == '(') stack++;
        if (c == ')') stack--;

        if (stack < 0) return false;
    }

    return !stack;
}
