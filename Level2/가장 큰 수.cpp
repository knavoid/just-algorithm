#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int n1, int n2) {

    string s1 = to_string(n1) + to_string(n2);
    string s2 = to_string(n2) + to_string(n1);
    
    return stoi(s1) > stoi(s2);
}

string solution(vector<int> numbers) {

    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for (int i : numbers) answer.append(to_string(i));

    return answer[0] != '0' ? answer : "0";
}
