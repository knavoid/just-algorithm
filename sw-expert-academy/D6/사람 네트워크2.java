import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
 
    static int T; // 테스트 케이스 수
    static int N; // 사람의 수
    static int[][] rel; // 사람 관계
    static final int INF = 9999999;
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
 
        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            // initialize
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            rel = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    rel[i][j] = Integer.parseInt(st.nextToken());
                    if (i != j && rel[i][j] == 0) {
                        rel[i][j] = INF;
                    }
                }
            }
 
            // floyd
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        rel[i][j] = Math.min(rel[i][j], rel[i][k] + rel[k][j]);
                    }
                }
            }
 
            // CC 최솟값 계산
            int minCC = Integer.MAX_VALUE;
            for (int i = 0; i < N; i++) {
                int cc = 0;
                for (int j = 0; j < N; j++) {
                    cc += rel[i][j];
                }
                minCC = Math.min(minCC, cc);
            }
 
            // result
            System.out.println("#" + tc + " " + minCC);
        }
    }
 
}