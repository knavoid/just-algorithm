#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {

    int answer = 0;
    vector<vector<int>> cango(n + 1);
    vector<int> dist(n + 1, 0), visited(n + 1, 0);
    queue<int> nq;

    for (vector<int> e : edge) {
        cango[e[0]].push_back(e[1]);
        cango[e[1]].push_back(e[0]);
    }

    nq.push(1);
    visited[1] = 1;

    while (!nq.empty()) {
        int from = nq.front();
        for (int to : cango[from]) {
            if (!visited[to]) {
                visited[to] = 1;
                dist[to] = dist[from] + 1;
                nq.push(to);
            }
        }
        nq.pop();
    }

    int max_value = *max_element(dist.begin() + 1, dist.end());
    for (int i : dist) {
        if (i == max_value) {
            answer++;
        }
    }

    return answer;
}
