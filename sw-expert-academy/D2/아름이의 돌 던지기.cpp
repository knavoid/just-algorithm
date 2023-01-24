#include <iostream>
#include <set>
 
using namespace std;
 
int main() {
 
    int T;
    cin >> T;
 
    for (int t = 1; t <= T; t++) {
        int N, number;
        cin >> N;
 
        multiset<int> numbers;
        for (int i = 0; i < N; i++) {
            cin >> number;
            number >= 0 ? numbers.insert(number) : numbers.insert(-number);
        }
 
        int closest = *numbers.begin();
        int closestCount = numbers.count(closest);
 
        cout << '#' << t << ' ' << closest << ' ' << closestCount << '\n';
    }
 
    return 0;
}