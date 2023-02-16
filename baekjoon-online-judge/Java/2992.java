import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	static String X; // 입력한 수
	static boolean[] selected; // X에서 각 자릿수 선택 여부
	static List<String> numbers = new ArrayList<String>(); // 조합 가능한 숫자 리스트

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// initialize
		X = sc.next();
		selected = new boolean[X.length()];

		// solution
		permutation(new String());
		Collections.sort(numbers);
		int idx = numbers.indexOf(X);
		if (idx == numbers.size() - 1) {
			System.out.println("0");
		} else {
			System.out.println(numbers.get(idx + 1));
		}

		sc.close();
	}

	static void permutation(String str) {
		if (str.length() == X.length()) {
			if (!numbers.contains(str)) {
				numbers.add(str);
			}
			return;
		}
		for (int i = 0; i < X.length(); i++) {
			if (!selected[i]) {
				selected[i] = true;
				permutation(str + X.charAt(i));
				selected[i] = false;
			}
		}
	}

}
