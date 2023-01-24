#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int time = 0;
    int total_weight = 0;

    queue<int> bridge;
    for (int i = 0; i < bridge_length; i++) bridge.push(0);

    for (int truck : truck_weights)
    {
        while (total_weight - bridge.front() + truck > weight)
        {
            total_weight -= bridge.front();
            bridge.pop();
            bridge.push(0);
            time++;
        }
        total_weight += truck - bridge.front();  // 새로 들어오는 트럭무게 추가 & 나가는 트럭 무게 제거
        bridge.pop();
        bridge.push(truck);
        time++;
    }

    time += bridge_length;  // 가장 최근에 들어간 트럭이 나오는데 걸리는 시간 추가

    return time;
}