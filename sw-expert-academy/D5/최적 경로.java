import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
 
    private static int T;
    private static int N; // 고객의 수
    private static int[][] client; // 고객 좌표들
    private static int[][] path; // 선택한 좌표들
    private static int answer;
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
 
        for (int tc = 1; tc <= T; tc++) {
            // initialize
            N = Integer.parseInt(br.readLine());
            client = new int[N][2];
            path = new int[N + 2][2];
            answer = Integer.MAX_VALUE;
            st = new StringTokenizer(br.readLine());
 
            // 회사 좌표를 시작으로
            path[0][0] = Integer.parseInt(st.nextToken());
            path[0][1] = Integer.parseInt(st.nextToken());
 
            // 집 좌표를 끝으로
            path[N + 1][0] = Integer.parseInt(st.nextToken());
            path[N + 1][1] = Integer.parseInt(st.nextToken());
 
            // 고객 좌표 입력
            for (int i = 0; i < N; i++) {
                client[i][0] = Integer.parseInt(st.nextToken());
                client[i][1] = Integer.parseInt(st.nextToken());
            }
 
            // 고객 좌표 순서 선택
            selectLocation(0, 0);
 
            // result
            System.out.printf("#%d %d\n", tc, answer);
        }
    }
 
    public static void selectLocation(int n, int selected) {
        // N개의 고객 좌표를 모두 선택한 경우
        if (n == N) {
            // 거리를 모두 합하기
            int dist = 0;
            for (int i = 0; i <= N; i++) {
                dist += Math.abs(path[i][0] - path[i + 1][0]) + Math.abs(path[i][1] - path[i + 1][1]);
            }
            answer = Math.min(answer, dist);
            return;
        }
        // 좌표 선택
        for (int i = 0; i < N; i++) {
            int bit = 1 << i;
            if ((selected & bit) == 0) { // 방문한 적이 없으면
                path[n + 1] = client[i];
                selectLocation(n + 1, selected | bit);
            }
        }
    }
 
}