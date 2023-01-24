import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;

        ArrayList<Integer> qA = new ArrayList<>();
        ArrayList<Integer> qB = new ArrayList<>();
        for (int n : arrayA)
            qA.add(n);
        for (int n : arrayB)
            qB.add(n);

        int indexA = 0;
        while (indexA != qA.size() - 1) {
            qA.add(GCD(qA.get(indexA), qA.get(indexA + 1)));
            indexA += 2;
        }

        int indexB = 0;
        while (indexB != qB.size() - 1) {
            qB.add(GCD(qB.get(indexB), qB.get(indexB + 1)));
            indexB += 2;
        }

        int A = qA.get(indexA); // arrayA의 최대공약수
        int B = qB.get(indexB); // arrayB의 최대공약수

        if (Arrays.stream(arrayB).allMatch(x -> x % A != 0))
            answer = Math.max(A, answer);
        if (Arrays.stream(arrayA).allMatch(x -> x % B != 0))
            answer = Math.max(B, answer);

        return answer;
    }

    public int GCD(int a, int b) {
        return b != 0 ? GCD(b, a % b) : a;
    }
}