import java.util.PriorityQueue;

class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        PriorityQueue<Integer> honor = new PriorityQueue<Integer>();
        for (int i = 0; i < score.length; i++) {
            honor.add(score[i]);
            if (k < honor.size())
                honor.poll();
            answer[i] = honor.peek();
        }
        return answer;
    }
}