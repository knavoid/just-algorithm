import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
 
public class Solution {
 
    private static int T;
    private static int H, W, N;
    private static char[][] map;
    private static char[] cmd;
    private static int tx, ty; // 전차 위치
    private static int[][] direct = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    private static List<Character> tank = Arrays.asList('^', 'v', '<', '>'); // 전차 마크
    private static List<Character> udlr = Arrays.asList('U', 'D', 'L', 'R'); // 상하좌우
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
 
        for (int tc = 1; tc <= T; tc++) {
            // initialize
            st = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            map = new char[H][W];
            for (int i = 0; i < H; i++) {
                map[i] = br.readLine().toCharArray();
                for (int j = 0; j < W; j++) {
                    if (tank.contains(map[i][j])) {
                        tx = i;
                        ty = j;
                        break;
                    }
                }
            }
            N = Integer.parseInt(br.readLine());
            cmd = br.readLine().toCharArray();
 
            // solution
            simulate();
 
            // result
            bw.write("#" + tc + " ");
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    bw.write(map[i][j]);
                }
                bw.newLine();
            }
        }
        bw.flush();
    }
 
    private static void simulate() {
        // 동작 수행
        for (char c : cmd) {
            if (c == 'S') { // 공격하기
                // 포탄 좌표 및 포탄 이동 방향
                int sx = tx;
                int sy = ty;
                int d = tank.indexOf(map[tx][ty]);
 
                // 벽, 강철을 만나거나 맵 밖으로 벗어나기 전까지 이동
                while (inRange(sx, sy) && map[sx][sy] != '*' && map[sx][sy] != '#') {
                    sx += direct[d][0];
                    sy += direct[d][1];
                }
                 
                // 벽을 만난 경우 파괴하기
                if (inRange(sx, sy) && map[sx][sy] == '*') {
                    map[sx][sy] = '.';
                }
            } else { // 이동하기
                // 전차 마크 변경
                map[tx][ty] = tank.get(udlr.indexOf(c));
                 
                // 이동 방향이 맵을 벗어나지 않으며 평지인 경우에 이동
                int d = tank.indexOf(map[tx][ty]);
                int dtx = tx + direct[d][0];
                int dty = ty + direct[d][1];
                if (inRange(dtx, dty) && map[dtx][dty] == '.') {
                    map[dtx][dty] = map[tx][ty];
                    map[tx][ty] = '.';
                    tx = dtx;
                    ty = dty;
                }
            }
        }
    }
 
    private static boolean inRange(int x, int y) {
        return 0 <= x && x < H && 0 <= y && y < W;
    }
 
}