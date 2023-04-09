import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
 
    static int T; // 테스트 케이스 수
    static int N; // 절벽지대 크기
    static int X; // 경사로의 길이
    static int[][] map; // 절벽지대
    static boolean[][] airstrip; // 활주로 설치 여부
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
 
        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            int answer = 0;
 
            // initialize
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            X = Integer.parseInt(st.nextToken());
            map = new int[N][N];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
 
            // 가로
            airstrip = new boolean[N][N];
            for (int i = 0; i < N; i++) {
                boolean possible = true;
                for (int j = 0; j < N - 1 && possible; j++) {
                    int diff = map[i][j] - map[i][j + 1];
                    if (Math.abs(diff) > 1) { // 높이 차이가 1보다 큰 경우
                        possible = false;
                        break;
                    } else if (Math.abs(diff) == 1) { // 높이 차이가 1이면.. 확인좀 해볼게요
                        if (diff > 0) { // 왼쪽이 더 높다
                            int h = map[i][j + 1];
                            for (int k = j + 1; k < X + j + 1; k++) {
                                // 활주로 못설치해..
                                if (N <= k || map[i][k] != h || airstrip[i][k]) {
                                    possible = false;
                                    break;
                                }
                                airstrip[i][k] = true;
                            }
                        } else { // 오른쪽이 더 높다
                            int h = map[i][j];
                            for (int k = j; k > j - X; k--) {
                                // 활주로 못설치해..
                                if (k < 0 || map[i][k] != h || airstrip[i][k]) {
                                    possible = false;
                                    break;
                                }
                                airstrip[i][k] = true;
                            }
                        }
                    }
                }
                // 활주로 설치 가능하대
                if (possible) {
                    answer++;
                }
            }
 
            // 세로
            airstrip = new boolean[N][N];
            for (int j = 0; j < N; j++) {
                boolean possible = true;
                for (int i = 0; i < N - 1 && possible; i++) {
                    int diff = map[i][j] - map[i + 1][j];
                    if (Math.abs(diff) > 1) { // 높이 차이가 1보다 큰 경우
                        possible = false;
                        break;
                    } else if (Math.abs(diff) == 1) { // 높이 차이가 1이면.. 확인좀 해볼게요
                        if (diff > 0) { // 위쪽이 더 높다
                            int h = map[i + 1][j];
                            for (int k = i + 1; k < X + i + 1; k++) {
                                // 활주로 못설치해..
                                if (N <= k || map[k][j] != h || airstrip[k][j]) {
                                    possible = false;
                                    break;
                                }
                                airstrip[k][j] = true;
                            }
                        } else { // 아래쪽이 더 높다
                            int h = map[i][j];
                            for (int k = i; k > i - X; k--) {
                                // 활주로 못설치해..
                                if (k < 0 || map[k][j] != h || airstrip[k][j]) {
                                    possible = false;
                                    break;
                                }
                                airstrip[k][j] = true;
                            }
                        }
                    }
                }
                // 활주로 설치 가능하대
                if (possible) {
                    answer++;
                }
            }
 
            // result
            System.out.println("#" + tc + " " + answer);
        }
    }
 
}