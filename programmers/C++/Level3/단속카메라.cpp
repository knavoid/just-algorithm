#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {

    int location, camera = 1;

    // 나간지점을 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), compare);

    location = routes[0][1];  // 첫 차량이 나간 위치에 카메라 설치

    for (int i = 1; i < routes.size(); i++) {
        // 다음 차량의 진입 위치가 최근 카메라 위치보다 앞선경우
        if (routes[i][0] > location) {  
            camera++;
            location = routes[i][1];
        }
    }

    return camera;
}
