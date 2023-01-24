#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {

    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while (pq.top() < K && pq.size() > 1)
    {
        int min_value1 = pq.top();
        pq.pop();

        int min_value2 = pq.top();
        pq.pop();

        int value = min_value1 + min_value2 * 2;
        pq.push(value);

        answer++;
    }

    return (pq.top() < K) ? -1 : answer;
}

// priority queue를 이용하여 푸는 것이 핵심
