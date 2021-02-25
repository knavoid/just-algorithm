#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    
    int answer = 0;
    vector<int> points;  // 결과의 점수를 저장
    vector<string> bonus_option;  // 결과의 보너스와 옵션을 저장

    int begin = 0;
    while (begin < dartResult.length()) 
    {
        int end = begin;

        // 결과에서 숫자를 추출
        while (isdigit(dartResult[end])) end++;
        points.push_back(stoi(dartResult.substr(begin, end - begin)));
        begin = end;

        // 결과에서 보너스/옵션을 추출
        while (!isdigit(dartResult[end]) && end < dartResult.length()) end++;
        bonus_option.push_back(dartResult.substr(begin, end - begin));
        begin = end;
    }

    for (int i = 0; i < 3; i++)
    {
        string bno = bonus_option[i];

        if (bno[0] == 'S') points[i] = pow(points[i], 1);
        if (bno[0] == 'D') points[i] = pow(points[i], 2);
        if (bno[0] == 'T') points[i] = pow(points[i], 3);

        if (bno.length() == 2)
        {
            if (bno[1] == '*')
            {
                points[i] *= 2;
                if (i > 0) points[i - 1] *= 2;
            }
            if (bno[1] == '#') points[i] *= -1;
        }
    }

    for (int point : points) answer += point;

    return answer;
}
