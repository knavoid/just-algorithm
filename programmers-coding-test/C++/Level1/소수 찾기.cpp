#include <string>
#include <vector>

using namespace std;

int solution(int n) {

	int answer = 0;
    vector<int> prime(n + 1, 1);

	for (int i = 2; i <= n / 2; i++)
        for (int j = 2 * i; j <= n; j += i)
            prime[j] = 0;
    
    for (int i = 2; i <= n; i++)
        if (prime[i] == 1) 
            answer++;    

	return answer;
}