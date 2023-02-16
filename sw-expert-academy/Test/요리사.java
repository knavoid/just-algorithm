import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
 
public class Solution {
 
    static int T; // 테스트 케이스 수
    static int N; // 식재료 수
    static int flavor[][]; // 식재료 맛
    static int answer;
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
 
        for (int tc = 1; tc <= T; tc++) {
            // initialize
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            flavor = new int[N + 1][N + 1];
            for (int i = 1; i <= N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 1; j <= N; j++) {
                    flavor[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            answer = Integer.MAX_VALUE;
 
            // solution
            selectIngredient(2, new ArrayList<>(Arrays.asList(1)));
 
            // result
            System.out.printf("#%d %d\n", tc, answer);
        }
    }
 
    // 식재료 선택
    static void selectIngredient(int begin, List<Integer> A) {
        if (A.size() == N / 2) {
            // A 요리가 선택하지 않은 음식을 B가 선택
            List<Integer> B = new ArrayList<>();
            for (int i = 1; i <= N; i++) {
                if (!A.contains(i)) {
                    B.add(i);
                }
            }
            // 맛 점수 계산 및 비교
            answer = Math.min(answer, Math.abs(totalFlavor(A) - totalFlavor(B)));
            return;
        }
        // A의 식재료 선택
        for (int i = begin; i <= N; i++) {
            A.add(i);
            selectIngredient(i + 1, A);
            A.remove(Integer.valueOf(i));
        }
    }
 
    // 선택한 식재료에 대한 맛 계산
    static int totalFlavor(List<Integer> F) {
        int total = 0;
        for (int i = 0; i < F.size() - 1; i++) {
            for (int j = i + 1; j < F.size(); j++) {
                total += (flavor[F.get(i)][F.get(j)] + flavor[F.get(j)][F.get(i)]);
            }
        }
        return total;
    }
 
}