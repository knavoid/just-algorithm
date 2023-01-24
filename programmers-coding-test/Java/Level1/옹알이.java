class Solution {

    final String[] pronounce = {"aya", "ye", "woo", "ma"};

    public int solution(String[] babbling) {
        int answer = 0;

        for (String b : babbling) {
            String before = "";
            boolean canPronounce = true;

            while (!b.isEmpty()) {
                boolean can = false;
                for (String p : pronounce) {
                    if (!p.equals(before) && b.indexOf(p) == 0) {
                        b = b.substring(p.length());
                        before = p;
                        can = true;
                        break;
                    }
                }
                if (!can) {
                    canPronounce = false;
                    break;
                }
            }
            if (canPronounce)
                answer++;
        }

        return answer;
    }
}