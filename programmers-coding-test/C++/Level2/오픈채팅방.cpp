#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {

	vector<string> answer;
	vector<pair<string, string>> user_action;
	unordered_map<string, string> hmap;

	for (string rec : record)
	{
		int index1 = rec.find(" ");
		string action = rec.substr(0, index1);
		string user, name;

		if (action == "Enter")
		{
			int index2 = rec.find(" ", index1 + 1);
			user = rec.substr(index1 + 1, index2 - index1 - 1);
			name = rec.substr(index2 + 1);
			hmap[user] = name;
			user_action.push_back({ user, "님이 들어왔습니다." });
		}

		if (action == "Leave")
		{
			user = rec.substr(index1 + 1);
			user_action.push_back({ user, "님이 나갔습니다." });
		}

		if (action == "Change")
		{
			int index2 = rec.find(" ", index1 + 1);
			user = rec.substr(index1 + 1, index2 - index1 - 1);
			name = rec.substr(index2 + 1);
			hmap[user] = name;
		}
	}

	for (pair<string, string> s : user_action)
		answer.push_back({ hmap[s.first] + s.second });

	return answer;
}
