class Solution {
    public int solution(int k, int[][] dungeons) {
        return getMaxDungeonCount(k, dungeons, 0, 0);
    }

    public int getMaxDungeonCount(int k, int[][] dungeons, int count, int selected) {
        int maxCount = count;
        for (int i = 0; i < dungeons.length; i++)
            if ((selected & (1 << i)) == 0 && dungeons[i][0] <= k)
                maxCount = Math.max(maxCount, getMaxDungeonCount(k - dungeons[i][1], dungeons, count + 1, selected | (1 << i)));
        return maxCount;
    }

    public static void main(String[] args) {
        System.out.println(1);
    }
}