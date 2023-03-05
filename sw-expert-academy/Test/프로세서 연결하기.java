import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
 
public class Solution {
 
    static int T; // 테스트 케이스 수
    static int N; // 멕시노스 크기
    static int[][] M; // 멕시노스 정보 (0: 빈 셀, 1: core, 2: 전선)
    static List<int[]> core; // 코어들의 위치 리스트
    static int[][] direct = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    static int answer;
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
 
        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            // initialize
            N = Integer.parseInt(br.readLine());
            M = new int[N][N];
            core = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    M[i][j] = Integer.parseInt(st.nextToken());
                    if (M[i][j] == 1 && !(i == 0 || i == N - 1 || j == 0 || j == N - 1)) {
                        core.add(new int[] { i, j });
                    }
                }
            }
 
            // solution
            for (int n = core.size(); n > 0; n--) {
                answer = Integer.MAX_VALUE;
                connectCore(n, 0, 0, 0, M);
                if (answer != Integer.MAX_VALUE) {
                    break;
                }
            }
 
            // result
            System.out.printf("#%d %d\n", tc, answer);
        }
    }
 
    static void connectCore(int n, int begin, int wire, int selected, int[][] M) {
        // 이미 다 선택했어
        if (n == 0) {
            answer = Math.min(answer, wire);
            return;
        }
        // 어떤 코어부터 연결할까?
        for (int i = begin; i < core.size(); i++) {
            int mask = 1 << i;
            int x = core.get(i)[0];
            int y = core.get(i)[1];
            if ((selected & mask) == 0) {
                for (int d = 0; d < 4; d++) {
                    // 연결 가능한지 파악
                    int[][] m = copy(M);
                    int count = 0;
                    boolean connectable = true;
                    int dx = x + direct[d][0];
                    int dy = y + direct[d][1];
                    while (inRange(dx, dy)) {
                        if (m[dx][dy] != 0) {
                            connectable = false;
                            break;
                        }
                        m[dx][dy] = 2; // 전선으로 표시
                        dx += direct[d][0];
                        dy += direct[d][1];
                        count++;
                    }
                    // 연결 가능하면 연결해라
                    if (connectable) {
                        connectCore(n - 1, i + 1, wire + count, selected | mask, m);
                    }
                }
            }
        }
    }
 
    static int[][] copy(int[][] arr) {
        int[][] copyArr = new int[arr.length][];
        for (int i = 0; i < arr.length; i++) {
            copyArr[i] = arr[i].clone();
        }
        return copyArr;
    }
 
    static boolean inRange(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    }
 
}