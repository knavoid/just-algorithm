import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int match = 0;
        int invalid = 0;
        Set<Integer> set = new HashSet<>();

        for (int win_num : win_nums)
            set.add(win_num);

        for (int lotto : lottos) {
            if (lotto == 0)
                invalid++;
            else if (set.contains(lotto))
                match++;
        }

        return new int[]{getRank(match + invalid), getRank(match)};
    }

    int getRank(int count) {
        return Math.min(6, 7 - count);
    }
}