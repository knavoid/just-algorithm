#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {

	double J;
	vector<string> vect1;
	vector<string> vect2;

	for (int i = 0; i < str1.length(); i++) str1[i] = tolower(str1[i]);
	for (int i = 0; i < str2.length(); i++) str2[i] = tolower(str2[i]);

	for (int i = 0; i < str1.length() - 1; i++)
		if (isalpha(str1[i]) && isalpha(str1[i + 1]))
			vect1.push_back(str1.substr(i, 2));

	for (int i = 0; i < str2.length() - 1; i++)
		if (isalpha(str2[i]) && isalpha(str2[i + 1]))
			vect2.push_back(str2.substr(i, 2));

	sort(vect1.begin(), vect1.end());
	sort(vect2.begin(), vect2.end());

	vector<string> intersection(vect1.size() + vect2.size());
	vector<string> unionn(vect1.size() + vect2.size());

	set_intersection(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), intersection.begin());
	set_union(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), unionn.begin());

	while (!intersection.empty() && intersection.at(intersection.size() - 1) == "") 
		intersection.pop_back();
	while (!unionn.empty() && unionn.at(unionn.size() - 1) == "") 
		unionn.pop_back();

	if (intersection.size() == 0 && unionn.size() == 0) J = 1.0;
	else J = (double)intersection.size() / (double)unionn.size();

	return (int)(J * 65536.0);
}
