import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int N, K;
	static Queue<Integer> people = new LinkedList<>();
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder answer = new StringBuilder();
		
		// initialize
		N = sc.nextInt();
		K = sc.nextInt();
		sc.close();
		for (int i = 1; i <= N; i++) {
			people.offer(i);
		}
		
		// solution
		answer.append("<");
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < K - 1; j++) {
				people.offer(people.poll());
			}
			answer.append(people.poll());
			if (i < N) {
				answer.append(", ");
			}
		}
		answer.append(">");
		
		// result
		System.out.println(answer);
	}
	
}
