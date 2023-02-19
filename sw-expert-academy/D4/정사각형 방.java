import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
 
    static int T;
    static int N;
    static int[][] room;
    static int[][] maxRoomCount;
    static int[][] direct = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    static int[] answer;
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
 
        for (int tc = 1; tc <= T; tc++) {
            // initialize
            N = Integer.parseInt(br.readLine());
            room = new int[N][N];
            maxRoomCount = new int[N][N];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    room[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            answer = new int[2];
 
            // solution
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    // 방문한적이 없는 경우에만 방문해보기
                    if (maxRoomCount[i][j] == 0) {
                        maxRoomCount[i][j] = visitRoom(i, j);
                    }
                    if (maxRoomCount[i][j] != answer[1] ? maxRoomCount[i][j] > answer[1] : room[i][j] < answer[0]) {
                        answer[0] = room[i][j];
                        answer[1] = maxRoomCount[i][j];
                    }
                }
            }
 
            // result
            System.out.printf("#%d %d %d\n", tc, answer[0], answer[1]);
        }
    }
 
    static int visitRoom(int x, int y) {
        int maxCount = 0;
        for (int d = 0; d < 4; d++) {
            int dx = x + direct[d][0];
            int dy = y + direct[d][1];
            if (inRange(dx, dy) && room[dx][dy] == room[x][y] + 1) {
                maxCount = Math.max(maxCount, visitRoom(dx, dy));
            }
        }
        return maxCount + 1;
    }
 
    static boolean inRange(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    }
 
}