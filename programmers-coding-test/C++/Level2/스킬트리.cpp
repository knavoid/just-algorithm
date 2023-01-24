#include <string>
#include <vector>

using namespace std;

bool isCorrect(string skill, string tree) {

    // skill에 포함되는 스킬이 tree에 없거나, 
    // new_skill이 skill의 시작 sub string인 경우에 counting

    string new_skill = "";
    for (int i = 0; i < tree.length(); i++)
    {
        if (skill.find(tree[i]) != -1) 
            new_skill.append(tree.substr(i, 1));
    }

    return new_skill == "" || skill.find(new_skill) == 0;
}

int solution(string skill, vector<string> skill_trees) {

    int answer = 0;
    for (string tree : skill_trees)
        if (isCorrect(skill, tree)) answer++;

    return answer;
}
