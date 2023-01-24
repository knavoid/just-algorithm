class Solution {
    public int solution(int[] number) {
        int answer = 0;
        int N = number.length;
        for (int i = 0; i < N - 2; i++)
            for (int j = i + 1; j < N - 1; j++)
                for (int k = j + 1; k < N; k++)
                    if (number[i] + number[j] + number[k] == 0)
                        answer++;
        
        return answer;
    }
}