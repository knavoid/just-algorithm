#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N, answer;
vector<string> words;

void selectWords(int n, set<char> alphabet) {

	if (n == N) {
		if (alphabet.size() == 26)
			answer++;
		return;
	}

	// 단어를 선택하지 않은 경우
	selectWords(n + 1, alphabet);

	// 단어를 선택한 경우
	for (char c : words[n])
		alphabet.insert(c);
	selectWords(n + 1, alphabet);
}

int main() {
	
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string word;
		cin >> N;

		words.clear();
		for (int i = 0; i < N; i++) {
			cin >> word;
			words.push_back(word);
		}

		answer = 0;
		selectWords(0, set<char>());

		cout << '#' << t << ' ' << answer << '\n';
	}

	return 0;
}