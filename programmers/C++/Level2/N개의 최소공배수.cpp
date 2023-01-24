#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int n1, int n2) {
    return n2 ? gcd(n2, n1 % n2) : n1;
}

int lms(int n1, int n2) {
    int GCD = gcd(n1, n2);
    return GCD * (n1 / GCD) * (n2 / GCD);
}

int solution(vector<int> arr) {

    sort(arr.begin(), arr.end(), greater<int>());

    int value = arr.at(0);
    
    for (int i = 1; i < arr.size(); i++)
        value = lms(value, arr.at(i));

    return value;
}
