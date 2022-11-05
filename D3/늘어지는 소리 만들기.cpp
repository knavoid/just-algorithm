#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		int H, idx;
		cin >> str >> H;

		// 문자열에서 문자들을 각각 분리
		vector<string> strs{ "" };
		for (char c : str)
			strs.push_back(string(1, c));

		// 각각 분리된 문자에 하이픈 추가
		for (int i = 0; i < H; i++) {
			cin >> idx;
			strs[idx].push_back('-');
		}
		
		// 결과 출력
		cout << '#' << t << ' ';
		for (string s : strs)
			cout << s;
		cout << '\n';
	}

	return 0;
}