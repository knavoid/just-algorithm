import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static String expression;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// initialize
		expression = br.readLine();

		// solution
		int answer = 0;
		int number = 0;
		boolean minus = false;
		for (int i = 0; i < expression.length(); i++) {
			char c = expression.charAt(i);
			if (Character.isDigit(c)) { // 숫자
				number = number * 10 + c - '0';
			} else { // 연산자
				answer += minus ? -number : number;
				number = 0;
				if (c == '-') {
					minus = true;
				}
			}
		}
		answer += minus ? -number : number;

		// result
		System.out.println(answer);
	}

}