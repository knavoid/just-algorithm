#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {

	vector<int> number;

	int begin = 0;
	while (1)
	{
		int end = s.find(" ", begin);
		if (end == -1)
		{
			int value = stoi(s.substr(begin, s.length() - begin));
			number.push_back(value);
			break;
		}
		else
		{
			int value = stoi(s.substr(begin, end - begin));
			number.push_back(value);
			begin = end + 1;
		}
	}

	sort(number.begin(), number.end());

	return to_string(number.at(0)) + " " + to_string(number.at(number.size() - 1));
}
