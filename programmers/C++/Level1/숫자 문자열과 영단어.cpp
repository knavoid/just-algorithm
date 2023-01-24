#include <string>
#include <regex>

using namespace std;

int solution(string s) {
	string words[10] = { "zero", "one", "two", "three", "four", 
		"five", "six", "seven", "eight", "nine" };
	
	for (int i = 0; i < 10; i++)
		s = regex_replace(s, regex(words[i]), to_string(i));

	return stoi(s);
}