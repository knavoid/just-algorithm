#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {

    vector<long long> answer;

    for (long long number : numbers) {
        int x = 0;
        while ((number + 1) % (long long)pow(2, x + 2) == 0) {
            x++;
        }
        answer.push_back(number + pow(2, x));
    }

    return answer;
}
