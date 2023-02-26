import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
 
public class Solution {
 
    private static int T;
    private static int M, A; // 이동시간 및 BC 개수
    private static int[] userA, userB; // 사용자 A, B의 이동 정보
    private static int[][] BC; // BC들의 정보
    private static int[][] direct = { { 0, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
    private static int answer;
     
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
 
        for (int tc = 1; tc <= T; tc++) {
            // initialize
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            A = Integer.parseInt(st.nextToken());
            userA = new int[M + 1];
            userB = new int[M + 1];
            BC = new int[A][4];
            answer = 0;
             
            // 사용자 A, B 입력
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= M; i++) {
                userA[i] = Integer.parseInt(st.nextToken());
            }           
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= M; i++) {
                userB[i] = Integer.parseInt(st.nextToken());
            }
             
            // BC 정보 입력
            for (int i = 0; i < A; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 4; j++) {
                    BC[i][j] = Integer.parseInt(st.nextToken());
                }
            }
             
            // solution 
            int ax = 1, ay = 1;
            int bx = 10, by = 10;
            for (int t = 0; t <= M; t++) {
                // 사용자 위치 이동
                ax += direct[userA[t]][0];
                ay += direct[userA[t]][1];
                bx += direct[userB[t]][0];
                by += direct[userB[t]][1];
                 
                // 각 BC의 충전 범위를 고려
                List<Integer> chargeA = new ArrayList<>();
                List<Integer> chargeB = new ArrayList<>();
                for (int i = 0; i < A; i++) {
                    // A가 접근 가능한지
                    if (Math.abs(BC[i][0] - ax) + Math.abs(BC[i][1] - ay) <= BC[i][2]) {
                        chargeA.add(i);
                    }
                    // B가 접근 가능한지
                    if (Math.abs(BC[i][0] - bx) + Math.abs(BC[i][1] - by) <= BC[i][2]) {
                        chargeB.add(i);
                    }
                }
                 
                // 선택 가능한 BC들의 조합을 고려
                int maxPower = 0;
                if (!chargeA.isEmpty() && !chargeB.isEmpty()) {
                    for (int a : chargeA) {
                        for (int b : chargeB) {
                            if (a == b) { // 같은 BC 선택
                                maxPower = Math.max(maxPower, BC[a][3]);
                            } else { // 각자 다른 BC 선택
                                maxPower = Math.max(maxPower, BC[a][3] + BC[b][3]);
                            }
                        }
                    }
                } else if (!chargeA.isEmpty()) {
                    for (int a : chargeA) {
                        maxPower = Math.max(maxPower, BC[a][3]);
                    }
                } else if (!chargeB.isEmpty()) {
                    for (int b : chargeB) {
                        maxPower = Math.max(maxPower, BC[b][3]);
                    }
                }
                answer += maxPower;
            }
             
             
            // result
            System.out.printf("#%d %d\n", tc, answer);
        }
    }
 
}