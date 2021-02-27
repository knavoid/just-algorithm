#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2) { return s1.length() < s2.length(); }

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		string phone = phone_book.at(i);
		for (int j = i + 1; j < phone_book.size(); j++)
			if (phone == phone_book.at(j).substr(0, phone.size()))
				return false;
	}

    return true;
}
