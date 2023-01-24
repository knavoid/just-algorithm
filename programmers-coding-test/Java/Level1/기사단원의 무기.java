class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        int[] powers = new int[number + 1];

        for (int i = 1; i <= number; i++)
            for (int j = i; j <= number; j += i)
                powers[j - 1]++;
        
        for (int p : powers)
            answer += (p <= limit) ? p : power;

        return answer;
    }
}