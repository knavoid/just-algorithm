#include <string>
#include <vector>
#include <map>

using namespace std;

// used와 같은 경우의 수를 저장하는 map
map<vector<int>, int> cases;

// user id가 '*'처리된 user id에 포함되는지 판단하는 함수
bool isMatch(string bid, string uid) {
	if (uid.length() != bid.length()) return false;
	for (int i = 0; i < uid.length(); i++) {
		if (bid[i] != '*' && uid[i] != bid[i]) {
			return false;
		}
	}
	return true;
}

// 선택할 수 있는 경우의 수를 구하는 함수
void select(int ban, int n, int& answer, vector<vector<int>>& match, vector<int>& used) {

	if (ban == n) {
		if (!cases.count(used)) {
			cases.insert({ used, 1 });
			answer++;
		}
		return;
	}

	for (int i = 0; i < used.size(); i++) {
		if (match[ban][i] == 1 && used[i] == 0) {
			used[i] = 1;
			select(ban + 1, n, answer, match, used);
			used[i] = 0;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {

	int answer = 0;

	// 각각의 banned_id가 user_id에 match되는 경우 표시하기 위한 배열
	vector<vector<int>> match(banned_id.size(), vector<int>(user_id.size(), 0));
	// 이미 경우의 수에 사용된 id인지 표시하기 위한 배열
	vector<int> used(user_id.size(), 0);

	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			if (isMatch(banned_id[i], user_id[j])) {
				match[i][j] = 1;
			}
		}
	}

	select(0, banned_id.size(), answer, match, used);

	return answer;
}
