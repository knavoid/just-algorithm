#include <string>

using namespace std;

int solution(string s) {

	int max_len = 1;
	int len, begin, end;

	for (int i = 0; i < s.length() - 1; i++) {
		// case 1
		if (s[i] == s[i + 1]) {
			len = 2, begin = i - 1, end = i + 2;
			while (begin >= 0 && end < s.length()) {
				if (s[begin--] != s[end++]) break;
				len += 2;
			}
			max_len = max(max_len, len);
		}
		// case 2
		if (i > 0 && s[i - 1] == s[i + 1]) {
			len = 3, begin = i - 2, end = i + 2;
			while (begin >= 0 && end < s.length()) {
				if (s[begin--] != s[end++]) break;
				len += 2;
			}
			max_len = max(max_len, len);
		}
	}

	return max_len;
}
