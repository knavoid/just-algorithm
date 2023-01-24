#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

unordered_map<string, int> decode{
	{"0001101", 0}, {"0011001", 1}, {"0010011", 2}, {"0111101", 3}, {"0100011", 4}, 
	{"0110001", 5}, {"0101111", 6}, {"0111011", 7}, {"0110111", 8}, {"0001011", 9}
};

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		string code; // 암호코드
		vector<int> info; // 암호코드 정보
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> code;
			// 모두 0으로 이루어지지 않고, 처음 정보가 발견된 경우
			if (code.find('1') != string::npos && info.empty()) {
				// 56자리 정보만 파싱
				code = code.substr(code.rfind('1') - 55, 56);
				while (info.size() != 8) {
					string ccc = code.substr(7 * info.size(), 7);
					info.push_back(decode[ccc]);
				}
			}
		}

		// 검증 코드
		int validCode = 0;
		for (int i = 0; i < 8; i++)
			validCode += i % 2 ? info[i] : 3 * info[i];

		int answer = validCode % 10 ? 0 : accumulate(info.begin(), info.end(), 0);
		cout << '#' << tc << ' ' << answer << '\n';
	}

	return 0;
}