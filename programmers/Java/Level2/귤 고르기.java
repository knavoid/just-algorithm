import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;

class Solution {
    public static int solution(int k, int[] tangerine) {
        int answer = 0;
        int count = 0;

        HashMap<Integer, Integer> sizeCount = new HashMap<>();
        for (int t : tangerine)
            sizeCount.put(t, sizeCount.getOrDefault(t, 0) + 1);

        ArrayList<Integer> sizes = new ArrayList<>(sizeCount.values());
        sizes.sort(Comparator.reverseOrder());

        int idx = 0;
        while (count < k) {
            count += sizes.get(idx++);
            answer++;
        }

        return answer;
    }

    public static void main(String[] args) {
        int[] t = {1, 3, 2, 5, 4, 5, 2, 3};
        int result = solution(6, t);
        System.out.println(result);
    }
}