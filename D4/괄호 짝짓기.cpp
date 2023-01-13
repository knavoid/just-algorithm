#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
 
using namespace std;
 
int N;
string str;
unordered_map<char, char> bPair = { {'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'} };
 
int main() {
 
    for (int tc = 1; tc <= 10; tc++) {
        // input
        cin >> N >> str;
 
        // solution
        stack<char> brackets;
        for (char c : str) {
            if (!brackets.empty() && bPair[brackets.top()] == c)
                brackets.pop();
            else
                brackets.push(c);
        }
 
        // output
        cout << '#' << tc << ' ' << brackets.empty() ? 1 : 0;
        cout << '\n';
    }
 
    return 0;
}