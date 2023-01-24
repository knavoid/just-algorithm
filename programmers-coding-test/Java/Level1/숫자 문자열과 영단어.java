class Solution {
    private String[] words = {"zero", "one", "two", "three", "four", "five",
            "six", "seven", "eight", "nine"};

    public int solution(String s) {
        for (int i = 0; i < 10; i++)
            s = s.replaceAll(words[i], Integer.toString(i));
        return Integer.parseInt(s);
    }
}