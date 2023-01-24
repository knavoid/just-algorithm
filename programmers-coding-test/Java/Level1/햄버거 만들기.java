class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;

        StringBuilder seq = new StringBuilder();
        for (int i : ingredient)
            seq.append(i + '0');

        int index = 3;
        while ((index = seq.indexOf("1231", index - 3)) != -1) {
            seq.delete(index, index + 4);
            answer++;
        }

        return answer;
    }
}