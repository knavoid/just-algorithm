#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct info {
    int num;
    string genre;
    int play;
};

map<string, int> genre_plays;

bool comp(info i1, info i2) {

    if (genre_plays[i1.genre] > genre_plays[i2.genre]) return true;
    if (genre_plays[i1.genre] < genre_plays[i2.genre]) return false;

    if (i1.play > i2.play) return true;
    if (i1.play < i2.play) return false;

    return i1.num < i2.num;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    vector<int> answer;
    vector<info> songs;

    // 각각의 노래들의 번호와 정보들을 songs에 저장
    for (int i = 0; i < genres.size(); i++)
    {
        songs.push_back({ i, genres.at(i), plays.at(i) });
        genre_plays[genres.at(i)] += plays.at(i);
    }

    sort(songs.begin(), songs.end(), comp);

    for (int i = 0; i < songs.size(); i++)
    {
        if (i > 1 && songs.at(i).genre == songs.at(i - 1).genre && songs.at(i).genre == songs.at(i - 2).genre) continue;
        answer.push_back(songs.at(i).num);
    }

    return answer;
}
