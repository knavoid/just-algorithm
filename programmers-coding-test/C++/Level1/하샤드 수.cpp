#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    
    int number = x;
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    
    return number % sum == 0;
}
