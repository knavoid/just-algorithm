#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    vector<int> result(n, 0);
    map<string, int> index;

    for (int i = 0; i < enroll.size(); i++) {
        index.insert({ enroll[i], i });
    }

    for (int i = 0; i < seller.size(); i++) {
        string name = seller[i];
        int money = amount[i] * 100;
        while (name != "-" && money > 0) {
            int mymoney = money - (money / 10);
            int idx = index.at(name);
            result[idx] += mymoney;
            name = referral[idx];
            money /= 10;
        }
    }

    return result;
}
