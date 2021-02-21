#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {

    vector<int> answer;

    int dat[201] = { 0 };

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            int sum = numbers[i] + numbers[j];
            dat[sum] = 1;
        }
    }

    for (int i = 0; i < 201; i++)
    {
        if (dat[i] == 1) answer.push_back(i);
    }

    return answer;
}