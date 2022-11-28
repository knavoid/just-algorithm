import java.util.HashMap;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        int n = discount.length;
        HashMap<String, Integer> sale = new HashMap<>();

        // 상품 키 세팅
        for (String w : want)
            sale.put(w, 0);
        for (String d : discount)
            sale.put(d, 0);

        // 첫날부터 열흘간의 할인 목록 세팅
        for (int day = 0; day < 10; day++) {
            String product = discount[day];
            sale.put(product, sale.get(product) + 1);
        }

        // 하루씩 진행하며 할인 목록 확인
        for (int day = 10; day <= n; day++) {
            // 회원가입 여부 파악
            boolean signup = true;
            for (int i = 0; i < want.length; i++) {
                if (sale.get(want[i]) < number[i]) {
                    signup = false;
                    break;
                }
            }
            if (signup)
                answer++;

            // 하루 진행
            if (day < n) {
                sale.put(discount[day], sale.get(discount[day]) + 1);
                sale.put(discount[day - 10], sale.get(discount[day - 10]) - 1);
            }
        }

        return answer;
    }
}