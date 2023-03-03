import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Solution {
 
    static int T;
    static int N, M, C;
    static int[][] honey;
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
 
        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            int answer = 0;
 
            // initialize
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            honey = new int[N][N];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    honey[i][j] = Integer.parseInt(st.nextToken());
                }
            }
 
            // solution
            for (int i1 = 0; i1 < N; i1++) {
                for (int j1 = 0; j1 <= N - M; j1++) {
                    for (int i2 = i1; i2 < N; i2++) {
                        for (int j2 = (i1 == i2) ? j1 + M : 0; j2 <= N - M; j2++) {
                            // 두 일꾼의 위치를 모두 선택하고 값 계산
                            answer = Math.max(answer, maxHoney(i1, j1) + maxHoney(i2, j2));
                        }
                    }
                }
            }
 
            // result
            System.out.printf("#%d %d\n", tc, answer);
        }
    }
 
    // 최대로 얻을 수 있는 꿀 양 반환
    static int maxHoney(int x, int y) {
        int max = 0;
        int[] h = Arrays.copyOfRange(honey[x], y, y + M);
        for (int i = (1 << M) - 1; i >= 0; i--) {
            int sum = 0;
            int value = 0;
            for (int j = 0; j < M; j++) {
                if ((i & (1 << j)) != 0) {
                    sum += h[j];
                    value += (h[j] * h[j]);
                }
            }
            if (sum <= C && value > max) {
                max = value;
            }
        }
 
        return max;
    }
 
}