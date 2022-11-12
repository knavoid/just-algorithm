#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M, answer = 0;
		string str;
		cin >> N >> M;

		unordered_set<string> strSet;

		// N개의 문자열을 집합에 추가
		for (int i = 0; i < N; i++) {
			cin >> str;
			strSet.insert(str);
		}

		// M개의 문자열이 집합에 있는지 확인
		for (int i = 0; i < M; i++) {
			cin >> str;
			if (strSet.find(str) != strSet.end())
				answer++;
		}
		
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}