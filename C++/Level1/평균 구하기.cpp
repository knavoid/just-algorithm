#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double sum = 0;
    for (int i : arr) sum += i;
    return sum / arr.size();
}
