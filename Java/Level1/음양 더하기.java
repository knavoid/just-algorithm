class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;
        int length = absolutes.length;

        for (int i = 0; i < length; i++)
            answer += signs[i] ? absolutes[i] : -absolutes[i];

        return answer;
    }
}