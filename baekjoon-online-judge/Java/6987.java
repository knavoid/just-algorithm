import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.Stream;

public class Main {

	private static int[] gameInfo;
	private static int[][] match = { // 0~5번 팀의 각 매치 (15개)
			{ 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 0, 5 }, 
			{ 1, 2 }, { 1, 3 }, { 1, 4 }, { 1, 5 }, { 2, 3 },
			{ 2, 4 }, { 2, 5 }, { 3, 4 }, { 3, 5 }, { 4, 5 } };
	private static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 0; t < 4; t++) {
			// initialize
			answer = 0;
			gameInfo = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

			// solution
			if (Arrays.stream(gameInfo).sum() == 30) { // 모든 승점이 30이 맞는 경우
				worldCup(0, new int[18]); // 판별해봅시다.
			}

			// result
			System.out.print(answer + " ");
		}
	}

	public static void worldCup(int game, int[] now) {
		// 15게임 모두 선택 완료!
		if (game == 15) {
			answer = 1;
			return;
		}
		// 매칭된 팀
		int left = match[game][0];
		int right = match[game][1];
		// 왼쪽팀이 승리해도 문제 없는 경우
		if (now[3 * left] < gameInfo[3 * left] && now[3 * right + 2] < gameInfo[3 * right + 2]) {
			int[] next = now.clone();
			next[3 * left]++;
			next[3 * right + 2]++;
			worldCup(game + 1, next);
		}
		// 무승부해도 문제 없는 경우
		if (now[3 * left + 1] < gameInfo[3 * left + 1] && now[3 * right + 1] < gameInfo[3 * right + 1]) {
			int[] next = now.clone();
			next[3 * left + 1]++;
			next[3 * right + 1]++;
			worldCup(game + 1, next);
		}
		// 오른쪽팀이 승리해도 문제 없는 경우
		if (now[3 * left + 2] < gameInfo[3 * left + 2] && now[3 * right] < gameInfo[3 * right]) {
			int[] next = now.clone();
			next[3 * left + 2]++;
			next[3 * right]++;
			worldCup(game + 1, next);
		}
	}

}
