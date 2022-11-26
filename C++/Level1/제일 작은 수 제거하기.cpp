#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    vector<int> answer;

    int min_value = *min_element(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
        if (arr[i] != min_value) answer.push_back(arr[i]);

    if (arr.empty()) answer.push_back(-1);

    return answer;
}