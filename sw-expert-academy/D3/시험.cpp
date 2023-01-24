#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct exam {
	int num;			// 참가자 번호
	int totalScore;		// 최종 점수
	int count;			// 푼 문제수
};

int solvedCount[2000]; // 문제당 푼 사람수
int gradingResult[2000][2000];
exam examInfo[2000];

// 점수 내림차순, 푼 문제수 내림차순, 참가자 번호 오름차순
bool compare(exam e1, exam e2) {

	if (e1.totalScore != e2.totalScore)
		return e1.totalScore > e2.totalScore;
	if (e1.count != e2.count)
		return e1.count > e2.count;

	return e1.num < e2.num;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		int N, T, P;
		cin >> N >> T >> P;

		memset(solvedCount, 0, sizeof(solvedCount));
		memset(gradingResult, 0, sizeof(gradingResult));
		memset(examInfo, 0, sizeof(examInfo));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < T; j++) {
				cin >> gradingResult[i][j];
				if (gradingResult[i][j] == 1)
					solvedCount[j]++;
			}
		}

		// 참가자 번호, 최종 점수, 푼 문제수를 계산하여 저장
		for (int i = 0; i < N; i++) {
			int num = i + 1;
			int totalScore = 0;
			int count = 0;

			for (int j = 0; j < T; j++) {
				if (gradingResult[i][j] == 1) {
					totalScore += N - solvedCount[j];
					count++;
				}
			}

			examInfo[i] = { num, totalScore, count };
		}

		// 주어진 기준으로 저장한 값 정렬
		sort(examInfo, examInfo + N, compare);

		// 결과 출력
		for (int i = 0; i < N; i++) {
			exam e = examInfo[i];
			if (e.num == P) {
				cout << '#' << t << ' ' << e.totalScore << ' ' << i + 1 << '\n';
				break;
			}
		}
	}

	return 0;
}