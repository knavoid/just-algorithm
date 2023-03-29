class Solution {
    public int solution(int n, int[] stations, int w) {
    	int answer = 0;
    	int begin = 1, end = 1;
    	for (int s : stations) {
    		end = s - w;
            if (begin < end) {
                answer += (end - begin - 1) / (2 * w + 1) + 1;
            }
    		begin = s + w + 1;
    	}
    	if (begin <= n) {
    		answer += (n - begin) / (2 * w + 1) + 1;    		
    	}
        return answer;
    }
}