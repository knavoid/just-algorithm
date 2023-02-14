import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int N; // 탑의 수
	static int[] top; // 탑의 높이들
	static Stack<Integer[]> stack = new Stack<>();
	static int[] answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		// initialize
		N = Integer.parseInt(br.readLine());
		answer = new int[N];
		st = new StringTokenizer(br.readLine());

		// solution
		for (int i = 1; i <= N; i++) {
			int value = Integer.parseInt(st.nextToken());
			while (!stack.empty() && stack.peek()[0] <= value) {
				stack.pop();
			}
			if (!stack.empty()) {
				answer[i - 1] = stack.peek()[1];
			} 
			stack.push(new Integer[] { value, i });
		}
		
		// result
		for (int a : answer) {
			bw.write(a + " ");
		}
		
		bw.flush();
		bw.close();
	}

}
