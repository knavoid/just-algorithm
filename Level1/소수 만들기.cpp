#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool isPrime(int num) {

    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;

    return true;
}

int solution(vector<int> nums) {
    
    int answer = 0;
    int len = nums.size();

    vector<int> mask(len);
    for (int i = len - 3; i < len; i++)
        mask[i] = 1;

    do {
        int sum = 0;
        for (int i = 0; i < len; i++)
            if (mask[i])
                sum += nums[i];

        if (isPrime(sum))
            answer++;

    } while (next_permutation(mask.begin(), mask.end()));

    return answer;
}