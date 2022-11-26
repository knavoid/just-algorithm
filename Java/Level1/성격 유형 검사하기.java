import java.util.HashMap;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        int N = survey.length;
        HashMap<Character, Integer> score = new HashMap<>();
        char[][] types = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};

        for (char[] type : types) {
            score.put(type[0], 0);
            score.put(type[1], 0);
        }

        for (int i = 0; i < N; i++) {
            int c = choices[i];
            if (c < 4)
                score.put(survey[i].charAt(0), score.get(survey[i].charAt(0)) + (4 - c));
            else
                score.put(survey[i].charAt(1), score.get(survey[i].charAt(1)) + (c - 4));
        }

        for (char[] type : types) {
            char t1 = type[0], t2 = type[1];
            answer += (score.get(t1) >= score.get(t2)) ? t1 : t2;
        }

        return answer;
    }
}