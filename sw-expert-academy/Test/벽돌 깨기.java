import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
 
public class Solution {
 
    static int T; // 테스트 케이스 수
    static int N; // 구슬 수
    static int W, H; // 넓이, 높이
    static int[][] brick; // 벽돌 정보
    static List<Integer> marble; // 선택한 구슬 위치
    static int[][] direct = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    static int answer; // 남은 벽돌의 최소 개수
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
 
        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            // initialize
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            brick = new int[H][W];
            for (int i = 0; i < H; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < W; j++) {
                    brick[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            marble = new ArrayList<>();
            answer = Integer.MAX_VALUE;
 
            // solution
            selectPosition(0);
 
            // result
            System.out.printf("#%d %d\n", tc, answer);
        }
 
    }
 
    static void selectPosition(int n) {
        // 구슬 위치를 다 선택했어요.
        if (n == N) {
            // 초기 벽돌 상태 복사
            int[][] b = new int[H][W];
            for (int i = 0; i < H; i++) {
                b[i] = brick[i].clone();
            }
            // 게임 시뮬레이션
            simulation(b);
            return;
        }
        // 구슬을 어디에 쏠까요?
        for (int i = 0; i < W; i++) {
            marble.add(i);
            selectPosition(n + 1);
            marble.remove(n);
        }
    }
 
    static void simulation(int[][] b) {
        // 구슬 횟수 만큼 반복
        for (int c : marble) {
            boolean[][] boom = new boolean[H][W]; // 터진 곳 체크
            Queue<int[]> queue = new ArrayDeque<>(); // 터진 곳을 하나하나씩 처리해야해요
            // 구슬 발사!
            for (int r = 0; r < H; r++) {
                int v = b[r][c];
                // 벽돌을 만났다
                if (v != 0) {
                    queue.add(new int[] { r, c, v });
                    break;
                }
            }
            // 연쇄적인 폭발
            while (!queue.isEmpty()) {
                int[] p = queue.poll();
                int x = p[0];
                int y = p[1];
                int v = p[2];
                boom[x][y] = true;
                // 4방향으로 퍼져 나가기
                for (int k = 1; k < v; k++) {
                    for (int d = 0; d < 4; d++) {
                        int dx = x + (k * direct[d][0]);
                        int dy = y + (k * direct[d][1]);
                        if (inRange(dx, dy) && b[dx][dy] != 0 && !boom[dx][dy]) {
                            boom[dx][dy] = true;
                            queue.add(new int[] { dx, dy, b[dx][dy] });
                        }
                    }
                }
            }
            // 터진 곳 지우기
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (boom[i][j]) {
                        b[i][j] = 0;
                    }
                }
            }
            // 중력에 의한 벽돌 내려오기
            for (int j = 0; j < W; j++) {
                int h = H - 1; // 벽돌이 내려올 위치
                while (h > 0 && b[h][j] != 0) {
                    h--;
                }
                for (int i = H - 1; i >= 0; i--) {
                    if (b[i][j] != 0 && i < h) { // 벽돌이 공중에 떠있으면
                        b[h][j] = b[i][j];
                        b[i][j] = 0;
                        h--;
                    }
                }
            }
        }
        // 벽돌 수 세기
        int count = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (b[i][j] != 0) {
                    count++;
                }
            }
        }
        // 정답 업데이트
        answer = Math.min(answer, count);
    }
 
    static boolean inRange(int x, int y) {
        return 0 <= x && x < H && 0 <= y && y < W;
    }
 
}