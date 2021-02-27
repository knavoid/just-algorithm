#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    int answer = s.length();

	for (int size = 1; size <= s.length() / 2; size++)  // size : 자를 문자열 길이
	{
		string result = "";
		vector<string> vect;

		// 문자열 자르기
		int start = 0;
		while (start < s.length())
		{
			string sub = (start + size <= s.length()) ? s.substr(start, size) : s.substr(start);
			vect.push_back(sub);
			start += size;
		}

		// 문자열 압축
		int count = 1;
		string target = vect.at(0);
		for (int i = 1; i < vect.size(); i++)
		{
			if (vect.at(i) == target) count++;
			else
			{
				if (count > 1) result.append(to_string(count));
				result.append(target);
				target = vect.at(i);
				count = 1;
			}

			if (i == vect.size() - 1)  // 마지막 무자열의 경우
			{
				if (count > 1) result.append(to_string(count));
				result.append(target);
			}
		}

		if (result.length() < answer) answer = result.length();
	}

    return answer;
}
